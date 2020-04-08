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
    map<char,string> mirror;//�����Ӧ��ԭ�ַ��;����ַ�
    mirror['A'] = "A";mirror['E'] = "3";mirror['H'] = "H";mirror['I'] = "I";mirror['J'] = "L";
    mirror['L'] = "J";mirror['M'] = "M";mirror['O'] = "O";mirror['S'] = "2";mirror['T'] = "T";
    mirror['U'] = "U";mirror['V'] = "V";mirror['W'] = "W";mirror['X'] = "X";mirror['Y'] = "Y";mirror['Z'] = "5";
    mirror['1'] = "1";mirror['2'] = "S";mirror['3'] = "E";mirror['5'] = "Z";mirror['8'] = "8";
    while(cin>>s)
    {
        string s_reverse = s;
        reverse(s_reverse.begin(),s_reverse.end());//��ת
        int n1 = 0,n2 = 0;
        if(s == s_reverse)//����ǻ��Ĵ�n1Ϊ1
            n1 = 1;
        string s_mirror = "";
        for(int i = s.length() - 1; i >= 0; i--)//�жϵ�ǰ�ַ��ǲ��Ǿ����ַ�
            if(mirror.find(s.at(i)) == mirror.end())//�����ÿո񻻵�
                s_mirror += " ";
            else
                s_mirror += mirror[s.at(i)];//�Ǿ��þ����ַ���
        if(s == s_mirror)//����Ǿ���n2Ϊ1
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
