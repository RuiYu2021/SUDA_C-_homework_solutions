#include<iostream>
#include <vector>
#include <cstring>
#include<cstdio>
#include<ctime>

using namespace std;
// 1. 使用 vector<int> 来存储大整数，vector中每个元素存储大整数的一个数位。比如整数 "12345" 存储为 {5,4,3,2,1}。
// 注意，为了后续计算方便，这里低位在前，高位在后。


// 2. 用户输入的大整数通常是字符串形式。编写两个辅助函数，实现字符串与大整数之间的互相转换。两个辅助函数原型如下：
void Print(vector<int> t,char ch='\n'){
    for(int i=t.size()-1;~i;i--)
        printf("%d",t[i]);
    putchar(ch);
}
vector<int> string_to_vector(const string& str){//将字符串转换成大整数
    int n=str.size();
    vector<int> t(n); //t[0]=str[n-1]
    for(int i=0;i<n;i++)
        t[i]=str[n-1-i]-'0';
    return t;
}
string vector_to_string(const vector<int>& num){//将大整数转换成字符串
    int n=num.size();
    string t;
    for(int i=n-1;~i;i--)
        t+=(char)('0'+num[i]);
    return t;
}


// 3. 编写一个函数，比较两个大整数的大小。
int compare(const vector<int>& a, const vector<int>& b){
    // 如果a>b，返回1，如果a<b，返回-1，否则返回0。
    int la=a.size(),lb=b.size();
    if(la>lb) return 1;
    if(la<lb) return -1;
    for(int i=la-1;~i;i--)
        if(a[i]>b[i]) return 1;
        else if(a[i]<b[i]) return -1;
    return 0;
}


// 4. 实现大整数的加法、减法和乘法。
vector<int> add(const vector<int>& a, const vector<int>& b){
    int la=a.size(),lb=b.size(), n=max(la,lb);
    vector<int> t(n+1);
    for(int i=0;i<n;i++){
        t[i]+=(la>i? a[i]:0)+(lb>i? b[i]:0);

        t[i+1]=t[i]/10;
        t[i]%=10;
    }
    if(!t[n]) t.pop_back();
    return t;
}

vector<int> subtract(const vector<int>& a, const vector<int>& b){ //假设a大于等于b
    int la=a.size(),lb=b.size();
    vector<int> t(la);
    for(int i=0;i<la;i++){ // 10000-9999 =1
        t[i]+=a[i]-(lb>i? b[i]:0);

        if(t[i]<0) //退位
            t[i+1]=-1, t[i]+=10;
    }
    while(la>1 && !t[la-1]) t.pop_back(),la--; //删除0
    return t;
}
vector<int> multiply(const vector<int>& a, const vector<int>& b){
    int la=a.size(),lb=b.size(), n=la+lb; //10*1 <1*10^3 3位
    vector<int> t(n);
    for(int i=0;i<la;i++)
        for(int j=0;j<lb;j++)
            t[i+j]+=a[i]*b[j];
    for(int i=0;i<n-1;i++)
        t[i+1]+=t[i]/10,
        t[i]%=10;

    while(n>1 && !t[n-1]) t.pop_back(),n--; //删除0
    return t;
}

string gen(int len){
    srand((unsigned int)time(0) + (unsigned int)(new int*));
    // cout<<to_string(rand()%100)<<endl;
    string t;
    // len=len*(rand()%1000/1000.0)+10000; // 0%~99.9% len +10
    for(int i=1;i<=len;i++) t+=char(rand()%10+'0');
    return t;
    // return to_string(rand());
}

int min(int x,int y){return x>y? y:x;}
int max(int x,int y){return x>y? x:y;}

//"12345" 存储为 {5,4,3,2,1}
vector<int> Karatsuba(vector<int> a, vector<int> b){

    
    int len=max(a.size(),b.size()),half=len/2;
    if(len<=64) return multiply(a,b);

    while(a.size()<len) a.push_back(0);
    while(b.size()<len) b.push_back(0);
    // cout<< vector_to_string(a) << endl;
    //拆分为A,B,C,D

    // if(len==1){ //1*1，直接运算并返回。
    //     vector<int> t(1);
    //     t[0]=a[0]*b[0];
    //     if(t[0]>=10) t.push_back(t[0]/10),t[0]%=10;
    //     return t;
    // }

    vector<int> A(len-half),B(half);
    for(int i=0;i<half;i++) B[i]=a[i];
    for(int i=half;i<len;i++) A[i-half]=a[i];
    vector<int> C(len-half),D(half);
    for(int i=0;i<half;i++) D[i]=b[i];
    for(int i=half;i<len;i++) C[i-half]=b[i];
    // cout<< vector_to_string(A) << endl;
    // cout<< vector_to_string(B) << endl;
    //计算
    vector<int> left=Karatsuba(A,C),right=Karatsuba(B,D),
    mid=subtract(subtract(   Karatsuba(add(A,B),add(C,D)), left ), right);

    //进位

    // cout<< vector_to_string(a) <<"  "<< vector_to_string(b)<<"  "\
    // <<vector_to_string(left)<<"  "<<vector_to_string(mid)<<"  "<<vector_to_string(right)<<endl;

    vector<int> t(len*2,0);//100*100-一点点
    for(int i=0;i<right.size();i++) t[i]=right[i];
    for(int i=0,p=half;i<mid.size();i++) t[i+p]+=mid[i];
    for(int i=0,p=half*2;i<left.size();i++) t[i+p]+=left[i];
    for(int i=0;i<len*2;i++)
        t[i+1]+=t[i]/10,t[i]%=10;
    while(t.size()>1 && !t.back()) t.pop_back();
    return t;
}

int main()
{
    // 5. 在main函数中测试上述函数。main函数如下：

    // int test[]={100,1000,5000,10000,20000,40000,100000};
    // for(int i=0;i<7;i++){
        // int LEN=test[i],T=10,T_T=T;

        // int mul_time=0,kara_time=0;
        // while(T--){
            
            string str1, str2;
            cout << "输入第一个大整数: ";
            cin >> str1;
            cout << "输入第二个大整数: ";
            cin >> str2;
            // str1=gen(LEN),str2=gen(LEN);
            // printf("%s %s\n",str1.c_str(),str2.c_str());

            vector<int> a = string_to_vector(str1);
            vector<int> b = string_to_vector(str2);

            int r = compare(a, b);
            if (r < 0) cout << str1 << " < " << str2 << endl;
            else if (r == 0) cout << str1 << " == " << str2 << endl;
            else if (r > 0) cout << str1 << " > " << str2 << endl;


            vector<int> result = add(a, b);
            cout << "相加结果: " << vector_to_string(result) << endl;


            if(r>=0){
                result = subtract(a, b);
                cout << "相减结果: " << vector_to_string(result) << endl;
            }

            // clock_t st=clock(),ed;
            result = multiply(a, b);
            // ed=clock();
            // printf("%d ",ed-st);
            // mul_time+=(ed-st);

            // st=clock();
            // vector<int> result2 = Karatsuba(a,b);
            // ed=clock();
            // printf("%d\n",ed-st);
            // kara_time+=(ed-st);
            cout << "相乘结果: " << vector_to_string(result) << endl;
            // cout << "相乘结果: " << vector_to_string(result2) << endl;
            // if(result!=result2){
            //     printf("ERROR!\n");
            //     break;
            // }
            // else
            //     printf("CORRECT!\n");

        // }
        // printf("乘数的长度为 %d 时，普通乘法平均耗时 %d ms，Karatsuba乘法平均耗时 %d ms\n",LEN, mul_time/T_T, kara_time/T_T);
    // }
    return 0;
}
