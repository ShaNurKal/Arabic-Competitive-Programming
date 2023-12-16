#include <iostream>

using namespace std;

int main()
{
    int x,dd,mm,yy,cc;
    while(cin>>x&&x!=0){
        int counter=0,con=0;
        for( int i=0 ; i<x ; i++ ){
            int d,m,y,c;
            cin>>d>>m>>y>>c;
            if(i==0){
                dd=d,mm=m,yy=y,cc=c;
                continue;
            }
            else{
                bool leap;
                if(y%4==0){
                    if(y%100==0){
                        if(y%400==0)
                            leap=1;
                        else
                            leap=0;
                    }
                    else{
                        leap=1;
                    }
                }
                else{
                    leap=0;
                }
                if(yy==y){
                    if(mm==m){
                        if(dd+1==d){
                            counter++;
                            con+=c-cc;
                        }
                    }
                    else if(mm+1==m&&d==1){
                        if(mm==1&&dd==31){
                            counter++;
                            con+=c-cc;
                        }
                        else if(mm==2){
                            if(leap){
                                if(dd==29){
                                    counter++;
                                    con+=c-cc;
                                }
                            }
                            else{
                                if(dd==28){
                                    counter++;
                                    con+=c-cc;
                                }
                            }
                        }
                        else if(mm==3&&dd==31){
                            counter++;
                            con+=c-cc;
                        }
                        else if(mm==4&&dd==30){
                            counter++;
                            con+=c-cc;
                        }
                        else if(mm==5&&dd==31){
                            counter++;
                            con+=c-cc;
                        }
                        else if(mm==6&&dd==30){
                            counter++;
                            con+=c-cc;
                        }
                        else if(mm==7&&dd==31){
                            counter++;
                            con+=c-cc;
                        }
                        else if(mm==8&&dd==31){
                            counter++;
                            con+=c-cc;
                        }
                        else if(mm==9&&dd==30){
                            counter++;
                            con+=c-cc;
                        }
                        else if(mm==10&&dd==31){
                            counter++;
                            con+=c-cc;
                        }
                        else if(mm==11&&dd==30){
                            counter++;
                            con+=c-cc;
                        }
                        else if(mm==12&&dd==31){
                            counter++;
                            con+=c-cc;
                        }

                    }
                }
                else if(yy+1==y){
                    if(mm==12&&m==1&&dd==31&&d==1){
                        counter++;
                        con+=c-cc;
                    }
                }
            }
            dd=d,mm=m,yy=y,cc=c;
        }
        cout<<counter<<" "<<con<<endl;
    }
    return 0;
}
