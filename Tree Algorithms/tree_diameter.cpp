#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;

const int INF = 1e9;
const int nx = 2e5+5;

int n, dp[nx][2]; // max, second max
vector<int> adj[nx];

void dfs(int now, int prev){
    for(auto tid : adj[now]){
        if(tid==prev) continue;
        dfs(tid, now);
        if(dp[tid][0] + 1 > dp[now][0]){
            dp[now][1] = dp[now][0];
            dp[now][0] = dp[tid][0]+1;
        }
        else if(dp[tid][0]+1>dp[now][1]) dp[now][1] = dp[tid][0]+1;
    }
}

int main(int argc, char **argv){
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, -1);
    int ans = -1;
    for(int i=1; i<=n; i++) ans = max(ans, dp[i][0] + dp[i][1]);
    cout << ans;

    return 0;
}
