#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> pi;
typedef pair<int,int> p;
auto comp=[]( const pi & x, const pi& y){
    if(x.first==y.first){
        return(x.second.second > y.second.second);
    }

   return (x.first < y.first);
};



struct Interval {
    int j,k;
};

bool compareInterval(Interval i1, Interval i2)
{
    return (i1.j > i2.j);
}
int main()
{
    // first sol;
    /*
    priority_queue <pi,vector<pi>,decltype(comp)> s(comp);
    int n;
    cin>>n;
    for ( int i=0 ; i<n ; i++){
        int j,k;
        cin>>j>>k;
        s.push({k,{j,i}});
    }
    while(!s.empty()){
        pi res;
        res=s.top();
        cout<<res.second.first<<' '<<res.first<<endl;
        s.pop();
    }*/
    int n;
    cin>>n;
    Interval s[n];
    for ( int i=0 ; i<n ; i++){
        int j,k;
        cin>>j>>k;
        s[i]={k,j};
    }
    stable_sort(s,s+n,compareInterval);
    for (int i=0; i<n ; i++ ){
        cout<<s[i].j<<' '<<s[i].k<<endl;
    }
    return 0;
}
