#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}; // define node structure for linked list.

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for a new node
    newNode->data = value;
    newNode->next = NULL; // Initially, the next node is NULL
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node **head, int value)
{
    struct Node *newNode = createNode(value); // Create a new node with the given value
    if (*head == NULL)
    {
        *head = newNode; // If the list is empty, the new node is the head
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next; // Traverse to the end of the list
    }
    temp->next = newNode; // Attach the new node at the end
}

// Function to print the linked list
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data); // Print the data of the current node
        temp = temp->next;            // Move to the next node
    }
    printf("NULL\n");
}

// Main function to test the linked list implementation
int main()
{
    struct Node *head = NULL; // Start with an empty list

    // Inserting nodes into the linked list
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    // Print the linked list
    printList(head);

    return 0;
}
