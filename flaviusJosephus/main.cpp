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
ll n,a,b;
void solve(){
    map<int,int> q;
    q[0]++;
    ll s=b%n;
    q[s]++;
    int sum=0;
    while(q[s]!=3){
        s=(((a*s)%n*s)%n+b)%n;
        q[s]++;
        if(q[s]==2) sum++;
    }

    cout<<(n-sum)<<endl;
}
int main()
{
    int t=1;
    //cin>>t;
    while(cin>>n&&n>=2){
        cin>>a>>b;
        solve();
    }
    return 0;
}
