#include <bits/stdc++.h>
using namespace std;

int n,lo,hi,sum,tmp,res=0;
int adj[4000001];
int a[4000001];


int main(){
    cin >> n;
    for(int i=2 ; i<=n ; i++){
        if(adj[i]) continue;
        for(int j=2*i ; j<=n ; j+=i) adj[j] = 1;
    }

    for(int i=2 ; i<=n ; i++){
        if(!adj[i]) a[tmp++] = i;
    }
    while(true){
        if(sum >= n) sum -= a[lo++];
        else if (tmp==hi) break; 
        else if (sum < n) sum += a[hi++];
        
        if(sum==n) res++;
        
    }

    cout << res;
}