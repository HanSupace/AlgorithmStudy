#include <bits/stdc++.h>
using namespace std;

int ret[1000001];
int a[1000001];
stack<int> stk;

int main(){
    int n;

    cin >> n;

    memset(ret,-1,sizeof(ret));

    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        while(stk.size() && a[stk.top()] < a[i]){
            ret[stk.top()] = a[i]; stk.pop();
        }
        stk.push(i);

    }

    for(int i=0 ; i<n ; i++){
        cout << ret[i] << " ";
    }
}