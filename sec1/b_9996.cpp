#include <bits/stdc++.h>
using namespace std;

string f;
string e;
string s;

int main(){
    int n;
    cin >> n;

    cin >> s;

    int pos = s.find("*");

    f = s.substr(0,pos);
    e = s.substr(pos+1);

    for(int i=0 ; i<n ;i++){
        string v;
        cin >> v;
        if(v.size()<(f.size()+e.size())){
            cout << "NE\n";
        }
        else if(v.substr(0,f.size())==f && v.substr(v.size()-e.size())==e){
            cout << "DA\n";
        }
        else cout <<"NE\n";

    }
}