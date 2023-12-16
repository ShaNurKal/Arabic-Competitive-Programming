#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
bool check( string s){
    if(s[0]!='.'&&s[0]==s[1]&&s[1]==s[2]) return true;
    if(s[3]!='.'&&s[3]==s[4]&&s[4]==s[5]) return true;
    if(s[6]!='.'&&s[6]==s[7]&&s[7]==s[8]) return true;
    if(s[1]!='.'&&s[1]==s[5]&&s[5]==s[9]) return true;
    if(s[3]!='.'&&s[3]==s[5]&&s[5]==s[7]) return true;
    return false;
}
int main()
{
    string x;
    for ( int i=0 ; i<3 ; i++ ){
        string y;
        cin>>y;
        x+=y;
    }
    cout<<endl;
    string tmp=".........";
    queue<string> q;
    string res="no";
    bool isX=1;
    q.push(tmp);
    while(!q.empty()){
        string s=q.front();
        q.pop();
        if(s==x) {res="yes"; break;}
        if(check(s)) continue;
        for ( int i=0; i<9 ; i++){
            if(s[i]=='.'){
                if(isX) s[i]='X';
                else s[i]='O';
                if(s[i]==x[i]) {q.push(s); cout<<s<<endl;}
                s[i]='.';
            }

        }
        if(isX) isX=0;
        else isX=1;
    }
    cout<<res;

    return 0;
}
