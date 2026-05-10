#include "FileStorage.h"
#include<fstream>
#include<iostream>
using namespace std;
void FileStorage::save(string& data) {
    ofstream outFile("test_output.txt");  // should create file in current directory

        if (outFile.is_open()) {
            outFile << "This is a test." << endl;
            outFile.close();
            cout << "File written successfully!" << endl;
        } else {
            cout << "Failed to open the file!" << endl;
        }
}
    
