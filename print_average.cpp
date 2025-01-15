#include <iostream>
#include <string>
#include <iomanip>
double Transform (char mark){
     switch (mark)
     {
     case 'A':
          return 5;
          break;

     case 'B':
          return 4;
          break;

     case 'C':
     case 'D':
          return 3;
          break;

     case 'F':
          return 2;
          break;
     default:
          break;
     }
}
// Шаблонная функция для вычисления и вывода средней оценки (для трех оценок)
template <typename T>
void print_average_mark(const char *name, T mark1, T mark2, T mark3)
{
     double average = (static_cast<double>(mark1) + static_cast<double>(mark2) + static_cast<double>(mark3)) / 3.0;
     std::cout << name << "'s average mark: " << std::fixed << std::setprecision(5) << (mark1 + mark2 + mark3) / 3.0 << std::endl;
}

// Перегруженная функция для вычисления и вывода средней оценки (для двух оценок)
template <typename T>
void print_average_mark(const char *name, T mark1, T mark2)
{
     std::cout << name << "'s average mark: " << std::fixed << std::setprecision(5) << (mark1 + mark2) / 2.0 << std::endl;
}

// Перегруженная функция для вычисления и вывода средней оценки по американской системе (символы A-F)
//ЯВНАЯ ПЕРЕГРУЗКА обобщенной функции
void print_average_mark(const char *name, char mark1, char mark2, char mark3)
{
     std::cout << name << "'s average mark (American grading system): " << std::fixed << std::setprecision(5) << (Transform(mark1) + Transform(mark2) + Transform(mark3)) / 3 << std::endl;
}

int main()
{
     print_average_mark("Ivan", 4, 4, 4);
     print_average_mark("Alex", 3, 3, 4);
     print_average_mark("Max", 3.5, 3.8, 3.655);
     print_average_mark("Jack", 'A', 'F', 'B');
     print_average_mark("Jane", 4, 5);
     print_average_mark("John", 2.5, 3.5);
     return 0;
}
