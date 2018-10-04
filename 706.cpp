/*
 Date :- 20.08.2018    Time :- 1:38 am
 CONCEPT :- Numbers accordingly as shown in the calculator
 DIFFICULTY :- Easy
*/
//change to bits/stdc++.h
#include "stdc++.h"
typedef unsigned long long ull;
typedef  long long ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
        int s;
        cin>>s;
        if(s == 0)
            break;
        string str;
        cin>>str;
        size_t n = str.length();
        int each_row = (2*s + 3), each_column = (s + 2);
        int row = each_row, column = each_column*n + n -1;
        char dash[row][column];
        memset(dash, ' ', sizeof(dash[0][0])*(row)*(column));
        int h=0;
        int j= 0, p = 0;
        while(h<n){
            int middle = each_row/2;// when starting with 0
            for(int i=0; i<row; i++){
                for(j=0; j<each_column; j++){
                    if(str[h] == '1'){
                        if( (j == each_column -1) && ((i>0 && i<middle) || (i>middle && i<each_row-1)))
                            dash[i][j+p] = '|';
                    }
                    else if(str[h] == '2'){
                        if(j>0 && j<each_column-1 && ((i==0) || (i==each_row-1) || (i ==  middle)))
                            dash[i][j+p] = '-';
                        else if( (j == each_column -1) && (i>0 && i<middle))
                            dash[i][j+p] = '|';
                        else if(j==0 && (i>middle && i<each_row-1))
                            dash[i][j+p] = '|';
                    }
                    else if(str[h] == '3'){
                        if(j>0 && j<each_column-1 && ((i==0) || (i==each_row-1) || (i ==  middle)))
                            dash[i][j+p] = '-';
                        else if( (j == each_column -1) && ((i>0 && i<middle) || (i>middle && i<each_row-1)))
                                dash[i][j+p] = '|';
                    }
                    else if(str[h] == '4'){
                        if(j>0 && j<each_column-1 && (i ==  middle))
                            dash[i][j+p] = '-';
                        else if( ((j == 0) || (j==each_column-1)) && (i>0 && i<middle))
                            dash[i][j+p] = '|';
                        else if( (j == each_column -1) && (i>middle && i<each_row-1))
                            dash[i][j+p] = '|';
                    }
                    else if(str[h] == '5'){
                        if(j>0 && j<each_column-1 && ((i ==  middle) || (i == 0) || (i==each_row-1)))
                            dash[i][j+p] = '-';
                        else if( (j == 0) && (i>0 && i<middle))
                            dash[i][j+p] = '|';
                        else if( (j == each_column-1) && (i>middle && i<each_row-1))
                            dash[i][j+p] = '|';
                    }
                    else if(str[h] == '6'){
                        if(j>0 && j<each_column-1 && ((i==0) || (i==each_row-1) || (i ==  middle)))
                            dash[i][j+p] = '-';
                        else if( (j == 0) && (i>0 && i<middle))
                                dash[i][j+p] = '|';
                        else if( ((j == 0) || (j==each_column-1)) && (i>middle && i<each_row-1))
                                dash[i][j+p] = '|';
                    }
                    else if(str[h] == '7'){
                        if((j>0 && j<each_column-1) && i==0)
                            dash[i][j+p] = '-';
                        else if( (j == each_column -1) && ((i>0 && i<middle) || (i>middle && i<each_row-1)))
                            dash[i][j+p] = '|';
                    }
                    else if(str[h] == '8'){
                        if(j>0 && j<each_column-1 && ((i==0) || (i==each_row-1) || (i ==  middle)))
                            dash[i][j+p] = '-';
                        else if( ((j == 0) || (j==each_column-1)) && (i>0 && i<middle))
                            dash[i][j+p] = '|';
                        else if( ((j == 0) || (j==each_column-1)) && (i>middle && i<each_row-1))
                            dash[i][j+p] = '|';
                    }
                    else if(str[h] == '9'){
                        if(j>0 && j<each_column-1 && ((i==0) || (i==each_row-1) || (i ==  middle)))
                            dash[i][j+p] = '-';
                        else if( ((j == 0) || (j==each_column-1)) && (i>0 && i<middle))
                            dash[i][j+p] = '|';
                        else if( (j==each_column-1) && (i>middle && i<each_row-1))
                            dash[i][j+p] = '|';
                    }
                    else if(str[h] == '0'){
                        if(j>0 && j<each_column-1 && ((i==0) || (i==each_row-1) ))
                            dash[i][j+p] = '-';
                        else if( ((j == 0) || (j==each_column-1)) && (i>0 && i<middle))
                            dash[i][j+p] = '|';
                        else if( ((j == 0) || (j==each_column-1)) && (i>middle && i<each_row-1))
                            dash[i][j+p] = '|';
                    }
                   
                }
                 
            }
            ++h;
            p = each_column*h + h;
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                cout<<dash[i][j];
            }
            cout<<"\n";
        }
        
    
    }
    return 0;
}
