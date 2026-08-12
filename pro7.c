// write a c program to take two-d  array to store the marks of five students in three subjects and display the highest marks in each subject and the total marks of each subject //
#include <stdio.h>      

int main() {
    int marks[5][3];
    int i, j;
    int highest[3] = {0};
    int total[3] = {0};

    // Input marks for each student in each subject
    for (i = 0; i < 5; i++) {
        printf("Enter marks for student %d:\n", i + 1);
        for (j = 0; j < 3; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
            total[j] += marks[i][j];
            if (marks[i][j] > highest[j]) {
                highest[j] = marks[i][j];
            }
        }
    }

    // Display highest marks in each subject
    printf("\nHighest marks in each subject:\n");
    for (j = 0; j < 3; j++) {
        printf("Subject %d: %d\n", j + 1, highest[j]);
    }

    // Display total marks in each subject
    printf("\nTotal marks in each subject:\n");
    for (j = 0; j < 3; j++) {
        printf("Subject %d: %d\n", j + 1, total[j]);
    }

    return 0;
}