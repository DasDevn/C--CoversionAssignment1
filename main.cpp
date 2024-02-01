#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void demoOpenCloseStreams (string);

int main() {

    string stringConversion = "C:\\C++\\Assignment1-Conversion\\cmake-build-debug\\output.cpp";
    demoOpenCloseStreams (stringConversion);


}
void demoOpenCloseStreams(string inputfile) {
    cout << "Files Open" << endl;

    // Declare stream objects
    ifstream inStream;
    ofstream outStream;

    // Connect files to stream objects
    inStream.open(inputfile);
    outStream.open("happy.html");

    string line;
    string stringConversion;  // Assuming you have a string to store the entire content

    // ... Read the entire content into stringConversion ...

    // Replace "<" with "&lt;" and ">" with "&gt;" in each line
    while (getline(inStream, line)) {
        stringConversion += line + "\n";
    }

    // Replace "<" with "&lt;" and ">" with "&gt;" in each line
    for (int i = 0; i < stringConversion.length(); ++i) {
        if (stringConversion[i] == '<') {
            stringConversion.replace(i, 1, "&lt;");
            // add 3 to i to go over what we just replaced
            i += 3;
        } else if (stringConversion[i] == '>') {
            stringConversion.replace(i, 1, "&gt;");
            i += 3;
        }
    }

    // Insert "<PRE>\n" at the beginning
    stringConversion.insert(0, "<PRE>\n");

    // Append "\n</PRE>" at the end
    stringConversion += "\n</PRE>";

    // Write the modified content to the output file
    outStream << stringConversion << endl;

    inStream.close();
    outStream.close();
}
