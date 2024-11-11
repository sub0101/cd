#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 50
#define MAX_SYMBOLS 50
#define MAX_STATES 10
#define MAX_STACK 100

typedef struct {
    char lhs;
    char rhs[10];
} Rule;

typedef struct {
    char action[10];
    int nextState;
} Action;

Rule rules[MAX_RULES];
Action actionTable[MAX_STATES][MAX_SYMBOLS];
int numRules = 3;
char terminals[MAX_SYMBOLS] = {'a', 'b', '$'};
int numTerminals = 3;

// Initialize the grammar with hardcoded rules
void initializeGrammar() {
    rules[0].lhs = 'S';
    strcpy(rules[0].rhs, "A");
    rules[1].lhs = 'A';
    strcpy(rules[1].rhs, "aA");
    rules[2].lhs = 'A';
    strcpy(rules[2].rhs, "b");
}

// Predefine states and actions for the sample grammar
void constructParsingTable() {
    // State 0
    actionTable[0][0] = (Action){"SHIFT", 1};  // on 'a'
    actionTable[0][1] = (Action){"SHIFT", 2};  // on 'b'

    // State 1
    actionTable[1][0] = (Action){"SHIFT", 1};  // on 'a'
    actionTable[1][1] = (Action){"REDUCE", 1}; // on 'b' (Reduce A -> aA)

    // State 2
    actionTable[2][2] = (Action){"ACCEPT", -1}; // on '$'
}

// Perform parsing using the predefined action table
void parseString(char *input) {
    int stack[MAX_STACK];
    int top = 0;
    int i = 0;
    char symbol;

    stack[top] = 0;  // Start at state 0
    printf("Parsing string: %s\n", input);

    while (1) {
        int state = stack[top];
        symbol = input[i];

        // Determine symbol index for 'a', 'b', and '$'
        int symbolIndex;
        if (symbol == 'a') {
            symbolIndex = 0;
        } else if (symbol == 'b') {
            symbolIndex = 1;
        } else if (symbol == '$') {
            symbolIndex = 2;
        } else {
            printf("Error: Invalid symbol '%c'\n", symbol);
            return;
        }

        Action action = actionTable[state][symbolIndex];

        if (strcmp(action.action, "SHIFT") == 0) {
            top++;
            stack[top] = action.nextState;
            i++;
            printf("SHIFT to state %d\n", action.nextState);
        } else if (strcmp(action.action, "REDUCE") == 0) {
            int ruleIndex = action.nextState;
            int length = strlen(rules[ruleIndex].rhs);
            top -= length;
            state = stack[top];
            // Goto the new state after reduction
            top++;
            stack[top] = 0; // Adjust this for actual goto transitions
            printf("REDUCE by rule %c -> %s\n", rules[ruleIndex].lhs, rules[ruleIndex].rhs);
        } else if (strcmp(action.action, "ACCEPT") == 0) {
            printf("String accepted!\n");
            return;
        } else {
            printf("Error: Unexpected symbol or state\n");
            return;
        }
    }
}

int main() {
    initializeGrammar();
    constructParsingTable();

    char input[100];
    printf("Enter the string to parse (e.g., 'aaab' or 'b'): ");
    scanf("%s", input);
    strcat(input, "$");  // Add end-of-input symbol
    parseString(input);

    return 0;
}

