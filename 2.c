#include <stdio.h>
#include <math.h>
long long int fact (long int g){
    long long int f=1;
    for (long int j=g;j>0;j-=2){
        f=f*j;
    }
    return f;
}
double step (double h,int k){
    long double ans=1;
    for (int i=0; i<k;i++){
        ans*=h;
    }
    return ans;}
int main(){

    printf("%lf", step(5,4));
   return 0;
}