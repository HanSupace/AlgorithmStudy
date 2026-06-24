#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int t;
    string a,b;
    
    cin >> n;
    for(int i=0 ; i<n ; i++){
        map<string, int> mp;

        cin >> t;
        for(int j=0; j<t ; j++){
            cin >> a >> b;
            mp[b]++;
        }
        long long ret=1;
        for(auto x : mp){
            ret *= ((long long)x.second+1);
        }
        ret--;
        cout << ret<<"\n";
    }

    return 0;
}
