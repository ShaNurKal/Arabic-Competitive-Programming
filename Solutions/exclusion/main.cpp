#include <iostream>
#include <cmath>
using namespace std;
int ex( int index, int d , int sign ,int n, int arr[] ){
    if(index==4){
        if(d==1)
            return 0;
        else sign*n/d;
    }
    return ex(index+1,d,sign,n,arr)+ex(index+1,d*arr[index],sign*-1,n,arr);
}
void in_ex( int n, int a,int a1, int a2, int a3, int a4){
    int counter=0;
    for( int i1=0 ; i1<2 ; i1++ ){
        for( int i2=0 ; i2<2 ; i2++ ){
            for( int i3=0 ; i3<2 ; i3++ ){
                for( int i4=0 ; i4<2 ; i4++ ){
                    for( int i5=0 ; i5<2 ; i5++ ){
                        int d=1,e=0;
                        if(i1) d*=a4,e++;
                        if(i2) d*=a3,e++;
                        if(i3) d*=a2,e++;
                        if(i4) d*=a1,e++;
                        if(i5) d*=a,e++;
                        if(e==0){
                            continue;
                        }
                        if(e%2==0)
                            counter-=n/d;
                        else{
                            counter+=n/d;
                        }


                    }
                }
            }
        }
    }
    cout<<counter<<endl;
}
int main()
{
    int n,m,a,d;
    cin>>m>>n>>a>>d;
    int a1=a+d,a2=a+2*d,a3=a+3*d,a4=a+4*d;
    int arr[5]={a,a1,a2,a3,a4};
   // in_ex(n,a,a1,a2,a3,a4);

    int counter=0;
    for ( int i=m ; i<=n ; i++){
        if ( i%a==0 || i%a1==0  || i%a2==0 || i%a3==0 || i%a4==0){
            counter++;
        }
    }
    //cout<<ex(0,1,-1,n,arr);
    cout<<abs(counter-(n-m))+1;
    return 0;
}
