#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;

const int INF = 1e9;
const int nx = 1e6+5;
int coins[105], dp[nx], n, x;

int solve(int c){
    if(c<0) return INF;
    if(dp[c]!=-1) return dp[c];
    if(c==0) return 0;
    int ans = INF;
    for(int i=0; i<n; i++){
        ans = min(ans, solve(c-coins[i])+1);
    } dp[c] = ans;
    return ans;
}

int main(int argc, char **argv){
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> x;
    for(int i=0; i<n; i++) cin >> coins[i];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    int ans = solve(x);
    cout << ((ans>=INF)? -1 : ans);

    return 0;
}
