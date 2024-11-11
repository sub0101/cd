#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isStopWord(char *word, FILE *stopFile) {
    char stopWord[50];
    rewind(stopFile);
    while (fscanf(stopFile, "%s", stopWord) != EOF) {
        if (strcmp(word, stopWord) == 0) return 1;
    }
    return 0;
}

int main() {
    FILE *storyFile, *stopFile, *resultFile;
    char word[50];

    storyFile = fopen("q6-story.txt", "r");
    stopFile = fopen("q6-stop_words.txt", "r");
    resultFile = fopen("q6-story_without_stopwords.txt", "w");

    if (!storyFile || !stopFile || !resultFile) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(storyFile, "%s", word) != EOF) {
        if (!isStopWord(word, stopFile)) {
            fprintf(resultFile, "%s ", word);
        }
    }

    fclose(storyFile);
    fclose(stopFile);
    fclose(resultFile);

    printf("Stop words removed successfully.\n");
    return 0;
}
