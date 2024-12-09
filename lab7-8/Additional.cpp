#include "Generall.h"
ProcessList::~ProcessList(){
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}
bool ProcessList::insert(const PCB& newPCB){ 
    ListNode* newNode = new ListNode(newPCB);
    ListNode* current = head;
    ListNode* previous = nullptr;

    while (current != nullptr && current->data.processID < newPCB.processID) {
        previous = current; // Сохранили последний не nullptr
        current = current->next;
    }

    if (current != nullptr && current->data.processID == newPCB.processID) {
        delete newNode;
        return false; // Дублирующий идентификатор
    }

    if (previous == nullptr) { // Случай если, ID меньше 1 элемента, в while не зашли ИЛИ head==nullptr
        newNode->next = head;
        head = newNode;
    } else {
        newNode->next = current;
        previous->next = newNode;
    }
    return true;
}
bool ProcessList::remove(int pid){
    ListNode* current = head;
    ListNode* previous = nullptr;

    while (current != nullptr && current->data.processID != pid) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        return false; // Идентификатор не найден ИЛИ нет элементов в списке
    }

    if (previous == nullptr) { // Случай, когда первый элемент имеет ID=pid;
        head = current->next;
    } else {
        previous->next = current->next;
    }
    delete current;
    return true;
}
void ProcessList::printList(){
ListNode* current = head;
    while (current != nullptr) {
        std::cout << "Process ID: " << current->data.processID << std::endl;
        std::cout << "Process Name: " << current->data.processNAme << std::endl;
        std::cout << "Status: " << (current->data.Status) << std::endl; 
        std::cout << "Command Counter: " << current->data.commandCounter << std::endl;
        std::cout << "CPU Registers: ";
        for (int t=0; t<10; t++) {
            std::cout <<  current->data.cpuRegisters[t] << " ";
        }
        std::cout << std::endl << std::endl;
        current = current->next;
    }
}
