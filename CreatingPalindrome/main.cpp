#include <iostream>
#include <bits/stdc++.h>
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
int a[10500],k;
int n,d;
int mem[10000+9][22][22];
// time O(n^2) // memory O(n*(k^2))
int calc( int i, int k1, int k2){
    int j=n-i-1-k1+k2;
    if(i>=j)
        return 0;
    if(k1+k2>k)
        return 30;
    int& memo=mem[i][k1][k2];
    if(memo!=-1) return memo;
    if(a[i]==a[j])
        return memo=calc(i+1,k1,k2);
    else
        return memo=min(calc(i,k1+1,k2),calc(i+1,k1,k2+1))+1;
}
int main()
{
   int t; cin>>t;
   for ( int j=1; j<=t ; j++){
        clr(mem,-1);
        scanf("%d %d",&n,&k);
        lp(i,n)
            scanf("%d",&a[i]);
        d=calc(0,0,0);
        if(d<=k){
            if(!d)
                printf("Case %d: Too easy\n",j);
            else
                printf("Case %d: %d\n",j,d);
        }
        else
            printf("Case %d: Too difficult\n",j);
   }
   system("pause");
   return 0;
}
