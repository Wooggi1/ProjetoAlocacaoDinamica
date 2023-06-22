#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 1000

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

static void createListHead();
int generateID();
int validateEmail(char email[]);
int validateSex(char sexo[]);
int validateHeight(double height);
int validateVaccine(int vaccine);
static void createUser();
//static int displayList();


int nodeCounter;

int main () {

    createListHead();
    //displayList();
    return 0;
}

static void createListHead(){
    struct node *newNode;
    int nodeID, nodeVaccine;
    char nodeName[100], nodeEmail[100], nodeSex[20], nodeAddress[100];
    double nodeHeight;

    startNode = (struct node*)malloc(sizeof(struct node));

    printf("Digite os dados do primeiro no abaixo\n");
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
    

    startNode->ID = generateID();
    strcpy(startNode->name, nodeName);
    strcpy(startNode->email, nodeEmail);
    strcpy(startNode->sex, nodeSex);
    strcpy(startNode->address, nodeAddress);
    startNode->height = nodeHeight;
    startNode->vaccine = nodeVaccine;
    startNode->PtrNext = NULL;
    nodeBuffer = startNode;

    printf("%d\n%s\n%s\n%s\n%s\n%.2f\n%d\n%p", startNode->ID, startNode->name, startNode->email, startNode->sex, startNode->address, startNode->height, startNode->vaccine, (void*)startNode->PtrNext);
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

static void addUser(){

}

//static int displayList(){
//    struct node *nodeBuffer;
//    nodeBuffer = startNode;

//    if(nodeBuffer == NULL){
//        printf("List is empty");
//        return 0;
//    }
//    else{
        
//        while (nodeBuffer != NULL)
//        {
            
//            printf("DATA: %d \n", nodeBuffer->data);
            
//            nodeBuffer = nodeBuffer->PtrProximo;
//        }
//    }
//}
