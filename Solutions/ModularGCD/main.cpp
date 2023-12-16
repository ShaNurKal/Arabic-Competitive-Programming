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
ll MOD=1e9+7;
ll calc ( ll a, ll c, ll n){
    if(__gcd(a,c)==0) return 0;
    ll sol=__gcd(a,c);
    lp(i,n-1){
        sol=__gcd(sol,c)%MOD;
    }
    return sol;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        ll a,b,n,c;
        cin>>a>>b>>n;
        c=abs(a-b);
        ll sol1=calc(a,c,n);
        ll sol2=calc(b,c,n);
        ll sol=__gcd((a%MOD+b%MOD)%MOD,c)%MOD;
        cout<<sol<<endl;
    }
    return 0;
}
