#include <bits/stdc++.h>
using namespace std;

int main(){
    int S = 18;
    int idx = 1;

    //idx번째 비트 지우기
    S &= ~(1<<idx);

    //idx번째 비트 바꾸기
    S ^= (1<<idx);
    
    //최하위 비트 알기
    idx = (-S & S);

    //비트 다 켜기
    int n=4;
    (1<<n)-1;
    
    //idx번째 비트 켜기
    S |= (1<<idx);

    //idx번째 비트 켜져있는지 확인
    if(S & (1<<idx));



}