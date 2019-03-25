/*
ID: mg172101
LANG: C++ 
PROG: namenum
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, char> dic = {{'A','2'}, {'B', '2'}, {'C', '2'}, {'D', '3'}, {'E', '3'}, {'F', '3'},
{'G', '4'}, {'H', '4'}, {'I', '4'}, {'J', '5'}, {'K', '5'}, {'L', '5'}, {'M', '6'}, {'N', '6'}, {'O', '6'},
{'P', '7'}, {'R', '7'}, {'S', '7'}, {'T', '8'}, {'U', '8'}, {'V', '8'}, {'W', '9'}, {'X', '9'}, {'Y', '9'} };

int main() {
    ifstream fin("dict.txt");
    vector<string> names;
    string s;
    while(fin >> s) {
        names.push_back(s);
    }

    string number(12, ' ');
    ifstream fin1("namenum.in");
    ofstream fout("namenum.out");
    fin1 >> number;
    bool available = false;
    
    for(auto iter = names.begin(); iter != names.end(); iter++) {
        int l = (*iter).size();
        string name = "";
        for(int i = 0; i < l; i++) {
            name += dic[(*iter)[i]];
        }
        if(name == number) {
            fout << *iter << endl;
            available = true;
        }
    }
    if(available == false) {
        fout << "NONE" << endl;
    }

    
    return 0;
}
