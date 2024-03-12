#include "header.h"

// ��������� ��� �������� ���������� � ��������
struct Student
{
    char name[20]; // ��� ��������
    char address[20]; // �������� �����
    char dateOfBirth[11]; // ���� ��������
};

// ������� ��� ���������� �������� ��������
int calculateAge(const char* dateOfBirth)
{
    // ��������� ������� ����
    time_t currentTime = time(NULL);
    struct tm* currentDate = localtime(&currentTime);
    int currentYear = currentDate->tm_year + 1900;
    int currentMonth = currentDate->tm_mon + 1;
    int currentDay = currentDate->tm_mday;

    // ������ ���� �������� ��������
    int birthDay, birthMonth, birthYear;
    sscanf_s(dateOfBirth, "%d.%d.%d", &birthDay, &birthMonth, &birthYear);

    // ���������� ��������
    int age = currentYear - birthYear;

    // ������ ����� � ���� ��������
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }

    return age;
}


// ������� ��� ����� ������ � ��������
struct Student inputStudentData(struct Student* student, int i)
{
    struct Student st;

    rewind(stdin);
    printf("������� ��� ��������: ");
    fgets(st.name, sizeof(st.name), stdin);
    st.name[strcspn(st.name, "\n")] = 0; // �������� ������� ����� ������

    rewind(stdin);
    printf("������� �������� ����� ��������: ");
    fgets(st.address, sizeof(st.address), stdin);
    st.address[strcspn(st.address, "\n")] = 0; // �������� ������� ����� ������

    rewind(stdin);
    printf("������� ���� �������� �������� (� ������� ��.��.����): ");
    fgets(st.dateOfBirth, sizeof(st.dateOfBirth), stdin);
    st.dateOfBirth[strcspn(st.dateOfBirth, "\n")] = 0; // �������� ������� ����� ������

    return *student = st;
}

// ������� ��� ��������� ���� ��������� �� ��� � ���������� �������
int compareStudents(const void* a, const void* b)
{
    struct Student* studentA = (struct Student*)a;
    struct Student* studentB = (struct Student*)b;

    return strcmp(studentA->name, studentB->name);
}

// ������� ��� ������ ���������� � ���������
void printStudents(struct Student* person, int numStudents)
{
    const static int width[] = { 20, 20, 12 };

    printf("| %-*s | %-*s | %-*s|\n", width[0], "���", width[1], "�������� �����",
        width[2], "���� ��������");
    printf("|");
    for (int i = 0; i < sizeof(width) / sizeof(width[0]); i++)
    {
        for (int j = 0; j < width[i] + 2; j++)
        {
            printf("-");
        }
        printf("|");
    }
    printf("\n");
    for (int i = 0; i < numStudents; i++)
    {
        printf("| %-*s | %-*s | %-*s |\n", width[0], person[i].name, width[1]
            , person[i].address, width[2], person[i].dateOfBirth);
    }
    printf("|");
    for (int i = 0; i < sizeof(width) / sizeof(width[0]); i++)
    {
        for (int j = 0; j < width[i] + 2; j++)
            printf("-");
        printf("|");
    }
    printf("\n");
}


// ������� ��� ������ ���������, ������� ����������� n ���
void findStudentsByAge(struct Student* students, int count, int age, int num)
{
    printf("\n��������, ������� ����������� %d ���:\n", age);

    int q = 0; //���� ��� �������

    for (int i = 0; i < count; i++)
    {
        // ���������� �������� �������� �� ������ ������� ���� � ���� ��������
        int studentAge = calculateAge(students[i].dateOfBirth);

        if (studentAge == age)
        {
            const static int width[] = { 20, 20, 12 };

            struct Student* studentsAge = (struct Student*)malloc(count * sizeof(struct Student));

            studentsAge[num] = students[i];
            

            if (q == 0)
            {
                printf("| %-*s | %-*s | %-*s|\n", width[0], "���", width[1], "�������� �����",
                    width[2], "���� ��������");
                printf("|");
                for (int i = 0; i < sizeof(width) / sizeof(width[0]); i++)
                {
                    for (int j = 0; j < width[i] + 2; j++)
                    {
                        printf("-");
                    }
                    printf("|");
                }
                q++;
            }
            
            printf("\n");
            printf("| %-*s | %-*s | %-*s |\n", width[0], studentsAge[num].name, width[1]
                , studentsAge[num].address, width[2], studentsAge[num].dateOfBirth);
            printf("|");
            for (int i = 0; i < sizeof(width) / sizeof(width[0]); i++)
            {
                for (int j = 0; j < width[i] + 2; j++)
                    printf("-");
                printf("|");
            }
            num++;
        }
    }
}

// ������� ������
void memoryOff(char* input)
{
    return free(input);
}

// ��������, ����� ������������ ���������� ��� ���
void TheEnd(char*& input1, int& retFlag)
{
    retFlag = 1;
    input1 = (char*)malloc(100 * sizeof(char));  //��������� ������  ��� ���������� ������

    printf("\n���� ������ �����, �� �������� 'exit' ��� '0' \n� ���� ������ �������� - ������� enter\n");
    rewind(stdin);
    fgets(input1, 100, stdin);  //���� ���������� ������ input1
    *(input1 + strcspn(input1, "\n")) = 0; // �������� ������� ����� ������

    //��������: ���������� ��� ���
    if (strcmp(input1, "exit") == 0 || strcmp(input1, "0") == 0)
    {
        memoryOff(input1);   //������� ������ ������� input1
            retFlag = 2;
    }


    free(input1);  //������� ������ ������� input1
}