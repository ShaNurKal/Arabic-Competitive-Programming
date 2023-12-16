#include <iostream>
#include <bits/stdc++.h>
#define all(v)  v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0; i<=n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
ll x;
unsigned long long sum;
void solve2(){
    sum=((x*(x+1))/2);
    sum*=((x*(x+1))/2);
    cout<<sum<<endl;
}
void solve(){
    sum=0;
    for (ll i=1 ; i<=x ; i++){
        sum+=(unsigned long long)(i*i*i);
    }
    cout<<sum<<endl;
}
int main()
{
    int t=1;
    //cin>>t;
    while(cin>>x){
        //solve();
        solve2();
    }
    return 0;
}
