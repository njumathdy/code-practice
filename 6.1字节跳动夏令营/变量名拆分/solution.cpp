/*******************
acwing856
*******************/

// my solution: tle

// #include <cstdlib>
// #include <cstdio>
// #include <exception>
// #include <vector>
// #include <algorithm>
// #include <string>
// #include <iostream>
// #include <set>

// using namespace std;

// string str;
// set<string> str_table;
// bool res = false;

// void dfs(vector<int>& index) {
//     int i = index.back();
//     if(str_table.find(str.substr(i+1, str.size()-i-1)) != str_table.end()) {
//         res = true;
//         return;
//     }
//     int j = 1;
//     while(i + j < str.size()) {
//         if(str_table.find(str.substr(i+1, j)) != str_table.end()) {
//             index.push_back(i+1+j-1);
//             dfs(index);
//             index.pop_back();
//         }
//         j++;
//     }         
// }

// void solve() {
//     vector<int> index;
//     index.push_back(-1);
//     dfs(index);
// }

// int main() {
//     cin >> str;
//     string temp;
//     while(cin >> temp)
//         str_table.insert(temp);

//     solve();
//     if(res)
//         cout << "True" << endl;
//     else
//         cout << "False" << endl;
    
//     return 0;
// }

// 字符串hash
#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

const int N = 10010, P = 131;

char str[ N ], word[ N ];

ull h[ N ], p[ N ];
unordered_set< ull > s;

int f[ N ];

ull get( int l, int r )
{
    return h[ r ] - h[ l - 1 ] * p[ r - l + 1 ];
}

int main()
{
    scanf( "%s", str + 1 );
    int n = strlen( str + 1 );

    p[ 0 ] = 1;
    for( int i = 1; i <= n; i ++ )
    {
        h[ i ] = h[ i - 1 ] * P + str[ i ];
        p[ i ] = p[ i - 1 ] * P;
    }

    while( scanf( "%s", word + 1 ) != - 1 )
    {
        ull tot = 0;
        for( int i = 1; word[ i ]; i++ ) tot = tot * P + word[ i ];
        s.insert( tot );
    }

    f[ 0 ] = 1;

    for( int i = 1; i <= n; i ++ )
    for( int j = i; j; j-- )
    {
        if( f[ j - 1 ] && s.count( get( j, i ) ) )
        {
            f[ i ] = 1;
            break;
        }
    }

    if( f[ n ] ) printf( "True" );
    else         printf( "False" );
    return 0;
}
