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
ll s,d;
void solve(){
    cin>>s>>d;
    if(s<d||(s+d)%2) cout<<"impossible"<<endl;
    else
        cout<<((s+d)/2)<<' '<<(s-((s+d)/2))<<endl;
}
int main()
{
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
