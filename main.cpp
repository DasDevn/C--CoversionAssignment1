#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void demoOpenPrint();
void demoOpenWrite();

int main() {

    void demoOpenPrint()
    {
        string line;
        ifstream myFileIn;
        //you may use either .fail() or the .is_open() method
        //of the file stream object
        myFileIn.open("myFileIn.txt");
        if(myFileIn.is_open())//or if(myFileIn.fail
        {
            cout << "File Open" << endl;
            while(!myFileIn.eof()){
                getline(myFileIn,line);
                cout << line<<endl;
            }
            myFileIn.close();
            cout<<"File closed"<<endl;
        }else{
            cout << "Input file failed to open"<< endl;
        }
    }

    void demoOpenWrite(const string& fileName) {
        ofstream myFileOut;

        myFileOut.open(fileName, ios::app);

        if (!myFileOut.fail()) {
            myFileOut << "stuff" << " and more stuff" << endl;
            myFileOut.close();
            cout << "File Closed" << endl;
        } else {
            cout << "Output File failed to open" << endl;
        }
    }

    string inputFileLocation;



    cout << "Please enter the full path of your file, only the full path file name will work\n\nex: `C:\C++\Assignemtn1-Conversion` : \n";

    getline(cin, inputFileLocation);


        for (size_t i = 0; i < inputFileLocation.length(); ++i) {
            if (inputFileLocation[i] == '<') {
                //< gets replaced with &lt
                inputFileLocation.replace(i, 1, "&lt;");
                //add 3 to i to go over what we just replaced
                i += 4;
            }
        }

        for (size_t i = 0; i < inputFileLocation.length(); ++i) {
            if (inputFileLocation[i] == '>') {
                //< gets replaced with &gt
                inputFileLocation.replace(i, 1, "&gt;");
                //add 3 to i to go over what we just replaced
                i += 4;
            }
        }

    inputFileLocation.insert(0, "<PRE>\n");

    inputFileLocation += "\n</PRE>";
        std::cout << inputFileLocation << std::endl;

        return 0;



}
