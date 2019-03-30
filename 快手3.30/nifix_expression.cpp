/*******************
 * 中缀表达式计算。
 * 将中缀表达式转成后缀表达式，再算后缀表达式的值。
 * 主要是对栈的运用。
*******************/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

using namespace std;  
  
int getPriority(char ch)  
{  
    //获取优先级  
    if (ch == '(') return 1;  
    else if (ch == '+' || ch == '-') return 2;  
    else if (ch == '*' || ch == '/') return 3;  
    else return 4;  
}  
  
string getPostfixExpression(string str)  
{  
    //将中缀表达式转化为后缀表达式  
    //默认输入是合法的  
    stack<char> mystack;  
    int size = str.size();  
    int i = 0;  
    char tmp;  
    string res = "";  
    while (i < size) {  
        if (str[i] >= '0' && str[i] <= '9'){  
            res.push_back(str[i]);  
        }  
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {  
            if (mystack.empty()) {  
                mystack.push(str[i]);  
            }  
            else {  
                while (!mystack.empty()) {  
                    tmp = mystack.top();  
                    if (getPriority(tmp) >= getPriority(str[i])) {  
                        //弹出栈顶元素  
                        res.push_back(tmp);  
                        mystack.pop();  
                    }  
                    else break;  
                }  
                mystack.push(str[i]);  
            }  
        }  
        else {  
            if(str[i]=='(') mystack.push(str[i]);  
            else {  
                while (mystack.top() != '(') {  
                    tmp = mystack.top();  
                    res.push_back(tmp);  
                    mystack.pop();  
                }  
                mystack.pop();  
            }  
        }  
        i++;  
    }  
  
    //遍历完后，若栈非空，弹出所有元素  
    while (!mystack.empty()) {  
        tmp = mystack.top();  
        res.push_back(tmp);  
        mystack.pop();  
    }  
    return res;  
}  
  
   
  
int calculator(string str)  
{  
    //计算后缀表达式的值，默认中缀表达式所有数字都是一位的，在0-9之间  
    stack<int> mystack;  
    int size = str.size();  
    int num1, num2, num3;  
    for (int i = 0; i < size; i++) {  
        if (str[i] >= '0' && str[i] <= '9') {  
            mystack.push(str[i] - '0');  
        }  
        else {  
            num2 = mystack.top();  
            mystack.pop();  
            num1 = mystack.top();  
            mystack.pop();  
            if (str[i] == '+') {  
                num3 = num1 + num2;  
            }  
            else if (str[i] == '-') {  
                num3 = num1 - num2;  
            }  
            else if (str[i] == '*') {  
                num3 = num1 * num2;  
            }  
            else if (str[i] == '/') {  
                num3 = num1 / num2;  
            }  
            mystack.push(num3);  
        }  
    }  
    return mystack.top();  
}  
  
   
int main()  
{  
    string str="1+(2-3)*4+4/2";  
    cout <<"中缀表达式为:"<< endl << str << endl;  
    string res = getPostfixExpression(str);  
    cout <<"后缀表达式为:"<< endl << res << endl;  
    int num_res = calculator(res);  
    cout <<"计算结果:"<< endl << num_res << endl;  
    system("pause");  
    return 0;  
} 
