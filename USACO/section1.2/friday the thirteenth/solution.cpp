/*
ID: mg172101
LANG: C++
PROG: friday
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int T, first = 6;
vector<int> countN(7, 0);

bool isLeapYear(int year) {
    if (year % 100 == 0) return year % 400 == 0;
    else return year % 4 == 0;
}

int main() {
    ofstream fout("friday.out");
    ifstream fin("friday.in");

    fin >> T;
    for(int year = 1900; year <= 1900 + T - 1; year++) {
        if(!isLeapYear(year)) {
            for(int i = 1; i <= 12; i++) {
                countN[first] ++;
                if(i == 1) first = (first + 3) % 7;
                else if (i == 2) continue;
                else if(i == 3) first = (first + 3) % 7;
                else if(i == 4) first = (first + 2) % 7;
                else if(i == 5) first = (first + 3) % 7;
                else if(i == 6) first = (first + 2) % 7;
                else if(i == 7) first = (first + 3) % 7;
                else if(i == 8) first = (first + 3) % 7;
                else if(i == 9) first = (first + 2) % 7;
                else if(i == 10) first = (first + 3) % 7;
                else if(i == 11) first = (first + 2) % 7;
                else first = (first + 3) % 7;
            }
        }
        else {
            for(int i = 1; i <= 12; i++) {
                countN[first] ++;
                if(i == 1) first = (first + 3) % 7;
                else if (i == 2) first = (first + 1) % 7;
                else if(i == 3) first = (first + 3) % 7;
                else if(i == 4) first = (first + 2) % 7;
                else if(i == 5) first = (first + 3) % 7;
                else if(i == 6) first = (first + 2) % 7;
                else if(i == 7) first = (first + 3) % 7;
                else if(i == 8) first = (first + 3) % 7;
                else if(i == 9) first = (first + 2) % 7;
                else if(i == 10) first = (first + 3) % 7;
                else if(i == 11) first = (first + 2) % 7;
                else first = (first + 3) % 7;
            }
        }
    }
    fout << countN[6] << " ";
    for(int i = 0; i < 5; i++) {
        fout << countN[i] << " ";
    } 
    fout << countN[5] << endl;
    return 0;
}
