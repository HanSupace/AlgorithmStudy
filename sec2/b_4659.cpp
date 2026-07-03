#include <bits/stdc++.h>
using namespace std;

int vcnt, lcnt;
bool include_v;

bool isVowel(char c){
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'); 
}

int main(){
    string s;
    

    while(cin >> s){
        if(s=="end") break;
        vcnt = 0;
        lcnt = 0;
        int flag = 0;
        include_v=0;
        for(int i=0 ; i<s.size() ; i++){
            char c = s[i];

            if(isVowel(c)){
                include_v=1;
                vcnt++;
                lcnt = 0;
            }
            else{
                vcnt=0;
                lcnt++;
            }

            if(vcnt == 3 || lcnt == 3){
                flag = 1;
                break;
            }

            if(i>0 && (c==s[i-1]) && (c!='e' && c!='o')){
                flag = 1;
                break;
            }
        }
        if(include_v==0) flag=1;
        if(!flag){
            cout << "<"<< s << ">" <<" is acceptable.\n";
        }
        else{
            cout << "<" <<  s << ">" << " is not acceptable.\n";
        }
    }

}