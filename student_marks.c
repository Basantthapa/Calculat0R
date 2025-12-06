#include <stdio.h>

struct Student {
    int roll_number;
    char name[50];
    float sub1;
    float sub2;
    float sub3;
    float total;
    float percentage;
};

int main() {
    struct Student students[12];
    int i;

    // Input student details
    for(i = 0; i < 12; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &students[i].roll_number);
        printf("Name: ");
        getchar(); // to remove leftover newline
        fgets(students[i].name, sizeof(students[i].name), stdin);

        // Remove newline from fgets
        if(students[i].name[strlen(students[i].name)-1] == '\n')
            students[i].name[strlen(students[i].name)-1] = '\0';

        printf("Marks in Subject 1: ");
        scanf("%f", &students[i].sub1);
        printf("Marks in Subject 2: ");
        scanf("%f", &students[i].sub2);
        printf("Marks in Subject 3: ");
        scanf("%f", &students[i].sub3);

        // Calculate total and percentage
        students[i].total = students[i].sub1 + students[i].sub2 + students[i].sub3;
        students[i].percentage = (students[i].total / 300) * 100;

        printf("\n");
    }

    // Display student details
    printf("\nStudent Details:\n");
    for(i = 0; i < 12; i++) {
        printf("Roll No: %d\n", students[i].roll_number);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.1f, %.1f, %.1f\n", students[i].sub1, students[i].sub2, students[i].sub3);
        printf("Total: %.1f\n", students[i].total);
        printf("Percentage: %.2f%%\n", students[i].percentage);
        printf("--------------------------\n");
    }

    return 0;
}
