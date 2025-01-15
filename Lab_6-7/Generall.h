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
int processID;// ������������� ��������
string processNAme;//�������� ��������
processStatus Status;
int commandCounter; //������� ������, ����������� �� ��������� ����������� �������.
int cpuRegisters[10];
public:
PCB(int ID, string ProcessName, processStatus Status, int commandCounter): processID(ID), processNAme(ProcessName), Status(Status), commandCounter(commandCounter) {
cpuRegisters [1] = {0};}
};

class ProcessList{
    // ���� ���������� ������
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
bool insert(const PCB& newPCB);//��������� ����� PCB � ������
bool remove (int pid);// ������� PCB �� ������ �� ��������������
void printList();//  ������� ���������� � ���� ��������� � ������

};

#endif