#include "Generall.h"
bool DArray::push_back(long int& reg) {
    if (length == max_length_array) {
        return false; // Или throw std::length_error("Array is full");
    }

    try {
       if (length == capacity) {
            _resize_array(capacity * resize_factor);
       }
       if (length < capacity)
            registers[length++] = reg;
       return true;

    }
    catch (const std::bad_alloc& ba){
        std::cerr << "Error: Memory allocation failed: " << ba.what() << '\n';
        return false;
    }
}
void DArray::_resize_array(int size_new) {
    if (size_new <= capacity) return;

    while (capacity < size_new) {
        capacity *= resize_factor;
        if (capacity >= max_length_array) {
            capacity = max_length_array;
            break;
        }
    }
    long int* p = new long int[capacity];
    try {
        if (p == nullptr) {
            throw std::bad_alloc();
        }
        for (int i = 0; i < length; ++i) {
            p[i] = registers[i];
        }
        delete[] registers;
        registers = p;
    }
    catch (const std::bad_alloc& ba){
        std::cerr << "Error: Memory allocation failed: " << ba.what() << '\n';
    }
}
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
        if (head!=nullptr){
            newNode->data.commandCounter = head->data.processID;
        }
        newNode->next = head;
        head = newNode;
            
    } else {
        previous->data.commandCounter = newNode->data.processID;
        newNode->data.commandCounter = current->data.processID;
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
        previous->data.commandCounter = current->next->data.processID;
        previous->next = current->next;
    }
    delete current;
    return true;
}
bool ProcessList::addRegisters(int index, long int registr){
    ListNode* current = head;
    while (current != nullptr && current->data.processID != index) {
        current = current->next;
    }

    if (current == nullptr) {
        return false; // Идентификатор не найден ИЛИ нет элементов в списке
    }
    current->data.Registers.push_back(registr);
    return true;
}
void ProcessList::printList(){
ListNode* current = head;
    while (current != nullptr) {
        std::cout << "Process ID: " << current->data.processID << std::endl;
        std::cout << "Process Name: " << current->data.processNAme << std::endl;
        std::cout << "Status: " << (current->data.STATUS[current->data.Status]) << std::endl;
        std::cout << "Command Counter: ";
        if (current->data.commandCounter!=1000000)
        cout<<current->data.commandCounter << std::endl;
        else 
        cout<<" --- "<<std::endl;
        std::cout << "CPU Registers: ";
        for (int t=0; t<current->data.Registers.size(); t++) {
            std::cout <<  current->data.Registers[t] << " ";
        }
        std::cout << std::endl << std::endl;
        current = current->next;
    }
}
