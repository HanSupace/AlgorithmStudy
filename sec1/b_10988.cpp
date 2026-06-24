#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int flag = 1;
    cin >> s;
    for(int i=0 ; i<s.size() ; i++){
        if(s.substr(i,1)!=s.substr(s.size()-i-1,1)){
            flag = 0;
            break;
        }    
    }
    cout << flag;
}