//2427406041 余睿
#include<iostream>
// #include<iomanip>
#include<cstdio>
using namespace std;
int main(){
    int n,m,k;
    scanf("%d%d%d",&m,&n,&k);
    // cout<<fixed<<setprecision(k)<<(double)m/n<<endl;
    printf("%d.",m/n);
    m%=n;
    for(int i=1;i<=k;i++){
        m*=10;
        printf("%d",m/n);
        m%=n;
    }
    printf("\n");

    return 0;
}