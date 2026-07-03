#include <bits/stdc++.h>
using namespace std;

string ret;
vector<string> v;

void go(){
    while(true){
        if(ret.size() && ret.front() ==  '0'){
        ret.erase(ret.begin());
        }
        else break;
        if(ret.size()==0) {
            ret+="0";
            break;
        }
    }
    v.push_back(ret);
    ret="";
}

bool cmp(string a, string b){
    if(a.size() == b.size()){
        return a<b;
    }
    return a.size() < b.size();
}

int main(){
    int n;
    cin >> n;
    for(int i=0 ; i <n ; i++){
        string s;
        cin >> s;
        ret="";
        for(int j=0 ; j<s.size() ; j++){
            char c = s[j];
            if(c < 65) ret+=c;
            else if(s.size()) go();
        }
        go();
    }

    sort(v.begin(), v.end(), cmp);

    for(string s : v){
        cout << s << "\n";
    }
}