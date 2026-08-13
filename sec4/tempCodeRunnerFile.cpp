#include <bits/stdc++.h>
using namespace std;

int t,n,x;
string p,s;
deque<int> d;

int main(){
    cin >> t;
    while(t--){
        cin >> p >> n >> s;
        x=0;
        for(char c : s){
            if(c=='[' || c==']') continue;
            else if(c>='0' && c<='9'){
                x = x*10+c-'0'; 
            }
            else{
                d.push_back(x);
                x=0;
            }
        }
        if(x > 0) d.push_back(x);

        bool rev = false;
        bool error = false;

        for(char c : p){
            if(c=='R') rev = !rev;
            if(c=='D'){
                if(d.empty()){
                    error=true;
                    break;
                }
                else{
                    if(rev){
                        d.pop_back();
                    }
                    else{
                        d.pop_front();
                    }
                }
            }
        }
        if(error) cout << "error\n";
        else{
            cout << '[';
            if(rev) reverse(d.begin(), d.end());

            for(int i=0 ; i<d.size() ; i++){
                cout << d[i];
                if(i!=d.size()-1) cout <<", ";
            }
            cout << ']\n';

        }
        

        d.clear();

    }
}