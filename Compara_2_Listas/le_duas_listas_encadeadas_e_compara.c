#include <stdio.h>

int buscar_ultimo(MARATONISTA* i);
int adicionar_a_lista(MARATONISTA* novoMat, MARATONISTA* inicio);
void mostra_participantes(MARATONISTA* inicio);
int fn_flag(MARATONISTA* candidato, MARATONISTA* lista);
int mostra_todos(MARATONISTA* inicio_l1, MARATONISTA* inicio_l2);



typedef struct participante {

    char nome[50];
    int num_inscr;
    struct participante* proximo;

}MARATONISTA;



int main() {

    MARATONISTA* lista_1 = NULL;
    MARATONISTA* lista_2 = NULL;
    MARATONISTA* novo = NULL;
    MARATONISTA mat;
    int opcao;


    do {
        printf("\n \n 1- Inserir competidores na lista 1");
        printf("\n 2- Inserir competidores na lista 2");
        printf("\n 3- Mostrar participantes da lista 1");
        printf("\n 4- Mostrar participantes da lista 2");
        printf("\n 5- Mostrar os participantes de ambas as provas");
        printf("\n \n 0- Para sair \n");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
        {
            printf(" Escreva o nome do participante: ");
            scanf("%s", &mat.nome);
            printf("\n Escreva seu numero de inscricao: ");
            scanf("%d", &mat.num_inscr);

            novo = &mat;

            lista_1 = adicionar_a_lista(novo, lista_1);
            break;

        }
        case 2:
        {
            printf(" Escreva o nome do participante: ");
            scanf("%s", &mat.nome);
            printf("\n Escreva seu numero de inscricao: ");
            scanf("%d", &mat.num_inscr);

            novo = &mat;

            lista_2 = adicionar_a_lista(novo, lista_2);
            break;

        }
        case 3:
        {
            mostra_participantes(lista_1);
            break;
        }
        case 4:
        {
            mostra_participantes(lista_2);
            break;
        }
        case 5:
        {
            mostra_todos(lista_1, lista_2);
            break;
        }
        }

    } while (opcao != 0);
}

/*###########################################################################################################*/

int buscar_ultimo(MARATONISTA* i) {

    MARATONISTA* ultimo = NULL;
    ultimo = i;

    while (ultimo->proximo != NULL)
    {
        ultimo = ultimo->proximo;
    }

    return ultimo;
}

/*###########################################################################################################*/

int adicionar_a_lista(MARATONISTA* novoMat, MARATONISTA* inicio) {

    MARATONISTA* novo, * ultimo;


    novo = malloc(sizeof(MARATONISTA));
    novo->num_inscr = novoMat->num_inscr;
    strcpy(novo->nome, novoMat->nome);

    novo->proximo = NULL;

    if (inicio == NULL) {

        inicio = novo;
    }
    else {
        ultimo = buscar_ultimo(inicio);
        ultimo->proximo = novo;
    }
    return inicio;
}

/*###########################################################################################################*/

void mostra_participantes(MARATONISTA* inicio) {

    MARATONISTA* aux = inicio;
    if (inicio == NULL) {
        printf("Lista vazia");
        return;
    }


    while (aux != NULL)
    {
        printf("\n %d - %s", aux->num_inscr, aux->nome);
        aux = aux->proximo;
    }

    return;
}

/*###########################################################################################################*/

int fn_flag(MARATONISTA* candidato, MARATONISTA* lista)
{
    MARATONISTA* aux = lista;

    while (aux != NULL)
    {
        if (aux->num_inscr == candidato->num_inscr)
            return 1;

        aux = aux->proximo;
    }

    return 0;



}

/*###########################################################################################################*/

int mostra_todos(MARATONISTA* inicio_l1, MARATONISTA* inicio_l2)
{
    MARATONISTA* aux_l1 = inicio_l1;
    MARATONISTA* aux_l2 = inicio_l2;

    int flag = 0;
    if (aux_l1 != NULL && aux_l2 != NULL)
    {

        while (aux_l1 != NULL)
        {

            flag = fn_flag(aux_l1, aux_l2);

            if (flag == 1) 
                printf("\n %d - %s", aux_l1->num_inscr, aux_l1->nome);

            aux_l1 = aux_l1->proximo;

        }

    }
    else printf("Lista vazia \n");
}
