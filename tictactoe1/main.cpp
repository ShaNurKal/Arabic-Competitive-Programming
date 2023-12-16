#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
bool check( string s){
    if(s[0]!='.'&&s[0]==s[1]&&s[1]==s[2]) return true;
    if(s[3]!='.'&&s[3]==s[4]&&s[4]==s[5]) return true;
    if(s[6]!='.'&&s[6]==s[7]&&s[7]==s[8]) return true;

    if(s[0]!='.'&&s[0]==s[3]&&s[3]==s[6]) return true;
    if(s[1]!='.'&&s[1]==s[4]&&s[4]==s[7]) return true;
    if(s[2]!='.'&&s[2]==s[5]&&s[5]==s[8]) return true;

    if(s[0]!='.'&&s[0]==s[4]&&s[4]==s[8]) return true;
    if(s[2]!='.'&&s[2]==s[4]&&s[4]==s[6]) return true;
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        string x;
        for ( int i=0 ; i<3 ; i++ ){
            string y;
            cin>>y;
            x+=y;
        }
        string tmp=".........";
        queue<pair<string,bool>> q;
        string res="no";
        q.push({tmp,1}  );
        while(!q.empty()){
            string s=q.front().first;
            bool isX=q.front().second;
            q.pop();
            if(s==x) {res="yes"; break;}
            if(check(s)) continue;
            for ( int i=0; i<9 ; i++){
                if(s[i]=='.'){
                    if(isX) s[i]='X';
                    else s[i]='O';
                    if(s[i]==x[i]) q.push({s,1^isX});
                    s[i]='.';
                }

            }
        }
        cout<<res<<endl;
    }
    return 0;
}
