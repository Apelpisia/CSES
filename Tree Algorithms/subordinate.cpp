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

int dp[nx], n;
vector<int> adj[nx];

void dfs(int now){
    for(auto id : adj[now]){
        dfs(id);
        dp[now]+=dp[id]+1;
    }
}

int main(int argc, char **argv){
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;
    for(int i=2; i<=n; i++){
        int t; cin >> t;
        adj[t].pb(i);
    }
    dfs(1);
    for(int i=1; i<=n; i++) cout << dp[i] << ' ';

    return 0;
}
