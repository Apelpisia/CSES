#include <bits/stdc++.h>
#define int long long

using namespace std;

const int nx = 2e5+5;
int n, q, arr[nx], ip, a, b, u, k;

struct fenwick{
    int f[nx];
    void update(int id, int val){
        while(id<=n) f[id]+=val, id+=(id&-id);
    }
    int qs(int id){
        int ans = 0;
        while(id>0){
            ans+=f[id];
            id-=(id&-id);
        } return ans;
    }
} f;

signed main(){
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        f.update(i, arr[i]-arr[i-1]);
    }
    while(q--){
        cin >> ip;
        if(ip==1){
            cin >> a >> b >> u;
            f.update(a, u);
            f.update(b+1, -u);
        } else{
            cin >> k;
            cout << f.qs(k) << "\n";
        }
    }

    return 0;
}
