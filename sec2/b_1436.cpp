#include <bits/stdc++.h>
using namespace std;

int main(){
    int i=666;
    int n;
    cin >> n;
    for(;;i++){
        if(to_string(i).find("666")!=string::npos) n--;
        if(n==0) {
            cout << i;
            break;
        }   
    }
}