// 2x+3y+z=9      2 3 1 9 1 2 3 6 3 1 2 8
// x+2y+3z=6
// 3x+y+2z=8
#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a[3][3],l[3][3],u[3][3],c[3],y[3],aa,bb,cc;
    for(int i=0,j=0;i<3;i++,j++){
        l[i][j] = 1;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(j>i){
                l[i][j] = 0;
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(j<i){
                u[i][j] = 0;
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> a[i][j];
        }
        cin >> c[i];
    }

    u[0][0] = a[0][0];
    u[0][1] = a[0][1];
    u[0][2] = a[0][2];
    l[1][0] = a[1][0]/a[0][0];
    u[1][1] = a[1][1] - l[1][0]*u[0][1];
    u[1][2] = a[1][2] - l[1][0]*u[0][2];
    l[2][0] = a[2][0]/a[0][0];
    l[2][1] = (a[2][1]-l[2][0]*u[0][1])/u[1][1];
    u[2][2] = a[2][2]-l[2][0]*u[0][2]-l[2][1]*u[1][2];
    
    y[0] = c[0];
    y[1] = c[1] - l[1][0]*y[0];
    y[2] = c[2] - l[2][0]*y[0] - l[2][1]*y[1];

    cc = y[2]/u[2][2];
    bb = (y[1]-u[1][2]*cc)/u[1][1];
    aa = (y[0]-u[0][1]*bb-u[0][2]*cc)/u[0][0];

    cout << "x = " << aa << endl;
    cout << "y = " << bb << endl;
    cout << "z = " << cc << endl;


}