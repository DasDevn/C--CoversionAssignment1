#include <iostream>
#include <string>
using namespace std;

int main() {

    string stringConversion = "#include <iostream>\n int main()\n {\n int x=4;\n if (x < 3) x++;\n cout << x << endl;\n }";

    string inputFileLocation;



    cout << "Please enter the full path of your file, only the full path file name will work\n\nex: `C:\C++\Assignemtn1-Conversion` : \n";

    getline(cin, inputFileLocation);


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
