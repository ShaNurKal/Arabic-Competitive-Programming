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
vector<vector<int>> adj;
vector<int> sol,black;
vector<bool> color;
int n,k;
bool canBeBlack( int x){
    rep(i,adj[x]){
        if(color[adj[x][i]])
            return false;
    }
    return true;
}
void backTrack( int x){
    if(x==n+1){
        if(sz(sol)<sz(black)){
            sol=black;
        }
        return;
    }
    if(((n-x)+sz(black))< sz(sol)) return;
    if(canBeBlack(x)){
        color[x]=1;
        black.push_back(x);

        backTrack(x+1);

        color[x]=0;
        black.pop_back();
    }
    backTrack(x+1);
}
void solve(){
    cin>>n>>k;
    adj.clear();
    adj.resize(n+1);
    sol.clear();
    color.resize(n+1,0);
    lp(i,k){
        int j,k; cin>>j>>k;
        adj[j].push_back(k);
        adj[k].push_back(j);
    }
    backTrack(1);
    int m=sz(sol);
    cout<<m<<endl;
    rep(i,sol){
        if(i) cout<<' ';
        cout<<sol[i];
    }
    cout<<endl;
}
int main()
{

    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
