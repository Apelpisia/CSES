#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define INF 1e9

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;

const int nx = 100005;
int sdist[nx];
vector<int> adj[nx];
queue<int> q;
int par[nx];

int main(int argc, char **argv){
    cin.tie(NULL)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++){
        int ipst, ipdest;
        cin >> ipst >> ipdest;
        adj[ipst].pb(ipdest);
        adj[ipdest].pb(ipst);
    }
    for(int i=2; i<=n; i++) sdist[i] = INF;
    par[1] = 1;
    q.push(1);
    while(!q.empty()){
        int id = q.front();
        q.pop();
        for(auto tid : adj[id]){
            if(sdist[tid]>sdist[id]+1){
                sdist[tid] = sdist[id]+1;
                q.push(tid);
                par[tid] = id;
            }
        }
    }
    if(sdist[n]==INF){cout << "IMPOSSIBLE"; return 0;}
    stack<int> order;
    order.push(n);
    while(order.top()!=1){
        order.push(par[order.top()]);
    }
    cout << sdist[n]+1 << "\n";
    while(!order.empty()){
        cout << order.top() << ' ';
        order.pop();
    }

    return 0;
}
