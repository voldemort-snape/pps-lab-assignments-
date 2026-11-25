#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int choice, i;
    char s1[100], s2[100], temp[100];

    do {
        printf("\n===== STRING OPERATIONS MENU =====\n");
        printf("1. Length (strlen)\n");
        printf("2. Copy (strcpy)\n");
        printf("3. Concatenate (strcat)\n");
        printf("4. Compare (strcmp)\n");
        printf("5. Reverse (strrev logic)\n");
        printf("6. Convert to Uppercase\n");
        printf("7. Convert to Lowercase\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                scanf(" %[^\n]", s1);
                printf("Length = %lu\n", strlen(s1));
                break;
            case 2:
                printf("Enter source string: ");
                scanf(" %[^\n]", s1);
                strcpy(s2, s1);
                printf("Copied string = %s\n", s2);
                break;
            case 3:
                printf("Enter first string: ");
                scanf(" %[^\n]", s1);
                printf("Enter second string: ");
                scanf(" %[^\n]", s2);
                strcat(s1, s2);
                printf("Concatenated string = %s\n", s1);
                break;
            case 4:
                printf("Enter first string: ");
                scanf(" %[^\n]", s1);
                printf("Enter second string: ");
                scanf(" %[^\n]", s2);
                if (strcmp(s1, s2) == 0)
                    printf("Strings are equal.\n");
                else
                    printf("Strings are NOT equal.\n");
                break;
            case 5:
                printf("Enter a string: ");
                scanf(" %[^\n]", s1);
                strcpy(temp, s1);
                for (i = 0; i < (int)strlen(s1); i++)
                    temp[i] = s1[strlen(s1) - 1 - i];
                temp[strlen(s1)] = '\0';
                printf("Reversed string = %s\n", temp);
                break;
            case 6:
                printf("Enter a string: ");
                scanf(" %[^\n]", s1);
                for (i = 0; s1[i] != '\0'; i++)
                    s1[i] = toupper(s1[i]);
                printf("Uppercase = %s\n", s1);
                break;
            case 7:
                printf("Enter a string: ");
                scanf(" %[^\n]", s1);
                for (i = 0; s1[i] != '\0'; i++)
                    s1[i] = tolower(s1[i]);
                printf("Lowercase = %s\n", s1);
                break;
            case 8:
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 8);

    return 0;
}
