//2427406041 余睿
#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
using namespace std;
typedef long long ll;
/*
1~10
1 4 9 16 25 36 49 64 81 100   n=61
找到一组 (a,b)，使得它俩相加=n
*/
ll l,r;
bool Solution3(ll n){

    // clock_t start=clock(),end;
    for(l=1,r=sqrt(n);l<=r;){ //解法3，保留之前枚举的进度。
        while(l*l+r*r>n) r--;
        while(l*l+r*r<n) l++;

        if(l*l+r*r==n)
            return true;
            // printf("%lld %lld\n",l,r);
            // end=clock();
            // return end-start;
        
    }
    return false;
}

int main(){
    // long long N=980000112000003778LL;

    // for(int test=1;test<=3;test++)
    //     printf("S3 time = %d ms\n",Solution3(N));
    ll n;scanf("%lld",&n);
    bool flag=true;
    if(n<=1)
        flag=false;
    for(ll i=2;i*i<=n;i++)
        if(n%i==0){flag=false;break;}
    if(!flag){
        printf("not a prime\n");
        return 0;
    }
    if(Solution3(n))
        printf("%lld %lld\n",l,r);
    else
        printf("cannot be expressed as required\n");

    return 0;
}