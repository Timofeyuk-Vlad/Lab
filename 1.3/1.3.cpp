/*������� �������� � ��������� : ���, �������� �����, ���� ��������.
 ������������ ������, � ������� �������� � ���������� ������� ���������, ������� ����������� n ���.
 ����, �����, ����� ��������� � ������ ��������.*/

#include "header.h"

// ��������� ��� �������� ���������� � ��������
struct Student
{
    char name[20]; // ��� ��������
    char address[20]; // �������� �����
    char dateOfBirth[11]; // ���� ��������
};

int main() 
{
    setlocale(LC_ALL, "RU");

    char* input1; //������ ��������, ������� ����� ����������, �������� ��������� ��� ���
    int retFlag; // ���� ��� ��������� ���������

    int n; // �������, �� �������� ����� ����� ���������
    int count; // ���������� ���������

    do
  {
    
    system("cls"); //������� �������

    printf("������� ���������� ���������: ");
    scanf_s("%d", &count);

    // �������� ������� ���������
    struct Student* students = (struct Student*)malloc(count * sizeof(struct Student));

    // ���� ������ � ���������
    for (int i = 0; i < count; i++) 
    {
        printf("\n������� ������ � �������� %d:\n", i + 1);
        inputStudentData (&students[i], i);
    }

    // ���������� ��������� �� ��� � ���������� �������
    qsort(students, count, sizeof(struct Student), compareStudents);

    // ����� ���������� � ���� ���������
    printf("\n�������� ���������� � ���������:\n\n");
    printStudents(students, count);

    printf("\n\n������� �������, �� �������� ����� ����� ���������: ");
    scanf_s("%d", &n);

    int num = 0; //���-�� ����� ������� ��������
    struct Student* studentsAge = (struct Student*)malloc(count * sizeof(struct Student));

    // ����� � ����� ��������� �� ��������
    findStudentsByAge(students, count, n, num);

    studentsAge = (struct Student*)realloc(studentsAge, num * sizeof(struct Student));

    // ������������ ������
    free(students);
    free(studentsAge);

    TheEnd(input1, retFlag);
    if (retFlag == 2) break;

    } while (1);
    return 0;
}