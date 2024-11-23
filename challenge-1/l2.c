#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Disable the deprecation warning for this file
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

int main() {
    setbuf(stdout, NULL);
    char name[32];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    int con = 0;
    int account_balance = 1100;
    srand(time(NULL));

    while (con == 0) {
        printf("\n\n\nWelcome to the Lottery Ticket Purchase System\n");
        printf("We sell lottery tickets\n");

        printf("\n1. Check Account Balance\n");
        printf("\n2. Buy Lottery Tickets\n");
        printf("\n3. Purchase Supreme Lottery Ticket\n");
        printf("\n4. Exit\n");
        int menu;
        printf("\nEnter a menu selection: ");
        fflush(stdin);
        scanf("%d", &menu);

        if (menu == 1) {
            printf("\n\n\n Balance: %d \n\n\n", account_balance);
        } else if (menu == 2) {
            printf("Currently for sale\n");
            printf("1. Basic Lottery Ticket ($100 each)\n");
            printf("2. VIP Lottery Ticket ($500 each)\n");
            int lottery_choice;
            fflush(stdin);
            scanf("%d", &lottery_choice);

            if (lottery_choice == 1) {
                printf("Basic Lottery Tickets cost 100 each, enter desired quantity: ");
                int number_tickets = 0;
                fflush(stdin);
                scanf("%d", &number_tickets);

                if (number_tickets > 0) {
                    int total_cost = 100 * number_tickets;
                    printf("\nThe final cost is: $%d\n", total_cost);

                    if (total_cost <= account_balance) {
                        account_balance -= total_cost;
                        printf("\nYour current balance after transaction: $%d\n\n", account_balance);

                        int win = rand() % 10;
                        if (win == 0) {
                            printf("Congratulations! You win a $1000 prize!\n");
                            account_balance += 1000;
                        } else {
                            printf("Sorry, you didn't win. Better luck next time!\n");
                        }
                    } else {
                        printf("Not enough funds to complete purchase\n");
                    }
                }
            } else if (lottery_choice == 2) {
                printf("VIP Lottery Tickets cost 500 each, enter desired quantity: ");
                int number_tickets = 0;
                fflush(stdin);
                scanf("%d", &number_tickets);

                if (number_tickets > 0) {
                    int total_cost = 500 * number_tickets;
                    printf("\nThe final cost is: $%d\n", total_cost);

                    if (total_cost <= account_balance) {
                        account_balance -= total_cost;
                        printf("\nYour current balance after transaction: $%d\n\n", account_balance);

                        int win = rand() % 5;
                        if (win == 0) {
                            printf("Congratulations! You win a $5000 prize!\n");
                            account_balance += 5000;
                        } else {
                            printf("Sorry, you didn't win. Better luck next time!\n");
                        }
                    } else {
                        printf("Not enough funds to complete purchase\n");
                    }
                }
            }
        } else if (menu == 3) {
            printf("3. Supreme Lottery Ticket ($1000000 each) - Is there a Flag in Here? IDK\n");

            printf("The Supreme Lottery Ticket costs 1,000,000. Purchase it to get the Flag!\n");

            int total_cost = 1000000;
            printf("Total cost: $%d\n", total_cost);

            if (account_balance >= total_cost) {
                account_balance -= total_cost;
                printf("\nYour current balance after transaction: $%d\n\n", account_balance);

                printf("Congratulations! You have purchased the Supreme Lottery Ticket!\n");
                printf("You are now entitled to the FLAG!\n");

                int supreme_choice;
                fflush(stdin);
                printf("What's Your Lucky Number? ");
                scanf("%d", &supreme_choice);

                if (supreme_choice % 2 == 0) {
                    FILE *flag_file = fopen("flag.txt", "r");
                    if (flag_file == NULL) {
                        perror("Error opening flag file");
                        exit(1);
                    }

                    char flag[128];  // Assuming the flag length is under 128 characters.
                    if (fgets(flag, sizeof(flag), flag_file) != NULL) {
                        printf("YOUR FLAG IS: %s\n", flag);
                    } else {
                        printf("Error reading flag file.\n");
                    }

                    fclose(flag_file);
                    exit(0);
                } else {
                    printf("LUCKY NUMBER NOT SO LUCKY\n");
                    exit(0);
                }
            } else {
                printf("Not enough funds to complete purchase\n\n\n");
            }
        } else {
            con = 1;
        }
    }
    return 0;
}

