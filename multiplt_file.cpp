#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ofstream fout;
    fout.open("country");
    fout << "India" << endl;
    fout << "USA" << endl;
    fout << "China" << endl;
    fout.close();

    fout.open("Capital");
    fout << "New Delhi" << endl;
    fout << "Washington, D.C." << endl;
    fout << "Beijing" << endl;
    fout.close();

    const int n = 80;
    char line[n];

    ifstream fin;
    fin.open("country");

    cout<<"Content of country file:" << endl;
    while (fin) {
        fin.getline(line, n);
        cout << line << endl;
    }

    fin.close();

    fin.open("Capital");

    cout<<"Content of Capital file:" << endl;
    while (fin) {
        fin.getline(line, n);
        cout << line << endl;
    }

    fin.close();

    
    return 0;
}