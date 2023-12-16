#include <iostream>
#include<math.h>
#include <iomanip>
using namespace std;

int main()
{
    double n,k,dis=0,q,w;
    cin>>n>>k;
    for ( int i=0; i<n ; i++){
        if(i==0){
            cin>>q>>w;
            continue;
        }
        double u,v;
        cin>>u>>v;
        dis+=sqrt(pow(u-q,2)+pow(v-w,2));
        q=u,w=v;
    }
    cout<<fixed<<setprecision(9)<<(dis/50)*k;
    return 0;
}
