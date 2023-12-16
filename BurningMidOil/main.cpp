#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int high=n , low=1;
    bool key=1;
    while (low < high){
        int mid=(high+low)/2;
        int res=0,i=0;
        while(true){
            int s=mid/(pow(k,i));
            if(s==0) break;
            res+=s;
            i++;
        }
        if(res<n) low=mid+1;
        else if(res>n) high=mid;
        else{
            cout<<mid;
            k=0;
            break;
        }
    }
    if(k)
    cout<<high;
    return 0;
}
