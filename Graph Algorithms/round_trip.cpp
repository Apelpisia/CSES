#include <bits/stdc++.h>

using namespace std;

const int nx = 1e5+5;
int n, m, sv, ev;
vector<int> adj[nx];
bool visited[nx];

bool visit_all(){
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            if(dfs(i, -1))
        }
    }
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int st, dest;
        cin >> st >> dest;
        adj[st].push_back(dest);
        adj[dest].push_back(st);
    }


    return 0;
}
