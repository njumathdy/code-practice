/*******************
We are thinking of an integer P within the range (A,B] — that is, A < P ≤ B. 
You have N tries to guess our number. 
After each guess that is not correct, we will tell you whether P is higher or lower than your guess.
*******************/
#include <string>
#include <iostream>

using namespace std;

int main() {
    int num_test_cases;
    cin >> num_test_cases;
    for(int i = 0; i < num_test_cases; i++) {
        int lo, hi;
        cin >> lo >> hi;
        int num_tries;
        cin >> num_tries;

        int head = lo + 1, tail = hi;
        while(true) {
            int m = (head + tail) / 2;
            cout << m << endl;
            string s;
            cin >> s;
            if(s == "CORRECT") break;
            if(s == "TOO_SMALL")
                head = m + 1;
            else 
                tail = m - 1;
        }
    }
    return 0;
}
