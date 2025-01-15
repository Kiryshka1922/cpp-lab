#include <iostream>
#include <string>
#include <iomanip>

// Шаблонная функция для вычисления и вывода средней оценки (для трех оценок)
template <typename T>
void print_average_mark(const char *name, T mark1, T mark2, T mark3)
{
     double average = (static_cast<double>(mark1) + static_cast<double>(mark2) + static_cast<double>(mark3)) / 3.0;
     std::cout << name << "'s average mark: " << std::fixed << std::setprecision(5) << average << std::endl;
}

// Перегруженная функция для вычисления и вывода средней оценки по американской системе (символы A-F)
void print_average_mark(const char *name, char mark1, char mark2, char mark3)
{
     int value1, value2, value3;

     switch (mark1)
     {
     case 'A':
          value1 = 5;
          break;
     case 'B':
          value1 = 4;
          break;
     case 'C':
     case 'D':
          value1 = 3;
          break;
     case 'F':
          value1 = 2;
          break;
     default:
          value1 = 0;
     }

     switch (mark2)
     {
     case 'A':
          value2 = 5;
          break;
     case 'B':
          value2 = 4;
          break;
     case 'C':
     case 'D':
          value2 = 3;
          break;
     case 'F':
          value2 = 2;
          break;
     default:
          value2 = 0;
     }

     switch (mark3)
     {
     case 'A':
          value3 = 5;
          break;
     case 'B':
          value3 = 4;
          break;
     case 'C':
     case 'D':
          value3 = 3;
          break;
     case 'F':
          value3 = 2;
          break;
     default:
          value3 = 0;
     }

     double average = (static_cast<double>(value1) + static_cast<double>(value2) + static_cast<double>(value3)) / 3.0;
     std::cout << name << "'s average mark (American grading system): " << std::fixed << std::setprecision(5) << average << std::endl;
}

// Перегруженная функция для вычисления и вывода средней оценки (для двух оценок)
template <typename T>
void print_average_mark(const char *name, T mark1, T mark2)
{
     double average = (static_cast<double>(mark1) + static_cast<double>(mark2)) / 2.0;
     std::cout << name << "'s average mark: " << std::fixed << std::setprecision(5) << average << std::endl;
}

int main()
{
     print_average_mark("Ivan", 4, 4, 4);
     print_average_mark("Alex", 3, 3, 4);
     print_average_mark("Max", 3.5, 3.8, 3.655);
     print_average_mark("Jack", 'B', 'B', 'B');

     print_average_mark("Jane", 4, 5);
     print_average_mark("John", 2.5, 3.5);
     return 0;
}
#include <iostream>
#include <string>
#include <iomanip>

    // Шаблонная функция для вычисления и вывода средней оценки (для трех оценок)
template <typename T>
void print_average_mark(const char* name, T mark1, T mark2, T mark3)
{
     double average = (static_cast<double>(mark1) + static_cast<double>(mark2) + static_cast<double>(mark3)) / 3.0;
     std::cout << name << "'s average mark: " << std::fixed << std::setprecision(5) << average << std::endl;
}

// Перегруженная функция для вычисления и вывода средней оценки по американской системе (символы A-F)
void print_average_mark(const char *name, char mark1, char mark2, char mark3)
{
     int value1, value2, value3;

     switch (mark1)
     {
     case 'A':
          value1 = 5;
          break;
     case 'B':
          value1 = 4;
          break;
     case 'C':
     case 'D':
          value1 = 3;
          break;
     case 'F':
          value1 = 2;
          break;
     default:
          value1 = 0;
     }

     switch (mark2)
     {
     case 'A':
          value2 = 5;
          break;
     case 'B':
          value2 = 4;
          break;
     case 'C':
     case 'D':
          value2 = 3;
          break;
     case 'F':
          value2 = 2;
          break;
     default:
          value2 = 0;
     }

     switch (mark3)
     {
     case 'A':
          value3 = 5;
          break;
     case 'B':
          value3 = 4;
          break;
     case 'C':
     case 'D':
          value3 = 3;
          break;
     case 'F':
          value3 = 2;
          break;
     default:
          value3 = 0;
     }

     double average = (static_cast<double>(value1) + static_cast<double>(value2) + static_cast<double>(value3)) / 3.0;
     std::cout << name << "'s average mark (American grading system): " << std::fixed << std::setprecision(5) << average << std::endl;
}

// Перегруженная функция для вычисления и вывода средней оценки (для двух оценок)
template <typename T>
void print_average_mark(const char *name, T mark1, T mark2)
{
     double average = (static_cast<double>(mark1) + static_cast<double>(mark2)) / 2.0;
     std::cout << name << "'s average mark: " << std::fixed << std::setprecision(5) << average << std::endl;
}

int main()
{
     print_average_mark("Ivan", 4, 4, 4);
     print_average_mark("Alex", 3, 3, 4);
     print_average_mark("Max", 3.5, 3.8, 3.655);
     print_average_mark("Jack", 'B', 'B', 'B');

     print_average_mark("Jane", 4, 5);
     print_average_mark("John", 2.5, 3.5);
     return 0;
}