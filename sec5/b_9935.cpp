#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    string t;

    cin >> s >> t;
    stack<char> stk;

    for(int i=0 ; i<s.size(); i++){
        stk.push(s[i]);
        if(stk.top()==t[t.size()-1] && stk.size()>=t.size()){
            string ss = "";
            for(int j=0 ; j< t.size() ; j++){
                ss+=stk.top(); stk.pop();
            }
            reverse(ss.begin(), ss.end());
            if(ss == t) continue;
            for(int j=0 ; j<ss.size() ; j++){
                stk.push(ss[j]);
            }
        }
    }
    string res = "";
    if(stk.empty()) {
        cout << "FRULA\n";
    }
    else{
        while(!stk.empty()){
        res+=stk.top(); stk.pop();
    }

    reverse(res.begin() ,res.end());
    cout << res;
    }   
    

}