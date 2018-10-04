#include "stdc++.h"
using namespace std;

int main(){
    unordered_map<char, char> umap;
    umap['W'] = 'Q';
    umap['E'] = 'W';
    umap['R'] = 'E';
    umap['T'] = 'R';
    umap['Y'] = 'T';
    umap['U'] = 'Y';
    umap['I'] = 'U';
    umap['O'] = 'I';
    umap['P'] = 'O';
    umap['['] = 'P';
    umap[']'] = '[';
    umap['\\'] = ']';
    umap['S'] = 'A';
    umap['D'] = 'S';
    umap['F'] = 'D';
    umap['G'] = 'F';
    umap['H'] = 'G';
    umap['J'] = 'H';
    umap['K'] = 'J';
    umap['L'] = 'K';
    umap[';'] = 'L';
    umap['\''] = ';';
    umap['X'] = 'Z';
    umap['C'] = 'X';
    umap['V'] = 'C';
    umap['B'] = 'V';
    umap['N'] = 'B';
    umap['M'] = 'N';
    umap[','] = 'M';
    umap['.'] = ',';
    umap['/'] = '.';
    umap['1'] = '`';
    umap['2'] = '1';
    umap['3'] = '2';
    umap['4'] = '3';
    umap['5'] = '4';
    umap['6'] = '5';
    umap['7'] = '6';
    umap['8'] = '7';
    umap['9'] = '8';
    umap['0'] = '9';
    umap['0'] = '9';
    umap['-'] = '0';
    umap['='] = '-';
    
    string s;
    while(1){
        getline(cin, s);
        if(s.length()==0)
            break;
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' '){
                cout<<" ";
                continue;
            }
            cout<<umap[s[i]];
        }
        s = "";
        cout<<"\n";
    }
    return 0;
}

