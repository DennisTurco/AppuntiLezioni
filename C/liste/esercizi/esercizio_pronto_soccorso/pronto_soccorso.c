#include <stdio.h>
#include <stdlib.h>

typedef struct Paziente {
    char* nome;
    int priorita; // 1 = massima, 2 = media, 3 = bassa
} Paziente;

typedef struct Node {
    Paziente paziente;
    struct Node* next;
    struct Node* prev;
} Node;

void estrai_paziente(Node **head) {
    if (*head == NULL) {
        printf("Nessun paziente in lista.\n");
        return;
    }

    Node* da_estrarre = *head;
    *head = da_estrarre->next;
    if (*head != NULL)
        (*head)->prev = NULL;

    printf("Paziente: %s (priorita' %d)\n", da_estrarre->paziente.nome, da_estrarre->paziente.priorita);

    free(da_estrarre);
}

Node* crea_nodo(Paziente paziente) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->paziente = paziente;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void aggiungi_in_testa(Node **head, Node *nuovo_nodo) {
    nuovo_nodo->next = *head;
    if (*head != NULL)
        (*head)->prev = nuovo_nodo;
    *head = nuovo_nodo;
}

// vogliamo che l'aggiunta, sia un aggiunta ordinata per priorita
void aggiungi_paziente(Node **head, Paziente paziente) {
    Node* nuovo_node = crea_nodo(paziente);

    // lista vuota
    if (*head == NULL) {
        *head = nuovo_node;
        return;
    }

    Node* temp = *head;
    // troviamo il punto dove inserire in base alla priorita'
    while (temp->next != NULL && temp->paziente.priorita <= paziente.priorita) {
        temp = temp->next;
    }

    if (temp == *head) { // caso in cui abbiamo un solo elemento nella lista
        aggiungi_in_testa(head, nuovo_node);
    } else if (head == NULL) { // inserimento in coda
        Node* tail = *head;
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = nuovo_node;
        nuovo_node->prev = tail;
    } else { // inserimento in mezzo
        Node* before = temp->prev;
        nuovo_node->next = temp;
        nuovo_node->prev = before;
        before->next = nuovo_node;
        temp->prev = nuovo_node;
    }
}

void stampa_lista(Node **head) {
    if (*head == NULL) {
        printf("(vuota)\n");
        return;
    }

    Node* temp = *head;
    while (temp != NULL) {
        printf("[%s, priorita' %d]", temp->paziente.nome, temp->paziente.priorita);
        if (temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}

int main () {
    Node *head = NULL;

    Paziente p1; p1.nome = "Mario Franchi"; p1.priorita = 3;
    Paziente p2; p2.nome = "Giorgio Lini"; p2.priorita = 2;
    Paziente p3; p3.nome = "Maria Gini"; p3.priorita = 1;
    Paziente p4; p4.nome = "Frisi Pini"; p4.priorita = 1;
    Paziente p5; p5.nome = "Luigia Masu"; p5.priorita = 3;

    aggiungi_paziente(&head, p1);
    aggiungi_paziente(&head, p2);
    aggiungi_paziente(&head, p3);
    aggiungi_paziente(&head, p4);
    aggiungi_paziente(&head, p5);

    stampa_lista(&head);

    for (int i = 0; i < 5; i++) {
        estrai_paziente(&head);
    }

    stampa_lista(&head);

    return 0;
}