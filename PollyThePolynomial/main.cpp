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
string x,m;
ll calc (  ll x, vector <int> s){
    ll y=0;
    int j=0;
    for ( int i=sz(s)-1 ; i>=0 ; i--){
        y+=((ll)s[i])*pow(x,j);
        j++;
    }
    return y;
}
void solve(){
    istringstream ix(x);
    istringstream im(m);
    vector <int> f;
    vector <ll> s;
    int k;
    while(ix>>k){
        f.push_back(k);
    }
    while(im>>k){
        s.push_back(k);
    }
    rep(i,s){
        s[i]=calc(s[i], f);
        if(i) cout<<' ';
        cout<<s[i];
    }
    cout<<endl;
}
int main()
{
    int t=1;
    //cin>>t;
    while(getline(cin,x)&&getline(cin,m)){
        solve();
    }
    return 0;
}
