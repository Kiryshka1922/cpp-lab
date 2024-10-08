#include <stdio.h>
#include <locale.h>
int chetn (long int c){
    long long int g=0;
    g=c*(c+1) / 2 ; // проверяю на четность сумму всех граммовок
    if (g%2==1){
        return 0;}
    else {
        return 1;}    
}
int main (){
    FILE *file = fopen ("laba.txt", "w");
    setlocale(LC_ALL, "Russian");
    long int n=0;
    long int f=0, d=0;
    scanf("%d", &n);
    long int arrpetya[n];
    long int arrmasha[n];
    for (int p=0; p<n;p+=1){
            arrpetya[p]=0;
            arrmasha[p]=0;
    }
    if (chetn(n)==0){
        fprintf(file, "NO\n");
    } 
    else {
        long int pol =(n*(n+1))/4;
        fprintf(file, "YES\n");
        for (long int h=n;h>0; h-=1){
            if (pol>=h){
                arrpetya[f]=h;
                f+=1;
                pol-=h;
            }
            else {
                arrmasha[d]=h;
                d+=1;
            }
        }
    }
long int sump=0, summ=0;
fprintf (file, "Количество мисок супа Маши: %d\n", d);
fprintf(file, "Граммовки мисок Маши: ");
for (int i=0; i<n; i+=1){
    if (arrmasha[i]!=0){
        fprintf(file, "%ld ", arrmasha[i]);
        summ+=arrmasha[i];}
    else{
        fprintf(file, "\n");
        break;}}
fprintf(file, "Количество мисок супа Пети: %d\n", f);
fprintf(file, "Граммовки мисок Пети: ");
for (int i=0; i<n; i+=1){
    if (arrpetya[i]!=0){
        fprintf(file, "%ld ", arrpetya[i]);
        sump+=arrpetya[i];}
    else{
        fprintf(file, "\n");
        break;}}
// Написал тест для своей программы, который проверяет проделанные вычисления 
if ((summ+sump==n*(n+1)/2) && d+f==n){
    fprintf(file, "Тест №1 выполнен успешно!");  
    }
fclose(file);
    return 0;
}
