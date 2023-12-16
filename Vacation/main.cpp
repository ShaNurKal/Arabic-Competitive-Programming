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
string a,b;
int mem[105][105];
int solve( int i, int j){
    if( i==sz(a) || j==sz(b))
        return 0;
    if(mem[i][j]!=-1)
        return mem[i][j];
    if(a[i]==b[j])
        return mem[i][j]=solve(i+1,j+1)+1;
    int ch1=solve(i+1,j);
    int ch2=solve(i,j+1);
    return mem[i][j]=max(ch1,ch2);
}
int main()
{
    int k,d=1;
    while(true){
        getline(cin,a);
        if(a=="#") break;
        getline(cin,b);
        clr(mem,-1);
        k=solve(0,0);
        printf("Case #%d: you can visit at most %d cities.\n",d++,k);
    }
    return 0;
}
