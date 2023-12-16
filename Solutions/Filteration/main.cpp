#include <iostream>
#include <bits/stdc++.h>
#define all(v)  v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
int sum=0;
bool visited[102];
char color[102];
void dfs( int x ,int cur , vector < vector <int> > &adj){
    if (color[x]=='b') cur++;
    visited[x]=1;
    rep(i,adj[x]){
        if(!visited[adj[x][i]]){
            if(color[x]=='b') color[adj[x][i]]='w';
            else color[adj[x][i]]='b';
            dfs(adj[x][i],cur,adj);
        }
    }
    visited[x]=0;
    color[x]='w';
    sum=max(cur,sum);
}
void solve (){
    clr(visited,0);
    clr(color,'w');
    int n,k; cin>>n>>k;
    vector< vector <int> >adj(n+1);
    lp(i,n){
        int j,k; cin>>j>>k;
        adj[j].push_back(k);
        adj[k].push_back(j);
    }
    dfs(1,0,adj);
    int sol=sum;
    color[1]='b';
    sum=0;
    dfs(1,0,adj);
    sol=max(sol,sum);
    cout<<sol<<endl;
}
int main()
{

    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

