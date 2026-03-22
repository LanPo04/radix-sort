#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

void radixSort(vector<unsigned char>& A) {
    vector<unsigned char> B(A.size());
    for (int k = 0; k < 8; k++) {
        vector<int> C(2, 0);
        for (auto num : A) {
            int bit = (num >> k) & 1;
            C[bit]++;
        }
    }
}

bool readNumbers(vector<unsigned char>& vec, const char* filename) {
    ifstream input(filename);
    if (!input.is_open()) {
        return false;
    }
    int temp;
    while (input >> temp) {
        if (temp >= 0 && temp <= 255) {
            vec.push_back(static_cast<unsigned char>(temp));
        }
    }
    input.close();
    return true;
}

void writeNumbers(unsigned char* polje, unsigned int velikost) {
    ofstream output("out.txt");
    for (unsigned int i = 0; i < velikost; i++) {
        if (i > 0) output << ' ';
        output << static_cast<int>(polje[i]);
    }
    output << endl;
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
    radixSort(A);
    writeNumbers(&A[0], A.size());
    return 0;
}