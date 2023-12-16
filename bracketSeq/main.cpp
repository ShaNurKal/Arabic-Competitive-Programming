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
string x;
int k=1;
void solve(){
    cin>>x;
    cout<<"Case "<<k<<':'<<endl;
    deque <char> s;
    rep(i,x){
        int sum=0,s2=0;
        char y=x[i];
        bool ch=0;
        if(y=='<'||y=='{'||y=='('||y=='['){
            sum++;
            char tmp=y=='<'?'>':y=='{'?'}':y=='('?')':']';
            s.push_back(tmp);
            for ( int j=i+1 ; j<sz(x); j++){
                if(s.empty()){
                    s2+=sum;
                    ch=1;
                }
                y=x[j];
                if(y=='>'||y=='}'||y==')'||y==']'){
                    if(!s.empty()&&y==s.back()){
                        s.pop_back();
                    }
                    else{
                        break;
                    }
                 }
                else{
                    tmp=y=='<'?'>':y=='{'?'}':y=='('?')':']';
                    s.push_back(tmp);
                }
                 sum++;
            }
        }
        if(!s.empty()&&ch) sum=s2;
        if(!s.empty()&&!ch) sum=0;
        s.clear();
        cout<<sum<<endl;
    }
    k++;
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
