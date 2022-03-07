#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string f1, f2;
    cout << "Enter name of source file :  ";
    cin >> f1;
    cout << "Enter name of destination file : ";
    cin >> f2;

    ifstream inp(f1);
    ofstream out(f2);

    string s;
    while (!inp.eof()){
        getline(inp, s);
        out << s << endl;
    }

    return 0;
}