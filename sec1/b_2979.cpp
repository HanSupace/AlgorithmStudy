#include <bits/stdc++.h>
using namespace std;

int t[101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b,c;

    cin >> a >> b >> c;

    for(int i=0 ; i<3 ; i++){
        int in, out;
        cin >> in >> out;
        for(int j=in ; j<out ; j++){
            t[j]++;
        }
    }

    int sum = 0;
    for(int i=1 ; i<101 ; i++){
        if(t[i]==0){
            continue;
        }
        else if(t[i]==1){
            sum+=a;
        }
        else if(t[i]==2){
            sum+=b*2;
        }
        else if(t[i]==3){
            sum+=c*3;
        }
    }

    cout << sum;

}