//2427406041 余睿
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    //第i行，(n-i+1)个
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=n;j>=1;j--)
            for(int cnt=1;cnt<=n-i+1;cnt++)
                if( j==1 && cnt==n-i+1)
                    printf("%d",j);
                else
                    printf("%d ",j);
        printf("\n");
    }
    return 0;
}