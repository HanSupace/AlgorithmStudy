#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> v;
int a,b;

int main(){
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }   
    sort(v.begin(), v.end());
    int realTime = v[0].second + v[0].first;
    for(int i=1 ; i<v.size() ; i++){
        realTime = max(realTime, v[i].first);
        realTime += v[i].second;
    }
    cout << realTime;

}