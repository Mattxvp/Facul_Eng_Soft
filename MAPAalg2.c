//ATIVIDADE MAPA - ALGORITIMOS E LÓGICA DE PROGRAMAÇÃO 2
//Desenvolvido por: Mathias Prolla - 2021

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>


char nome[200];
char cpf[200];
char sexo[2];
int idade;
int main();



struct elemento {
    char pergunta[256];
    int pontuacao;
};

struct elemento questoes[] = {
    {.pergunta = "Tem febre: ", .pontuacao = 5},
    {.pergunta = "Tem dor de cabeça: ", .pontuacao = 1},
    {.pergunta = "Tem secreção nasal ou espirros: ", .pontuacao = 1},
    {.pergunta = "Tem dor/irritação na garganta: ", .pontuacao = 1},
    {.pergunta = "Tem tosse seca: ", .pontuacao = 3},
    {.pergunta = "Tem dificuldade respiratória: ", .pontuacao = 10},
    {.pergunta = "Tem dores no corpo: ", .pontuacao = 1},
    {.pergunta = "Tem diarréia: ", .pontuacao = 1},
    {.pergunta = "Esteve em contato, nos últimos 14 dias, com um caso diagnosticado com COVID-19: ", .pontuacao = 10},
    {.pergunta = "Esteve em locais com grande aglomeração: ", .pontuacao = 3},
};



void perguntas(){
    
    char resp;
    int soma = 0;
    int i = 0;

    FILE *arqTxt;
    arqTxt = fopen("dataBase.txt", "a");

    if (arqTxt==NULL)
    {
        printf("Erro ao criar arquivo");
    }

    system("cls");
    printf("Responda as perguntas abaixo com S(sim) ou N(não)\n");
    printf("--------------------------------------------------\n");
    
    for(i = 0; i < 10; i++){
        printf("%s", questoes[i].pergunta);
        scanf("%c", &resp);
        fflush(stdin);
        fprintf(arqTxt, "%s %c\n", questoes[i].pergunta, resp);
        if(resp == 'S' || resp == 's') {
            soma = soma + questoes[i].pontuacao;
            
        }
    }

    fprintf(arqTxt, "Pontuação total: %d", soma);
    fclose(arqTxt);
    system("cls");
    if(soma >= 0 && soma < 10){
        printf("Você somou %d pontos e deve se encaminhar para a ala de Baixo Risco", soma);
    }
    if(soma >= 10 && soma < 20){
        printf("Você somou %d pontos e deve se encaminhar para a ala de Médio Risco", soma);
    }
    if(soma >= 20){
        printf("Você somou %d pontos e deve se encaminhar para a ala de ALto Risco", soma);
    }

    soma = 0;

    printf("\nPressione ENTER para voltar ao Menu Principal..");
    getchar();
    main();
}


void cadastrarPaciente(){

    setlocale(LC_ALL, "portuguese");

    FILE *arqTxt;
    arqTxt = fopen("dataBase.txt", "a");

    if (arqTxt==NULL)
    {
        printf("Erro ao criar arquivo");
    }

    printf("\nQual o nome do Paciente: ");
    scanf("%s", nome);
    fflush(stdin);

    printf("\nQual o CPF do Paciente: ");
    scanf("%s", cpf);
    fflush(stdin);

    printf("\nQual o Sexo do Paciente (M/F): ");
    scanf("%s", sexo);
    fflush(stdin);

    printf("\nQual a idade do Paciente: ");
    scanf("%d", &idade);
    fflush(stdin);

    fprintf(arqTxt, "Nome: %s\nCPF: %s\nSexo: %s\nIdade: %d", nome, cpf, sexo, idade);
    fclose(arqTxt);

    printf("Dados salvos!\n");
    getchar();
    perguntas();
}






int main() {

    int opcao;

    printf("----------MENU PRINCIPAL----------\n");
    printf(" 1 - Cadastrar Paciente \n ");
    printf(" 2 - Sair \n ");
    printf("Escolha uma opção -> \n");
    scanf("%i", &opcao);
    fflush(stdin);

    switch(opcao) {
        case 1:
            cadastrarPaciente();
            break;
        case 2:
            printf("\n Finalizando o programa..");
            break;
        default:
            
            break;
    }
}

