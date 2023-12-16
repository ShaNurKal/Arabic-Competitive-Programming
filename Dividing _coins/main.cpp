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
int a[109];
int Max,m;
int oo=(int)1e7;
int mem[105][50500];
int solve(int i, int sum){
    if(i==m){
        return abs((Max-sum)-sum);
    }
    int& ret=mem[i][sum];
    if(ret!=oo) return mem[i][sum];
    int ch1=solve(i+1,sum+a[i]);
    int ch2=solve(i+1,sum);
    return ret=min(ch1,ch2);
}
int main()
{
    int t; cin>>t;
    while(t--){
       Max=0;
       cin>>m;
       lp(i,m){
            cin>>a[i];
            Max+=a[i];
       }
       lp(i,105){
           lp(j,50500){
             mem[i][j]=oo;
           }
       }
       cout<<solve(0,0)<<endl;
    }
    return 0;
}
