#include <stdio.h>

int isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeap(year))
        return 29;
    return days[month - 1];
}

/* Day of week for 1st of the month: 0 = Sunday ... 6 = Saturday */
int startDay(int month, int year) {
    int d = 1, y = year, m = month;
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (m < 3)
        y -= 1;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

int main() {
    int year, month, i, day, start, total;
    char *names[] = {"January", "February", "March", "April", "May", "June",
                     "July", "August", "September", "October", "November", "December"};

    printf("Enter year: ");
    scanf("%d", &year);

    for (month = 1; month <= 12; month++) {
        printf("\n   ---- %s %d ----\n", names[month - 1], year);
        printf("  Su  Mo  Tu  We  Th  Fr  Sa\n");

        start = startDay(month, year);
        total = daysInMonth(month, year);

        for (i = 0; i < start; i++)
            printf("    ");

        for (day = 1; day <= total; day++) {
            printf("%4d", day);
            if ((day + start) % 7 == 0)
                printf("\n");
        }
        printf("\n");
    }

    return 0;
}
