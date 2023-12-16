#include <iostream>
#include <bits/stdc++.h>
#define all(v)  v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v); i++)
#define clr(v, d)  memset(v, d, sizeof(v))
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
int n;
int main()
{
    cin>>n;
    int w,h;
    stack<int>s;
    int con=0;
    lp(i,n){
        cin>>w>>h;
        if(s.empty()){
            s.push(h);
            con++;
        }
        else{
            while(s.top()>h){
                s.pop();
                if(s.empty()) break;
            }
            if(!s.empty()){
                if(s.top()==h) continue;
                else{
                    s.push(h);
                    con++;
                }
            }
            else{
                s.push(h);
                con++;
            }

        }
    }
    cout<<con<<endl;
    return 0;
}
