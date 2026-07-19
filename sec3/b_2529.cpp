#include <bits/stdc++.h>
using namespace std;

int check[10];
int k;
vector<char> op;
vector<string> ret;

bool opCheck(char a, char b, char c){
    if(a=='<' && b<c) return true;
    else if(a=='>' && b>c) return true;
    return false;
}

void sol(int idx, string s){
    if(idx == k+1){
        ret.push_back(s);
        return;
    }

    for(int i=0 ; i<=9 ; i++){
        if(check[i]) continue;
        if(idx == 0 || opCheck(op[idx-1], s[idx-1], i+'0')){
            check[i] = 1;
            sol(idx+1, s+to_string(i));
            check[i]=0;
        }
    }


}

int main(){
    cin >> k;
    char c;
    for(int i=0 ; i<k ; i++){
        cin >> c;
        op.push_back(c);
    }
    sol(0,"");
    sort(ret.begin(), ret.end());
    cout <<  ret[ret.size()-1] << "\n" << ret[0];
    


}