#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    int cnt=0;
    string s;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> s;
        stack<char> stk;

        for(char a : s){

            if(!stk.empty() && stk.top() == a){
                stk.pop();
            }
            else{
                stk.push(a);
            }
        }
        if(stk.empty()){
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}
