#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int number;
    char username[50];
    float money;
} Account;

void create_account(Account *c)
{
    printf("\nCriar conta\n");
    printf("insert the account number: ");
    scanf("%d", &c->number);
    printf("insert your username: ");
    scanf(" %[^\n]", c->username);
    c->money = 0.0;
    printf("\nAccount created ✅");
}

void delete_account() {}

void check_account(Account c)
{
    printf("\nCheck Account");
    printf("Account Number: %d\n\nUser: %s\n\nMoney: %f", c.number, c.username, c.money);
}

void desposit_money(Account *c)
{
    float value;
    printf("\nDeposit money ---\n insert a value: ");
    scanf("%f", &value);

    if (value > 0)
    {
        c->money += value;
        printf("\nDeposit Done ✅");
    }
    else
    {
        printf("\nInvalid value ❌");
    }
}

void sacar(Account *c)
{
    float value;
    printf("take money ---\ninsert a value: ");
    scanf("%f", &value);
    if (value > 0 && value <= c->money)
    {
        c->money -= value;
        printf("\nMoney taked ✅");
    }
    else
    {
        printf("\ninvalid value insuficient money in account ❌");
    }
}

int main()
{
    Account account;
    int option, created = 0;
    do
    {
        printf("\n=== Sistema Bancário ===\n");
        printf("1. Criar conta\n");
        printf("2. Consultar saldo\n");
        printf("3. Depositar\n");
        printf("4. Sacar\n");
        printf("5. Sair\n");
        printf("Escolha: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            create_account(&account);
            created = 1;
            break;
        case 2:
            if (created)
                check_account(account);
            else
                printf("\nplease create an account first");
            break;
        case 3:
            if (created)
                desposit_money(&account);
            else
                printf("\nplease create an account first");
            break;
        case 4:
            if (created)
                check_account(account);
            else
                printf("\nplease create an account first");
            break;
        }

    } while (option != 5);

    return 0;
}