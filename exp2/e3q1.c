#include <stdio.h>

void findComments(FILE *source, FILE *comments) {
    char c;
    while ((c = fgetc(source)) != EOF) {
        if (c == '/') {
            char next = fgetc(source);
            if (next == '*') { // Multi-line comment
                fprintf(comments, "Multi-line comment: /*");
                while (1) {
                    char c1 = fgetc(source);
                    if (c1 == EOF) break; // Handle unexpected EOF
                    fprintf(comments, "%c", c1);
                    if (c1 == '*' && (c = fgetc(source)) == '/') {
                        fprintf(comments, "/\n");
                        break;
                    }
                }
            } else if (next == '/') { // Single-line comment
                fprintf(comments, "Single-line comment: //");
                while ((c = fgetc(source)) != '\n' && c != EOF) {
                    fprintf(comments, "%c", c);
                }
                fprintf(comments, "\n");
            } else {
                ungetc(next, source); // If not a comment, put it back
            }
        }
    }
}

int main() {
    FILE *input = fopen("input.c", "r");
    FILE *comments = fopen("comments.txt", "w");

    if (!input || !comments) {
        printf("Error opening file\n");
        return 1;
    }

    findComments(input, comments);
    fclose(input);
    fclose(comments);

    printf("Comments extracted successfully.\n");
    return 0;
}

