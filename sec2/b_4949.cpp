#include <bits/stdc++.h>
using namespace std;

string s;

int main(){

    while(true){
        getline(cin,s);
        if(s[0]=='.') break;
        stack<char> stk;

        for(char c : s){
            if(stk.empty() && (c==']'||c==')')){
                stk.push(c);
                break;
            }
            if(c=='(' || c=='['){
                stk.push(c);
            }

            if(c==']'){
                if(stk.top()=='['){
                    stk.pop();
                }
                else{
                    stk.push(c);
                }
                
            }
            else if(c==')'){
                    if(stk.top()=='('){
                        stk.pop();
                    }
                    else{
                        stk.push(c);
                    }
                
            }
        }
        if(stk.empty()){
            cout << "yes" <<"\n";
        }
        else{
            cout <<"no" << "\n";
        }
    }
}