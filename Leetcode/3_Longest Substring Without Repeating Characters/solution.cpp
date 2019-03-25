/*****************
 * 暴力搜索有效，但是很慢。
 * 高效的方法是利用Hashset的高效查询，具体技巧是sliding window:
 * A window is a range of elements in the array/string which usually defined by the start and end indices.
 * A sliding window is a window "slides" its two boundaries to the certain direction.
*****************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <map>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isIn(string s, char c) {
        if(s == "") return -1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == c) return 1;
        }
        return 0;
    }
    //brute force
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        int length = 1;
        int l = s.size();
        if(l == 1) return 1;
        for(int i = 0; i < l; i++) {
            int j;
            for(j = 1; j < l-i; j++) {
                if(isIn(s.substr(i, j), s[i+j])) break;
            }
            length = length >= j ? length: j;
        }
        return length;
    }
    //sliding window
    int lengthOfLongestSubstring1(string s) {
        int left = 0, len = 0; 
        map<char, int> dict; //hashset, 快速查询，在此题中，还可以换成数组，使得查询速度更快
        //遍历字符串
        for (int right=0; right<s.size(); right++) {
            //s[right]在dict中
            if (dict.find(s[right]) != dict.end()) {
                left = max(left, dict[s[right]] + 1);//将最左边移动到该字符后边一个位置，因为此时[i, j)的其余i均不可能对应最大长度
            }
            dict[s[right]] = right;//初始化字符所对应的位置
            len = max(len, right - left + 1);//更新最大长度
        }
        return len;
    }
};

int main() {
    
    return 0;
}
