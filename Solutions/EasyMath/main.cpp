#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;




ll ai[5];
ll t,n,m,a,d;
ll lcm ( ll x, ll y){
    return ((x*y)/__gcd(x,y));
}
ll eIn ( ll n, ll i , int sign, ll s){
    if(i==5){
        return (sign*n)/s;
    }
    return eIn( n , i+1 , sign*(-1) , lcm(s,ai[i]) ) + eIn( n, i+1, sign, s) ;
}
int main()
{

    cin>>t;
    while(t--){
        cin>>n>>m>>a>>d;
        n--;
        ai[0]=a,ai[1]= a+d, ai[2]= a+(2*d) , ai[3]= a+(3*d) , ai[4]= a+(4*d);
        ll sum1=eIn(n,0,1,1);
        ll sum2=eIn(m,0,1,1);
        cout<<abs(sum2-sum1)<<endl;

    }
    return 0;
}
