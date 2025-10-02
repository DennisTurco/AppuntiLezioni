/*]
ARRAY:
    - statico
    - accesso diretto agli elementi (molto buono perche' veloce)
LIST:
    - dinamica
    - accesso sequenziale agli elementi (ci mette piu' tempo)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node_at_first(struct Node** head, int data) {
    struct Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void add_node_at_end(struct Node** head, int data) {
    struct Node* new_node = create_node(data);

    // controlliamo se la lista e' vuota
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
}

void add_node_by_pos() {
    return;
}

int get_index_from_data(struct Node** head, int wanted) {
    int index = 0;
    struct Node* temp = *head;
    while(temp != NULL) {
        if (temp->data == wanted) {
            return index;
        }
        index++;
        temp = temp->next;
    }
    return -1;
}

void print_list(struct Node** head) {
    struct Node* temp = *head;
    while(temp->next != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d -> NULL", temp->data);
}

int main () {

    struct Node* head = NULL;

    add_node_at_end(&head, 5);
    add_node_at_end(&head, 6);
    add_node_at_end(&head, 7);
    add_node_at_end(&head, 8);
    add_node_at_end(&head, 9);
    add_node_at_end(&head, 0);

    print_list(&head);

    int index = get_index_from_data(&head, 0);
    if (index == -1) {
        printf("\nL'elemento ricercato non e' presente nella lista\n");
    } else {
        printf("\nL'elemento si trova in posizione: %d\n", index);
    }

    add_node_at_first(&head, 10);

    print_list(&head);

    return 0;
}