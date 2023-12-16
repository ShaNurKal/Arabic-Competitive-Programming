    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        string x,y;
        while (cin>>x>>y){
        if(x=="0"||y=="0"){
            cout<<0<<endl;
        }
        else{
            vector <int> m;
            m.push_back(0);
            int arr1[x.size()],arr2[y.size()];
            for ( int i=0 ; i<x.size() ; i++){
                arr1[i]=int(x[i])-48;
            }
            for ( int i=0 ; i<y.size() ; i++){
                arr2[i]=int(y[i])-48;
            }
            int s=0,e=x.size()-1;
             while(s<e){
                swap (arr1[s],arr1[e]);
                s++,e--;
             }
             s=0,e=y.size()-1;
             while(s<e){
                swap (arr2[s],arr2[e]);
                s++,e--;
             }
            for ( int i=0 ; i<y.size() ; i++ ){
                for ( int j=0 ; j<x.size() ; j++){
                    long long sum=arr2[i]*arr1[j];
                    int k=i+j;
                    while(k>m.size()-1){
                    m.push_back(0);
                    }
                    int digit=sum+m[k];
                    if(digit<10){
                        m[k]=digit;
                    }
                    else{
                        int n=k;
                        m[n]=digit%10;
                        while(digit>=10){
                            n++;
                            if(n>m.size()-1){
                                digit=digit/10;
                                m.push_back(digit);
                            }
                            else{
                               m[n]+=digit/10;
                               digit=m[n];
                            }
                        }
                    }
                }
            }

            bool flag=0;
             for( int i=m.size()-1; i>=0 ; i-- ){
               if(m[i]>0){
                flag=1;
               }
            }
            if(flag){
                for( int i=m.size()-1; i>=0 ; i-- ){
                    cout<<m[i];
                }
            }
            cout<<endl;
            }
        }
        return 0;
    }
