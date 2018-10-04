/*
 Graphical Editor
 Had to optimize for faster I/O process so used scanf/printf.
 */

#include "stdc++.h"
#define M 251
#define N 251
typedef unsigned long long ULL;
using namespace std;


char image[M][N];
int m, n;//dimensions of the image :: m - column , n - row
char curr_color;
void fill_color(int x, int y, char color){
    if(x > m || y > n || x<1 || y<1 )
        return;
    else if(image[y][x] != curr_color || curr_color == color)
        return;
    image[y][x] = color;
    fill_color(x, y-1, color);
    fill_color(x+1, y, color);
    fill_color(x, y+1, color);
    fill_color(x-1, y, color);
}

int main() {
    char command;
    memset(image, 'O', sizeof(image[0][0])*M*N);
    while(1){
        scanf("%c", &command);
        if(command == 'X')
            break;
        int x, y, x1, y1, x2, y2, temp;
        char color;
        switch(command){
            case 'I':
                scanf("%d %d", &m , &n);
                memset(image, 'O', sizeof(image[0][0])*M*N);
                break;
            case 'C':
                memset(image, 'O', sizeof(image[0][0])*M*N);
                break;
            case 'L':
                scanf("%d %d %c", &x , &y, &color);
                image[y][x] = color;
                break;
            case 'V':
                scanf("%d %d %d %c", &x , &y1, &y2, &color);
                temp = y1;
                if (y1  > y2) swap(y1, y2);
                for(int i = y1; i<=y2; i++)
                    image[i][x] = color;
                break;
            case 'H':
                scanf("%d %d %d %c", &x1 , &x2, &y, &color);
                temp = x1;
                if (x1  > x2){ x1 = x2, x2 = temp; }
                for(int i=x1; i<=x2; i++)
                    image[y][i] = color;
                break;
            case 'K':
                scanf("%d %d %d %d %c", &x1, &y1, &x2, &y2, &color);
                temp = x1;
                if (x1  > x2){ x1 = x2, x2 = temp; }
                temp = y1;
                if (y1  > y2){ y1 = y2, y2 = temp; }
                for(int i=y1; i<=y2; i++)
                    for(int j=x1; j<=x2; j++)
                        image[i][j] = color;
                break;
            case 'F':
                scanf("%d %d %c", &x , &y, &color);
                curr_color = image[y][x];
                fill_color(x, y, color);
                break;
            case 'S':
                char name[1000];
                scanf("%s", name);
                printf("%s\n", name);
                for(int i = 1; i<=n; i++){
                    for(int j=1; j<=m; j++)
                        printf("%c", image[i][j]);
                    printf("\n");
                }
        }
    }
    return 0;
}


