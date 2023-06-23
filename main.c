#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

struct node {
    int ID;
    char name[100];
    char email[100];
    char sex[20];
    char address[100];
    double height;
    int vaccine;
    struct node *PtrNext;
};

struct node *startNode;
struct node *nodeBuffer;

void addNodes();
void editNode();
void displayList();
int generateID();
int validateEmail(char email[]);
int validateSex(char sexo[]);
int validateHeight(double height);
int validateVaccine(int vaccine);
 


int nodeCounter = 0;

int main () {
    int option;

    do{
        printf("1 - Criar/Adicionar Nodes a lista\n");
        printf("2 - Editar dados do Node\n");
        printf("3 - Excluir Node\n");
        printf("4 - Listar dados do Node\n");
        printf("Digite a opcao: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            addNodes();
            break;
        case 2:
            editNode();
            break;
        case 4:
            displayList();
            break;
        default:
            break;
        }
    }while (option != 0);
    
    return 0;
}

void addNodes(){
    struct node *newNode;
    int nodeID, nodeVaccine;
    char nodeName[100], nodeEmail[100], nodeSex[20], nodeAddress[100];
    double nodeHeight;

    printf("Digite os dados do node abaixo\n");
    printf("Digite o nome completo: ");
    scanf(" %[^\n]", nodeName);
    printf("Digite o email: ");
    scanf(" %[^\n]", nodeEmail);

    while (validateEmail(nodeEmail) != 0) {
        printf("Tente novamente: ");
        scanf(" %[^\n]", nodeEmail);
    }

    printf("Digite o sexo (Masculino, Feminino ou Indiferente): ");
    scanf(" %[^\n]", nodeSex);
    nodeSex[0] = toupper(nodeSex[0]);

    while(validateSex(nodeSex) != 0){
        printf("Tente novamente: ");
        scanf(" %[^\n]", nodeSex);
        nodeSex[0] = toupper(nodeSex[0]);
    }

    printf("Digite o endereco: ");
    scanf(" %[^\n]", nodeAddress);
    printf("Digite a altura(Entre 1.0 e 2.0): ");
    scanf("%lf", &nodeHeight);

    while (validateHeight(nodeHeight) != 0){
        printf("Tente novamente: ");
        scanf("%lf", &nodeHeight);
    }

    printf("Digite o status de vacinacao (1 para sim 0 para nao): ");
    scanf("%d", &nodeVaccine);

    while (validateVaccine(nodeVaccine) != 0)
    {
        printf("Tente novamente: ");
        scanf("%d", &nodeVaccine);
    }
    
    if (nodeCounter == 0){
        startNode = (struct node*)malloc(sizeof(struct node));

        startNode->ID = generateID();
        strcpy(startNode->name, nodeName);
        strcpy(startNode->email, nodeEmail);
        strcpy(startNode->sex, nodeSex);
        strcpy(startNode->address, nodeAddress);
        startNode->height = nodeHeight;
        startNode->vaccine = nodeVaccine;
        startNode->PtrNext = NULL;
        nodeBuffer = startNode;
        nodeCounter = 1;
        printf("Node inicial criado com sucesso\n");
    }
    else{
        newNode = (struct node*)malloc(sizeof(struct node));
        
        newNode->ID = generateID();
        strcpy(newNode->name, nodeName);
        strcpy(newNode->email, nodeEmail);
        strcpy(newNode->sex, nodeSex);
        strcpy(newNode->address, nodeAddress);
        newNode->height = nodeHeight;
        newNode->vaccine = nodeVaccine;
        newNode->PtrNext = NULL;
        nodeBuffer->PtrNext = newNode;
        nodeBuffer = nodeBuffer->PtrNext;
        nodeCounter++;
        printf("Novo node adicionado a lista com sucesso\n");
    }
}

int generateID(){
    srand(time(NULL));

    int min = 10000;
    int max = 99999;
    int ID = (rand() % (max - min + 1)) + min;

    return ID;
}

int validateEmail(char email[]){

    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@'){
            return 0;
        }
    }
    printf("Email invalido\n");
    return 1;
}

int validateSex(char sex[]){
    if ((strcmp(sex, "Masculino") == 0 || strcmp(sex, "Feminino") == 0 || strcmp(sex, "Indiferente") == 0)){
        return 0;
    }
    else{
        printf("Sexo invalido\n");
        return 1;
    }
}

int validateHeight(double height){

    if (height >= 1 && height <= 2){
        return 0;
    }
    else{
        printf("Altura invalida\n");
        return 1;
    }
}

int validateVaccine(int vaccine){
    if (vaccine == 1 || vaccine == 0){
        return 0;
    }
    else{
        printf("Vacina invalida\n");
        return 1;
    }
}

void editNode(){
    struct node *nodeBuffer;
    char email[100];
    int found = 0;
    nodeBuffer = startNode;

    while(found != 1){
        printf("Digite o email do node que deseja editar: ");
        scanf(" %[^\n]", &email);
        if(nodeBuffer == NULL){
            printf("A lista esta vazia\n");
            return;
        }
        else if (strcmp(nodeBuffer->email, email) == 0){
            int option;
            found = 1;
            do{
                printf("1 - Editar nome\n");
                printf("2 - Editar sexo\n");
                printf("3 - Editar endereco\n");
                printf("4 - Editar altura\n");
                printf("5 - Editar status de vacinacao\n");
                printf("0 - Sair da edicao\n");
                printf("Opcao escolhida: ");
                scanf("%d", &option);

                switch (option)
                {
                case 1:
                    printf("Digite o novo nome: ");
                    scanf(" %[^\n]", nodeBuffer->name);
                    break;
                case 2:
                    char sex[20];
                    printf("Digite o novo sexo: ");
                    scanf(" %[^\n]", sex);
                    sex[0] = toupper(sex[0]);

                    while(validateSex(sex) != 0){
                        printf("Tente novamente: ");
                        scanf(" %[^\n]", sex);
                        sex[0] = toupper(sex[0]);
                    }

                    strcpy(nodeBuffer->sex, sex);
                    break;
                case 3:
                    printf("Digite o novo endereco: ");
                    scanf(" %[^\n]", nodeBuffer->address);
                    break;
                case 4:
                    double height;
                    printf("Digite a nova altura: ");
                    scanf("%lf", &height); 

                    while (validateHeight(height) != 0){
                        printf("Tente novamente: ");
                        scanf("%lf", &height);
                    }
                    break;
                case 5:
                    int vaccine;
                    printf("Digite o status de vacinacao novo: ");
                    scanf("%d", &vaccine);

                    while (validateVaccine(vaccine) != 0)
                    {
                        printf("Tente novamente: ");
                        scanf("%d", &vaccine);
                    };
                    break;
                case 0:
                    return;
                default:
                    printf("Valor invalido\n");
                    break;
                }
            }while(option != 0);
        }
        else{
            nodeBuffer = nodeBuffer->PtrNext;
        }
    }

}

void displayList(){
    struct node *nodeBuffer;
    nodeBuffer = startNode;
    int counter = 1;

    if(nodeBuffer == NULL){
        printf("A lista esta vazia\n");
        return;
    }
    else{
        
       while (nodeBuffer != NULL)
        {
            printf("-----------NODE %d-----------\n", counter);
            printf("ID: %d \n", nodeBuffer->ID);
            printf("Nome: %s\n", nodeBuffer->name);
            printf("Email: %s\n", nodeBuffer->email);
            printf("Sexo: %s\n", nodeBuffer->sex);
            printf("Endereco: %s\n", nodeBuffer->address);
            printf("Altura %.2f\n", nodeBuffer->height);
            printf("Status de vacinacao %d\n", nodeBuffer->vaccine);
            counter++;
            nodeBuffer = nodeBuffer->PtrNext;
        }
    }
}
