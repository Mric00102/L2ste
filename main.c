#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

void display(LinkedList* list);
void reset(LinkedList* list);
void append(LinkedList* list, int value);
void prepend(LinkedList* list, int value);
int popFront(LinkedList* list);
int popBack(LinkedList* list);
void insertAt(LinkedList* list, int position, int value);
void removeAt(LinkedList* list, int position);
void loadFromFile(LinkedList* list, const char* fileName);
void saveToFile(LinkedList* list, const char* fileName);

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

void display(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void reset(LinkedList* list) {
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
}

void append(LinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void prepend(LinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
}

int popFront(LinkedList* list) {
    if (list->head == NULL) return -1;
    Node* temp = list->head;
    int data = temp->data;
    list->head = list->head->next;
    free(temp);
    return data;
}

int popBack(LinkedList* list) {
    if (list->head == NULL) return -1;
    Node* current = list->head;
    if (current->next == NULL) {
        int data = current->data;
        free(current);
        list->head = NULL;
        return data;
    }
    while (current->next->next != NULL) {
        current = current->next;
    }
    Node* temp = current->next;
    int data = temp->data;
    current->next = NULL;
    free(temp);
    return data;
}

void insertAt(LinkedList* list, int position, int value) {
    if (position == 0) {
        prepend(list, value);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    Node* temp = list->head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position hors limite\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void removeAt(LinkedList* list, int position) {
    if (list->head == NULL) return;
    Node* temp = list->head;
    if (position == 0) {
        list->head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        return;
    }
    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void loadFromFile(LinkedList* list, const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return;
    }
    reset(list);
    int value;
    while (fscanf(file, "%d", &value) != EOF) {
        append(list, value);
    }
    fclose(file);
    printf("Liste chargée depuis le fichier %s.\n", fileName);
}

void saveToFile(LinkedList* list, const char* fileName) {
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return;
    }
    Node* current = list->head;
    while (current != NULL) {
        fprintf(file, "%d\n", current->data);
        current = current->next;
    }
    fclose(file);
    printf("Liste sauvegardée dans le fichier %s.\n", fileName);
}

int main() {
    LinkedList* list = createLinkedList();
    int choice, value, position;
    char fileName[256];

    printf("Gestionnaire de Liste Chaînée\n");
    while (1) {
        printf("\n1. Afficher la liste\n");
        printf("2. Ajouter un élément à la fin\n");
        printf("3. Ajouter un élément au début\n");
        printf("4. Supprimer un élément au début\n");
        printf("5. Supprimer un élément à la fin\n");
        printf("6. Insérer un élément à une position\n");
        printf("7. Supprimer un élément à une position\n");
        printf("8. Réinitialiser la liste\n");
        printf("9. Charger la liste depuis un fichier\n");
        printf("10. Sauvegarder la liste dans un fichier\n");
        printf("0. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(list);
                break;
            case 2:
                printf("Valeur à ajouter: ");
                scanf("%d", &value);
                append(list, value);
                break;
            case 3:
                printf("Valeur à ajouter: ");
                scanf("%d", &value);
                prepend(list, value);
                break;
            case 4:
                popFront(list);
                break;
            case 5:
                popBack(list);
                break;
            case 6:
                printf("Position: ");
                scanf("%d", &position);
                printf("Valeur à insérer: ");
                scanf("%d", &value);
                insertAt(list, position, value);
                break;
            case 7:
                printf("Position: ");
                scanf("%d", &position);
                removeAt(list, position);
                break;
            case 8:
                reset(list);
                printf("Liste réinitialisée.\n");
                break;
            case 9:
                printf("Nom du fichier: ");
                scanf("%255s", fileName);
                loadFromFile(list, fileName);
                break;
            case 10:
                printf("Nom du fichier: ");
                scanf("%255s", fileName);
                saveToFile(list, fileName);
                break;
            case 0:
                printf("Au revoir!\n");
                reset(list);
                free(list);
                return 0;
            default:
                printf("Choix invalide.\n");
        }
    }
}
