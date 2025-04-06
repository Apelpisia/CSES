#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv){
    cin.tie(NULL)->sync_with_stdio(false);
    int n, temp, id; vector<int> lis;
    cin >> n >> temp; lis.push_back(temp);
    for(int i=1; i<n; i++){
        cin >> temp;
        if(temp<=lis.back()){
            id=lower_bound(lis.begin(), lis.end(), temp)-lis.begin();
            lis[id] = temp;
        } else lis.push_back(temp);
    } cout << lis.size();

    return 0;
}
