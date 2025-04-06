#include <bits/stdc++.h>

#define INF 1e9
#define pb push_back
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;

const ll nx = 2e5+5;
ll arr[nx];
ll l=0, r=0, md;

bool check(ll n, ll k){
    ll cnt=0, subarrcnt = 1;
    for(ll i=0; i<n; i++){
        cnt+=arr[i];
        if(cnt>md){
            subarrcnt++;
            cnt = arr[i];
            if(subarrcnt>k) return false;
        }
    }
    return true;
}

int main(int argc, char **argv){
    cin.tie(NULL)->sync_with_stdio(false);
    ll n, k; cin >> n >> k;
    for(ll i=0; i<n; i++){
        cin >> arr[i];
        l = max(l, arr[i]);
        r+=arr[i];
    }
    while(l<r){
        md = (l+r)/2;
        if(check(n, k)){
            r = md;
        } else{
            l = md+1;
        }
    }
    cout << l;

    return 0;
}
