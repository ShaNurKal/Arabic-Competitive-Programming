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
typedef pair<int,int> pi;
ll arr[16];
ll n,m;
ll lcm ( ll x , ll y){
 return (x*y)/__gcd(x,y);
}
ll exc( int i , short int sign , ll tot ){
    if(i==m){
        if(tot==1) return 0;
        return sign*(n/tot);
    }
   return exc(i+1,sign*-1,lcm(tot,arr[i]))+exc(i+1,sign,tot);
}
int main()
{
   while(cin>>n>>m){
    lp(i,m){
        cin>>arr[i];
    }
    ll sum=exc(0,-1,1);
    sum=n-sum;
    cout<<sum<<endl;
   }
}
