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
int a,b,s;
void solve(){
  s=0;
  lp(i,32){
        if((a&1&&!(b&1))||(!(a&1)&&b&1)) s+=pow(2,i);
        else s<<=0;
        a>>=1;
        b>>=1;
  }
  cout<<s<<endl;
}
int main()
{
    int t=1;
    //cin>>t;
    while(cin>>a>>b){
        solve();
    }
    return 0;
}
