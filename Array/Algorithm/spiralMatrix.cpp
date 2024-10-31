#include <iostream>
using namespace std;

#define rept(i,a,b) for(int i = a;i<b;i++)
#define br cout << '\n'

int grid[50][50];

void spiral(int r,int c){
    int rr=0,cc=0;
    int move[4][2] = {
    //  {r,c}
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    };

    int endPoint[4][2] = {
    //  {r,c}
        {0,c-1},
        {r-1,c-1},
        {r-1,0},
        {1,0}
    };

    int move_endP[4][2] = {
    //  {r,c}
        {1,-1},
        {-1,-1},
        {-1,1},
        {1,1}
    };

    int instraction = 0;
    rept(cellNo,1,r*c+1){
        grid[rr][cc] = cellNo;
        rr += move[instraction][0];
        cc += move[instraction][1];
        if(rr==endPoint[instraction][0] && cc==endPoint[instraction][1]){
            endPoint[instraction][0] += move_endP[instraction][0];
            endPoint[instraction][1] += move_endP[instraction][1];
            instraction = (instraction+1)%4;
        }
    }
}

void printMarix(int r,int c){
    rept(row,0,r){
        rept(col,0,c){
            cout << grid[row][col] << '\t';
        }br;
    }br;
}

int main(){
    int r,c; //row,col
    cin >> r >> c;
    spiral(r,c);
    printMarix(r,c);
}
