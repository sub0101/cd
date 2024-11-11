#include <stdio.h>

int main() {
    FILE *file1, *file2;
    char c;

    file1 = fopen("q4-source.txt", "r");
    file2 = fopen("q4-destination.txt", "w");

    if (file1 == NULL || file2 == NULL) {
        printf("Error in opening file!\n");
        return 1;
    }

    while ((c = fgetc(file1)) != EOF) {
        fputc(c, file2);
    }

    fclose(file1);
    fclose(file2);
    printf("Content copied successfully.\n");
    return 0;
}
