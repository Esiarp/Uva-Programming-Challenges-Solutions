/*
 Check the check.
 Was pretty easy, had to think a little bit about implementation.
 */
#include "stdc++.h"
#define ROW 8
#define COL 8
#define MAX_SIZE 64
typedef unsigned long long ULL;
using namespace std;

char board[ROW][COL];
// 1 - White king is in check 2 - Black king is in check 0 - Neither king is in check
int check_flag;

void pawn(int i, int j, char c){
    //if white king is in check
    if(c == 'p'){
        //when black is top left corner
        if(j == 0 && i<=ROW-2 && (board[i+1][j+1] == 'K'))
            check_flag = 1;
        else if( j == COL-1 && i<=ROW-2 && (board[i+1][j-1]) == 'K')
            check_flag = 1;
        else if(i == ROW-1)
            check_flag = 0;
        //when black pawn is not at the top corners and not in the last row
        else{
            if(board[i+1][j-1] == 'K' || board[i+1][j+1] == 'K')
                check_flag = 1;
        }
    }
    else{
        //when black is bottom left corner
        if(j == 0 && i>=1 && (board[i-1][j+1] == 'k'))
            check_flag = 2;
        else if( j == COL-1 && i>=1 && (board[i-1][j-1]) == 'k')
            check_flag = 2;
        else if(i == 0)
            check_flag = 0;
        //when black pawn is not at the top corners and not in the last row
        else{
            if(board[i-1][j-1] == 'k' || board[i-1][j+1] == 'k')
                check_flag = 2;
        }
    }
    
}

void knight(int i, int j, char c){
    char king_case;
    int flag ;
    if(c == 'n'){
        king_case = 'K';
        flag = 1;
    }
    else{
        king_case = 'k';
        flag = 2;
    }
    if(i>0 && j>=2 && board[i-1][j-2] == king_case) {check_flag = flag; return;}
    if(i>=2 && j>0 && board[i-2][j-1] == king_case) {check_flag = flag; return;}
    if(i>=1 && j<=COL-3 && board[i-1][j+2] == king_case) {check_flag = flag; return;}
    if(i>=2 && j<=COL-2 && board[i-2][j+1] == king_case) {check_flag = flag; return;}
    if(i<=ROW-2 && j>=2 && board[i+1][j-2] == king_case) {check_flag = flag; return;}
    if(i<=ROW-3 && j>=1 && board[i+2][j-1] == king_case) {check_flag = flag; return;}
    if(i<=ROW-2 && j<=COL-3 && board[i+1][j+2] == king_case) {check_flag = flag; return;}
    if(i<=ROW-3 && j<=COL-2 && board[i+2][j+1] == king_case) {check_flag = flag; return;}
    
}

void bishop(int i, int j, char c){
    char king_case;
    int flag ;
    if(c == 'b'){
        king_case = 'K';
        flag = 1;
    }
    else{
        king_case = 'k';
        flag = 2;
    }
    for(int it = 1; ((i-it>=0) && (j+it<=COL-1)); it++){
        if(board[i-it][j+it] == king_case) {check_flag = flag; return;}
        if(board[i-it][j+it] != '.')
            break;
    }
    for(int it = 1; ((i-it>=0) && (j-it>=0)); it++){
        if(board[i-it][j-it] == king_case) {check_flag = flag; return;}
        if(board[i-it][j-it] != '.')
            break;
    }
    for(int it = 1; ((i+it<=ROW-1) && (j+it<=COL-1)); it++){
        if(board[i+it][j+it] == king_case) {check_flag = flag; return;}
        if(board[i+it][j+it] != '.')
            break;
    }
    for(int it = 1; ((i+it<=ROW-1) && (j-it>=0)); it++){
        if(board[i+it][j-it] == king_case) {check_flag = flag; return;}
        if(board[i+it][j-it] != '.')
            break;
    }
    return;
}

void rook(int i, int j, char c){
    char king_case;
    int flag ;
    if(c == 'r'){
        king_case = 'K';
        flag = 1;
    }
    else{
        king_case = 'k';
        flag = 2;
    }
    for(int it = j+1; it<=COL-1; it++){
        if(board[i][it] == king_case) {check_flag = flag; return;}
        else if(board[i][it] != '.')
            break;
    }
    for(int it = j-1; it>=0; it--){
        if(board[i][it] == king_case) {check_flag = flag; return;}
        else if(board[i][it] != '.')
            break;
    }
    for(int it = i+1; it<=ROW-1; it++){
        if(board[it][j] == king_case) {check_flag = flag; return;}
        else if(board[it][j] != '.')
            break;
    }
    for(int it = i-1; it>=0; it--){
        if(board[it][j] == king_case) {check_flag = flag; return;}
        else if(board[it][j] != '.')
            break;
    }
}

void queen(int i, int j, char c){
    char king_case, temp_b, temp_r;
    int flag ;
    if(c == 'q'){
        king_case = 'K';
        temp_b = 'b', temp_r = 'r';
        flag = 1;
    }
    else{
        king_case = 'k';
        temp_b = 'B', temp_r = 'R';
        flag = 2;
    }
    bishop(i, j, temp_b);
    if(check_flag == 1 || check_flag == 2)
        return;
    rook(i, j, temp_r);
}

void king(int i, int j, char c){
    char king_case;
    int flag ;
    if(c == 'k'){
        king_case = 'K';
        flag = 1;
    }
    else{
        king_case = 'k';
        flag = 2;
    }
    if(j == 0 && i<=ROW-2 && (((board[i+1][j+1] == king_case) || board[i+1][j] == king_case || board[i][j+1] == king_case) || (i>0 && (board[i-1][j+1] == king_case || board[i-1][j] == king_case)) )){ check_flag = flag; return;}
    
    else if(j == COL-1 && i<=ROW-2 && (((board[i+1][j-1] == king_case) || board[i+1][j] == king_case || board[i][j-1] == king_case) || (i>0 && (board[i-1][j-1] == king_case|| board[i-1][j] == king_case)) )){ check_flag = flag; return;}
    
    else if(j == 0 && ((i == 0 && (board[i][j+1] == king_case|| board[i+1][j] == king_case || board[i+1][j+1] == king_case)) || (i==ROW-1 && (board[i][j+1] == king_case || board[i-1][j] == king_case || board[i-1][j+1] == king_case)))){ check_flag = flag; return;}
    
    else if(j == COL-1 && ((i == 0 && (board[i][j-1] == king_case || board[i+1][j] == king_case || board[i+1][j-1] == king_case)) || (i==ROW-1 && (board[i][j-1] == king_case || board[i-1][j] == king_case || board[i-1][j-1] == king_case)))){ check_flag = flag; return;}
    //for general case
    if(i>0 && j<COL-1 && i<ROW-1 && j>0){
        if(board[i-1][j] == king_case || board[i-1][j-1] == king_case || board[i-1][j+1] == king_case || board[i][j-1] == king_case || board[i][j+1]==king_case || board[i+1][j]==king_case || board[i+1][j-1] == king_case || board[i+1][j+1] ==king_case){ check_flag = flag; return;}
    }
    
}
int main() {
    ULL game = 1;
    while(1){
        check_flag = 0;
        int empty = 0;
        //reading board
        for(int i = 0; i<ROW; i++){
            for(int j =0 ; j<COL; j++){
                cin>>board[i][j];
                if(board[i][j] == '.')
                    ++empty;
            }
        }
        //board has only empty spaces
        if(empty == MAX_SIZE)
            return 0;
        
        for(int i = 0; i<ROW; i++){
            for(int j =0 ; j<COL; j++){
                char c = board[i][j];
                if(c != '.')
                    switch(c){
                        case 'p' :
                            pawn(i, j, c);break;
                        case 'P':
                            pawn(i, j, c);break;
                        case 'n' :
                            knight(i, j, c);break;
                        case 'N' :
                            knight(i, j, c); break;
                        case 'b' :
                            bishop(i, j, c);break;
                        case 'B' :
                            bishop(i, j, c);break;
                        case 'r' :
                            rook(i, j, c);break;
                        case 'R' :
                            rook(i, j, c);break;
                        case 'q' :
                            queen(i, j, c);break;
                        case 'Q' :
                            queen(i, j, c);break;
                        case 'k' :
                            king(i, j, c);break;
                        case 'K' :
                            king(i, j, c);break;
                    }
                if(check_flag == 1 || check_flag == 2)
                    break;
            }
            if(check_flag == 1 || check_flag == 2)
                break;
        }
        if(check_flag == 1)
            printf("Game #%llu: white king is in check.\n", game);
        else if(check_flag == 2)
            printf("Game #%llu: black king is in check.\n", game);
        else
            printf("Game #%llu: no king is in check.\n", game);
        ++game;
    }
    return 0;
}


