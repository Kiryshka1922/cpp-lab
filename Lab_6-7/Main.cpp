#include "Generall.h"
int main() {
    ProcessList processList;//1. ������������� ������� ������ ProcessList.

    processList.insert({1, "ProcessA", Running, 10}); //2. ������� ���������� ��������� � ������.
    processList.insert({2, "ProcessB", Waiting, 20});
    processList.insert({3, "ProcessC", Stopped, 30});

    processList.printList(); //3.  ������ ������ ����� ������� ��� �������� ������������ ����������. 

    processList.remove(2); //4.  �������� ������ ��� ���������� ��������� �� ������
    std::cout << "\nAfter removing process with ID 2:\n";
    processList.printList();// 5. ������ ������ ����� �������� ��� ������������ ���������. 

    if (!processList.insert({2, "ProcessB", Waiting, 20})) //6.  ������������ ������� ������� ������������ � �������� �������������� ���������.
        std::cout << "\nFailed to insert duplicate process ID 2.\n";

    processList.printList();// 7. ��������� ����� ������: ������ ��������� ��������� ������. 
    return 0;
}