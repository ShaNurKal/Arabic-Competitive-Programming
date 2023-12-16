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
int lcm( int i, int j){
 return i*j/__gcd(i,j);
}
int main()
{
  int n,t;
  while (cin>>n>>t&&n!=0){
     int x[n],y[t];
     lp(i,n) cin>>x[i];
     lp(i,t) cin>>y[i];
     sort(x,x+n,greater<int>());
     lp(k,t)
     {
         int mi=0,ma=INT_MAX;
         for ( int i=0; i<n; i++){
            for ( int i1=i+1; i1<n ; i1++){
                for ( int i2=i1+1; i2<n ;i2++){
                    for ( int i3=i2+1; i3<n ; i3++){
                        int tmp=lcm(x[i],x[i1]);
                        tmp=lcm(tmp,x[i2]);
                        tmp=lcm(tmp,x[i3]);
                        int a=(y[k]/tmp)*tmp;
                        int b=a;
                        if(b<y[k]) b+=tmp;
                        mi=max(mi,a);
                        ma=min(ma,b);
                    }
                }
            }
         }
         cout<<mi<<' '<<ma<<endl;
     }
  }
}
