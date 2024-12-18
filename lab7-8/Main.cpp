#include "Generall.h"
int main(int argc, char** argv)
{
    ProcessList processList; // 1. Инициализация объекта класса ProcessList.

    processList.insert({10, "ProcessA", Running}); // 2. Вставка нескольких процессов в список.
    processList.insert({1, "ProcessB", Waiting});
    processList.insert({6, "ProcessC", Stopped});
    processList.insert({4, "ProcessD", Running});
    // processList.addRegisters(10, 123456);
    // processList.addRegisters(10, 1234568);
    
    processList.printList(); // 3.  Печать списка после вставок для проверки корректности добавления.
    cout << "- - - - - - - - - - - - - - - - ";

    processList.remove(6); // 4.  Удаление одного или нескольких процессов из списка
    cout << "\n\t\tAfter removing process with ID 6:\n";
    processList.printList(); // 5. Печать списка после удалений для демонстрации изменений.

    cout << "- - - - - - - - - - - - - - - - ";
    // 6.  Демонстрация попыток вставки существующих и удаления несуществующих элементов.

    try
    {
        if (!processList.insert({10, "ProcessB", Waiting}))
            throw(1);
    }
    catch (int t)
    {
        cout << "\n\t\tFailed to insert duplicate process ID \n";
    }
    try{
        if (!processList.remove(50))
        throw (1);
    }
    catch(int t){
            cout << "\n\t\tThere is no such item in the list\n";

    }
    processList.printList(); // 7. Финальный вывод списка: Печать конечного состояния списка.
    cout << "- - - - - - - - - - - - - - - - ";
    return 0;
}
