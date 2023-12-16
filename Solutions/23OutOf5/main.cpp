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
int a[5];
int v[5];
bool sol=0;

void backtrack( int x, int sum, bool first){
    if(sol) return;
    if(x==5){
        if(sum==23) sol=1;
        return;
    }
    for ( int i=0 ; i<5 ; i++){
            if(v[i]) continue;
            v[i]=1;
            if(first){
                backtrack(x+1,sum+a[i],1);
                backtrack(x+1,sum-a[i],1);
                backtrack(x+1,sum*a[i],1);
            }
            else
                backtrack(x+1,a[i],1);
            v[i]=0;
    }
}


int main()
{

    //int t=1;
    //cin>>t;
    while(true){
        sol=0;
        lp(i,5) {cin>>a[i]; v[i]=0;}
        if(a[0]==0) break;
        backtrack(0,0,0);
        if(sol) puts("Possible");
        else puts("Impossible");
    }
    return 0;
}

