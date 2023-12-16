#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#define all(v)  v.begin(),v.end()
using namespace std;
map<string,string> p;
map<string,int> v;
string find_p( string x){
    if(x==p[x]) return x;
    return p[x]=find_p(p[x]);
}
int main()
{
    int t;
    cin>>t;

    while(t--){
        int m;
        cin>>m;
        while(m--){
        string x,y;
        cin>>x>>y;
        string p1,p2;
        if(p.count(x)==0){
            p[x]=x,p1=x,v[x]=1;
        }
        else p1=find_p(x);
        if(p.count(y)==0){
            p[y]=y,p2=y,v[y]=1;
        }
        else p2=find_p(y);
        int res;
        if(p1==p2){
            res=v[p1];
        }
        else if(v[p1]>=v[p2]){
            v[p1]+=v[p2];
            p[p2]=p1;
            p[x]=p1;
            p[y]=p1;
            res=v[p1];
        }
        else{
            v[p2]+=v[p1];
            p[p1]=p2;
            p[x]=p2;
            p[y]=p2;
            res=v[p2];
        }
        cout<<res<<endl;
        }
        p.clear(),v.clear();
    }
    return 0;
}
