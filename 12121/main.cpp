    #include <iostream>

    using namespace std;

    char arr[102][102];
    bool visited [102][102];
    int movx[4]={0,0,1,-1};
    int movy[4]={1,-1,0,0};
    int con=0;

    bool check( int i , int j , int n, int m ){
        if(i<n&&i>=0&&j<m&&j>=0) return true;

        else return false;

    }
    void dfs ( int i,int j, int n, int m ,char r){
        visited[i][j]=1;

        char t=arr[i][j];
        for ( int k=0 ; k<4 ; k++ ){
            int xc=i+movx[k];
            int yc=j+movy[k];
            bool s=check(xc,yc,n,m);
            if(s&&visited[xc][yc]==0){
                if(t==r){

                    if(arr[xc][yc]==r){
                        dfs(xc,yc,n,m,r);
                    }
                    else if(arr[xc][yc]!='.'){
                        con++;
                        dfs(xc,yc,n,m,r);
                    }
                }
                else{
                    if(arr[xc][yc]==t){
                        dfs(xc,yc,n,m,r);
                    }
                }
            }
        }

    }
    int main()
    {
        int n,m;
        char r;
        cin>>n>>m>>r;
        for ( int i=0 ; i<n ; i++){
            for ( int j=0 ; j<m ; j++){
                cin>>arr[i][j];
                visited[i][j]=0;
            }
        }

        for ( int i=0 ; i<n ; i++){
            for ( int j=0 ; j<m ; j++){
                if(arr[i][j]==r&&visited[i][j]==0){
                    dfs(i,j,n,m,r);
                }
            }
        }
        cout<<con;
        return 0;
    }
