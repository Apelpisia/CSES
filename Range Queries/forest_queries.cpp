#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;

const int INF = 1e9;
int i, j, k;

const int nx = 1005;
int qs[nx][nx], n, q;

int main(int argc, char **argv){
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> q;
    for(i=1; i<=n; i++){
        string ip; cin >> ip;
        for(j=1; j<=n; j++){
            qs[i][j] = qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+(ip[j-1]=='*' ? 1 : 0);
        }
    }
    while(q--){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << qs[y2][x2]-qs[y2][x1-1]-qs[y1-1][x2]+qs[y1-1][x1-1] << "\n";
    }

    return 0;
}
