#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;

const int INF = 1e9;
const int nx = 1005;
const int modder = 1e9+7;
int n, dp[nx][nx];
bool visited[nx][nx];
string grid[nx];

int solve(int y, int x){
    if(visited[y][x]) return dp[y][x];
    visited[y][x] = true;
    if(y>0 && grid[y-1][x]!='*') dp[y][x]+=solve(y-1, x);
    if(x>0 && grid[y][x-1]!='*') dp[y][x]+=solve(y, x-1);
    dp[y][x]%=modder;
    return dp[y][x];
}

int main(int argc, char **argv){
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++) cin >> grid[i];
    dp[0][0] = 1;
    if(grid[n-1][n-1]=='*' || grid[0][0]=='*'){cout << 0; return 0;}
    cout << solve(n-1, n-1);

    return 0;
}
