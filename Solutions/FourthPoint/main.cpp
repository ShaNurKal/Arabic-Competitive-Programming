#include <iostream>
#include <bits/stdc++.h>
#define all(v)  v.begin(),v.end()
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))
using namespace std;
typedef long long ll;
typedef pair<double, double> pi;



int main()
{
    ll t;

    pi arr[4];
    pi mid;
    double x1,y1,x2,y2,x3,y3,x4,y4;
    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)==8){
        arr[0].first=x1,arr[0].second=y1;
        arr[1].first=x2,arr[1].second=y2;
        arr[2].first=x3,arr[2].second=y3;
        arr[3].first=x4,arr[3].second=y4;
        int posx,posy;
        lp(i,4){
            for (int j=i+1 ; j<4 ; j++){
                if(arr[i]==arr[j]){
                  mid=arr[i];
                  posx=i,posy=j;
                }

            }
        }
        int pos=0;
        while(pos==posx||pos==posy) pos++;
        double x=arr[pos].first;
        double y=arr[pos].second;
        pos++;
        while(pos==posx||pos==posy) pos++;
        x=(x+arr[pos].first)/2;
        y=(y+arr[pos].second)/2;
        double a=(2*x)-mid.first;
        double b=(2*y)-mid.second;
        cout<<fixed<<setprecision(3)<<a<<' ';
        cout<<fixed<<setprecision(3)<<b<<endl;
    }
    return 0;
}
