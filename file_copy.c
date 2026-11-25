#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *src, *dest;
    char srcName[100], destName[100];
    int ch;

    printf("Enter source file name: ");
    scanf("%s", srcName);
    printf("Enter destination file name: ");
    scanf("%s", destName);

    src = fopen(srcName, "r");
    if (src == NULL) {
        printf("Error: Cannot open source file '%s'\n", srcName);
        exit(1);
    }

    dest = fopen(destName, "w");
    if (dest == NULL) {
        printf("Error: Cannot create destination file '%s'\n", destName);
        fclose(src);
        exit(1);
    }

    while ((ch = fgetc(src)) != EOF)
        fputc(ch, dest);

    printf("File copied successfully from %s to %s\n", srcName, destName);

    fclose(src);
    fclose(dest);

    return 0;
}
