#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[30];
    char subject[30];
    int marks;
};

void addStudent(FILE*fp) {
    struct Student s;
    printf("Enter Roll No: ");
     scanf("%d", &s.rollno);
    printf("Enter Name: "); 
    scanf("%s", &s.name);
    printf("Enter Subject: "); 
    scanf("%s", &s.subject);
    printf("Enter Marks: ");
     scanf("%d", &s.marks);

    fseek(fp, 0, SEEK_END);
    fwrite(&s, sizeof(s), 1, fp);
    printf("Record Added.");
}

void displayStudents(FILE *fp) {
    struct Student s;
    rewind(fp);
    printf("RollNo\tName\tSubject\tMarks");
    while (fread(&s, sizeof(s), 1, fp) == 1) {
        printf("%d\t%s\t%s\t%d", s.rollno, s.name, s.subject, s.marks);
    }
}

void searchStudent(FILE *fp, int rollno) {
    struct Student s; int found = 0;
    rewind(fp);
    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.rollno == rollno) {
            printf("Found: %d\t%s\t%s\t%d", s.rollno, s.name, s.subject, s.marks);
            found = 1;
            break;
        }
    }
    if (!found) printf("Record not found.");
}

void updateStudent(FILE *fp, int rollno) {
    struct Student s; int found = 0;
    rewind(fp);
    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.rollno == rollno) {
            printf("Enter New Name: "); scanf("%s", s.name);
            printf("Enter New Subject: "); scanf("%s", s.subject);
            printf("Enter New Marks: "); scanf("%d", &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);
            found = 1;
            printf("Record Updated.");
            break;
        }
    }
    if (!found) printf("Record not found.");
}

void deleteStudent(FILE *fp, int rollno) {
    FILE *tmp = fopen("temp.dat", "wb");
    struct Student s; int found = 0;
    rewind(fp);
    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.rollno != rollno) {
            fwrite(&s, sizeof(s), 1, tmp);
        } else {
            found = 1;
        }
    }
    fclose(fp); fclose(tmp);
    remove("students.dat");
    rename("temp.dat", "students.dat");

    fp = fopen("students.dat", "rb+");
    if (found) printf("Record Deleted.");
    else printf("Record not found.");
}

int main() {
    FILE *fp = fopen("students.dat", "rb+");
    if (fp == NULL) fp = fopen("students.dat", "wb+");
    int choice, rollno;

    while (1) {
        printf("1. Add Student 2. Display Students 3. Search Student 4. Update Student 5. Delete Student 6. ExitEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(fp); break;
            case 2: displayStudents(fp); break;
            case 3: printf("Enter Roll No: "); scanf("%d", &rollno); searchStudent(fp, rollno); break;
            case 4: printf("Enter Roll No: "); scanf("%d", &rollno); updateStudent(fp, rollno); break;
            case 5: printf("Enter Roll No: "); scanf("%d", &rollno); deleteStudent(fp, rollno); fp = fopen("students.dat", "rb+"); break;
            case 6: fclose(fp); exit(0);
            default: printf("Invalid choice!");
        }
    }
    return 0;
}
