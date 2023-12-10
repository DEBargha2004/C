#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

int insertAtBeginning(int data);
int deleteFromBeginning();
int display();
int insertAtEnd(int data);
int deleteFromEnd();
int insertAt(int position, int data);
int deleteAt(int position);

int main()
{
    int choice, data, position;
    while (choice != 4)
    {
        printf("\n1. Insert at beginning\n2. Delete from beginning\n3. Display\n4. Exit\n5.Insert at end\n6.Delete from end\n7.Insert at position\n8.Delete from\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
        case 2:
            deleteFromBeginning();
            break;
        case 3:
            display();
            break;
        case 5:
            printf("Enter the data: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 6:
            deleteFromEnd();
            break;
        case 7:
            printf("Enter the position: ");
            scanf("%d", &position);
            printf("Enter the data: ");
            scanf("%d", &data);
            insertAt(position, data);
        case 8:
            printf("Enter the position: ");
            scanf("%d", &position);
            deleteAt(position);
        default:
            break;
        }
    }
}

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    return newNode;
}

int insertAtBeginning(int data)
{
    struct node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;

    return 0;
}

int deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        head = head->next;
    }
    return 0;
}

int display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    return 0;
}

int insertAtEnd(int data)
{
    struct node *newNode = createNode(data);
    struct node *temp = head;
    if (temp == NULL)
    {
        insertAtBeginning(data);
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
    return 0;
}

int deleteFromEnd()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty");
    }
    else
    {
        if (temp->next == NULL)
        {
            head = NULL;
        }
        else
        {
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
        }
    }
    return 0;
}

int insertAt(int position, int data)
{
    int currentPosition = 0;
    struct node *currentNode;
    struct node *newNode = createNode(data);
    struct node *temp = head;
    if (temp == NULL)
    {
        if (position == 1)
        {
            insertAtBeginning(data);
        }
        else
        {
            printf("Invalid position1");
        }
    }

    else
    {
        if (position == 1)
        {
            insertAtBeginning(data);
        }
        else
        {
            while (currentPosition < position - 1)
            {
                if (temp != NULL)
                {
                    currentNode = temp;
                    temp = temp->next;
                    currentPosition++;
                }
                else
                {
                    currentNode = temp;
                    break;
                }
            }
            if (currentNode == NULL)
            {
                printf("Invalid position2");
            }
            else
            {
                struct node *nextNode = currentNode->next;
                currentNode->next = newNode;
                newNode->next = nextNode;
            }
        }
    }
    return 0;
}

int deleteAt(int position)
{
    int currentPosition = 0;
    struct node *currentNode;
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty");
    }

    else
    {
        if (position == 1)
        {
            deleteFromBeginning();
        }
        else
        {
            while (currentPosition < position - 1)
            {
                if (temp != NULL)
                {
                    currentNode = temp;
                    temp = temp->next;
                    currentPosition++;
                }
                else
                {
                    currentNode = temp;
                    break;
                }
            }
            if (currentNode == NULL)
            {
                printf("Invalid position");
            }
            else
            {
                struct node *nextNode = currentNode->next;
                currentNode->next = nextNode->next;
            }
        }
    }
    return 0;
}