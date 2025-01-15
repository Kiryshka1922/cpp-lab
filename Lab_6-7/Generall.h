#ifndef HEADER
#define HEADER
#include <iostream>
#include <string.h>
using std::cout;
using std::cin;
using std::string;
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
int commandCounter; //Счетчик команд, указывающий на следующую исполняемую команду.
int cpuRegisters[10];
public:
PCB(int ID, string ProcessName, processStatus Status, int commandCounter): processID(ID), processNAme(ProcessName), Status(Status), commandCounter(commandCounter) {
cpuRegisters [1] = {0};}
};

class ProcessList{
    // Узел связанного списка
    class ListNode{
    public:
    PCB data;
    ListNode* next;
    public:
    ListNode(const PCB& pcb_data, ListNode* next_node = nullptr) : data(pcb_data), next(next_node) {}
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
void printList();//  Выводит информацию о всех процессах в списке

};

#endif