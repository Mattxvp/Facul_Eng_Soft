//ATIVIDADE 1 - ALGORITIMOS E LÓGICA DE PROGRAMAÇÃO 1
//Desenvolvido por: Mathias Prolla - 2021

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

//_______________________________________________________________________

int vJoao = 0, vMaria = 0, vZe = 0, vVotoNulo = 0, vInvalido = 0;
int pZureta = 0, pGomes = 0, pVotoNulo = 0, pInvalido = 0;

int main() {

    setlocale(LC_ALL,"Portuguese");

    int opcao_menu = 0, opcao_vereador = 0, opcao_prefeito = 0;
    system("cls");

    printf("||||||||| MENU PRINCIPAL ||||||||||||\n");
    printf("\n");
    printf(" 1 - VOTAR \n");
    printf(" 2 - APURAÇÃO DOS VOTOS \n");
    printf(" 3 - SAIR \n");
    printf("-------------------------------------\n");
    printf("DIGITE O QUE VOCÊ DESEJA --> ");  
    scanf("%i", &opcao_menu);
    fflush(stdin);

    switch (opcao_menu)
    {
    case 1:
        system("cls");
        printf("||||||||| VOTAÇÃO-VEREADOR |||||||||\n");
        printf("\n");
        printf("111 - Vereador Joao do Frete\n");
        printf("222 - Vereador Maria da Pamonha\n");
        printf("333 - Vereador Ze da Farmacia\n");
        printf("444 - Voto nulo\n");
        printf("-----------------------------");
        printf("\n");
        printf("QUAL O SEU VOTO PARA VEREADOR? --> ");
        scanf("%i", &opcao_vereador);
        fflush(stdin);
        switch(opcao_vereador)
        {
            case 111:
                printf("Voto confirmado em Vereador Joao do Frete!\n");
                vJoao = vJoao + 1;
                break;
            case 222:
                printf("Voto confirmado em Vereador Maria da Pamonha!\n");
                vMaria = vMaria + 1;
                break;
            case 333:
                printf("Voto confirmado em Vereador Ze da Farmacia!\n");
                vZe = vZe + 1;
                break;
            case 444:
                printf("Voto nulo!\n");
                vVotoNulo = vVotoNulo + 1;
                break;
            
            default:
            printf("Este voto é invalido!\n");
            vInvalido = vInvalido + 1;
            break;
        }
        
        system("pause");
        system("cls");
        printf("||||||||| VOTAÇÃO-PREFEITO |||||||||\n");
        printf("\n");
        printf("11 - Para Pr. Dr. Zureta\n");
        printf("22 - Para Pr. Senhor Gomes\n");
        printf("44 - Voto nulo\n");
        printf("-----------------------------");
        printf("\n");
        printf("QUAL O SEU VOTO PARA PREFEITO? --> ");
        scanf("%i", &opcao_prefeito);
        fflush(stdin);
        switch(opcao_prefeito)
        {
            case 11:
                printf("Voto confirmado em Prefeito Dr. Zureta!\n");
                pZureta = pZureta + 1;
                break;
            
            case 22:
                printf("Voto confirmado em Prefeito Senhor Gomes!\n");
                pGomes = pGomes + 1;
                break;
            case 44:
                printf("Voto Nulo!\n");
                pVotoNulo = pVotoNulo + 1;
                break;
            default:
                printf("Voto inválido!\n");
                pInvalido = pInvalido + 1;
                printf("Opção inválida!");
                break;
            
        }
        
        system("pause");
        main();
        break;

    case 2:
        system("cls");
        printf("||||||||| APURAÇÃO DOS VOTOS ||||||||||\n");
        printf("\n");
        printf("--------- VEREADORES ----------\n");
        printf("Vereador Joao do Frete 111: %d votos.\n", vJoao);
        printf("Vereador Maria da Pamonha 222: %d votos.\n", vMaria);
        printf("Vereador Ze da Farmacia 333: %d votos.\n", vZe);
        printf("Votos Nulos 444: %d votos.\n", vVotoNulo);
        printf("Votos Inválidos: %d votos.\n", vInvalido);
        printf("\n");
        printf("--------- PREFEITOS -----------\n");
        printf("Prefeito Dr. Zureta 11: %d votos.\n", pZureta);
        printf("Prefeito Senhor Gomes 22: %d votos.\n", pGomes);
        printf("Votos Nulos 44: %d votos.\n", pVotoNulo);
        printf("Votos Inválidos: %d votos.\n", pInvalido);
        printf("---------------------------------------\n");
    
        system("pause");
        main();
        break;
    
    case 3:
        printf("Finalizando o programa ...");
        break;
    default:
        printf("Não entendi o que você quis dizer, tente novamente..");
        system("cls");
        system("pause");
        fflush(stdin);
        main();
        break;

    }
}


