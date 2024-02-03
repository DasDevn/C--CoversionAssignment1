#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "../inc/htmlConverter.h"
using namespace std;




int main() {
    string inputFile = getFileName();
    string outputFile = getSaveLocation();
    demoOpenCloseStreams(inputFile, outputFile);
}

