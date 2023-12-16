#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int vp,vd,t,f,c,tot=0,dis1=0,dis2=0,step=0,stop=-1;
    cin>>vp>>vd>>t>>f>>c;
    bool d1=1,s=0;
    dis1+=vp*t;
    while(dis1<c){
        tot=t;
        dis1+=vp;
        if(d1) dis2+=vd;
        if(dis2>=dis1 && dis1<c && s==0){
            stop=f+((dis2/vd));
            dis2=0;
            s=1,step++;
            d1=0;
            continue;
        }
        if(s){
            stop--;
        }

        if(stop==0) {stop=-1;d1=1,s=0;}
        tot++;

    }
    cout<<step;

    return 0;
}
