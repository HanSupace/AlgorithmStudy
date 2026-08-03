#include <bits/stdc++.h>
using namespace std;
const int INF = -987654321;

int words[50], n, k, res=INF;

    int count(int mask){
        int cnt=0;
        for(int word : words){
            if(word && (word & mask) == word) cnt++;
        }
        return cnt;
    }

    int sol(int idx, int k, int mask){
        if(k<0) return 0;
        if(idx == 26) return count(mask);

        int ret = sol(idx+1, k-1, mask | (1<<idx));
        if(idx!='a'-'a' && idx!='n'-'a' && idx!='t'-'a' && idx!='i'-'a' && idx!='c'-'a'){
            ret = max(ret,sol(idx+1,k,mask));
        }
        return ret;
    }

int main(){

    cin >> n >> k;
    string s;
    for(int i=0 ; i<n ; i++){
        cin >> s;
        for(char c : s){
            words[i] |= (1<<(c-'a'));
        }
    }

    cout << sol(0,k,0);

}