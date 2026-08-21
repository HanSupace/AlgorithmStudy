#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n,k, a[104], visited[104],cnt=0;
vector<int> v;
int main(){
    cin >> n >> k;
    for(int i=0 ; i<k ; i++){
        cin >> a[i];
    }
    for(int i=0 ; i<k ; i++){
        if(!visited[a[i]]){
            if(v.size()==n){
                int l_idx = 0, pos;
                for(int _a : v){
                    int pick = INF;
                    for(int j=i+1 ; j<k ; j++){
                        if(_a == a[j]){
                            pick = j;
                            break;
                        }
                    }
                    if(l_idx < pick){
                        l_idx = pick;
                        pos = _a;
                    }
                }
                visited[pos] = 0;
                cnt++;
                v.erase(find(v.begin(),v.end(),pos));
            }
            v.push_back(a[i]); visited[a[i]]=1;
        }
    }
    cout << cnt << "\n";

}