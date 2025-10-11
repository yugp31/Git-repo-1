#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtFront(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else 
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}
void insertAtEnd(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else 
    {
        struct Node* current = *head;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}
void deleteLastNode(struct Node** head) 
{
    if (*head == NULL) 
    {
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) 
    {
        current = current->next;
    }
    if (current->prev != NULL) 
    {
        current->prev->next = NULL;
    } else 
    {
        *head = NULL;
    }
    free(current);
}
void deleteBeforePosition(struct Node** head, int position) 
{
    if (*head == NULL || position <= 2) 
    {
        return;
    }
    struct Node* current = *head;
    int i;
    for (i = 0; i < position - 3; i++) 
    {
        if (current->next == NULL) 
        {
            return;
        }
        current = current->next;
    }
    struct Node* temp = current->prev;
    if (temp != NULL) 
    {
        temp->next = current->next;
    }
    if (current->next != NULL) 
    {
        current->next->prev = temp;
    }
    free(current);
}
void display(struct Node* head) 
{
    struct Node* current = head;
    while (current != NULL) 
    {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void menu()
{
    struct Node* head = NULL;
    int choice, data, position;
    restart:
    printf("\nPress 1 to Insert at front\n");
    printf("Press 2 to Insert at end\n");
    printf("Press 3 to Delete last node\n");
    printf("Press 4 to Delete node before specified position\n");
    printf("Press 5 to Display doubly linked list\n");
    printf("Press 6 to Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) 
    {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtFront(&head, data);
            goto restart;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            goto restart;
        case 3:
            deleteLastNode(&head);
            goto restart;
        case 4:
            printf("Enter position: ");
            scanf("%d", &position);
            deleteBeforePosition(&head, position);
            goto restart;
        case 5:
            display(head);
            goto restart;
        case 6:
            printf("Exit.\n");
            break;
        default:
            printf("Wrong Choice.\n");
            goto restart;
    }
}
int main() 
{
    menu();
    system("PAUSE");
    return 0;
}