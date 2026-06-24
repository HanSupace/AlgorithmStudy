#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    string res;

    getline(cin, s); 


    for(char a : s){
        if(a>=65 && a<=90){
            if((a+13)>90){
                res += (a-13);
            }
            else{
                res+=(a+13);
            }
        }
        else if(a>=97 && a<=122){
            if((a+13)>122){
                res += (a-13);
            }
            else{
                res+=(a+13);
            }
        }
        else{
            res += a;
        }
    }
    cout << res;
}