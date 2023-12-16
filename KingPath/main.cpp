#include <iostream>
#include <bits/stdc++.h>
#define all(v)  v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
int movx[8]={0,0,1,-1,1,-1,-1,1};
int movy[8]={1,-1,0,0,1,1,-1,-1};
bool check( ll i , ll j ){
    return (i>=0&&i<=1e9&&j>=0&& j<=1e9);
    return false;
}

int main()
{
    ll x0,x1,y0,y1;
    cin>>x0>>x1>>y0>>y1;
    pi fin={y0,y1},start={x0,x1};
    int n;
    cin>>n;
    map<pi,bool> a;
    map<pi,bool> visited;
    map<pi,ll> dis;
    lp(i,n){
        ll r,x,y;
        cin>>r>>x>>y;
        for ( int i=x; i<=y ;i++){
            a[{r,i}]=true;
            visited[{r,i}]=false;
            dis[{r,i}]=0;
        }
    }
    if(start==fin){
        cout<<0;
        return 0;
    }
    queue<pi> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        pi tmp=q.front(),t;
        q.pop();
        for ( int k=0 ; k<8 ; k++ ){
            ll xc=tmp.first+movx[k];
            ll yc=tmp.second+movy[k];
            t={xc,yc};
            if(t==fin){
                dis[tmp]++;
                cout<<dis[tmp];
                return 0;
            }
            if(check(xc,yc)&&a[t]&&!visited[t]){
                q.push(t);
                dis[t]=dis[tmp]+1;
                visited[t]=true;
            }
        }
    }
    cout<<-1;
}
