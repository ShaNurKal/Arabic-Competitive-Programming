#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define all(v)  (v.begin(),v.end())
#define sz(v)    (int)(v.size())
#define lp(i,n) for(int i=0 ; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))

typedef long long ll;
int c=0;
using namespace std;
void calc( int s, int e , int num){
    if(num==0&&s!=e) return;
    if(s==e&&num==0){
        c++;
        return;
    }
    calc(s+1,e,num-1);
    calc(s-1,e,num-1);
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int d1=0,d2=0,num=0;
    rep(i,s1){
        if(s1[i]=='-') d1--;
        else d1++;
        if(s2[i]=='-') d2--;
        else if(s2[i]=='+') d2++;
        else  num++;
    }
    if(d1==d2&&num==0){
        double m=1;
        cout<<fixed<<setprecision(12)<<m<<endl;
    }
    else{
    calc(d1,d2,num);
    double t=pow(2,num);
    double res=double(c/t);
    cout<<fixed<<setprecision(12)<<res<<endl;
    }

    return 0;
}
