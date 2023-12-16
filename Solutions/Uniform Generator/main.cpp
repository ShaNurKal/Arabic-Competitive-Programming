#include <iostream>
#include <iomanip>
static bool arr[100001];
using namespace std;
int main()
{
   int step,mod;
   while ( cin>>step>>mod){
        for ( int j=0 ; j<mod-1 ; j++ ){
            arr[j]=0;
        }
        long long seed=0;
        for ( int j=0; j<mod ; j++){
            long long newseed = seed+step;
            long long s=newseed%mod;
            arr[s]=1;
            seed=newseed;
        }
       bool f=1;
        for ( int j=0; j<mod ; j++){
            if(arr[j]==0){
                f=0;
            }
        }
            cout<< setw(10) <<step
                << setw(10) <<mod
                <<"    ";
       if(f){
         cout<<"Good Choice"<<endl<<endl;
       }
       else{
        cout<<"Bad Choice"<<endl<<endl;
       }
   }
}
