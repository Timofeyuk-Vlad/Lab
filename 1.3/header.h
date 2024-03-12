#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<locale.h>

int calculateAge(const char* dateOfBirth);
struct Student inputStudentData(struct Student* student, int i);
int compareStudents(const void* a, const void* b);
void printStudents(struct Student* person, int numStudents);
void findStudentsByAge(struct Student* students, int count, int age, int num);
void TheEnd(char*& input1, int& retFlag);
void memoryOff(char* input);