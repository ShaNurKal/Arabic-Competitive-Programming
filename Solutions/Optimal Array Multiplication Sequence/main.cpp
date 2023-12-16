#include <iostream>
#include <bits/stdc++.h>
#include<limits>
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0; i<n ; i++)
#define rep(i,v) for(int i=0 ; i<(int)sz(v); i++)
#define clr(v, d)  memset(v, d, sizeof(v))
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
using namespace std;
int n;
vector<pi> v;
ll mem[12][12];
ll p[12][12];
long long solve( int s, int e){
    if(s==e) return 0;
    ll& ret=mem[s][e];
    if( ret!= -1) return ret;
    ll sol1,sol2;
    ret=LLONG_MAX;
    for ( int i=s; i<e ; i++){
        sol1=solve(s,i);
        sol2=solve(i+1,e);
        if(ret>(sol1+sol2+(v[s].F*v[i].S*v[e].S))){
            ret=sol1+sol2+(v[s].F*v[i].S*v[e].S);
            p[s][e]=i;
        }
    }
    return ret;
}
void print(int i, int j){
    if(i==j){
        printf("A%d",i);
        return;
    }
    printf("(");
    print(i,p[i][j]);
    printf(" x ");
    print(p[i][j]+1,j);
    printf(")");
}
int main() {
    int j,k;
    int num=1;
    while(cin>>n&&n!=0){
        clr(mem,-1);
        v=vector<pi>(n+1);
        for ( int i=1; i<=n ; i++){
            cin>>j>>k;
            v[i]={j,k};
        }
        ll m=solve(1,n);
        printf("Case %d: ",num++);
        print(1,n);
        puts("");
    }
}
