#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char c_program[1000], *token;
    FILE *file = fopen("q5-program.c", "r");

    if (file == NULL) {
        printf("Cannot open file\n");
        return 1;
    }

    fread(c_program, sizeof(char), 1000, file);
    fclose(file);

    token = strtok(c_program, " \n\t(){};,");
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " \n\t(){};,");
    }
    return 0;
}

