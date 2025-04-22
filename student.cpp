#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Define a structure for student
struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;

// Function declarations
void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();

int main() {
    int choice;

    do {
        printf("\n----- Student Management System -----\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Delete Student by Roll Number\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice != 5);

    return 0;
}

// Add a new student
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &students[studentCount].rollNumber);
    printf("Enter Name: ");
    scanf(" %[^\n]", students[studentCount].name); // to read string with spaces
    printf("Enter Marks: ");
    scanf("%f", &students[studentCount].marks);

    studentCount++;
    printf("Student added successfully.\n");
}

// Display all students
void displayStudents() {
    if (studentCount == 0) {
        printf("No student records available.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < studentCount; i++) {
        printf("Roll No: %d\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("----------------------\n");
    }
}

// Search for a student
void searchStudent() {
    int roll;
    printf("Enter Roll Number to Search: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            printf("Student found:\n");
            printf("Roll No: %d\n", students[i].rollNumber);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll);
}

// Delete a student
void deleteStudent() {
    int roll;
    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student with roll number %d deleted.\n", roll);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll);
}
