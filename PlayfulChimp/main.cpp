#include <iostream>
#include <vector>
using namespace std;
int high( vector<int> &arr, int high , int low , int val ){
    while(low<=high){
    int mid=(high+low)/2;
    if (val>=arr[mid]) low=mid+1;
    else high=mid-1;
    }
    if(low>= (int) arr.size()) return -1;
    else return arr[low];
}

int low( vector<int> &arr, int high , int low , int val ){
    while(low<=high){
    int mid=(high+low)/2;
    if (val>arr[mid]) low=mid+1;
    else high=mid-1;
    }
    if(high<0) return -1;
    else return arr[high];
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for ( int i=0 ; i<n ; i++ ){
        cin>>arr[i];
    }
    int q;
    cin>>q;
    while(q--){
        int k;
        cin>>k;
        int first= low(arr,n-1,0,k);
        int second= high(arr,n-1,0,k);
        if(first==-1) cout<<'X'<<' ';
        else cout<<first<<' ';
        if(second==-1) cout<<'X'<<endl;
        else cout<<second<<endl;

    }
    return 0;
}
