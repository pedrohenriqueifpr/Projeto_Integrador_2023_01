#include "biblioteca.h"

int menu(){
    int opcao;
    printf("\nSelecione uma das opcoes abaixo\n");
    printf("--------------\n");
    printf("|    Menu    |\n");
    printf("--------------\n");
    printf("|1 - Produtos|\n");
    printf("|2 - Vendas  |\n");
    printf("|3 - Sair    |\n");
    printf("--------------\n");
    do{
        printf("Digite a opcao desejada:");
        scanf("%i",&opcao);
        getchar();
    if(opcao<1||opcao>3)
        printf("\nOpcao Invalida\n\n");
    }while(opcao<1||opcao>3);
    return opcao;
}

void menuProdutos(char *loop){
    int opcao = 0;
    while(*loop=='s'&&*loop!='n'){
    printf("\nSelecione uma das opcoes abaixo\n");
    printf("----------------\n");
    printf("|   Produtos   |\n");
    printf("----------------\n");
    printf("|1 - Exibir    |\n");
    printf("|2 - Cadastrar |\n");
    printf("|3 - Atualizar |\n");
    printf("|4 - Excluir   |\n");
    printf("|5 - Voltar    |\n");
    printf("----------------\n");
    do{
        printf("Digite a opcao desejada:");
        scanf("%i",&opcao);
        getchar();
    if(opcao<1||opcao>5)
        printf("\nOpcao Invalida\n\n");
    }while(opcao<1||opcao>5);
        switch (opcao){
        case 1:
            exibirProdutos();
            validaLoop(loop);
        break;
        case 2:
            cadastrarProdutos();
        break;
        case 3:
            atualizarProdutos();
            validaLoop(loop);
        break;
        case 4:
            excluirProdutos();
            validaLoop(loop);
        break;
        case 5:
            return;
        break;
        }
    }
}

void menuVendas(char *loop){
    int opcao = 0;
    while(*loop=='s'&&*loop!='n'){
    printf("\nSelecione uma das opcoes abaixo\n");
    printf("----------------\n");
    printf("|    Vendas    |\n");
    printf("----------------\n");
    printf("|1 - Realizar  |\n");
    printf("|2 - Relatorio |\n");
    printf("|3 - Voltar    |\n");
    printf("----------------\n");
    do{
        printf("Digite a opcao desejada:");
        scanf("%i",&opcao);
        getchar();
    if(opcao<1||opcao>3)
        printf("\nOpcao Invalida\n\n");
    }while(opcao<1||opcao>3);
        switch (opcao){
        case 1:
            realizarVendas();
            validaLoop(loop);
        break;
        case 2:
            relatorioVendas();
            validaLoop(loop);
        break;
        case 3:
            return;
        break;
        }
    }
}

void validaLoop(char *loop){
    do{
        printf("\nVoce deseja continuar usando o programa? s ou n:");
        scanf("%c",loop);
        getchar();
        if(*loop!='s'&&*loop!='n'&&*loop!='S'&&*loop!='N')
            printf("Opcao Invalida");
    }while(*loop!='s'&&*loop!='n'&&*loop!='S'&&*loop!='N');
}

void exibirProdutos(){
    printf("\nDe uma olhada nos itens do catalogo\n");
    printf("---------------------------------------------------\n");
    printf("|Codigo  |Nome dos  itens     |Preco   |Quantidade|\n");
    printf("---------------------------------------------------\n");
    for(int i = 0;i<qtditens;i++)
        printf("|%-8i|%-20s|%-8.2f|%-10i|\n",itens[i].codigo,itens[i].nome,itens[i].preco,itens[i].quantidade);
    printf("---------------------------------------------------\n");
}

void cadastrarProdutos(){
    char loop = 's';
    int erro = 0;
    while(loop == 's'||loop == 'S'){

        itens = realloc(itens,(qtditens + 1) * sizeof(berenice_itens));
        relatorio = realloc(relatorio,(qtditens + 1) * sizeof(berenice_vendas));

        if (itens == NULL) {
            printf("\nErro na alocacao de memoria\n");
            return;
        }

        do{
            printf("\nDigite o codigo do novo item:");
            scanf("%i",&itens[qtditens].codigo);
            getchar();

            if(itens[qtditens].codigo<0){
                printf("\nCodigo digitado invalido!\n");
                erro=1;
            }
            else{
                erro=0;

                for(int i=0;i<qtditens;i++){
                    if(itens[i].codigo==itens[qtditens].codigo){
                        printf("\nEsse codigo ja existe\n");
                        erro=1;
                    }
                }
            }
        }while(erro==1);

        do{
            printf("Digite o nome do novo item:");
            fgets(itens[qtditens].nome, sizeof(itens[qtditens].nome),stdin);
            itens[qtditens].nome[strcspn(itens[qtditens].nome, "\n")] = '\0';
            fflush(stdin);

            erro=0;

            for(int i=0;i<qtditens;i++){
                if(strcmp(itens[i].nome,itens[qtditens].nome) == 0){
                    printf("\nEsse nome ja existe\n\n");
                    erro=1;
                }
            }
            if(itens[qtditens].nome[0]=='\0'){
                printf("\nNome vazio deve ser preenchido\n\n");
                erro=1;
            }
        }while(erro==1);

        do{
            printf("Digite o preco do novo item:");
            scanf("%f",&itens[qtditens].preco);
            getchar();
            if(itens[qtditens].preco<=0)
                printf("\nPreco inserido invalido\n\n");
        }while(itens[qtditens].preco<=0);

        do{
            printf("Digite a quantidade do novo item:");
            scanf("%i",&itens[qtditens].quantidade);
            getchar();
            if(itens[qtditens].quantidade<=0)
                printf("\nQuantidade inserida invalida\n\n");
        }while(itens[qtditens].quantidade<=0);

        printf("\nItem adicionado com sucesso!\n");
        relatorio[qtditens].codigo = itens[qtditens].codigo;
        strcpy(relatorio[qtditens].nome,itens[qtditens].nome);
        relatorio[qtditens].preco = itens[qtditens].preco;
        relatorio[qtditens].quantidade = 0;
        qtditens++;

        do{
            printf("\nVoce quer cadastrar mais um item? s ou n:");
            scanf("%c",&loop);
            getchar();
            if(loop!='s'&&loop!='n'&&loop!='S'&&loop!='N')
                printf("Opcao Invalida");
        }while(loop!='s'&&loop!='n'&&loop!='S'&&loop!='N');

        int auxi;
    float auxf;
    char auxc[21];
    for (int i = 0;i<qtditens;i++) {
        for (int j = 0;j<qtditens;j++) {
            if (itens[i].codigo<itens[j].codigo){
                auxi = itens[i].codigo;
                itens[i].codigo = itens[j].codigo;
                itens[j].codigo = auxi;

                strcpy(auxc,itens[i].nome);
                strcpy(itens[i].nome,itens[j].nome);
                strcpy(itens[j].nome,auxc);

                auxf = itens[i].preco;
                itens[i].preco = itens[j].preco;
                itens[j].preco = auxf;

                auxi = itens[i].quantidade;
                itens[i].quantidade = itens[j].quantidade;
                itens[j].quantidade = auxi;
            }
        }
    }
    }
}



void atualizarProdutos (){
    int codigo, indice = -1;
    char confirmacao;
    int quantidade;
    float preco;

    exibirProdutos();

    printf("\nDigite o codigo do produto que deseja atualizar:");
    scanf("%d", &codigo);
    getchar();

    for (int i = 0; i < qtditens; i++) {
        if (itens[i].codigo == codigo) {
            indice = i;
        }
    }

    if (indice != -1) {
        printf("\nCodigo: %i", itens[indice].codigo);
        printf("\nNome: %s", itens[indice].nome);
        printf("\nPreco: %.2f", itens[indice].preco);
        printf("\nQuantidade: %i", itens[indice].quantidade);


            do{
                printf("\n\nDigite o novo preco do item:");
                scanf("%f",&preco);
                getchar();
                if(preco<=0)
                    printf("\nPreco inserido invalido\n\n");
            }while(preco<=0);

            do{
                printf("\nDigite a nova quantidade do item:");
                scanf("%i",&quantidade);
                getchar();
                if(quantidade<=0)
                    printf("\nQuantidade inserida invalida\n\n");
            }while(quantidade<=0);

            printf("\n*****Antes*****");
            printf("\nCodigo: %i", itens[indice].codigo);
            printf("\nNome: %s", itens[indice].nome);
            printf("\nPreco: %.2f", itens[indice].preco);
            printf("\nQuantidade: %i", itens[indice].quantidade);

            printf("\n\n*****Depois*****");
            printf("\nCodigo: %i", itens[indice].codigo);
            printf("\nNome: %s", itens[indice].nome);
            printf("\nPreco: %.2f",preco);
            printf("\nQuantidade: %i",quantidade);

            printf("\n\nDeseja mesmo atualizar os dados desse produto? s ou n: ");
            scanf("%c", &confirmacao);
            getchar();

            if (confirmacao == 's' || confirmacao == 'S') {

                itens[indice].preco = preco;
                itens[indice].quantidade = quantidade;


                relatorio[qtditens].preco = preco;

                printf("\nProduto atualizado com sucesso!\n");
        } else {
            printf("\nProduto nao foi atualizado!\n");
        }
    } else {
        printf("\nProduto nao encontrado!\n");
    }
}

void excluirProdutos(){
    int codigo,indice=-1;
    char confirmacao;

    exibirProdutos();

    printf("\nDigite o codigo do produto que deseja excluir: ");
    scanf("%d", &codigo);
    getchar();

    for (int i = 0; i < qtditens; i++)
        if (itens[i].codigo == codigo)
            indice = i;

    if (indice != -1) {
        printf("\nCodigo: %i",itens[indice].codigo);
        printf("\nNome: %s",itens[indice].nome);
        printf("\nPreco: %.2f",itens[indice].preco);
        printf("\nQuantidade: %i",itens[indice].quantidade);
        printf("\n\nDeseja mesmo excluir esse produto? s ou n: ");
        scanf("%c", &confirmacao);
        getchar();

        if(confirmacao == 's'||confirmacao == 'S'){

        for (int i = indice; i < qtditens - 1; i++) {
            itens[i] = itens[i + 1];
            relatorio[i] = relatorio[i+1];
        }

        itens = realloc(itens, (qtditens - 1) * sizeof(berenice_itens));
        relatorio = realloc(relatorio, (qtditens - 1) * sizeof(berenice_vendas));

        if (itens == NULL||relatorio==NULL) {
            printf("\n\nErro na realocacao da memoria\n");
            return;
        }

        printf("\nProduto excluido com sucesso!\n");
        qtditens--;
        }
        else{
            printf("\nProduto nao foi excluido!\n");
        }
    } else {
        printf("\nProduto nao encontrado!\n");
    }
}

void salvarProdutos() {
    if(1==0){///Usar o conteudo desse if se nao possuir o arquivo bin com os itens iniciais
        qtditens = 5;
        itens = malloc(5 * sizeof(berenice_itens));
        itens[0].codigo = 1;
        strcpy(itens[0].nome, "Pao de Forma");
        itens[0].preco = 7.50;
        itens[0].quantidade = 0;

        itens[1].codigo = 2;
        strcpy(itens[1].nome, "Pao de Centeio");
        itens[1].preco = 8.69;
        itens[1].quantidade = 0;

        itens[2].codigo = 3;
        strcpy(itens[2].nome, "Broa de Milho");
        itens[2].preco = 5.00;
        itens[2].quantidade = 0;

        itens[3].codigo = 4;
        strcpy(itens[3].nome, "Sonho");
        itens[3].preco = 4.50;
        itens[3].quantidade = 0;

        itens[4].codigo = 5;
        strcpy(itens[4].nome, "Tubaina");
        itens[4].preco = 3.25;
        itens[4].quantidade = 0;
    }

    FILE *arquivobin = fopen("produtos.bin", "wb");

    if (arquivobin == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fwrite(&qtditens, sizeof(int), 1, arquivobin);
    fwrite(itens, sizeof(berenice_itens), qtditens, arquivobin);

    fclose(arquivobin);

    time_t t = time(NULL);
    struct tm *current_time = localtime(&t);

    char nomeArquivo[50];
    strftime(nomeArquivo, sizeof(nomeArquivo), "Relatorio %d_%m_%Y Horario %H_%M_%S.txt", current_time);

    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    float total;
    fprintf(arquivo,"---------------------------------------------------------------------------------\n");
    fprintf(arquivo,"|Codigo|Nome dos  itens     |QTD ATUAL  |QTD Vendida|Valor Unitario|SubTotal    |\n");
    fprintf(arquivo,"---------------------------------------------------------------------------------\n");
    for (int i = 0; i < qtditens; i++){
            relatorio[i].subtotal = relatorio[i].quantidade * relatorio[i].preco;
            fprintf(arquivo,"|%-6i|%-20s|%-11d|%-11d|R$%-12.2f|R$%-10.2f|\n",relatorio[i].codigo,relatorio[i].nome,itens[i].quantidade,relatorio[i].quantidade,relatorio[i].preco,relatorio[i].subtotal);
            total = total + relatorio[i].subtotal;
    }
    fprintf(arquivo,"---------------------------------------------------------------------------------\n");
    fprintf(arquivo,"|Total de todas as vendas                                          |R$%-10.2f|\n",total);
    fprintf(arquivo,"---------------------------------------------------------------------------------\n");

    fclose(arquivo);
    free(itens);
    free(relatorio);
}

void lerProdutos() {
    FILE *arquivo = fopen("produtos.bin", "rb");

    if (arquivo == NULL) {
        printf("Arquivo de produtos nao encontrado.\n");
        return;
    }

    fread(&qtditens, sizeof(int), 1, arquivo);

    itens = malloc(qtditens * sizeof(berenice_itens));
    if (itens == NULL) {
        printf("Erro na alocacao de memoria.\n");
        fclose(arquivo);
        return;
    }

    fread(itens, sizeof(berenice_itens), qtditens, arquivo);

    fclose(arquivo);

    relatorio = malloc(qtditens * sizeof(berenice_vendas));
    for(int i=0;i<qtditens;i++){
        relatorio[i].codigo = itens[i].codigo;
        strcpy(relatorio[i].nome , itens[i].nome);
        relatorio[i].preco = itens[i].preco;
        relatorio[i].quantidade = 0;
    }
}

void realizarVendas(){
    int item,quantidade,pagamento,parcelas,qtdvendas=0,indice = -1,aux;
    float recebido,troco,total,totalbruto;
    char loop = 's';
    berenice_vendas *cupom = malloc(sizeof(berenice_vendas));

        for(int i=0;i<qtditens;i++){
            if(itens[i].quantidade == 0){
                aux++;
            }
        }

        if(aux == qtditens){
            printf("\nNao e possivel realizar uma venda pois nao tem nenhum item em estoque\n");
            return;
        }

    while(loop=='s'&&loop!='n'){
        aux=0;
        for(int i=0;i<qtditens;i++){
            if(itens[i].quantidade == 0){
                aux++;
            }
        }

        if(aux == qtditens){
            printf("\nNao e possivel realizar mais uma venda pois nao tem nenhum item em estoque\n");
            break;
        }

        exibirProdutos();

        do{
            printf("\nDigite o codigo do item que voce deseja:");
            scanf("%i",&item);
            getchar();

            for(int i=0;i<qtditens;i++){
                if(itens[i].codigo==item){
                        indice = i;
                }
            }

            if(indice==-1)
                printf("Opcao Invalida");
            else if(itens[indice].quantidade<=0)
                printf("Nao tem itens para serem vendidos");
        }while(indice==-1||itens[indice].quantidade<=0);

        do{
            printf("\nDigite a quantidade de itens que voce deseja:");
            scanf("%i",&quantidade);
            getchar();

            if(quantidade<=0){
                printf("\nOpcao Invalida\n");
            }else if(itens[indice].quantidade<quantidade){
                printf("\nNao tem itens suficientes para serem comprados\n");
            }else if(itens[indice].quantidade>=quantidade){
                itens[indice].quantidade = itens[indice].quantidade - quantidade;
                break;
            }
        }while(quantidade<=0||itens[indice].quantidade<quantidade);


        realloc(cupom, (qtdvendas+1) * sizeof(berenice_vendas));
        cupom[qtdvendas].codigo = itens[indice].codigo;
        strcpy(cupom[qtdvendas].nome, itens[indice].nome);
        cupom[qtdvendas].preco = itens[indice].preco;
        cupom[qtdvendas].quantidade = quantidade;
        cupom[qtdvendas].subtotal = quantidade * itens[indice].preco;
        total = total + cupom[qtdvendas].subtotal;
        totalbruto = total;
        qtdvendas++;

        relatorio[indice].quantidade = quantidade;

        printf("\n**Cupom Fiscal**\n");
        printf("--------------------------------------------------------------------\n");
        printf("|Codigo|Nome dos  itens     |Quantidade|Valor Unitario|SubTotal    |\n");
        printf("--------------------------------------------------------------------\n");
        for (int i = 0; i < qtdvendas; i++)
            printf("|%-6i|%-20s|%-10d|R$%-12.2f|R$%-10.2f|\n",cupom[i].codigo,cupom[i].nome,cupom[i].quantidade,cupom[i].preco,cupom[i].subtotal);
        printf("--------------------------------------------------------------------\n");
        printf("|Total da venda atual:                                |R$%-10.2f|\n",total);
        printf("--------------------------------------------------------------------\n");
        do{
            printf("\nVoce deseja comprar outro item? s ou n:");
            scanf("%c",&loop);
            getchar();
            if(loop!='s'&&loop!='n'&&loop!='S'&&loop!='N')
                printf("Opcao Invalida");
        }while(loop!='s'&&loop!='n'&&loop!='S'&&loop!='N');
    }

        do{
        printf("\nQual seria a forma de pagamento desejada?");
        printf("\nDigite 1 para a vista e 2 para a prazo:");
        scanf("%i",&pagamento);
        getchar();
        if(pagamento!=1&&pagamento!=2)
            printf("Opcao Invalida\n");
        }while(pagamento!=1&&pagamento!=2);

    if (pagamento==1){
        if(total<=50.00){
            total = total - (total * 0.08);
            printf("\nCom o desconto de 8%% sua conta fica %.2f reais",total);
        }else if(total>50.00&&total<100.00){
            total = total - (total * 0.10);
            printf("\nCom o desconto de 10%% sua conta fica %.2f reais",total);
        }else if(total>=100.00){
            total = total - (total * 0.18);
            printf("\nCom o desconto de 18%% sua conta fica %.2f reais",total);
        }

        printf("\nDigite o valor recebido:");
        scanf("%f",&recebido);
        getchar();
        while(recebido<total){
            printf("\nDesculpe valor recebido invalido ou insuficiente digite novamente:");
            scanf("%f",&recebido);
            getchar();
        }

            if(recebido-total==0){
                printf("\nNao ha troco do pagamento\n");
            }else
                printf("\nDevolva de troco %.2f reais\n",recebido - total);
            printf("\nCompra concluida com sucesso :)\n");

        }else if(pagamento==2){
            int parcelas;
        printf("\nDigite a quantidade de parcelas:");
        scanf("%i",&parcelas);
        getchar();
        while(parcelas<=0){
            printf("Desculpe quantidade de parcelas inserida invalida digite novamente:");
            scanf("%i",&parcelas);
            getchar();
        }

        if(parcelas>0&&parcelas<=3){
            total = total + (total * 0.05);
            printf("\nCom o acrecimo de 5%% sua conta fica %.2f reais",total);
        }else if(parcelas>3){
            total = total + (total * 0.08);
            printf("\nCom o acrecimo de 8%% sua conta fica %.2f reais",total);
        }

        printf("\nSua conta parcelada em %i vezes\n",parcelas);
        printf("Deu um total de %.2f reais\n",total);
        printf("Cada parcela ira custar %.2f reais\n",total/parcelas);
        printf("Compra concluida com sucesso :)");

        free(cupom);
    }

    time_t t = time(NULL);
    struct tm *current_time = localtime(&t);

    char nomeArquivo[50];
    strftime(nomeArquivo, sizeof(nomeArquivo), "Cupom %d_%m_%Y Horario %H_%M_%S.txt", current_time);

    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(arquivo,"--------------------------------------------------------------------\n");
    fprintf(arquivo,"|Codigo|Nome dos  itens     |Quantidade|Valor Unitario|SubTotal    |\n");
    fprintf(arquivo,"--------------------------------------------------------------------\n");
    for (int i = 0; i < qtdvendas; i++)
        fprintf(arquivo,"|%-6i|%-20s|%-10d|R$%-12.2f|R$%-10.2f|\n",cupom[i].codigo,cupom[i].nome,cupom[i].quantidade,cupom[i].preco,cupom[i].subtotal);
    fprintf(arquivo,"--------------------------------------------------------------------\n");
    fprintf(arquivo,"|Total bruto da venda:                                |R$%-10.2f|\n",totalbruto);
    fprintf(arquivo,"--------------------------------------------------------------------\n");
    fprintf(arquivo,"|Total com desconto da venda:                         |R$%-10.2f|\n",total);
    fprintf(arquivo,"--------------------------------------------------------------------\n");

    fclose(arquivo);
}

void relatorioVendas(){
    float total;
    printf("\n**Relatorio de Vendas**\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("|Codigo|Nome dos  itens     |QTD Atual  |QTD Vendida|Valor Unitario|SubTotal    |\n");
    printf("---------------------------------------------------------------------------------\n");
    for (int i = 0; i < qtditens; i++){
            relatorio[i].subtotal = relatorio[i].quantidade * relatorio[i].preco;
            printf("|%-6i|%-20s|%-11d|%-11d|R$%-12.2f|R$%-10.2f|\n",relatorio[i].codigo,relatorio[i].nome,itens[i].quantidade,relatorio[i].quantidade,relatorio[i].preco,relatorio[i].subtotal);
            total = total + relatorio[i].subtotal;
    }
    printf("---------------------------------------------------------------------------------\n");
    printf("|Total de todas as vendas                                          |R$%-10.2f|\n",total);
    printf("---------------------------------------------------------------------------------\n");
}