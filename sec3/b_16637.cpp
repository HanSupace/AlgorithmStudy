#include <bits/stdc++.h>
using namespace std;

vector<int> num;
vector<char> oper_;
string s;
int ret = -987654321;

int oper(char a, int b, int c){
    if(a=='+') return b+c;
    if(a=='-') return b-c;
    if(a=='*') return b*c;
}

void sol(int here, int _num){
    if(here==num.size()-1){
        ret = max(ret,_num);
        return;
    }
    sol(here+1,oper(oper_[here],_num,num[here+1]));
    if(here + 2 <= num.size() - 1){
        int temp = oper(oper_[here + 1], num[here + 1], num[here + 2]); 
        sol(here + 2, oper(oper_[here], _num, temp));  
    } 
}

int main(){
    int n;
    cin >> n;
    cin >> s;
    for(int i=0 ; i<n ; i++){
        if(i%2==0) num.push_back(s[i]-'0');
        else oper_.push_back(s[i]);
    }

    sol(0,num[0]);
    cout << ret;
}