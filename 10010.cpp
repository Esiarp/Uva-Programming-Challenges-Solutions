#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector< vector <char> > letters;

string tolower(string &s){
    string res = "";
    for(int i=0; i<s.length(); i++)
        res += tolower(s[i]);
    return res;
}

bool check_print_result(string &s, int k, int pos_i, int pos_j){
    if(k==s.length()){
        cout<<pos_i+1<<" "<<pos_j+1<<"\n";
        return true;
    }
    return false;
}

bool check(string &s, int pos_i, int pos_j, int n, int m){
    int k = 0, flag = 1;
    //check west side
    for(int j= pos_j; j>=0 && k<s.length(); j--){
        if(s[k] != letters[pos_i][j]){
            flag = 0;
            break;
        }
        k++;
    }
    if(flag){
        if(check_print_result(s, k, pos_i, pos_j))
            return true;
    }
    
    k = 0, flag = 1;
    //check north west side
    for(int i = pos_i, j=pos_j; i>=0 && j>=0 && k<s.length(); --i, --j){
        if(s[k] != letters[i][j]){
            flag = 0;
            break;
        }
        k++;
    }
    if(flag){
        if(check_print_result(s, k, pos_i, pos_j))
            return true;
    }
    
    k=0, flag = 1;
    //check north side
    for(int i=pos_i; i>=0 && k<s.length(); i--){
        if(s[k] != letters[i][pos_j]){
            flag = 0;
            break;
        }
        k++;
    }
    if(flag){
        if(check_print_result(s, k, pos_i, pos_j))
            return true;
    }
    
    k=0, flag = 1;
    //check north east side
    for(int i = pos_i, j = pos_j; i>=0 && j<m &&k<s.length(); i--, j++){
        if(s[k] != letters[i][j]){
            flag = 0;
            break;
        }
        k++;
    }
    if(flag){
        if(check_print_result(s, k, pos_i, pos_j))
            return true;
    }
    
    k=0, flag = 1;
    //check east side
    for(int j = pos_j; j<m && k<s.length(); j++){
        if(s[k] != letters[pos_i][j]){
            flag = 0;
            break;
        }
        k++;
    }
    if(flag){
        if(check_print_result(s, k, pos_i, pos_j))
            return true;
    }
    
    k=0, flag = 1;
    //check south east side
    for(int i=pos_i, j=pos_j; i<n && j<m && k<s.length(); i++, j++){
        if(s[k] != letters[i][j]){
            flag = 0;
            break;
        }
        k++;
    }
    if(flag){
        if(check_print_result(s, k, pos_i, pos_j))
            return true;
    }
    
    k=0, flag = 1;
    //check south side
    for(int i=pos_i; i<n && k<s.length(); i++){
        if(s[k] != letters[i][pos_j]){
            flag = 0;
            break;
        }
        k++;
    }
    if(flag){
        if(check_print_result(s, k, pos_i, pos_j))
            return true;
    }
    
    k=0, flag = 1;
    //check south west side
    for(int i=pos_i, j=pos_j; i<n && j>=0 && k<s.length(); i++, j--){
        if(s[k] != letters[i][j]){
            flag = 0;
            break;
        }
        k++;
    }
    if(flag){
        if(check_print_result(s, k, pos_i, pos_j))
            return true;
    }
    return false;
}

void solve(string &s, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(letters[i][j] == s[0]){
                if(check(s, i, j, n, m))
                    return;
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        for(int i=0; i<n; i++){
            vector<char> row;
            for(int j=0; j<m; j++){
                char c;
                cin>>c;
                c = tolower(c);
                row.pb(c);
            }
            letters.pb(row);
        }
        //for queries/words
        int q;
        cin>>q;
        for(int i =0; i<q; i++){
            string s;
            cin>>s;
            s = tolower(s);
            solve(s, n, m);
        }
        letters.clear();
        if(t!=0)
            cout<<"\n";
    }
    return 0;
}
