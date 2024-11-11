#include <stdio.h>

int main() {
    FILE *file1, *file2;
    char filename[100], c;
    int delete_line, temp = 1;

    printf("Enter the filename: ");
    scanf("%s", filename);
    file1 = fopen(filename, "r");
    file2 = fopen("temp.txt", "w");

    printf("Enter line number to delete: ");
    scanf("%d", &delete_line);

    while ((c = fgetc(file1)) != EOF) {
        if (c == '\n') temp++;
        if (temp != delete_line) fputc(c, file2);
    }

    fclose(file1);
    fclose(file2);
    remove(filename);
    rename("temp.txt", filename);
    printf("Line %d deleted successfully.\n", delete_line);
    return 0;
}
