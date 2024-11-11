#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int state = 0, i = 0;

    printf("Enter a string: ");
    gets(str); // Note: gets() is unsafe, consider using fgets() in real applications

    while (str[i] != '\0') {
        switch (state) {
            case 0:
                if (str[i] == 'a') state = 1;
                else if (str[i] == 'b') state = 3;
                else state = 6;
                break;
            case 1:
                if (str[i] == 'a') state = 1;
                else if (str[i] == 'b') state = 2;
                else state = 6;
                break;
            case 2:
                if (str[i] == 'b') state = 4;
                else state = 6;
                break;
            case 3:
                if (str[i] == 'b') state = 3;
                else state = 6;
                break;
            case 4:
                state = 6;
                break;
            case 6:
                break;
        }
        i++;
    }

    if (state == 1 || state == 3 || state == 4) {
        printf("String is recognized under the given patterns.\n");
    } else {
        printf("String is not recognized under the given patterns.\n");
    }

    return 0;
}

