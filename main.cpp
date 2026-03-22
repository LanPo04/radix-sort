#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

bool readNumbers(vector<unsigned char>& vec, const char* filename) {
    ifstream input(filename);
    int temp;
    if (!input.is_open()) {
        return false;
    }
    while (input >> temp) {
        if (temp >= 0 && temp <= 255) {
            vec.push_back(static_cast<unsigned char>(temp));
        }
    }
    input.close();
    return true;
}


int main(int argc, char* argv[]) {
    vector<unsigned char> A;
    if (argc != 2) {
        cout << "Usage: vaja2 <input_file>" << endl;
        return 1;
    }
    if (!readNumbers(A, argv[1])) {
        cout << "Error: Cannot open input file" << endl;
        return 1;
    }
    return 0;
}