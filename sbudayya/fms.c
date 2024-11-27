#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void vulnerable_function();
void read_from_file(const char *filename, char *buffer, size_t size);

char flag[64];

int main()
{
    read_from_file("/sbudayya/private/flag.txt", flag, sizeof(flag));

    setbuf(stdout, NULL);
    printf("Welcome to the Format String Challenge!\n");
    printf("Find the flag hidden in memory using the format string vulnerability.\n");
    vulnerable_function();
    return 0;
}

void read_from_file(const char *filename, char *buffer, size_t size)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Error opening file");
        exit(1);
    }

    if (!fgets(buffer, size, file))
    {
        perror("Error reading file");
        fclose(file);
        exit(1);
    }

    buffer[strcspn(buffer, "\n")] = '\0';
    fclose(file);
}

void vulnerable_function()
{
    char stored_password[32];
    char user_input[128];
    char user_password[32];

    read_from_file("/sbudayya/private/password.txt", stored_password, sizeof(stored_password));

    printf("\nShhhhhh!! Tell me what's your little secret : ");
    scanf("%31s", user_password);

    if (strcmp(user_password, stored_password) == 0)
    {
        printf("\n\nAwww, you would really share the secret with me \n");
        printf("Here is one of my secrets, have fun : %p\n", (void *)flag);
    }
    else
    {
        printf("You lied to me that's not your secret, I HATE YOU, BYE.\n");
        printf(user_password);
        printf("\n");
        return;
    }

    printf("\nYeah but can tell me one more secret please......");
    scanf("%127s", user_input);

    printf(user_input);
    printf("\n");
}
