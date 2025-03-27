//2427406041 余睿
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    double a,b;
    char op;
    // cin>>a>>b>>op;
    scanf("%lf %lf %c",&a,&b,&op); //12.3 34.5 *
    // printf("[%c]\n",op);
    switch(op){
        case '+':
            printf("%.6f\n",a+b);
            break;
        case '-':
            printf("%.6f\n",a-b);
            break;
        
        case '*':
            printf("%.6f\n",a*b);
            break;
        case '/':
            if(b==0)
                printf("divided by zero\n");
            else
                printf("%.6f\n",a/b);
            break;
        default:
            printf("invalid operator\n");
    }
    return 0;
}