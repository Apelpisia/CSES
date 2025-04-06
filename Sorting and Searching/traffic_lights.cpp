#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;

const int INF = 1e9;
int i, j ,k;

set<int> tl;
multiset<int> dist;
int x, n;

int main(int argc, char **argv){
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> x >> n;
    tl.insert(0);
    tl.insert(x);
    dist.insert(x);
    for(i = 0; i<n; i++){
        int ip; cin >> ip;
        tl.insert(ip);
        auto it = tl.lower_bound(ip);
        int pv = *prev(it), nx = *next(it);
        dist.erase(dist.lower_bound(nx-pv));
        dist.insert(ip-pv);
        dist.insert(nx-ip);
        cout << *dist.rbegin() << ' ';
    }

    return 0;
}
