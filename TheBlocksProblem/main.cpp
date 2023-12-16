#include <iostream>
#include <bits/stdc++.h>
#define all(v)  v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v); i++)
#define clr(v, d)  memset(v, d, sizeof(v))
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
int n;
vector <deque<int>> v;
deque<int> q;
map<int,int> m;
vector <string> in(4);
void mov( int a ){
    int x=m[a],y;
    while(v[x].back()!=a){
        y=v[x].back();
        v[y].push_front(y);
        m[y]=y;
        v[x].pop_back();
    }
    v[x].pop_back();
}
void onto ( int a ){
    int x=m[a],y;
    while(v[x].back()!=a){
        y=v[x].back();
        v[y].push_front(y);
        m[y]=y;
        v[x].pop_back();
    }
}

void pile( int a){
    int x=m[a],y;
    while(v[x].back()!=a){
        y=v[x].back();
        q.push_front(y);
        v[x].pop_back();
    }
    q.push_front(a);
    v[x].pop_back();
}
int toint( string s){
    reverse(s.begin(),s.end());
    int con=0;
    rep(i,s){
        con+=(s[i]-'0')*pow(10,i);
    }
    return con;
}
void solve(){
    int f,s;
    f=toint(in[1]);
    s=toint(in[3]);
    if(m[f]==m[s]) return;
    if(in[0]=="move"){
        mov(f);
        if(in[2]=="onto"){
            onto(s);
        }
        m[f]=m[s];
        v[m[s]].push_back(f);
    }
    else{
        pile(f);
        if(in[2]=="onto"){
            onto(s);
        }
        int x=m[s];
        while(!q.empty()){
            m[q.front()]=x;
            v[x].push_back(q.front());
            q.pop_front();
        }
    }
}

int main()
{
    cin>>n;
    v=vector <deque<int>>(n);
    lp(i,n){
        v[i].push_back(i);
        m[i]=i;
    }

    bool out=0;
    while(true){
        rep(i,in){
            cin>>in[i];
            if(in[i]=="quit"){
                out=1;
                break;
            }
        }
        if(out) break;
        solve();
    }
    lp(i,n){
       cout<<i<<":";
       rep(j,v[i]){
            cout<<' '<<v[i][j];
       }
       cout<<endl;
    }
    return 0;
}
