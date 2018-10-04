/*
 A really tricky set of test cases having empty lines gave a WA,
 added some conditions of 'cin.eof' and 'cin.good', which got it accepted.
 
 Logic is simple go through the first string and second string after taking every
 character of the first string and matching with the second string, if they match delete
 that particular character from the second string and break the current loop, and then continue the same process from the next character of the first string.
 */

#include <bits/stdc++.h>
using namespace std;


int main(){
    char c;
    string s1, s2;
    while(!cin.eof()){
        string res = "";
        getline(cin, s1);
        if (!std::cin.good()) return 0;
        getline(cin, s2);
        size_t s1_len = s1.length(), s2_len = s2.length();
        for(int i=0; i<s1_len; i++){
            for(int j=0; j<s2_len; j++){
                if(s1[i]==s2[j]){
                    res += s1[i];
                    s2.erase(j, 1);
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        cout<<res<<"\n";
    }
    return 0;
}
