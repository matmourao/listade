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

Node* copyNode(Node* no)
{
    Node* temp = newNode(no->payload);
    temp->next = no->next;
    temp->prev = no->prev;
    return temp;
}

void switchConsec(List* lista, Node* no1, Node* no2)
{
    if(no1->prev == nullptr)
    {
        lista->head = no2;
    }
    else no1->prev->next = no2; 
    
    if(no2->next == nullptr)
    {
        lista->tail = no1;
    }
    else no2->next->prev = no1; 
    
    Node* temp = copyNode(no1);
    no1->prev = no2; 
    no1->next = no2->next;
    no2->next = no1;
    no2->prev = temp->prev; 
    free(temp);
}

void swapNodes(List* lista, Node* no1, Node* no2)
{
    if(no1->next == no2)
    {
        switchConsec(lista, no1, no1->next);
        return;
    }
    if(no2->next == no1)
    {
        switchConsec(lista, no2, no2->next);
        return;
    }
    
    if(no1->prev == nullptr)
    {
        lista->head = no2;
    }
    else no1->prev->next = no2; 
    
    if(no1->next == nullptr)
    {
        lista->tail = no2;
    }
    else no1->next->prev = no2;
    
    if(no2->prev == nullptr)
    {
        lista->head = no1;
    }
    else no2->prev->next = no1;
    
    if(no2->next == nullptr)
    {
        lista->tail = no1;
    }
    else no2->next->prev = no1; 
    
    Node* temp = copyNode(no1);
    no1->prev = no2->prev; 
    no1->next = no2->next; 
    no2->prev = temp->prev; 
    no2->next = temp->next;
    free(temp);
}

int lenght(List* lista)
{
    int i=0;
    Node* temp = lista->head;
    while(temp != nullptr)
    {
        i++;
        temp = temp->next;
    }
    return i;
}

void swapIndex(List* lista, int index1, int index2)
{
    Node* temp1 = lista->head;
    for(int i=0; i<index1; i++)
    {
        temp1 = temp1->next;
    }
    Node* temp2 = lista->head;
    for(int i=0; i<index2; i++)
    {
        temp2 = temp2->next;
    }
    swapNodes(lista, temp1, temp2);
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

void insertionSort(List* lista)
{
    Node* temp = lista->head;

    while(temp->next != nullptr)
    {
        temp = temp->next;
        while(temp->payload<temp->prev->payload)
        {
            swapNodes(lista, temp, temp->prev);
            if(temp->prev==nullptr) break;
        }
    }
}

int main() {
    List* lista1 = newList();
    addHead(lista1, 1);
    addTail(lista1, 2);
    addHead(lista1, 3);
    addTail(lista1, 4);
    addHead(lista1, 5);
    printList(lista1);
    
    insertionSort(lista1);
    printList(lista1);
    reversePrint(lista1);
    
    return 0;
}
