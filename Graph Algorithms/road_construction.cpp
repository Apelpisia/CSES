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

const int nx = 1e5+5;

int sz[nx], par[nx], ranks[nx], mxsz = 1, samt, n, m;

void initSet(int amt){
    samt = amt;
    for(i = 1; i<=amt; i++){
        sz[i] = 1;
        par[i] = i;
        ranks[i] = 0;
    }
}

int findSet(int sn){
    if(sn==par[sn]) return sn;
    return par[sn] = findSet(par[sn]);
}

bool isSameSet(int s1, int s2){
    if(findSet(s1)==findSet(s2)) return true;
    return false;
}

void unionSet(int s1, int s2){
    int p1 = findSet(s1), p2 = findSet(s2);
    if(p1!=p2){
        samt--;
        if(ranks[p1]>ranks[p2]){
            par[p2] = p1;
            sz[p1]+=sz[p2];
            mxsz = max(mxsz, sz[p1]);
        } else{
            par[p1] = p2;
            if(ranks[p1]==ranks[p2]) ranks[p2]++;
            sz[p2]+=sz[p1];
            mxsz = max(mxsz, sz[p2]);
        }
    }
}

int main(int argc, char **argv){
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> m;
    initSet(n);
    while(m--){
        int t1, t2;
        cin >> t1 >> t2;
        unionSet(t1, t2);
        cout << samt << ' ' << mxsz << "\n";
    }

    return 0;
}
