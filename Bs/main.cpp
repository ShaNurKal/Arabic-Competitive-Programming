#include <iostream>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>
#define all(v)  (v.begin(),v.end())
#define sz(v)    (int)(v.size())
#define lp(i,n) for(int i=0 ; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))

typedef long long ll;

using namespace std;
double eclid ( int x1, int y1, int x2, int y2){
    double k= (double)(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
    k=sqrt(k);
    return k;
}
int main()
{
    int xa,ya,xb,yb;
    cin>>xa>>ya>>xb>>yb;
    int xm=max(xa,xb),ym=max(ya,yb);
    vector< pair<int,int> > p= {{xa,ya},{xb,yb},{xb,ya},{xa,yb}};
    int m;
    cin>>m;
    vector< pair< pair<int,int>,double> > r(m);
    set < pair<int,int> > l;
    lp(i,m){
        int j,k;
        double c;
        cin>>j>>k>>c;
        r[i].first=make_pair(j,k);
        r[i].second=c;
    }
   int res=0;
    rep(i,p){
         bool plusx=0,plusy=0;
        int j=p[i].first,k=p[i].second;
        if(j<xm) plusx=1;
        if(k<ym) plusy=1;
        // problem here with going around the rectangule
        while( j<=xm && k<=ym ){
            bool b=1;
            rep(a,r){
                pair <int,int> t= r[a].first;
                double tmp= eclid(j,k,t.first,t.second);
                if(tmp<=r[a].second){
                    b=0;
                    break;
                }
            }
            if(b){
                res++;
                // problem here;
                pair <int,int> t= make_pair(j,k);
                l.insert(t);
            }
            if(plusx) j++;
            if(plusy) k++;
        }
    }
    cout<<res;
    return 0;
}
