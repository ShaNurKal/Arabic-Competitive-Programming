#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--){
        int xl1,xl2,yl1,yl2,xu1,xu2,yu1,yu2;
        cin>>xl1>>yl1>>xu1>>yu1>>xl2>>yl2>>xu2>>yu2;
        int rxl=max(xl1,xl2);
        int rxu=min(xu1,xu2);
        int ryl=max(yl1,yl2);
        int ryu=min(yu1,yu2);
        if(rxl<rxu && ryl<ryu){
            cout<<rxl<<' '<<ryl<<' '<<rxu<<' '<<ryu<<endl;
        }
        else cout<<"No Overlap\n";

        if(n) cout<<"\n";
    }
    return 0;
}
