/*
ID: mg172101
LANG: C++11
PROG: beads
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    int n;string a;
    fin>>n>>a;
    string aa = a+a;
    int max = -1;
    for(int i=0;i<n;++i)
    {
        int j = i;
        int tmp = 0;
        {
 
            while(aa[j]=='w'){
                j++;
                tmp++;
                if(j>=i+n)
                    goto L;
            }
            char r = aa[j];
            while(aa[j]==r||aa[j]=='w'){
                j++;
                tmp++;
                if(j>=i+n)
                    goto L;
            }
            char x = aa[j];
            while(aa[j]==x||aa[j]=='w'){
                j++;
                tmp++;
                if(j>=i+n)
                    goto L;
            }
        }
        L:
        //cout<<tmp<<endl;
        if(tmp>max)
            max = tmp;
    }
    fout<<max<<endl;
 
    return 0;

}
