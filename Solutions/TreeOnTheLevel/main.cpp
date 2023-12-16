#include <iostream>
#include <bits/stdc++.h>
#define all(v)  v.begin(),v.end()
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))
using namespace std;
typedef long long ll;
typedef pair<string, string> pi;

vector<string> res;
map<string,string> s;
bool bfs ( string x ){
    queue <string> q;
    q.push(x);
    bool t=0;
    while(!q.empty()){
        string tmp=q.front();
        q.pop();
        res.push_back(tmp);
        string f=tmp+'L',s=tmp+'R';
        bool ff=0,ss=0;
        for (auto i : s){
            if(i.first==tmp){
                t=1;
            }
            else if(i.first==f){
                ff=1;
            }
            else if(i.first==s){
                ss=1;
            }
        }
        if(ff) q.push(s[i]);
        if(ss) q.push(s[i]);
    }
    return t;
}
int main()
{
    string x;
    while(cin>>x&&x!="()"){
        int pos=x.find(',');
        string first=x.substr(1,pos-1);
        string second=x.substr(pos+1,sz(x)-pos-2);
        s[second]=first;
    }
    bool t=0;
    string ans="";
    for ( auto i : s ){
            if(i.first==ans){
                t=bfs(i.first,z);
            }
    }
    rep(i,res){
        cout<<res[i]<<' ';
    }
    cout<<endl;

    return 0;
}
