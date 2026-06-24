#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
map<int, string> mp2;

int main(){
    int n,m;
    string s;
    cin >> n >> m;

    for(int i=1 ; i<=n ; i++){
        cin >> s;
        mp[s]=i;
        mp2[i]=s;
    }

    for(int i=0 ; i<m ; i++){
        cin >> s;
        if(atoi(s.c_str())==0){
            cout << mp[s]<<"\n";
        }
        else{
            cout << mp2[atoi(s.c_str())]<<"\n";
        }
    }


}