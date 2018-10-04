#include "stdc++.h"
using namespace std;

int main(){
    int n;
    vector <int> diff_num;
    while(cin>>n){
        int prev, curr;
        for(int i = 0; i<n; i++){
            scanf("%d", &curr);
            if(i>0)
                diff_num.push_back(abs(curr-prev));
            prev = curr;
        }
        sort(diff_num.begin(), diff_num.end());
        int i;
        int flag = 0;
        for(i=1; i<diff_num.size(); i++){
            if((diff_num[i] - diff_num[i-1])!= 1){
                flag = 1;
                break;
            }
        }
        if(flag == 0 && diff_num.size() == 1){
            if(diff_num[0] != 1)
                flag = 1;
        }
        ( n==1 || (flag == 0  && ((diff_num[diff_num.size()-1] == n-1) && diff_num[0] == 1))) ? cout<<"Jolly\n" : cout<<"Not jolly\n";
        diff_num.clear();
    }
    return 0;
}

