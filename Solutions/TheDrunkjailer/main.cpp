#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        bool arr[n+1]={0};

        for ( int i=1 ; i<=n ; i++ ){
            for ( int j=i ; j<=n ; j+=i){
                if(arr[j]==0) arr[j]=1;
                else arr[j]=0;
            }
        }
        int res=0;
        for (int i=1 ; i<=n ; i++){
            if(arr[i]) res++;
        }
        cout<<res<<endl;
    }
    return 0;
}
