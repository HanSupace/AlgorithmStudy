#include <bits/stdc++.h>
using namespace std;
int l[26];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    string s;

    cin >> s;

    for(char a : s){
        l[a-'a'] += 1;
    }

    for(int i=0 ; i<26 ; i++){
        cout << l[i]<<" ";
    }
}