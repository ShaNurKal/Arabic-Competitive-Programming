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
int siz=20000000+2;

int main()
{
    vector <bool> n(siz,true);
    vector <int> res(siz);
    n[0]=false,n[1]=false;
    for ( int i=2; i*i<=siz ; i++ ){
        for ( int j=i*2; j<=siz ; j+=i){
            n[j]=false;
        }
    }
    int j=0;
    rep(i,n){
        if(n[i]){
            if((n[i+2])){
                res[j]=i;
                j++;
            }
        }
    }
    int t;
    while(cin>>t){
        t--;
        int m=res[t]+2;
        cout<<'('<<res[t]<<", "<<m<<')'<<endl;
    }
}
