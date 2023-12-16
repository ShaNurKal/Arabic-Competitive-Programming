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
#define MOD 2000000011;
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
//***** pow function log(n) complexity
ll calc( ll a, ll n){
    if(n==0)
        return 1;
    if(n==1)
        return a;
    ll sol=calc(a,n/2);
    sol=(sol*sol)%MOD;
    if(n%2==1) sol=(sol*a)%MOD;
    return sol;

}
void solve(  int c ){
    int n;
    cin>>n;
    ll ans=calc(n,n-2);
    cout<<"Case #"<<c<<": "<<ans<<endl;
}
int main()
{

    int t;
    cin>>t;
    int c=1;
    while(t--){
        solve(c);
        c++;
    }
    return 0;
}
