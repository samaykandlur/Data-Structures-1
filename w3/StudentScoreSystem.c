#include <stdio.h>
#include <string.h>


struct Student {
    char name[50];
    int rollno;
    float marks;
};

void readStudents(struct Student *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", (students + i)->name);

        printf("Roll Number: ");
        scanf("%d", &(students + i)->rollno);

        printf("Marks: ");
        scanf("%f", &(students + i)->marks);
    }
}

void displayStudents(struct Student *students, int n) {
    printf("\nStudent Details:\n");
    printf("Name, Roll No, Marks\n");
    for (int i = 0; i < n; i++) {
        printf("%s, %d, %.2f\n", (students + i)->name, (students + i)->rollno, (students + i)->marks);
    }
}

void displayTopper(struct Student *students, int n) {
    int topIndex = 0;
    for (int i = 1; i < n; i++) {
        if ((students + i)->marks > (students + topIndex)->marks) {
            topIndex = i;
        }
    }
    printf("\nTopper: %s with %.2f marks\n", (students + topIndex)->name, (students + topIndex)->marks);
}
void displaySortedByMarks(struct Student *students, int n) {
    struct Student temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((students + i)->marks > (students + j)->marks) {
                temp = *(students + i);
                *(students + i) = *(students + j);
                *(students + j) = temp;
            }
        }
    }

    printf("\nStudents in Ascending Order of Marks:\n");
    for (int i = 0; i < n; i++) {
        printf("%s (%.2f)\n", (students + i)->name, (students + i)->marks);
    }
}

int main() {
    int n;
    struct Student students[100];

    printf("Enter number of students: ");
    scanf("%d", &n);

    readStudents(students, n);
    displayStudents(students, n);
    displayTopper(students, n);
    displaySortedByMarks(students, n);

    return 0;
}
