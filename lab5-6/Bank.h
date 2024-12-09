#ifndef HEADER
#define HEADER 
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
using std::cout;
using std::cin;
using std::string;
class CheckingAccount;
class Customer{
    protected:
    string First_Name;
    string Last_name;
    public:
    CheckingAccount* ptr{nullptr};
    Customer()=default;
    Customer(string name, string family): First_Name(name), Last_name(family){}
    string get_Fname()const {
        return this->First_Name;
    } 
    string get_Lname() const {
        return this->Last_name;
    }
};
class BankAccount: public Customer{
static int counter; 
string Password;
int ID{0};
public:
BankAccount()=default;
BankAccount(string name, string family, string Passowrd): Customer(name, family), Password(Passowrd){ ID=++counter;}
BankAccount(string name, string family, string Passowrd, int ID): Customer(name, family), Password(Passowrd){ this->ID=ID;}

string get_password()const {
    return this->Password;
}
int get_count()const { return counter;} // общее количество пользователей
int get_ID() const{
    return this->ID;
}
};
struct Operation {
    string where_from; //откуда
    string Where; // куда
    int how_many{0}; // сколько
};
class SavingAccount; // опережающее объявление
class Transaction: public BankAccount{
Operation Transacts [15];
public:
int counter_operation = 0;
Transaction(string name, string family, string Passowrd): BankAccount(name, family,  Passowrd){}
Transaction(string name, string family, string Passowrd, int ID): BankAccount(name, family,  Passowrd, ID){}
Transaction()=default;
Operation* get_base_history(){
    return Transacts;
}
int get_counter_operation(){
    return this->counter_operation;
}
void push_in_base(int t = 0);
virtual void Deposit(int summa){} // пополнение баланса наличными
virtual void Deposit (const CheckingAccount& people, int summa){}// пополнение баланса после перевода от кого-то
virtual void Reposit(int summa){} // снятие наличных
virtual void Reposit(CheckingAccount& people, int summa){} // перевод другому человеку
virtual void Sreposit( SavingAccount& other, int summa){} // перевод с основы на сберергательный
virtual void Sdeposit(CheckingAccount& other, int summa){} // перевод со сберегатльного на основу
};
class CheckingAccount: public Transaction{
int Main_Balance{0};
public:
bool flag = false;
~CheckingAccount(){
    if (counter_operation!=0)
    push_in_base();
}
void append_main_balance(int summa){
Main_Balance+=summa;
}
CheckingAccount()=default;
bool get_flag(){
    return flag==true ? true : false;
}
CheckingAccount(string name, string family, string Passowrd, int balance = 0): Transaction(name, family, Passowrd), Main_Balance(balance){}
int get_main_balance(){
    return this->Main_Balance;
}
void add_in_base();
void Reposit( CheckingAccount& people, int summa) override; 
void Deposit(int summa)override;
void Deposit (const CheckingAccount& people, int summa)override;
void Reposit (int Summa) override;
void Sreposit( SavingAccount& other, int summa) override;
bool operator ==(SavingAccount& my_acc);
};
class SavingAccount: public Transaction{
int Save_Balance{0};
public:
SavingAccount()=default;
SavingAccount(const CheckingAccount& other, int balance=0): Transaction(other.get_Fname(), other.get_Lname(), other.get_password(), other.get_ID()), Save_Balance(balance){
}
void set_save_balance(int f){
    Save_Balance+=f;
}
void set_create_balance(int s){
    Save_Balance = s; 
}
void Sdeposit(CheckingAccount& other, int summa) override;
void add_in_base();
int get_save_balanse(){
    return this->Save_Balance;
    }
};
class DArray {
    enum {
        start_length_array = 8, // начальная длина массива
        resize_factor = 2,      // множитель увеличения размерности
        max_length_array = 50,  // максимальный размер массива
    };
    int length {0};   // количество записанных пользователей
    int capacity {0}; // Физический размер массива
    CheckingAccount* Users {nullptr};
    void _resize_array(int size_new); //  Функция увеличвающая размер массива
public:
    DArray() : length(0), capacity(start_length_array)
    {
        Users = new CheckingAccount [start_length_array];
        capacity = start_length_array;
    }
    ~DArray();
    int size() const { return length; }
    int capacity_ar() const { return capacity; }
    CheckingAccount* get_data() const { return this->Users; }
    void push_back(CheckingAccount& other);
};
void show_menu_registration(DArray& other);
void Aktivate_Base(DArray& Users);
#endif
