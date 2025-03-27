//2427406041 余睿
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int a;
    int m1=0,m2=0,m3=0; //赋初始值！
    // printf("%d\n",m1);
    while(true){
        scanf("%d",&a);
        if(a<=0) break;
        if(a>=m1){ // a (a m1 m2)
            m3=m2;
            m2=m1;
            m1=a;
        }
        else if(a>=m2){
            m3=m2;
            m2=a;
        }
        else if(a>=m3)
            m3=a;
    }
    
    if(m1==0){
        printf("no input\n");
        return 0;
    }
    if(m1) printf("%d",m1);
    if(m2) printf(" %d",m2);
    if(m3) printf(" %d",m3);
    printf("\n");

    return 0;
}