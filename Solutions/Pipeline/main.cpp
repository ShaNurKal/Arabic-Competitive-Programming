#include <iostream>

using namespace std;
long long sum( long long n){
    return (n*(n+1))/2;
}
long long sum2( long long s , long long e){
    if(s<=1){
        return sum(e);
    }
 return sum(e)-sum(s-1);
}
long long binary( int k , long long n){
 int lo=1,hi=k;
    while(lo<hi){
        int mid=(lo+hi)/2;
        long long s= sum2(mid,k);
        if(s == n){
            return k-mid+1;
        }
        if(s>n){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    return k-lo+2;
}
int main()
{
    long long n,k;
    cin>>n>>k;
    if(n==1){
        cout<<0;
    }
    else if( n<=k){
        cout<<1;
    }
    else{
     n--;
     k--;
     if(sum(k)<n){
        cout<<-1;
     }
     else{
        int spit=binary(k,n);
        cout<<spit;
     }
    }


    return 0;
}
