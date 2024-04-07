#include "biblioteca.h"

int main(){
    lerProdutos();
    char loop = 's';
    printf("Bem vindo a Padaria da Berenice\n");
    while(loop=='s'&&loop!='n'){
        switch (menu()){
        case 1:
            menuProdutos(&loop);
        break;
        case 2:
            menuVendas(&loop);
        break;
        case 3:
            loop = 'n';
        break;
        }
    }
    printf("\nSaindo...\n");
    salvarProdutos();
    return 0;
}
