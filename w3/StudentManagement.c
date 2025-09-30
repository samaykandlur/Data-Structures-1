#include <stdio.h>

struct Student {
    char name[50];
    int rollNo;
    int grade;
};

void readStudents(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Roll Number: ");
        scanf("%d", &students[i].rollNo);

        printf("Grade: ");
        scanf("%d", &students[i].grade);
    }
}

void displayStudents(struct Student students[], int n) {
    printf("\nStudent Information:\n");
    printf("Name, Roll No, Grade\n");
    for (int i = 0; i < n; i++) {
        printf("%s, %d, %d\n", students[i].name, students[i].rollNo, students[i].grade);
    }
}

void sortStudentsByRoll(struct Student students[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].rollNo > students[j].rollNo) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    struct Student students[100];

    printf("Enter the number of students: ");
    scanf("%d", &n);

    readStudents(students, n);
    sortStudentsByRoll(students, n);
    displayStudents(students, n);

    return 0;
}
