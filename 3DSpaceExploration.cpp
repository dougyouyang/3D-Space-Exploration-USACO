//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <queue>

using namespace std;
queue<int> r, c, d;
char mat[110][110][110];

void floodfill(int row, int col, int de)
{
    r.push(row), c.push(col), d.push(de);
    while(!r.empty()){
        int a=r.front(), b=c.front(), cc=d.front();
        r.pop(), c.pop(), d.pop();
        if(mat[a+1][b][cc]=='*'){
            mat[a+1][b][cc]='#';
            r.push(a+1), c.push(b), d.push(cc);
        }
        if(mat[a-1][b][cc]=='*'){
            mat[a-1][b][cc]='#';
            r.push(a-1), c.push(b), d.push(cc);
        }
        if(mat[a][b+1][cc]=='*'){
            mat[a][b+1][cc]='#';
            r.push(a), c.push(b+1), d.push(cc);
        }
        if(mat[a][b-1][cc]=='*'){
            mat[a][b-1][cc]='#';
            r.push(a), c.push(b-1), d.push(cc);
        }
        if(mat[a][b][cc+1]=='*'){
            mat[a][b][cc+1]='#';
            r.push(a), c.push(b), d.push(cc+1);
        }
        if(mat[a][b][cc-1]=='*'){
            mat[a][b][cc-1]='#';
            r.push(a), c.push(b), d.push(cc-1);
        }
    }
}

int main()
{
    int n, sum=0;
    int i, j, k;
    
    cin >> n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(k=1;k<=n;k++){
                cin >> mat[j][k][i];
            }
        }
    }
    
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(k=1;k<=n;k++){
                if(mat[j][k][i]=='*'){
                    sum++;
                    floodfill(j, k, i);
                    
                }
            }
        }
    }
    
    cout << sum << endl;
    
    return 0;
}
