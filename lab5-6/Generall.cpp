#include "Bank.h"
int main (){
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
DArray Users;
setlocale(LC_ALL, "Russian");
Aktivate_Base(Users);
show_menu_registration(Users);
return 0;
}
