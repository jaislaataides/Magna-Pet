#include <string.h>

// ------------------------------------------- A R Q U I V O S ----------------------------------------------------------
FILE *dadosDiarios;
FILE *ultId;
FILE *ultId2;
FILE *dadosTutor;
FILE *dadosClinica;
FILE *registroTutor;
FILE *vacinas; 
FILE *telaTutor;
FILE *logins;
FILE *loja;
FILE *plantao;

char arquivo[30], dataDoRegistro[10];


//---- gera id sequencial dos animais ----------------------------------------------------------------------------------
int  gerarID1(){
    int ID;
        fseek(ultId, 0, SEEK_END);
        int size = ftell(ultId);
        fclose(ultId); 

        if(size == -1){
            ultId = fopen("UltimaID.txt", "w");
            fprintf(ultId, "%d", 1);
            fclose(ultId);
        }else{
        ultId = fopen("UltimaID.txt", "r");
        fscanf(ultId, "%d", &ID);
        ID++;
        fclose(ultId);
        ultId = fopen("UltimaID.txt","w");
        fprintf(ultId, "%d",ID);
        fclose(ultId);
        }
    return ID;
}

//---- gera id sequencial dos usuários ----------------------------------------------------------------------------------
int  gerarID2(){
    int ID;
        fseek(ultId2, 0, SEEK_END);
        int size = ftell(ultId2);
        fclose(ultId2); 

        if(size == -1 || size == 0){
            ultId2 = fopen("UltimaID2.txt", "w");
            fprintf(ultId, "%d", 1000);
            fclose(ultId2);
        }else{
        ultId2 = fopen("UltimaID2.txt", "r");
        fscanf(ultId2, "%d", &ID);
        ID++;
        fclose(ultId2);
        ultId2 = fopen("UltimaID2.txt","w");
        fprintf(ultId2, "%d",ID);
        fclose(ultId2);
        }
    return ID;
}

//------- armazena dados diários dos pets --------------------------------------------------------------------------
void armazenarDiario(int i, char *data, float codigo){
    sprintf(arquivo, "pet%d.txt", animal[i].id);
    dadosDiarios = fopen(arquivo,"a");
    fprintf(dadosDiarios, "%s$%.0f\n",data,codigo);
    fclose(dadosDiarios);
}

// -------- salva cadastro de usuário -------------------------------------------------------------------------------
void salvar(char tipodeusuario){

    if(tipodeusuario=='1'){
        sprintf(arquivo, "tutor%d.bin", dono.id);
        dadosTutor = fopen(arquivo, "wb");
        fwrite(&dono, sizeof(struct tutor), 1, dadosTutor);
        for(int i=0; i<dono.quantidade; i++){
            fwrite(&animal[i], sizeof(pet), 1, dadosTutor);
        }
        fclose(dadosTutor);
    }else{
        sprintf(arquivo, "clinica%d.bin", clinica.id);
        dadosClinica = fopen(arquivo, "wb");
        fwrite(&clinica, sizeof(struct clinica), 1, dadosClinica);
        for(int i=0; i<clinica.quantidade; i++){
            fwrite(&vet[i], sizeof(veterinarios), 1, dadosClinica);
        }
        fclose(dadosClinica);
    }
    cadastroRealizado();
}

// ----------- salva cadastro de usuário -------------------------------------------------------------------------------
void salvarPet(char tipodeusuario){

    if(tipodeusuario=='1'){
        sprintf(arquivo, "tutor%d.bin", dono.id);
        dadosTutor = fopen(arquivo, "ab");

        for(int i=0; i<dono.quantidade; i++){
            fwrite(&animal[i], sizeof(pet), 1, dadosTutor);
        }

        fclose(dadosTutor);
    }else{
        sprintf(arquivo, "clinica%d.bin", clinica.id);
        dadosClinica = fopen(arquivo, "ab");

        for(int i=0; i<clinica.quantidade; i++){
            fwrite(&vet[i], sizeof(veterinarios), 1, dadosClinica);
        }

        fclose(dadosClinica);
    }
    cadastroRealizado();
}

// ------------ armazena vacinas ----------------------------------------------------------------------------------------
void cadastrarVacina(int id, int tipodeusuario, int petEscolhido){

    int qtd;

    if(id<1000 && tipodeusuario==1){
        //------------- T U T O R ------------------
        sprintf(arquivo, "registro-Tutor%d.bin", dono.id);
        if(buscarRegistro(id, tipodeusuario, arquivo)==0){
            registroTutor = fopen(arquivo, "ab");
            fwrite(id, sizeof(int), 1, registroTutor);
            fclose(registroTutor);

            do{
                criaMenuLinhaSuperior();
                criaMenuItem(STRTAM, " ");
                criaMenuItem(STRTAM, "         Quantas vacinas deseja cadastrar?");
                criaMenuItem(STRTAM, "      Lembre-se de que voce pode realizar essa");
                criaMenuItem(STRTAM, "                etapa uma unica vez!");
                criaMenuItem(STRTAM, " ");
                criaMenuLinhaRodape(STRTAM);
                criaMenuItem(STRTAM, " ");
                printf("\n\n                   escolha:");
                scanf("%c",&escolha);
                qtd = escolha -'0';
            }while(qtd<1 || qtd>50);

            vacina = malloc(qtd * sizeof(struct vacinas));

            sprintf(arquivo, "vacinas-pet%d.bin", id);
            vacinas = fopen(arquivo, "ab");

            obterVacinas(qtd);

            fclose(vacinas);

            cadastroRealizado();

            system("pause");
            printf("\n\n");
            criaMenuLinhaSuperior();
            criaMenuItem(STRTAM, "      Voce sera direcionado ao menu");
            criaMenuLinhaRodape(STRTAM);
            system("pause");

        }else{
            criaMenuLinhaSuperior();
            criaMenuItem(STRTAM, " ");
            criaMenuItem(STRTAM, "                   OPS!");
            criaMenuItem(STRTAM, " ");
            criaMenuItem(STRTAM, "      Parece que voce ja cadastrou");
            criaMenuItem(STRTAM, "        vacinas para esse pet...");
            criaMenuItem(STRTAM, " ");
            criaMenuItem(STRTAM, "       Agora so um profissional da");
            criaMenuItem(STRTAM, "     saude animal pode inserir vacinas");
            criaMenuItem(STRTAM, " ");
            criaMenuLinhaRodape(STRTAM);
            system("pause");
            printf("\n\n");
            criaMenuLinhaSuperior();
            criaMenuItem(STRTAM, "      Voce sera direcionado ao menu");
            criaMenuLinhaRodape(STRTAM);
            system("pause");
        }
    }else{
        // ------------ C L Í N I C A --------------
        do{
                criaMenuLinhaSuperior();
                criaMenuItem(STRTAM, " ");
                criaMenuItem(STRTAM, "         Quantas vacinas deseja cadastrar?");
                criaMenuItem(STRTAM, " ");
                criaMenuLinhaRodape(STRTAM);
                criaMenuItem(STRTAM, " ");
                printf("\n\n                   escolha:");
                scanf("%c",&escolha);
            qtd = escolha - '0';
        }while(qtd < 1 || qtd > 10);

        vacina = malloc(qtd * sizeof(struct vacinas));

        sprintf(arquivo, "vacinas-pet%d.bin", id);
        vacinas = fopen(arquivo, "ab");

        obterVacinas(qtd);
        
        fclose(vacinas);
        cadastroRealizado();

        system("pause");
        printf("\n\n");
        criaMenuLinhaSuperior();
        criaMenuItem(STRTAM, "      Voce sera direcionado ao menu");
        criaMenuLinhaRodape(STRTAM);
        system("pause");
    }
}

//------ obtém informações das vacinas ----------------------------------------------------------------------------------
void obterVacinas(int qtd){
    for (int i=0; i<qtd; i++){
        //obter nome da vacina, dose e data
        fflush(stdin);
        printf("\nEscreva o nome da %d vacina: ");
        fgets(vacina[i].nome, 40, stdin);
        printf("\n Escreva a data no formato dd/mm/aaaa");
        fflush(stdin);
        fgets(vacina[i].data, 10, stdin);
        printf("\nEscreva o numero da dose");
        scanf("%d",&vacina[i].dose);
        fwrite(&vacina[i], sizeof(struct vacinas), 1, vacinas);
    }
}

// ------- busca registro de inserção de vacina por id ------------------------------------------------------------------
int buscarRegistro(int id, int tipodeusuario, char *arquivo){
    int log;
    registroTutor = fopen(arquivo, "rb");
    while(!feof (registroTutor)){
        fread(&log, sizeof(int), 1, registroTutor);
        if(log==id){
            return 1;
        }
    }
    return 0;
}

// ---------- limpa e notifica ------------------------------------------------------------------------------------------
void limpaENotifica(int setaNotificacao){
    char notificacao[300];
    system("cls");
    fflush(stdin);
    sprintf(arquivo, "tutor-%d.txt", dono.id);
    //setanotificacao = 1
    if(tipodeusuario=='1' && setaNotificacao==1){
        telaTutor = fopen(arquivo, "r");
        fscanf(telaTutor, "%s", notificacao);
        fclose(telaTutor);
        criaMenuLinhaSuperior();
        criaMenuItem(STRTAM, "                  LEMBRETE        ");
        criaMenuItem(STRTAM, " ");
        criaMenuLinhaRodape(STRTAM);
        printaNotificacao(notificacao);
    }else if(tipodeusuario == '2'){
        telaTutor = fopen(arquivo, "w");
        printf("Escreva a notificacao a seguir com espaço e sem enter: ");
        fgets(notificacao, 300, stdin);
        fwrite(notificacao, 300, 1, telaTutor);
        fclose(telaTutor);
    }else if(regulador>0 && tipodeusuario == '1'){
        printf("\n ---------------------------------------------");
        printf("\n|             OLA, BEM VINDO(A)!              |");
        printf("\n|          Nao se esqueca de registrar        |");
        printf("\n|        como foi o dia de seus bichinhos     |");
        printf("\n|                     hoje!                   |");
        printf("\n ---------------------------------------------");
    }
}

//exibição de mensagem fornecida pela clinica
void printaNotificacao(char *mensagem){
    int x;
    if(strlen(mensagem)>50){
        for (int i=0; mensagem[i]!='\0'; i++){
            if(i%40==0){
                x=i;
            }
            if(i>x && mensagem[i]==' '){
                mensagem[i] = '\n';
            }
        }
    }
    for(int i=0; mensagem[i]!='\0'; i++){
        if(mensagem[i-1]=='\n'){
            printf("%c", 200);
        }else{
        printf("%c",mensagem[i]);
        }
    }
}

//verifica se ha registro diario na data do sistema e em caso negativo exibe mensagem de lembrete
void gerarNotificacaoDiario(){
    char dia[2], mes[2];
    dia[0] = data[0];
    dia[1] = data[1];
    mes[0] = data[3];
    mes[1] = data[4];
    buscadorPorData(dia, mes, animal[0].id);
}

//armazena as structs dos usuarios que se cadastraram
void historicoLogins(){
    logins = fopen("logins.bin", "ab");
    fwrite(&dono, sizeof(struct tutor), 1, logins);
    fclose(logins);
}

//cadastro de produtos
void cadastrarProdutos(){

    int qtd;

    printf("Quantos produtos deseja inserir?");
    scanf("%d",&qtd);

    produto = malloc(qtd * sizeof(vendas));

    loja = fopen("Produtos.bin", "ab");
    for(int i=0; i<qtd; i++){
        fflush(stdin);
        printf("\nInsira o nome do produto %d", i +1);
        fgets(produto[i].nome, 40, stdin); 
        printf("\nQual o codigo dele?");
        fgets(produto[i].codigo, 10, stdin);
        printf("\nQual a quentidade desse produaito no estoque: ");
        scanf("%d",&produto[i].estoque);
        printf("\nQual o preco de %s? ",produto[i].nome);
        scanf("%f",&produto[i].preco);
        fflush(stdin);
    }
    fclose(loja);
    free(produto);
}

//verifica se os dados de login informados pelo usuario ja foram cadastrados
int validaLogin(){
    struct tutor auxiliar;
    logins = fopen("logins.bin", "rb");
    while(!feof(logins)){
        fread(&auxiliar, sizeof(struct tutor), 1, logins);
        if(strcmp(auxiliar.email, dono.email)==0 && strcmp(auxiliar.senha, dono.senha)==0){
            fclose(logins);
            return 0;
        }
    }
    fclose(logins);
    return 1;
}

//primeira etapa da busca dos animais: encontrar seus donos
void listaUsuario(){
    struct tutor auxiliar;
    int i=0;
    logins = fopen("logins.bin", "rb");
    while(!feof(logins)){
        fread(&auxiliar, sizeof(struct tutor), 1, logins);
        printf("\n%d - %s",i,auxiliar.nome);
        i++;
    }
    parametro = i;
    fclose(logins);
}

//segunda etapa da busca dos animais: obter o id dos seus donos
int encontraIDUsuario(int escolha){
    struct tutor auxiliar;
    int i=0;
    logins = fopen("logins.bin", "rb");
    while(!feof(logins)){
        fread(&auxiliar, sizeof(struct tutor), 1, logins);
        if(i==escolha){
            return auxiliar.id;
        }
        i++;
    }
    fclose(logins);
    return 1;
}

//terceira etapa da busca dos animais: encontrar todos os animais do tutor com a id encontrada
void listaPetsPorTutor(int tutorID){

    pet auxiliar;
    i=0;
    sprintf(arquivo, "tutor%d.bin",tutorID);
    dadosTutor = fopen(arquivo, "rb");
    fseek(dadosTutor, sizeof(pet), sizeof(struct tutor));
    while(!feof){
        fread(&auxiliar, sizeof(pet), 1, dadosTutor);
        printf("        %d - %s",i,auxiliar.nomepet);
        i++;
    }
    parametro = i;
    fclose(dadosTutor);
}

//etapa final da busca dos animais: obter o id do animal desejado
int encontraPet(int escolha, int tutorID){

    pet auxiliar;
    i=0;
    sprintf(arquivo, "tutor%d.bin",tutorID);
    dadosTutor = fopen(arquivo, "rb");
    fseek(dadosTutor, sizeof(pet), sizeof(struct tutor));
    while(!feof){
        fread(&auxiliar, sizeof(pet), 1, dadosTutor);
        if(i==escolha){
            return auxiliar.id;
        }
        i++;
    }
    fclose(dadosTutor);
}

void buscadorPorData(char *dia, char *mes, int ID_Animal){
    char string[18];
    
    sprintf(arquivo, "pet-%d.txt", ID_Animal);
    dadosDiarios = fopen(arquivo, "r");
    while(!feof(dadosDiarios)){
        fread(&string, 18, 1, dadosDiarios);
        if(string[0]==dia[0] && string[1]==dia[1] && string[3]==mes[0] && string[4]==mes[1]){
            for(i=0, j=11; i<6, j<19; i++, j++){
                VetorAuxiliarCodigo[i] = string[j] - '0';
            }
        }
    }
    if (VetorAuxiliarCodigo[0] == 0 && tipodeusuario == '2'){
        criaMenuLinhaSuperior();
        criaMenuItem(STRTAM, " ");
        criaMenuItem(STRTAM, "       Nenhum registro desse pet foi ");
        criaMenuItem(STRTAM, "             encontrado nessa data");
        criaMenuItem(STRTAM, " ");
        criaMenuLinhaRodape(STRTAM);
    }else if(VetorAuxiliarCodigo[0] == 0 && tipodeusuario == '1'){

    }
    fclose(dadosDiarios);
    printaDadosDiarios(setanotificacao);
}

void buscadorPorTipo(int posicao, char valor, int ID_Animal){
    char string[18];

    sprintf(arquivo, "pet%d.txt", ID_Animal);
    dadosDiarios = fopen(arquivo, "r");
    while(!feof(dadosDiarios)){
        fread(&string, 18, 1, dadosDiarios);
        if(string[posicao]==valor){
            for(i=0; i<10; i++){
                dataDoRegistro[i] = string[i];
            }
        }
    }
    fclose(dadosDiarios);
    if(dataDoRegistro[0] == ' '){
        limpaENotifica(setanotificacao);
        criaForm();
        criaLinhaForm();
        printf("\nEssa caracteristica foi encontrada na data: %s",dataDoRegistro);
        criaMenuLinhaRodape(STRTAM);
    }
}

armazenarPlantonista(char *nomePlantonista){
    plantao = fopen("plantonista.txt","a");
    fwrite(&nomePlantonista, 30 * sizeof(char), 1, plantao);
    fprintf(plantao, "#%s\n",data);
    fclose(plantao);
}

// void mostrarPlantonista(){

// }

// void printaVacina(){

//     vacinas = fopen();
// }
//--------------------------------- M A N I P U L A Ç Ã O   D E   D A T A   ----------------------------------------------
//extrair data do sistema
//usar depois de set locale portugues
char *getData(){
    char **months;
    months = malloc(12 * sizeof(char*));
    for(int i = 0; i < 12; i++){
        months[i] = malloc(4 * sizeof(char));
    }
    //matriz de meses padrão
    months[0] = "Jan";
    months[1] = "Fev";
    months[2] = "Mar";
    months[3] = "Abr";
    months[4] = "Maio";
    months[5] = "Jun";
    months[6] = "Jul";
    months[7] = "Ago";
    months[8] = "Set";
    months[9] = "Out";
    months[10] = "Nov";
    months[11] = "Dez";

    //obtem data do sistema
    char *datinha = malloc(12 * sizeof(char));
    datinha = __DATE__;
    int mes, letra;
    char *mess = malloc (sizeof(char)), *data = malloc(10 *sizeof(char));


    for(int i=0; i<12; i++){
        int comparacao=0;
        letra=0;
        for (int j=0; j<4; j++){
            if(comparacao == 0 && datinha[j] != ' '){
                if(datinha[j]!=months[i][j]){
                    comparacao++;
                }else{
                    letra++;
                }
            }
        }
        if(comparacao == 0){
            mes=i+1;
            break;
        }
    }

    if(mes<10){
        mess[0] ='0';
    }else{
        mess[0] = ((int)mes/10) + '0';
    }
    mess[1] = mes%10 + '0';
    mess[2] = '\0';

    //atribuição da data com formato modificado para a string que será retornada
    if(datinha[letra+1]==' '){
        data[0] = '0';
    }else{
        data[0] = datinha[letra+1];
    }
    data[1] = datinha[letra+2];
    data[2] = '/';
    data[3] = mess[0];
    data[4] = mess[1];
    data[5] = '/';
    data[6] = datinha[letra+4];
    data[7] = datinha[letra+5];
    data[8] = datinha[letra+6];
    data[9] = datinha[letra+7];
    data[10] = '\0';

    return data;
}

