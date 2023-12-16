    #include <iostream>
    #include <cmath>
    #include <iomanip>
    #include <algorithm>
    using namespace std;

    long long    a[52][52];
    void com(){
     a[1][0]=1;
     a[1][1]=1;
     for ( int i=2 ; i<=50 ; i++){
        a[i][0]=1;
        for ( int j=1 ; j<=i ; j++){
            a[i][j]=a[i-1][j]+a[i-1][j-1];
        }
     }
    }

    int main()
    {
        com();
        int n;
        while(cin>>n&&n!=0){
            int l[n],res=0;
            for ( int i=0 ; i<n ; i++ ){cin>>l[i];}
            for ( int i=0 ; i<n ; i++){
                for ( int j=i+1 ; j<n ; j++){
                    if(__gcd(l[i],l[j])==1) res++;
                }
            }
            if(res==0){
                cout<<"No estimate for this data set.\n";
            }
            else{
                int c=a[n][2];
                double m =((double)6*c)/res;
                double s=sqrt(m);
                cout<<fixed<<setprecision(6)<<s<<endl;
            }
        }
        return 0;
    }
