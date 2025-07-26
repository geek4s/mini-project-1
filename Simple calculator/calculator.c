#include<stdio.h>
void show_menu() {
    printf("\n----- Simple Calculator-----\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. EXIT\n");
    printf("Choose an operation: ");
}
int main() {
    int choice;
    float num1,num2;

    while (1) {
        show_menu();
        scanf("%d", &choice);
        if(choice==5) {
            printf("Exiting Calculator....\n");
            break;
        }
        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);
        
        switch(choice) {
            case 1:
                printf("Result: %.2f\n", num1+num2);
                break;
            case 2:
                printf("Result: %.2f\n", num1-num2);
                break;
            case 3:
                printf("Result: %.2f\n", num1*num2);
                break;
            case 4:
                if(num2 !=0)
                   printf("Result: %.2f\n", num1/num2);
                else 
                   printf("Error: cannot divide by zero.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
