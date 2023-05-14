#include <stdio.h>

int main()
{
    int pin = 1234; // default PIN
    float balance = 5000; // default balance
    int option;

    printf("Welcome to the ATM machine.\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. Withdraw\n");
        printf("2. Deposit\n");
        printf("3. Check balance\n");
        printf("4. Change PIN\n");
        printf("5. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                float withdrawAmount;
                printf("Enter amount to withdraw: ");
                scanf("%f", &withdrawAmount);
                if (withdrawAmount > balance) {
                    printf("Insufficient balance.\n");
                } else {
                    balance -= withdrawAmount;
                    printf("Withdrawal successful. Current balance: %.2f\n", balance);
                }
                break;

            case 2:
                float depositAmount;
                printf("Enter amount to deposit: ");
                scanf("%f", &depositAmount);
                balance += depositAmount;
                printf("Deposit successful. Current balance: %.2f\n", balance);
                break;

            case 3:
                printf("Current balance: %.2f\n", balance);
                break;

            case 4:
                int newPin, confirmPin;
                printf("Enter new PIN: ");
                scanf("%d", &newPin);
                printf("Confirm new PIN: ");
                scanf("%d", &confirmPin);
                if (newPin == confirmPin) {
                    pin = newPin;
                    printf("PIN changed successfully.\n");
                } else {
                    printf("PINs do not match. Please try again.\n");
                }
                break;

            case 5:
                printf("Thank you for using the ATM machine.\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 5);

    return 0;
}
