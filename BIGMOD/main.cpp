#include <iostream>

using namespace std;
long long pow( int b, int p, int m){
    if(p==0) return 1;
    long long res=pow(b,p/2,m);

    res=res*res;
    if(p%2==1) return (res*b)%m;
    else return res%m;

}
int main()
{
    int b,p,m;
    while(cin>>b>>p>>m){
        long long res=pow(b%m,p,m);
        cout<<res<<endl;
    }
    return 0;
}
