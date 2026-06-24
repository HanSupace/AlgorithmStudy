#include <bits/stdc++.h>
using namespace std;

int a[100004];
int n,k;

int main(){
    cin >> n >>k;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    int max = -104;
    for(int i=0 ; i<=n-k ; i++){
        int sum = 0;
        for(int j=i ; j<i+k ; j++){
            sum += a[j];
        }
        if(max < sum){
            max = sum;
        }
    }
    cout << max;
}