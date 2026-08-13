#include <bits/stdc++.h>
using namespace std;

int n, ret=-987654321;
string s;
stack<int> stk;

int main(){
    cin >> n;
    cin >> s;
    stk.push(-1);
    for(int i=0 ; i<n ; i++){
        if(s[i]=='('){
            stk.push(i);
        }
        else if(s[i]==')'){
            stk.pop();
            if(!stk.empty()){
                ret = max(ret, i-stk.top());
            }
            else{
                stk.push(i);
            }
        }
    }
    if(ret == -987654321) cout << 0;
    else cout << ret;
}