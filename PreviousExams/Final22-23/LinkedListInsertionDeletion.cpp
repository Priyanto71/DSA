#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

void display()
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data;
        if(temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }
    cout << " -> NULL\n";
}

void insertAtBeginning(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = head;

    head = newNode;
}

void insertAtEnd(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAfterThirdNode(int value)
{
    Node* temp = head;

    for(int i = 1; i < 3; i++)
    {
        temp = temp->next;
    }

    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = temp->next;

    temp->next = newNode;
}

void deleteFromBeginning()
{
    if(head == NULL)
        return;

    Node* temp = head;

    head = head->next;

    delete temp;
}

void deleteFromEnd()
{
    if(head == NULL)
        return;

    if(head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

void deleteThirdNode()
{
    Node* temp = head;

    for(int i = 1; i < 2; i++)
    {
        temp = temp->next;
    }

    Node* del = temp->next;

    temp->next = del->next;

    delete del;
}

int main()
{
    cout << "Insert 10 at start\n";

    insertAtEnd(20);
    insertAtEnd(30);

    display();

    insertAtBeginning(10);

    display();

    cout << "\nInsert 50 at end\n";

    insertAtEnd(50);

    display();

    cout << "\nInsert 40 after 3rd node\n";

    insertAfterThirdNode(40);

    display();

    cout << "\nDelete from start\n";

    head = NULL;

    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);

    display();

    deleteFromBeginning();

    display();

    cout << "\nDelete from end\n";

    head = NULL;

    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);

    display();

    deleteFromEnd();

    display();

    cout << "\nDelete 3rd node\n";

    head = NULL;

    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(50);
    insertAtEnd(60);

    display();

    deleteThirdNode();

    display();

    return 0;
}