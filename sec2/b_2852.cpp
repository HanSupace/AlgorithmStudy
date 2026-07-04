#include <bits/stdc++.h>
using namespace std;
#define prev lala

int n, A, B,t, asum, bsum;
string s, prev;

string print(int a){
    string h = "00"+to_string(a/60);
    string m = "00"+to_string(a%60);
    return (h.substr(h.size()-2,2) + ":" +m.substr(m.size()-2,2));
}

int changeToInt(string s){
    return atoi(s.substr(0,2).c_str())*60 + atoi(s.substr(3,2).c_str());
}

void sol(int &sum, string s){
    sum += changeToInt(s)-changeToInt(prev);
}

int main(){

    cin >> n;

    for(int i=0 ; i<n ; i++){
        cin >> t >> s;
        if(A>B) sol(asum,s);
        else if(B>A) sol(bsum, s);
        t==1 ? A++ : B++;
        prev = s;

    }
    if(A>B) sol(asum,"48:00");
    else if(B>A) sol(bsum , "48:00");
    cout << print(asum);
    cout << "\n";
    cout << print(bsum);


}