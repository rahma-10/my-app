#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct user {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void registerUser() {
    struct user newUser;
    printf("Registration Form:\n");
    printf("Username: ");
    scanf("%s", newUser.username);

    printf("Password: ");
    scanf("%s", newUser.password);

    // Save the user to the database file
    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    fprintf(file, "%s,%s\n", newUser.username, newUser.password);
    fclose(file);

    printf("Registration successful!\n");
}

int loginUser() {
    char inputUsername[MAX_USERNAME_LENGTH];
    char inputPassword[MAX_PASSWORD_LENGTH];

    printf("Login Form:\n");
    printf("Username: ");
    scanf("%s", inputUsername);

    printf("Password: ");
    scanf("%s", inputPassword);

    // Read user data from the file and compare credentials
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 0;
    }

    struct user existingUser;
    while (fscanf(file, "%[^,],%s", existingUser.username, existingUser.password) == 2) {
        if (strcmp(existingUser.username, inputUsername) == 0 && strcmp(existingUser.password, inputPassword) == 0) {
            fclose(file);
            printf("Login successful!\n");
            return 1;
        }
    }

    fclose(file);
    printf("Invalid username or password.\n");
    return 0;
}

int main() {
    int choice=[1,2];
    printf("Welcome to the Login and Registration System\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            if (loginUser()) {
                // Proceed with logged-in functionality
                printf("Logged-in functionality here.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}