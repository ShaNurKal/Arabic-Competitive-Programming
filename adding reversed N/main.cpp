#include <iostream>
#include <string>
using namespace std;

void display( int sum[], int siz){
    sum[siz]=0;
    for ( int i=0; i<siz ;i++){
        if(sum[i]>=10){sum[i+1]+=sum[i]/10,sum[i]%=10;}
    }
    int i=0;
    if(siz==1&&sum[0]==0)cout<<sum[0];
    while (sum[i]==0) i++;
    for(; i<siz ; i++){
        cout<<sum[i];
    }
    if(sum[siz]>0) cout<<sum[siz];
    cout<<endl;
}
void sumXY(int x[], int y[] , int sum[], int sizx, int sizy){
 for ( int i=0 ; i<sizx ; i++){
    if(i>=sizy){
        sum[i]=x[i];
    }
    else{
    sum[i]=x[i]+y[i];
    }
 }

}
void fil( int arr[], string x){
     for ( int i=0 ; i<x.size() ; i++ ){
            arr[i]=x[i]-'0';
        }
}
int main()
{
    int x[300],y[300],sum[300];
    int n;
    cin>>n;
    while(n--){
        string xx,yy;
        cin>>xx>>yy;
        fil(x,xx),fil(y,yy);
        if(xx.size()>=yy.size()){
            sumXY(x,y,sum,(int)xx.size(), (int)yy.size());
            display(sum,(int)xx.size());
        }
        else{
            sumXY(y,x,sum,(int)yy.size(), (int)xx.size());
            display(sum,(int)yy.size());
        }
    }
    return 0;
}
