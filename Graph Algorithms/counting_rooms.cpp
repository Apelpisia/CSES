#include <bits/stdc++.h>

#define INF 1e9
#define pb push_back
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int nx = 1005;
char room[nx][nx];

void flood_fill(int x, int y, int n, int m){
    if(x>=m || y>=n || x<0 || y<0 || room[y][x]=='#') return;
    room[y][x] = '#';
    flood_fill(x-1, y, n, m);
    flood_fill(x+1, y, n, m);
    flood_fill(x, y-1, n, m);
    flood_fill(x, y+1, n, m);
}

int main(int argc, char **argv){
    cin.tie(NULL)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> room[i][j];
        }
    }

    int cnt = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(room[i][j]=='.'){
                flood_fill(j, i, n, m);
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}
