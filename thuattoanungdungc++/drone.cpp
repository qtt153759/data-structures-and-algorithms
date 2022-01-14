#include<bits/stdc++.h>
using namespace std;
const int N=3001;
const int K=102;
int c[N];
int a[N];
int f[N][K];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k+1;j++){
            f[i][j]==-INT_MAX ;
        }
    }
    f[1][1]=c[1];
    for(int i=1;i<=n-1;i++){
        for(int z=i+1;z<=i+a[i];z++){
            if(z>n) break;
            for(int j=2;j<=k+1;j++){
                f[z][j]=max(f[z][j],f[i][j-1]+c[z]);
               // printf("i=%d z=%d j =%d  f=%d\n",i,z,j,f[z][j]);
            }
        }
    }
    int maxValue=-INT_MAX ;
    for(int j=2;j<=k+1;j++){
        maxValue=max(maxValue,f[n][j]);
    }
    cout<<maxValue;
}