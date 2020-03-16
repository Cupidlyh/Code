#include <iostream>

using namespace std;

class Solution {
public:
    string compressString(string S) {
        if(S.length() == 0)//×Ö·û´®Îª¿Õ
            return "";
        string res = "";
        int i,num = 1;
        char ch = S[0];
        for(i = 1; i < S.length(); i++) {
            if(S[i] == ch)
                num++;
            else {
                res += ch + to_string(num);//Êý×ÖÒª×ª³É×Ö·û´®
                ch = S[i];
                num = 1;
            }
        }
        res += ch + to_string(num);
        return res.length() >= S.length() ? S : res;
    }
};
