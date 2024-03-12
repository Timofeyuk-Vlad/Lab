#include "header.h"

// Структура для хранения информации о студенте
struct Student
{
    char name[20]; // ФИО студента
    char address[20]; // Домашний адрес
    char dateOfBirth[11]; // Дата рождения
};

// Функция для вычисления возраста студента
int calculateAge(const char* dateOfBirth)
{
    // Получение текущей даты
    time_t currentTime = time(NULL);
    struct tm* currentDate = localtime(&currentTime);
    int currentYear = currentDate->tm_year + 1900;
    int currentMonth = currentDate->tm_mon + 1;
    int currentDay = currentDate->tm_mday;

    // Разбор даты рождения студента
    int birthDay, birthMonth, birthYear;
    sscanf_s(dateOfBirth, "%d.%d.%d", &birthDay, &birthMonth, &birthYear);

    // Вычисление возраста
    int age = currentYear - birthYear;

    // Учесть месяц и день рождения
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }

    return age;
}


// Функция для ввода данных о студенте
struct Student inputStudentData(struct Student* student, int i)
{
    struct Student st;

    rewind(stdin);
    printf("Введите ФИО студента: ");
    fgets(st.name, sizeof(st.name), stdin);
    st.name[strcspn(st.name, "\n")] = 0; // Удаление символа новой строки

    rewind(stdin);
    printf("Введите домашний адрес студента: ");
    fgets(st.address, sizeof(st.address), stdin);
    st.address[strcspn(st.address, "\n")] = 0; // Удаление символа новой строки

    rewind(stdin);
    printf("Введите дату рождения студента (в формате ДД.ММ.ГГГГ): ");
    fgets(st.dateOfBirth, sizeof(st.dateOfBirth), stdin);
    st.dateOfBirth[strcspn(st.dateOfBirth, "\n")] = 0; // Удаление символа новой строки

    return *student = st;
}

// Функция для сравнения двух студентов по ФИО в алфавитном порядке
int compareStudents(const void* a, const void* b)
{
    struct Student* studentA = (struct Student*)a;
    struct Student* studentB = (struct Student*)b;

    return strcmp(studentA->name, studentB->name);
}

// Функция для вывода информации о студентах
void printStudents(struct Student* person, int numStudents)
{
    const static int width[] = { 20, 20, 12 };

    printf("| %-*s | %-*s | %-*s|\n", width[0], "ФИО", width[1], "Домашний адрес",
        width[2], "Дата рождения");
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


// Функция для поиска студентов, которым исполнилось n лет
void findStudentsByAge(struct Student* students, int count, int age, int num)
{
    printf("\nСтуденты, которым исполнилось %d лет:\n", age);

    int q = 0; //флаг для таблицы

    for (int i = 0; i < count; i++)
    {
        // Вычисление возраста студента на основе текущей даты и даты рождения
        int studentAge = calculateAge(students[i].dateOfBirth);

        if (studentAge == age)
        {
            const static int width[] = { 20, 20, 12 };

            struct Student* studentsAge = (struct Student*)malloc(count * sizeof(struct Student));

            studentsAge[num] = students[i];
            

            if (q == 0)
            {
                printf("| %-*s | %-*s | %-*s|\n", width[0], "ФИО", width[1], "Домашний адрес",
                    width[2], "Дата рождения");
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

// очищает память
void memoryOff(char* input)
{
    return free(input);
}

// проверка, хочет пользователь продолжить или нет
void TheEnd(char*& input1, int& retFlag)
{
    retFlag = 1;
    input1 = (char*)malloc(100 * sizeof(char));  //выделение памяти  под символьную строку

    printf("\nЕсли хотите выйти, то напишите 'exit' или '0' \nА если хотите остаться - нажмите enter\n");
    rewind(stdin);
    fgets(input1, 100, stdin);  //ввод символьной строки input1
    *(input1 + strcspn(input1, "\n")) = 0; // Удаление символа новой строки

    //проверка: продолжить или нет
    if (strcmp(input1, "exit") == 0 || strcmp(input1, "0") == 0)
    {
        memoryOff(input1);   //очищает память массива input1
            retFlag = 2;
    }


    free(input1);  //очищает память массива input1
}