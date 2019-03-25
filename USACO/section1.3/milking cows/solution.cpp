/*
ID: mg172101
LANG: C++
PROG: milk2
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <list>

using namespace std;

class Farmer {
public:
    int begin_;//开始时间
    int end_;//结束时间

    Farmer(int beg, int end) {
        begin_ = beg;
        end_ = end;
    }//构造函数
    Farmer(const Farmer& source) {//const 常，不可变
        begin_ = source.begin_;
        end_ = source.end_;
    }//构造函数
    ~Farmer(){}//默认构造函数
};
//定义两个farmer的大小关系，根据开始工作的时间定义
bool compareBeginTime(const Farmer& farmer1, const Farmer& farmer2) {
    if(farmer1.begin_ < farmer2.begin_) {
        return true;
    } else return false;   
}
//主程序
int main() {
    ofstream fout("milk2.out");//读入数据文件
    ifstream fin("milk2.in");//输出结果

    list<Farmer> times;//农民的列表

    int N;//农民个数
    int begin = 0, end = 0;//用来记录每次输入的开始和结束时间

    fin >> N;//读取农民个数

    //处理数据，如何处理？
    for(int i = 0; i < N; i++) {
        fin >> begin >> end;
        for(list<Farmer>::iterator it = times.begin(); it != times.end();) {
            if(end < (*it).begin_ || begin > (*it).end_) {
                it++;
                continue;
            }
            begin = min((*it).begin_, begin);//较小的开始时间
            end = max((*it).end_, end);//较大的结束时间
            list<Farmer>::iterator it_temp = it;
            it++;
            times.erase(it_temp);//删掉旧区间
        }//遍历列表
        times.push_back(Farmer(begin, end));//将新的区间添加到列表
    }
    times.sort(compareBeginTime);//排序，按照开始时间先后

    int max1 = 0, max2 = 0;
    for(list<Farmer>::iterator it = times.begin(); it != times.end(); it++) {
        max1 = max(((*it).end_ - (*it).begin_), max1);
        list<Farmer>::iterator it_temp = it;
        if((++it) != times.end()) {
            max2 = max((*it).begin_ - (*it_temp).end_, max2);
        }
        it = it_temp;
    }

    fout << max1 << " " << max2 << endl;
    
    return 0;
}
