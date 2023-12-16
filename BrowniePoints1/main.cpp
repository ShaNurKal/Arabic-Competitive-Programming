#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair <long long, long long> pairs;
int main()
{
    int p;
    while(cin>>p&&p!=0){
        int mid=p/2;
        pairs m;
        vector <pairs> arr(p);
        for ( int i=0 ; i<p ; i++ ){
            long long j,k;
            cin>>j>>k;
            if(i==mid){
                m={j,k};
            }
            arr[i]={j,k};
        }
        int q1=0,q2=0,q3=0,q4=0;
        for ( int i=0 ; i<p ; i++ ){
           if(mid==i) continue;
           if(arr[i].first > m.first && arr[i].second > m.second){
                q1++;
           }
           if(arr[i].first < m.first && arr[i].second > m.second){
                q2++;
           }
           if(arr[i].first < m.first && arr[i].second < m.second){
                q3++;
           }
           if(arr[i].first > m.first && arr[i].second < m.second){
                q4++;
           }
        }
        q1+=q3,q2+=q4;
        cout<<q1<<' '<<q2<<endl;
    }
    return 0;
}
