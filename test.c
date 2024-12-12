#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void displayInstructions();
double getFirstInput();
char getOperator();
double getOperand();
void performOperation(double *result, char operator, double operand);

int main() {
    double result;
    int firstInput = 1;
    char operator;

    displayInstructions();

    while (1) {
        if (firstInput) {
            result = getFirstInput();
            firstInput = 0;
        } else {
            operator = getOperator();
            if (operator == 'q') {
                break;
            }

            double operand = getOperand();
            performOperation(&result, operator, operand);
        }

        printf("Current result: %.2f\n", result);
    }

    printf("Final result: %.2f\n", result);
    return 0;
}

// Function to display program instructions
void displayInstructions() {
    printf("Simple Calculator\n");
    printf("Enter numbers and operators continuously.\n");
    printf("Type 'q' to quit.\n\n");
}

// Function to get the first input
double getFirstInput() {
    double input;
    printf("Enter the first number: ");
    if (scanf("%lf", &input) != 1) {
        printf("Invalid input. Exiting.\n");
        exit(1);
    }
    return input;
}

// Function to get the operator
char getOperator() {
    char operator;
    printf("Enter an operator (+, -, *, /) or 'q' to quit: ");
    scanf(" %c", &operator); // space before %c to ignore whitespace
    return operator;
}

// Function to get the operand
double getOperand() {
    double input;
    printf("Enter the next number: ");
    if (scanf("%lf", &input) != 1) {
        printf("Invalid input. Exiting.\n");
        exit(1);
    }
    return input;
}

// Function to perform the calculation
void performOperation(double *result, char operator, double operand) {
    switch (operator) {
        case '+':
            *result += operand;
            break;
        case '-':
            *result -= operand;
            break;
        case '*':
            *result *= operand;
            break;
        case '/':
            if (operand == 0) {
                printf("Error: Division by zero.\n");
                return;
            }
            *result /= operand;
            break;
        default:
            printf("Invalid operator. Use +, -, *, or /.\n");
    }
}
