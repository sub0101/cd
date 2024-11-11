#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_ID_LEN 20

void process(FILE *input, FILE *output) {
    char c;
    int id_len = 0;
    char identifier[MAX_ID_LEN];
    
    while ((c = fgetc(input)) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            continue; // Ignore spaces, newlines, tabs
        }

        if (c == '/') { // Check for comments
            char next = fgetc(input);
            if (next == '*') { // Multi-line comment
                while (1) {
                    char c1 = fgetc(input);
                    if (c1 == '*' && (c = fgetc(input)) == '/') break;
                }
                continue;
            } else if (next == '/') { // Single-line comment
                while ((c = fgetc(input)) != '\n');
                continue;
            } else {
                fputc(c, output); // it's a division operator
                ungetc(next, input);
                continue;
            }
        }

        if (isalnum(c)) {
            identifier[id_len++] = c;
            if (id_len >= MAX_ID_LEN) {
                id_len = MAX_ID_LEN - 1; // Restrict length
            }
        } else {
            if (id_len > 0) {
                identifier[id_len] = '\0'; // Null-terminate the identifier
                fprintf(output, "%s ", identifier); // Writing identifier
                id_len = 0; // Reset for the next identifier
            }
            fputc(c, output); // Output other characters like operators
        }
    }

    // In case the last character was part of an identifier, output it
    if (id_len > 0) {
        identifier[id_len] = '\0';
        fprintf(output, "%s", identifier);
    }
}

int main() {
    FILE *input = fopen("input.c", "r");
    FILE *output = fopen("tokens.txt", "w");
    
    if (!input || !output) {
        printf("Error opening files\n");
        return 1;
    }

    process(input, output);
    fclose(input);
    fclose(output);
    
    printf("Tokenization complete. Check tokens.txt for the output.\n");
    return 0;
}

