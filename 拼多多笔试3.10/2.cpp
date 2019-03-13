/*******************
 * 拼多多提前批笔试第二题
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <iostream>
#include <string>

using namespace std;

string s;
char res;

void toLower(string& s) {
    int length = s.length();
    for(int i = 0; i < length; i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') 
            s[i] = 'a' + (s[i] - 'A');
    }
}

// 用来检查字符串在位置pos前后是否出现过重复的字符，若出现过，则返回true，否则返回false
bool check(string& str,int pos) {
    int i,j;
    for(i=0;i<pos;i++)
    {
        for(j=pos+1;str[j];j++)
        {
            if(str[i]==str[j])
                break;
        }
        if(str[j]=='\0')
            return false;
    }
    return true;
}

void solve(string &str) {
    toLower(str);
    // 将res初始化为第一个字符，若无重复字符出现，则输出res
    res = str[0];
    // 从第一个位置开始遍历，只要当当前字符比res小且res在当前字符的后面出现才能更新res
    for(int i = 0; i < str.length(); i++) {
        if(check(str, i) && str[i] < res)
            res = str[i];
    }
}

int main() {
    cin >> s;
    solve(s);
    cout << res << endl;

    return 0;
}