#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
using namespace std;

int main()
{
    string s;
    map<char,string> mirror;//保存对应的原字符和镜像字符
    mirror['A'] = "A";mirror['E'] = "3";mirror['H'] = "H";mirror['I'] = "I";mirror['J'] = "L";
    mirror['L'] = "J";mirror['M'] = "M";mirror['O'] = "O";mirror['S'] = "2";mirror['T'] = "T";
    mirror['U'] = "U";mirror['V'] = "V";mirror['W'] = "W";mirror['X'] = "X";mirror['Y'] = "Y";mirror['Z'] = "5";
    mirror['1'] = "1";mirror['2'] = "S";mirror['3'] = "E";mirror['5'] = "Z";mirror['8'] = "8";
    while(cin>>s)
    {
        string s_reverse = s;
        reverse(s_reverse.begin(),s_reverse.end());//翻转
        int n1 = 0,n2 = 0;
        if(s == s_reverse)//如果是回文串n1为1
            n1 = 1;
        string s_mirror = "";
        for(int i = s.length() - 1; i >= 0; i--)//判断当前字符是不是镜像字符
            if(mirror.find(s.at(i)) == mirror.end())//不是用空格换掉
                s_mirror += " ";
            else
                s_mirror += mirror[s.at(i)];//是就用镜像字符换
        if(s == s_mirror)//如果是镜像串n2为1
            n2 = 1;
        if(n1 == 0 && n2 == 0)
            cout<<s<<" -- is not a palindrome."<<endl<<endl;
        else if(n1 == 1 && n2 == 0)
            cout<<s<<" -- is a regular palindrome."<<endl<<endl;
        else if(n1 == 0 && n2 == 1)
            cout<<s<<" -- is a mirrored string."<<endl<<endl;
        else if(n1 == 1 && n2 == 1)
            cout<<s<<" -- is a mirrored palindrome."<<endl<<endl;
    }
    return 0;
}
