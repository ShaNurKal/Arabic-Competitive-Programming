#include <iostream>
#include <bits/stdc++.h>
#define all(v)  v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=1; i<=n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
int main()
{
    unsigned long long n,a,b,p,q;
    cin>>n>>a>>b>>p>>q;
    unsigned long long sum=0;
    set <int> s;
    unsigned long long s1=n/a,s2=n/b,s3;
    if(a>1){
        int x=a;
    for ( int i=2 ; i*i<=x ; i++){
        while(x%i==0){
                x/=i;
                s.insert(i);
            }
        }
        if(x>1){
                s.insert(x);
        }
    }
     if(b>1){
        int x=b;
    for ( int i=2 ; i*i<=x ; i++){
        while(x%i==0){
                x/=i;
                s.insert(i);
            }
        }
        if(x>1){
            s.insert(x);
        }
    }
    int m=1;
    for ( auto i : s){
        m*=i;
    }
    if(a%b==0||b%a==0){
        s3=n/max(a,b);
        sum=s1*p+s2*q-(s3*min(p,q));
    }
    else{
        s3=n/m;
        sum=s1*p+s2*q-(s3*min(p,q));
    }
    cout<<sum<<endl;
}
