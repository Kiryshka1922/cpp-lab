#include "Generall.h"
int main() {
    ProcessList processList;//1. Инициализация объекта класса ProcessList.

    processList.insert({1, "ProcessA", Running, 10}); //2. Вставка нескольких процессов в список.
    processList.insert({2, "ProcessB", Waiting, 20});
    processList.insert({3, "ProcessC", Stopped, 30});

    processList.printList(); //3.  Печать списка после вставок для проверки корректности добавления. 

    processList.remove(2); //4.  Удаление одного или нескольких процессов из списка
    std::cout << "\nAfter removing process with ID 2:\n";
    processList.printList();// 5. Печать списка после удалений для демонстрации изменений. 

    if (!processList.insert({2, "ProcessB", Waiting, 20})) //6.  Демонстрация попыток вставки существующих и удаления несуществующих элементов.
        std::cout << "\nFailed to insert duplicate process ID 2.\n";

    processList.printList();// 7. Финальный вывод списка: Печать конечного состояния списка. 
    return 0;
}