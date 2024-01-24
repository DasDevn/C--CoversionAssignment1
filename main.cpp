#include <iostream>
#include <string>
using namespace std;

int main() {

    string stringConversion = "#include <iostream>\n int main()\n {\n int x=4;\n if (x < 3) x++;\n cout << x << endl;\n }";


        for (size_t i = 0; i < stringConversion.length(); ++i) {
            if (stringConversion[i] == '<') {
                //< gets replaced with &lt
                stringConversion.replace(i, 1, "&lt");
                //add 3 to i to go over what we just replaced
                i += 3;
            }
        }

        for (size_t i = 0; i < stringConversion.length(); ++i) {
            if (stringConversion[i] == '>') {
                //< gets replaced with &gt
                stringConversion.replace(i, 1, "&gt");
                //add 3 to i to go over what we just replaced
                i += 3;
            }
        }

    stringConversion.insert(0, "<PRE>\n");

    stringConversion += "\n</PRE>";
        std::cout << stringConversion << std::endl;

        return 0;



}
