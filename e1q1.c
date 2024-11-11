#include <stdio.h>
int main() {
FILE *file;
char filename[100], c;
int characters = 0, words = 0, lines = 0;
printf("Enter the filename: ");
scanf("%s", filename);
file = fopen(filename, "r");
if (file == NULL) {
printf("Could not open file %s", filename);
return 1;
}
while ((c = fgetc(file)) != EOF) {
characters++;
if (c == ' ' || c == '\n')
words++;
if (c == '\n')
lines++;
}fclose(file);
printf("Characters: %d\nWords: %d\nLines: %d\n", characters, words, lines);
return 0;
}
