#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtFront(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void insertAtEnd(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}
void insertInAscendingOrder(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (*head == NULL || data < (*head)->data) 
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < data) 
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}
void deleteFirstNode(struct Node** head) 
{
    if (*head == NULL) 
    {
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}
void deleteBeforePosition(struct Node** head, int position) 
{
    if (*head == NULL || position <= 2) 
    {
        return;
    }
    struct Node* current = *head;
    for (int i = 0; i < position - 3; i++) 
    {
        if (current->next == NULL) 
        {
            return;
        }
        current = current->next;
    }
    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}
void deleteAfterPosition(struct Node** head, int position) 
{
    if (*head == NULL || position <= 0) 
    {
        return;
    }
    if (position == 1 && (*head)->next != NULL) 
    {
        struct Node* temp = (*head)->next;
        free(*head);
        *head = temp;
        return;
    }
    struct Node* current = *head;
    for (int i = 0; i < position - 1; i++) 
    {
        if (current->next == NULL) 
        {
            return;
        }
        current = current->next;
    }
    if (current->next != NULL) 
    {
        struct Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}
void display(struct Node* head) 
{
    struct Node* current = head;
    while (current != NULL) 
    {
        printf("%d -> ", current->data);
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
    printf("Press 3 to Insert in ascending order\n");
    printf("Press 4 to Delete first node\n");
    printf("Press 5 to Delete node before specified position\n");
    printf("Press 6 to Delete node after specified position\n");
    printf("Press 7 to Display linked list\n");
    printf("Press 8 to Quit\n");
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
            printf("Enter data: ");
            scanf("%d", &data);
            insertInAscendingOrder(&head, data);
            goto restart;
        case 4:
            deleteFirstNode(&head);
            goto restart;
        case 5:
            printf("Enter position: ");
            scanf("%d", &position);
            deleteBeforePosition(&head, position);
            goto restart;
        case 6:
            printf("Enter position: ");
            scanf("%d", &position);
            deleteAfterPosition(&head, position);
            goto restart;
        case 7:
            display(head);
            goto restart;
        case 8:
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
