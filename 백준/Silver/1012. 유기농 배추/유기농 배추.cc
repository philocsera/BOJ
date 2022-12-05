#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    int m, n, k, rslt;
    int x, y;
    int field[50][50] = {0};

    cin >> T;

    function<void(int, int)> find = [&](int x, int y){
        field[x][y] = 0;
        if(x && field[x-1][y]) find(x-1,y);
        if(y && field[x][y-1]) find(x,y-1);
        if(x+1!=m && field[x+1][y]) find(x+1,y);
        if(y+1!=n && field[x][y+1]) find(x,y+1);
    };

    while(T--){
        cin >> m >> n >> k;
        rslt = 0;
        while(k--){
            cin >> x >> y;
            field[x][y] = 1;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(field[i][j]){
                    rslt++;
                    find(i,j);
                }
            }
        }
        cout << rslt << "\n";
    }
}