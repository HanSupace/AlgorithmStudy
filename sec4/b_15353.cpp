#include <bits/stdc++.h>
using namespace std;
string add_string(string a, string b){
    int sum=0;
    string ret;
    while(a.size() || b.size() || sum){
        if(a.size()){
            sum+=a.back() - '0';
            a.pop_back();
        }
        if(b.size()){
            sum+=b.back() - '0';
            b.pop_back();
        }
        ret += (sum%10) + '0';
        sum/=10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(){
    string a,b;
    cin >> a >> b;
    cout << add_string(a,b);
}