//2427406041 余睿
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e4+10;
char c[N];
int n;
int main(){
    scanf("%s",c+1);
    n=strlen(c+1);
    for(int i=1;i<=n;i++){
        char ch=c[i];
        if(ch!='0' && ch!='1'){
            puts("no");
            return 0;
        }
    }
    puts("yes");
    return 0;
}