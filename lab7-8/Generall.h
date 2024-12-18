#ifndef HEADER
#define HEADER
#include <iostream>
#include <string.h>
using std::cout;
using std::cin;
using std::string;
class DArray
{
    enum
    {
        start_length_array = 8, // начальная длина массива
        resize_factor = 2,      // множитель увеличения размерности
        max_length_array = 50,  // максимальный размер массива
    };
    int length{0};   // количество записанных регистров
    int capacity{0}; // Физический размер массива
    long int *registers{nullptr};
    void _resize_array(int size_new); //  Функция увеличвающая размер массива
public:
    DArray() : length(0), capacity(start_length_array)
    {
        registers = new long int [start_length_array];
    }
    ~DArray(){
        delete [] registers;
        //registers = nullptr;
    }
    int size() const { return length; }
    int capacity_ar() const { return capacity; }
    long int *get_data() const { return this->registers; }
    bool push_back(long int &reg);
    long int&  operator[](int index) const{ // 1. Добавили const, возвращаем элемент по константной ссылке
        if (index < 0 || index >= length) { // 2. Проверка на выход за границы
            throw std::out_of_range("Index out of range"); // 3. Выбрасываем исключение std::out_of_range
        }
        return registers[index]; // 4. Возвращаем ссылку на элемент, если индекс в пределах
    }
};
enum processStatus
    {
        Running, 
        Waiting,
        Stopped
    };
struct PCB {
int processID;// Идентификатор процесса
string processNAme;//Название процесса
processStatus Status;
int commandCounter = 1000000; //Счетчик команд, указывающий на следующую исполняемую команду.
DArray Registers;
const char* STATUS[3]={"Running", "Waiting", "Stopped"};
public:
PCB(int ID, string ProcessName, processStatus Status): processID(ID), processNAme(ProcessName), Status(Status){}
};

class ProcessList{
    // Узел связанного списка
    class ListNode{
    public:
    PCB data;
    ListNode* next;
    public:
    ListNode(const PCB& pcb_data, ListNode* next_node = nullptr) : data(pcb_data), next(next_node) {
        //data.commandCounter = next->data.commandCounter;
    }
    ~ListNode(){}
};
    ListNode* head;
    public:
    ProcessList(){
        this->head = nullptr;
    }
    ~ProcessList();
bool insert(const PCB& newPCB);//Вставляет новый PCB в список
bool remove (int pid);// Удаляет PCB из списка по идентификатору
bool addRegisters(int index, long int registers);
void printList();//  Выводит информацию о всех процессах в списке

};

#endif
