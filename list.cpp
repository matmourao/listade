#include <iostream>
using namespace std;

struct Node
{
    int payload;
    Node* next;
    Node* prev;
};

struct List
{
    Node* head;
    Node* tail;
};

Node* newNode(int data)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp -> next = nullptr;
    temp -> prev = nullptr;
    temp -> payload = data;
    return temp;
}


List* newList()
{
    List* temp = (List*) malloc(sizeof(List));
    temp -> head = nullptr;
    temp -> tail = nullptr;
    return temp;
}

void addHead(List* lista, int data)
{
    Node* temp = newNode(data);
    temp -> next = lista -> head;
    
    if(lista -> head == nullptr)
    {
        lista->head = temp;
        lista->tail = temp;
        return;
    }
    
    lista -> head -> prev = temp;
    lista -> head = temp;
}

void addTail(List* lista, int data)
{
    Node* temp = newNode(data);
    temp -> prev = lista -> tail;
    
    if(lista -> tail == nullptr)
    {
        lista->head = temp;
        lista->tail = temp;
        return;
    }
    
    lista -> tail -> next = temp;
    lista -> tail = temp;
}

void printList(List* lista)
{
    if(lista->head == nullptr)
    {
        cout << "Lista vazia!" << endl;
        return;
    }
    
    Node* temp = lista->head;
    while(temp->next != nullptr)
    {
        cout << temp->payload << " - ";
        temp = temp->next;
    }
    cout << temp->payload << endl;
}

void delHead(List* lista)
{
    if(lista->head == nullptr)
    {
        cout << "Lista já vazia!" << endl;
        return;
    }
    
    Node* temp = lista->head;
    lista->head = temp->next;
    lista->head->prev = nullptr;
    free(temp);
}

void delTail(List* lista)
{
    if(lista->tail == nullptr)
    {
        cout << "Lista já vazia!" << endl;
        return;
    }
    
    Node* temp = lista->tail;
    lista->tail = temp->prev;
    lista->tail->next = nullptr;
    free(temp);
}

void reversePrint(List* lista)
{
    if(lista->tail == nullptr)
    {
        cout << "Lista vazia!" << endl;
        return;
    }
    
    Node* temp = lista->tail;
    while(temp->prev != nullptr)
    {
        cout << temp->payload << " - ";
        temp = temp->prev;
    }
    cout << temp->payload << endl;
}

void insertAfter(List* lista, Node* no, int data)
{
    Node* temp = newNode(data);
    temp->prev = no;
    temp->next = no->next;
    if(no->next != nullptr)
    {
        no->next->prev = temp;
    }
    else lista->tail = temp;
    no->next = temp;
}

int main() {
    List* lista1 = newList();
    addHead(lista1, 1);
    addTail(lista1, 2);
    addHead(lista1, 3);
    delHead(lista1);
    delTail(lista1);
    printList(lista1);
    
    return 0;
}
