#include <stdio.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    FILE *file;
    struct Student s;
    int n;

    file = fopen("students.txt", "w");
    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter name and marks of student %d: ", i+1);
        scanf("%s %d", s.name, &s.marks);
        fprintf(file, "%s %d\n", s.name, s.marks);
    }

    fclose(file);
    printf("Data written to file successfully.\n");
    return 0;
}

