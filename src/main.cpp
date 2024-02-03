#include <iostream>
#include <string>
#include "../inc/htmlConverter.h"
using namespace std;

//cite: https://stackoverflow.com/questions/49877965/c-catchstdexception-e-vs-catch
//exception #1, will handle all exceptions and then throw error with what the error is

int main() {
    try {
        string inputFile = getFileName();
        string outputFile = getSaveLocation();
        demoOpenCloseStreams(inputFile, outputFile);
    } catch (const exception& e) {
        cout << "Error: " << e.what() ;
        return 1;
    }
    return 0;
}

