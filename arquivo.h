#include <string.h>

// ------------------------------------------- A R Q U I V O S ----------------------------------------------------------
//TODO:função geradora de arquivo


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