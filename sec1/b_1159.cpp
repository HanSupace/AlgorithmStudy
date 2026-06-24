#include <bits/stdc++.h>

using namespace std;

int a[26];

int main(){
    int n;
    cin >> n;
    string s;
    for(int i=0 ; i<n ; i++){
        cin >> s;
        a[s[0]-'a']++;
    }
    string res;
    for(int i=0 ; i<26 ; i++){
        if(a[i]>=5){
            res+= 'a'+i;
        }
    }
    if(res.size()){
        cout << res;

    }else{
        cout << "PREDAJA";
    }
}