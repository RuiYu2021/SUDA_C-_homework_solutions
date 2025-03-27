//2427406041 余睿
#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
int a,b,k;
void Solution1(int &c,int &d){
    c=100,d=1; //初始值必须赋值，还得保证不影响答案.
    for(int i=1;i<=k;i++) //c.
        for(int j=1;j<=k;j++) //d.
            if(i*b>=a*j){ //10^8  int :2*10^9
                if(i*d<c*j)
                    c=i,d=j;
            }
    // printf("%d %d\n",c,d);
}
void Solution2(int &c,int &d){
    int x=1,y=1;
    c=100,d=1;
    while(x<=k && y<=k){
        if((double)y/x>=(double)a/b){
            if((double)y/x<(double)c/d)
                c=y,d=x;
            x+=1;
        }
        else
            y+=1;
    }
}
// void Init(){
//     srand((unsigned int)(time(NULL)) + (int)(new int*) );
//     a=rand()+1,b=rand()+1,k=rand()%100+1;
//     printf("a,b,k=%d %d %d\n",a,b,k);
// }


int main(){
    // int a,b,k;
    scanf("%d%d%d",&a,&b,&k);

    // while(true){
    //     Init();

        int c1,d1;
        Solution1(c1,d1);
        printf("%d %d\n",c1,d1);

        // int c2,d2;
        // Solution2(c2,d2);
        // printf("%d %d\n",c2,d2);
        // if(c1!=c2 || d1!=d2){
        //     printf("Don't match!\n");
        //     printf("%d %d %d\n",a,b,k);
        //     break;
        // }
        // printf("\n");
    // }

    return 0;
}