//Sprint 11/09 Interface Frontend (Nicolas)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define USERNAME_LEN 20
#define PASSWORD_LEN 20

typedef struct {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
} User;

User users[MAX_USERS];
int user_count = 0;

void add_user(const char *username, const char *password) {
    if (user_count >= MAX_USERS) {
        printf("\nNúmero máximo de usuários atingido.\n");
        return;
    }
    strncpy(users[user_count].username, username, USERNAME_LEN);
    strncpy(users[user_count].password, password, PASSWORD_LEN);
    user_count++;
}

int authenticate(const char *username, const char *password) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

void register_user() {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];

    printf("\n--- Registro de Usuário ---\n");
    printf("Digite o nome de usuário: ");
    scanf("%s", username);
    printf("Digite a senha: ");
    scanf("%s", password);

    add_user(username, password);
    printf("\nUsuário registrado com sucesso!\n");
}

void login_user() {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];

    printf("\n--- Login ---\n");
    printf("Digite o nome de usuário: ");
    scanf("%s", username);
    printf("Digite a senha: ");
    scanf("%s", password);

    if (authenticate(username, password)) {
        printf("\nLogin bem-sucedido! Bem-vindo(a), %s!\n", username);
    } else {
        printf("\nNome de usuário ou senha incorretos.\n");
    }
}

void welcome_screen() {
    printf("\n");
    printf("****************************************\n");
    printf("*                                      *\n");
    printf("*          BEM-VINDO AO MERCADO         *\n");
    printf("*                                      *\n");
    printf("****************************************\n");
}

int main() {
    int choice;

    setlocale (LC_ALL, "portuguese");

    welcome_screen();

    while (1) {
        printf("\n--- Menu Principal ---\n");
        printf("1. Registrar\n");
        printf("2. Login\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                login_user();
                break;
            case 3:
                printf("\nSaindo...\n");
                exit(0);
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

