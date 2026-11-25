#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks[3];
    float total;
    float percentage;
    char result[10];
};

int main() {
    int n, i, j;
    struct Student s[50];

    printf("Enter number of students (max 50): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\n--- Student %d ---\n", i + 1);
        printf("Roll number: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        s[i].total = 0;
        for (j = 0; j < 3; j++) {
            printf("Marks in subject %d (out of 100): ", j + 1);
            scanf("%f", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].percentage = s[i].total / 3;

        /* Pass if every subject is 40 or above */
        if (s[i].marks[0] >= 40 && s[i].marks[1] >= 40 && s[i].marks[2] >= 40)
            sprintf(s[i].result, "PASS");
        else
            sprintf(s[i].result, "FAIL");
    }

    printf("\n=================== STUDENT RESULT ===================\n");
    printf("%-6s %-20s %-8s %-10s %-6s\n", "Roll", "Name", "Total", "Percent", "Result");
    printf("------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-6d %-20s %-8.1f %-10.2f %-6s\n",
               s[i].roll, s[i].name, s[i].total, s[i].percentage, s[i].result);
    }

    return 0;
}
