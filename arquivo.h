#include <string.h>

// ------------------------------------------- A R Q U I V O S ----------------------------------------------------------
FILE *dadosDiarios;
FILE *ultId;
FILE *ultId2;
FILE *dadosTutor;
FILE *dadosClinica;
FILE *registroTutor;
FILE *vacinas; 
//TODO:
FILE *tela;//txt?
FILE *loja;//bin

//TODO: BUSCADOR DE LOGIN //bin

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
        printf("\n%d\n", size);
        fclose(ultId2); 

        if(size == -1){
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
    char arquivo[8];
    sprintf(arquivo, "pet%d.txt", animal[i].id);
    dadosDiarios = fopen(arquivo,"a");
    fprintf(dadosDiarios, "#%s$%.0f\n",data,codigo);
    fclose(dadosDiarios);
}

// -------- salva cadastro de usuário -------------------------------------------------------------------------------
void salvar(char tipodeusuario){
    char *arquivo = malloc(sizeof(char));

    if(tipodeusuario=='1'){
        sprintf(arquivo, "tutor%d.bin", dono.id);
        dadosTutor = fopen(arquivo, "ab");
        fwrite(&dono, sizeof(struct tutor), 1, dadosTutor);
        for(int i=0; i<dono.quantidade; i++){
            fwrite(&animal[i], sizeof(pet), 1, dadosTutor);
        }
        fclose(dadosTutor);
    }else{
        sprintf(arquivo, "clinica%d.bin", clinica.id);
        dadosClinica = fopen(arquivo, "ab");
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
    char arquivo[30];

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
    char arquivo[15], choice;
    int qtd, i;

    if(id<1000 && tipodeusuario==1){
        //------------- T U T O R ------------------
        sprintf(arquivo, "registro-Tutor%d.bin", dono.id);
        if(buscarRegistro(id, tipodeusuario, arquivo)==0){
            registroTutor = fopen(arquivo, "ab");
            fwrite(id, sizeof(int), 1, registroTutor);
            fclose(registroTutor);

            do{
                printf("Quantas vacinas deseja cadastrar?");
                printf("\nLembre-se de que voce pode realizar essa etapa uma unica vez!\n");
                printf("\n          escolha:");
                scanf("%c",&choice);
                qtd = choice -'0';
            }while(qtd<1 || qtd>50);

            vacina = malloc(qtd * sizeof(struct vacinas));

            sprintf(arquivo, "vacinas-pet%d.bin", id);
            vacinas = fopen(arquivo, "ab");

            obterVacinas(qtd);

            fclose(vacinas);
            cadastroRealizado();
        }
    }else{
        // ------------ C L Í N I C A --------------
        do{
            printf("\nQuantas vacinas deseja registrar?");
            scanf("%c",&choice);
            qtd = choice - '0';
        }while(qtd < 1 || qtd > 10);

        vacina = malloc(qtd * sizeof(struct vacinas));

        sprintf(arquivo, "vacinas-pet%d.bin", id);
        vacinas = fopen(arquivo, "ab");

        obterVacinas(qtd);
        
        fclose(vacinas);
        cadastroRealizado();
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

