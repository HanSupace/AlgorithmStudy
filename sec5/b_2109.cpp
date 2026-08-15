#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,p,d,prv,res=0;
    vector<pair<int,int>> v;
    priority_queue<int, vector<int>, greater<int>> q;

    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> p >> d;
        v.push_back({d,p});
    }

    sort(v.begin(), v.end());

    for(int i=0 ; i<n ; i++){
        q.push(v[i].second);
        if(q.size()>v[i].first){
            q.pop();
        }
    }
    while(q.size()){
        res += q.top(); q.pop();
    }
    cout << res << "\n";
}