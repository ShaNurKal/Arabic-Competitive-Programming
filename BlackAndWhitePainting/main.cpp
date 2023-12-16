#include <iostream>

using namespace std;

int main()
{
    int n,m,c;

    while( cin>>n>>m>>c&& n!=0 ){
        int mod= (c==1) ? 1 : 0 ;
        int sol=( (n-7)*(m-7) + mod)/2;
        cout<<sol<<endl;
    }
    return 0;
}
