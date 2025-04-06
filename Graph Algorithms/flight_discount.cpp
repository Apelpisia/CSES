#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;

const ll INF = 1e18;

const int nx=100005;
vector<ii> adj[nx];
bool visited[nx][2];
ll sdist[nx][2];
priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;

int main(int argc, char **argv){
    cin.tie(NULL)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++){
        int ipst, ipdest, ipdist;
        cin >> ipst >> ipdest >> ipdist;
        adj[ipst].pb({ipdest, ipdist});
    }
    for(int i=2; i<=n; i++){
        sdist[i][0] = INF;
        sdist[i][1] = INF;
    } pq.push({0, {1, 1}});
    while(!pq.empty()){
        auto [dist, p] = pq.top();
        pq.pop();
        if(visited[p.f][p.s]) continue;
        visited[p.f][p.s] = true;
        for(auto [tid, tdist] : adj[p.f]){
            if(p.s==1){
                if(sdist[tid][0]>dist+(tdist/2)){
                    sdist[tid][0] = dist+(tdist/2);
                    pq.push({sdist[tid][0], {tid, 0}});
                }
                if(sdist[tid][1]>dist+tdist){
                    sdist[tid][1] = dist+tdist;
                    pq.push({sdist[tid][1], {tid, 1}});
                }
            } else{
                if(sdist[tid][0]>dist+tdist){
                    sdist[tid][0] = dist+tdist;
                    pq.push({sdist[tid][0], {tid, 0}});
                }
            }
        }
    }
    cout << min(sdist[n][0], sdist[n][1]);

    return 0;
}
