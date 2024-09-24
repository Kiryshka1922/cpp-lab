#include <stdio.h>
#include <math.h>
long long int fact (int g){
    long long int f=1;
    for (int j=g;j>0;j-=2){
        f=f*j;
    }
    return f;}
    double step (double h,int k){
    double ans;
    ans=h;
    if (k==0){
    return 1 ;}
    for (int i=1; i<k;i++){
        ans*=h;
    }
    return ans;
}
double T(double x){
    double ch=0, zn=0, z=0, e=0;
    long long int k=0, l=0;
    for (int i=0; i<=10;i+=1){
        k = fact(2*i+1);
        l = fact(2*i);
        z= step(x, (2*i+1));
        e = step (x, (2*i));
        ch+=z/k;
        zn+=e/l;
    }
    double m =ch/zn; 
    return m;}
int main () {
    double y;
    printf("y=: ");
    scanf("%lf", &y);
    double res;
    res=((7*T(0.25)+2*T(1+y))/(6-T(y*y-1)));
    printf("%lf", res);
    return 0;
}