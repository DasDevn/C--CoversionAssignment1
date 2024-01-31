#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void demoOpenCloseStreams ();

int main() {

    string stringConversion = "#include <iostream>\n int main()\n {\n int x=4;\n if (x < 3) x++;\n cout << x << endl;\n }";
    demoOpenCloseStreams ();

        for (size_t i = 0; i < stringConversion.length(); ++i) {
            if (stringConversion[i] == '<') {
                //< gets replaced with &lt
                stringConversion.replace(i, 1, "&lt;");
                //add 3 to i to go over what we just replaced
                i += 4;
            }
        }

        for (size_t i = 0; i < stringConversion.length(); ++i) {
            if (stringConversion[i] == '>') {
                //< gets replaced with &gt
                stringConversion.replace(i, 1, "&gt;");
                //add 3 to i to go over what we just replaced
                i += 4;
            }
        }

    stringConversion.insert(0, "<PRE>\n");

    stringConversion += "\n</PRE>";
        std::cout << stringConversion << std::endl;

        return 0;



}

void demoOpenCloseStreams () {
    cout << "Files Open" << endl;
    //declare stream objects
    ifstream inStream;
    ofstream outStream;

    //connect files to stream object
    inStream.open("C:/C++/Assignment1-Conversion/src/assignmentOneSourceFile.cpp");
    outStream.open("output.html");

    string line;
    while (getline(inStream, line)) {
        outStream << line << endl;
    }

    inStream.close();
    outStream.close();

}