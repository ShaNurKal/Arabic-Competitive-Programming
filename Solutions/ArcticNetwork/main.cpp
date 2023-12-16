#include <iostream>
#include <bits/stdc++.h>
#define all(v)  (v.begin(),v.end())
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))
using namespace std;

struct edge{
    int i,j;
    double c;
};
bool com( edge a, edge b){
    return a.c < b.c;
}
struct findUnion{
    vector<int> rnk,parent;

    findUnion( int n ){
        rnk= vector <int>(n),parent=vector <int>(n);
        lp(i,n){
            rnk[i]=1,parent[i]=i;
        }
    }
    int find_set( int x){
        if(parent[x]==x) return x;
        return parent[x]=find_set(parent[x]);
    }
    void link (int x, int y){
        if (rnk[x]>rnk[y]) swap(x,y);
        parent[y]=x;
        if(rnk[x]==rnk[y]) rnk[y]++;
    }
    bool Union_set( int x, int y){
        x=find_set(x),y=find_set(y);
        if(x!=y){
            link (x,y);
        }
        return x!=y;
    }

};
int main()
{
    int t;
    cin>>t;
    while(t--){
        int s,n;
        cin>>s>>n;
        s-=1;
        int x[n],y[n];
        for ( int i=0 ; i<n ; i++){
            cin>>x[i]>>y[i];
        }
        edge arr[(n*n)+9];
        int m=0;
        for ( int i=0 ; i<n ; i++ ){
            for ( int j=i+1 ; j<n ; j++){
                double xc=x[i]-x[j];
                double yc=y[i]-y[j];
                xc*=xc,yc*=yc;
                double dis=xc+yc;
                edge tmp;
                tmp.i=i,tmp.j=j,tmp.c=dis;
                arr[m]=tmp;
                m++;
            }
        }
        sort(arr,arr+m,com);
        findUnion v(n);
        vector <edge> res;
        for ( int i=0; i<m ; i++ ){
            if(v.Union_set(arr[i].i,arr[i].j)){
                res.push_back(arr[i]);
            }
        }

        if(sz(res)==s) cout<<"0.00"<<endl;
        else{
                int r=sz(res)-1;
                r-=s;
                cout<<fixed<<setprecision(2)<<sqrt(res[r].c)<<endl;
        }
    }
    return 0;
}
