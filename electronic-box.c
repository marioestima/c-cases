#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char name[50];
    char password[50];
    _Bool active;
} Employe;

typedef struct
{
    char product_name[50];
    float price;
    char product_symbol[10];
} Products;

void list_productos(Products *p, int total)
{
    printf("\n--- Lista de Produtos ---\n");
    for (int i = 0; i < total; i++)
    {
        printf("%s - %.2f %s\n", p[i].product_name, p[i].price, p[i].product_symbol);
    }
}

void cadastrar_compra(Employe e, Products *p, int total)
{
    if (e.active)
    {
        printf("\n%s está cadastrando uma compra...\n", e.name);
        list_productos(p, total);
    }
    else
    {
        printf("Não foi possivel cadastrar a compra. Este funcionário não existe ou não está ativo.\n");
    }
}

void cadastrar_funcionario(Employe *e)
{
    printf("\nCadastrar funcionario\n");
    printf("Insira o seu nome por favor: ");
    scanf(" %[^\n]", e->name);
    printf("Insira uma password forte: ");
    scanf(" %[^\n]", e->password);

    if (strlen(e->password) < 6)
    {
        printf("A senha é muito fraca!\n");
        e->active = false;
    }
    else
    {
        e->active = true;
        printf("Empregado %s cadastrado com sucesso!\n", e->name);
    }
}

int main()
{
    Employe e;
    Products produtos[] = {
        {"Pão", 1.50, "🍞"},
        {"Batata Frita", 3.00, "🍟"},
        {"Maçã", 2.20, "🍎"},
        {"Banana", 2.00, "🍌"},
        {"Tomate", 1.80, "🍅"}};

    cadastrar_funcionario(&e);
    cadastrar_compra(e, produtos, 5);

    return 0;
}
