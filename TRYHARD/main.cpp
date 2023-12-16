#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#define all(v)  (v.begin(),v.end())
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))

using namespace std;
typedef vector <int> v;
struct edge{
    int i,j,v;
};

   int parent[105],rk[105];
   void init(int n) {
    static int i;
    for(int i = 0; i <= n; i++)
        parent[i] = i, rk[i] = 1;
}
    int find_set( int x){
        if(x==parent[x]) return x;
        return parent[x]=find_set(parent[x]);
    }
    void link ( int x, int y){
        if(rk[x]> rk[y]) swap(x,y);
        parent[x]=y;
        if(rk[x]==rk[y]) rk[y]++;
    }
    bool Union( int x , int y){
     x=find_set(x),y=find_set(y);
     if (x!=y){
        link(x,y);
        return 1;
     }
     return 0;
    }


bool cmp (edge a, edge b){
    return a.v <  b.v;
}
edge arr[200+9];
vector <edge> ee;
int MST( int n, int m){
        int cost=0;
        init(n);
        lp(i,m){
            if(Union(arr[i].i,arr[i].j)){
                cost+=arr[i].v;
                ee.push_back(arr[i]);
            }
        }
    return cost;
}
int MST2( int n ,int m ){
     int costsec=INT_MAX;
        lp(i,m){
            int tmp=0;
            int k=0;
            bool check=0;
            init(n);
            int e=0;
            lp(j,m){
                if(i==j) continue;
                if(Union(arr[j].i,arr[j].j)){
                    tmp+=arr[j].v;
                    e++;
                    if(ee[k].i==arr[j].i&&ee[k].j==arr[j].j&&ee[k].v==arr[j].v){
                        k++;
                    }
                    else
                        check=1;
                }
            }
            if( e==n-1 && check )
             costsec=min(tmp,costsec);
        }
        return costsec;
}

int main()
{
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        lp(i,m){
            int x,y,k;
            cin>>x>>y>>k;
            arr[i].i=x,arr[i].j=y,arr[i].v=k;
        }
        sort(arr,arr+m,cmp);
        int cost=MST(n,m);
        int costsec=MST2(n,m);
        cout<<cost<<' '<<costsec<<endl;
    }
    return 0;
}
