Hanoi.c 
#include <stdio.h>
#include <locale.h>
void Mowe (char point1, char point2){
        printf("�� '%c' --> � '%c'\n", point1, point2);
    }
void Tower(int ammount, char point1, char point2, char temp){
    if (ammount==0){
        return;
        }
    Tower(ammount-1, point1, temp, point2);
    Mowe(point1, point2);
    Tower(ammount-1, temp, point2, point1);
    }
int main(){
    setlocale(LC_ALL, "Russian");
    int c;                                            //  �����
    printf("������� ���������� ������ �� ����� � :"); // |   |   |
    scanf("%d", &c);                                  // |   |   | 
    Tower(c, 'A', 'B', 'C');                          // �   �   �
   return 0;
}


