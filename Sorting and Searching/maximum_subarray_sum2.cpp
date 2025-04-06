#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;

const ll INF = 1e18;
ll i, j, k;

const ll nx = 2e5+5;
ll n, a, b, qs[nx], ans = -INF;
deque<pll> dq;

int main(int argc, char **argv){
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> a >> b;
    for(i=1; i<=n; i++){
        ll ip;
        cin >> ip;
        qs[i] = ip+qs[i-1];
    }
    dq.pb({0, 0});
    for(i=a; i<=n; i++){
        while(!dq.empty() && i-dq.front().s>b) dq.pop_front();
        ll nans = qs[i]-dq.front().f;
        ans = max(ans, nans);
        while(!dq.empty() && dq.back().f>=qs[i-a+1]) dq.pop_back();
        dq.pb({qs[i-a+1], i-a+1});
    }
    cout << ans;

    return 0;
}
