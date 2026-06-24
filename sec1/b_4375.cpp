#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(scanf("%d",&n) != EOF){
        int a = 1;
        int ret = 1;
    
        while(true){
            if(a%n==0){
                printf("%d\n", ret); 
                break;
            }
            else{
                ret++;
                a=(a*10)+1;
                a%=n;
            }
        }
    }

    return 0;
}
