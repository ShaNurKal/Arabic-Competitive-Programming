#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#define all(v)  (v.begin(),v.end())
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0 ; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))

using namespace std;
typedef vector <int> v;
typedef pair< int, pair<int,int> > edge;
priority_queue <edge,vector<edge>,greater<edge>> e;
struct UnionFind{
    v rk,parent;
    int forest;
    UnionFind( int n) {
     rk=v(n),parent=v(n);
     lp(i,n){
         rk[i]=1,parent[i]=i;
        }
    }
    int fin_set(int x){
        if(parent[x]==x) return x;
        return parent[x]=fin_set(parent[x]);
    }
    void link( int x, int y){
        if(rk[x]>rk[y]) swap(x,y);
        parent[x]=y;
        if(rk[x]==rk[y]) rk[y]++;
    }
    int union_set( int x, int y){
        x=fin_set(x),y=fin_set(y);
        if(x!=y){
            link(x,y);
            forest--;
            return 1;
        }
        return 0;
    }

};

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        UnionFind vp(n+1);
        vector < pair <int,int> > c(n+1);
        vector < pair <int,int> > sol;
        for(int i=1; i<=n ; i++){
            int j,k;
            cin>>j>>k;
            c[i]={j,k};
        }
        int m;
        cin>>m;
        int cnt=0;
        lp(i,m){
            int j,k;
            cin>>j>>k;
            cnt+=vp.union_set(j,k);
        }
        if(cnt==n-1){
           cout<<"No new highways need";
        }
        else{
        for( int i=1 ; i<=n ; i++ ){
            for( int j=i+1 ; j<=n ; j++ ){
                int x=c[i].first-c[j].first;
                int y=c[i].second-c[j].second;
                int dis=(x*x)+(y*y);
                e.push({dis,{i,j}});
            }
        }
        while(!e.empty()){
            edge tmp=e.top();
            e.pop();
            if(vp.union_set(tmp.second.first,tmp.second.second)){
                sol.push_back({tmp.second.first,tmp.second.second});
            }
        }
        rep(i,sol)
            cout<<sol[i].first<<' '<<sol[i].second<<endl;
        e= priority_queue <edge,vector<edge>,greater<edge>>();
        }
        if(t){
            puts("");
        }
    }
    return 0;
}
