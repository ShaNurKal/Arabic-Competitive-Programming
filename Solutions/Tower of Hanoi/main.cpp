#include <iostream>

using namespace std;
int sum=0,n,sol=-1;

void hanoi(int n, int from , int to ,int temp,string s, string seq){
    if(n==0){
        return;
    }
    if(s==seq){
        sol=sum;
    }
    hanoi(n-1,from ,temp,to,s,seq);
    seq[n-1]=to+'0';
    cout<<seq<<endl;
    sum++;
    hanoi(n-1,temp,to,from,s,seq);


}
int main()
{
    cin>>n;
    string seq,s;
    for ( int i=0 ;i<n ;i++){
        //int y;
        //cin>>y;
        //s+=y+'0';
        seq+='1';
    }
    hanoi(n,1,2,3,s,seq);
    if(s==seq) cout<<0;
    else{
    hanoi(n,1,2,3,s,seq);
    cout<<sol;
    }
    return 0;
}
