#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "../inc/htmlConverter.h"
using namespace std;

//CLion recommended making the parameters const and references, working fine,
//researched it a bit, somewhat understand why, more research needed

//exception #2  '...' any exceptions are caught
void demoOpenCloseStreams(const string& inputFile, const string& outputFile) {
    try{
        cout << "File Converted and Saved" << endl;

        // Declare stream objects
        ifstream inStream;
        ofstream outStream;

        // Connect files to stream objects
        inStream.open(inputFile);
        outStream.open(outputFile);

        //Declare variables to be used
        string line;
        string stringConversion;


        // Replace "<" with "&lt;" and ">" with "&gt;" in each line
        while (getline(inStream, line)) {
            stringConversion += line + "\n";
        }

        // Replace "<" with "&lt;" and ">" with "&gt;" in each line
        for (int i = 0; i < stringConversion.length(); ++i) {
            if (stringConversion[i] == '<') {
                stringConversion.replace(i, 1, "&lt;");
                // Add 3 to i to go over what we just replaced
                i += 3;
            } else if (stringConversion[i] == '>') {
                stringConversion.replace(i, 1, "&gt;");
                i += 3;
            }
        }

        // Insert "<PRE>\n" at the beginning
        stringConversion.insert(0, "<PRE>\n");

        // Add "\n</PRE>" at the end
        stringConversion += "</PRE>";

        // Write the modified content to the output file
        outStream << stringConversion << endl;
    } catch (...) {
        cout << "An unexpected error occurred." << endl;
    }
}

//Exception #3 - exception library error for regex
//https://stackoverflow.com/questions/24702677/regular-expression-to-match-a-valid-absolute-windows-directory-containing-spaces
//https://regex101.com/
//https://en.cppreference.com/w/cpp/error/runtime_error
//https://en.cppreference.com/w/cpp/regex/regex_error
bool isValidInput(const string& input) {
    try {
        // Define the regex pattern
        regex pattern(R"(^[a-zA-Z]:\\.*\.(cpp|html)$)");
        // Test input against the regex pattern
        return regex_match(input, pattern);
    } catch (const regex_error& e) {
        // Handle regex error
        cout << "Regex error: " << e.what() << endl;
        return false;
    }
}


// Function to get user input for file name
string getFileName() {
    string fileName;
    //do while loop continues to execute until a proper name is enter or the person quits
    do {
        cout << "Please enter the complete path of the .cpp file you want to convert to an HTML file or enter 'quit' to exit program. \n (e.g. C:\\Path\\to\\your\\file.cpp): \n";
        getline(cin, fileName);
        if (fileName == "quit") {
            cout << "Exiting the program.\n";
            exit(0);
        }
        //added incase file does not exist
        if (!isValidInput(fileName) || !ifstream(fileName)) {
            cout << "Invalid file name or file does not exist.\n\n";
            fileName.clear();  // Clear the input to ask for it again
        }
    } while (fileName.empty());
    return fileName;
} //



//Function to save file
string getSaveLocation() {
    string saveLocation;
    do {
        cout << "\nPlease enter the complete path where you'd like to save the converted (.cpp to .html) file or enter 'quit' to exit program \n Don't forget to add a name for the file at the end of the path followed with .html! \n (e.g. C:\\Path\\to\\your\\file\\fileName.html): \n";
        getline(cin, saveLocation);
        if (saveLocation == "quit") {
            cout << "Exiting the program.\n";
            exit(0);
        }
        if (!isValidInput(saveLocation)) {
            cout << "Invalid save location.\n\n";
        }
    } while (!isValidInput(saveLocation));
    return saveLocation;
}

