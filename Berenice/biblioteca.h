#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>

typedef struct{
    int codigo;
    char nome[21];
    float preco;
    int quantidade;
}berenice_itens;

typedef struct{
    int codigo;
    char nome[21];
    float preco;
    int quantidade;
    float subtotal;
}berenice_vendas;

int menu();
void menuProdutos(char *loop);
void menuVendas(char *loop);
void validaLoop(char *loop);
void exibirProdutos();
void cadastrarProdutos();
void atualizarProdutos();
void excluirProdutos();
void salvarProdutos();
void lerProdutos();
void realizarVendas();
void relatorioVendas();

berenice_itens *itens;
berenice_vendas *relatorio;
int qtditens;

#endif // BIBLIOTECA_H_INCLUDED
