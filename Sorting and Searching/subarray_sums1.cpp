#include <bits/stdc++.h>

using namespace std;

const int nx = 2e5+5;
int n, x, arr[nx], ans = 0, l=0, r=0, s=0;

int main(int argc, char** argv){
    cin >> n >> x;
    for(int i=0; i<n; i++) cin >> arr[i];
    s = arr[0];
    while(l<=r){
        if(s==x){
            ans++;
            if(r>=n-1) break;
            r++;
            s+=arr[r];
            s-=arr[l];
            l++;
        } else if(s<x){
            if(r>=n-1) break;
            r++;
            s+=arr[r];
        } else if(l==r){
            if(r>=n-1) break;
            r++;
            l++;
            s = arr[r];
        } else{
            s-=arr[l];
            l++;
        }
    }

    cout << ans;

    return 0;
}
