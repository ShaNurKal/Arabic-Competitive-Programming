#include <iostream>
#include <bits/stdc++.h>
#define all(v)  (v.begin(),v.end())
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))
using namespace std;
typedef long long ll;

int main()
{
    string x;
    cin>>x;
    int siz=sz(x);
    int m;
    cin>>m;
    int arr[siz]={1};
    int s[(siz/2)]={0};
    lp(i,m){
        int d;
        cin>>d;
        d--;
        s[d]++;
    }
     for ( int i=0 ; i<siz/2; i++ ){
        if(i==0)
            continue;
        s[i]+=s[i-1];
    }
    for ( int i=0 ; i<siz/2; i++ ){
        if(s[i]%2==1){
            swap(x[i],x[siz-i-1]);
        }
    }
    cout<<x;
    return 0;
}
