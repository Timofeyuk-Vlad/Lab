/*Имеются сведения о студентах : ФИО, домашний адрес, дата рождения.
 Сформировать массив, в котором записать в алфавитном порядке студентов, которым исполнилось n лет.
 Ввод, поиск, вывод выполнять в разных функциях.*/

#include "header.h"

// Структура для хранения информации о студенте
struct Student
{
    char name[20]; // ФИО студента
    char address[20]; // Домашний адрес
    char dateOfBirth[11]; // Дата рождения
};

int main() 
{
    setlocale(LC_ALL, "RU");

    char* input1; //массив символов, который будет определять, продожим программу или нет
    int retFlag; // флаг для окончания программы

    int n; // Возраст, по которому нужно найти студентов
    int count; // Количество студентов

    do
  {
    
    system("cls"); //очищает консоль

    printf("Введите количество студентов: ");
    scanf_s("%d", &count);

    // Создание массива студентов
    struct Student* students = (struct Student*)malloc(count * sizeof(struct Student));

    // Ввод данных о студентах
    for (int i = 0; i < count; i++) 
    {
        printf("\nВведите данные о студенте %d:\n", i + 1);
        inputStudentData (&students[i], i);
    }

    // Сортировка студентов по ФИО в алфавитном порядке
    qsort(students, count, sizeof(struct Student), compareStudents);

    // Вывод информации о всех студентах
    printf("\nВведённая информация о студентах:\n\n");
    printStudents(students, count);

    printf("\n\nВведите возраст, по которому нужно найти студентов: ");
    scanf_s("%d", &n);

    int num = 0; //кол-во людей нужного возраста
    struct Student* studentsAge = (struct Student*)malloc(count * sizeof(struct Student));

    // Поиск и вывод студентов по возрасту
    findStudentsByAge(students, count, n, num);

    studentsAge = (struct Student*)realloc(studentsAge, num * sizeof(struct Student));

    // Освобождение памяти
    free(students);
    free(studentsAge);

    TheEnd(input1, retFlag);
    if (retFlag == 2) break;

    } while (1);
    return 0;
}