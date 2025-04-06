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

int n;
multiset<int> tower;

int main(int argc, char **argv){
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;
    for(i = 0; i < n; i++){
        int ip; cin >> ip;
        auto it = tower.upper_bound(ip);
        if(it==tower.end()) tower.insert(ip);
        else{
            tower.erase(it);
            tower.insert(ip);
        }
    }
    cout << tower.size();

    return 0;
}
