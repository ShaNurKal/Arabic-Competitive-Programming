#include <iostream>

using namespace std;
int bin( int a, int b, int c, int d){
    int high=10000,low=0;
    while(low<high){
        int mid=(high+low)/2;
        int f=c-(mid*d),o=a+(mid*b);
        if(o==f) return mid;
        if(o>f) high=mid;
        else low=mid+1;
    }
    return high;
}
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if (a>=c)cout<<a;
    else{
    int res=bin(a,b,c,d);
    int o1=a+(res*b),f=c-((res-1)*d);
    if (o1>f){
        if(o1>f){
            cout<<f;
        }
        else cout<<o1;
    }
    else{
        cout<<o1;
    }
    }
    return 0;
}
