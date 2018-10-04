//change to bits/stdc++.h
#include "stdc++.h"
typedef unsigned long long ull;
typedef  long long ll;

using namespace std;

ull sum;

ull rec(ull n){
    if(n==1)
        return sum;
    if(n&1){
        ++sum;
        return(rec(3*n +1));
    }
    else{
        ++sum;
        return (rec(n/2));
    }
        
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull x, y;
    while(cin>>x>>y){
        ull cycle_length = 0, p_x = x, p_y = y;
        if(x>y){
           ull temp = x;
            x = y;
            y = temp;
        }
        for(int i = x; i<=y; i++){
            sum = 0;
            cycle_length = max(rec(i), cycle_length);
        }
        cout<<p_x<<" "<<p_y<<" "<<cycle_length+1<<"\n";
    }
    return 0;
}
