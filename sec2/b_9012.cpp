#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        stack<char> stk;

        for(char c : s){
            if(stk.empty()){
                stk.push(c);
            }
            else{
                if((stk.top()=='(') && (c==')')){
                    stk.pop();
                }
                else{
                    stk.push(c);
                }
            }
        }
        if(stk.empty()){
            cout <<"YES"<<"\n";

        }
        else{
            cout << "NO" << "\n";
        }

    }
}