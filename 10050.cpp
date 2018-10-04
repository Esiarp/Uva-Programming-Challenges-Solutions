#include "stdc++.h"
#define MAX 3651
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, p;
        cin>>n>>p;
        int hartal[MAX+1];
        memset(hartal, 0, sizeof(hartal[0])*(MAX+1));
        for(int i = 0; i<p; i++){
            int x;
            cin>>x;
            hartal[x] = x;
        }
        for(int i = 1; i<=n; i++){
            if(hartal[i]!=0)
                for(int j = i; j<=n; j+=i){
                    hartal[j] = i;
                }
        }
        int count = 0;//no of working days lost
        for(int i =1; i<=n; i++){
            //Beware this day has hartal :(
            if(hartal[i] != 0){
                if((i%7) == 0 || ((i+1)%7 ==0))
                    continue;
                else
                    ++count;
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}
