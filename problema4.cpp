#include <iostream>

using namespace std;

struct Node
{
    int id;
    bool is_alive;
    Node* next;
};

Node* newNode(int iVal)
{
    Node* ptrTemp = (Node*) malloc(sizeof(Node));
    ptrTemp -> is_alive = true;
    ptrTemp -> next = nullptr;
    ptrTemp -> id = iVal;
    return ptrTemp;
}

void print_alive(Node* no)
{
    Node* ptrTemp = no;
    while(!ptrTemp->is_alive)
    {
        ptrTemp = ptrTemp->next;
    }
    cout << ptrTemp->id;
    ptrTemp = ptrTemp->next;
    
    while(ptrTemp != no)
    {
        if(ptrTemp->is_alive)
        {
            cout << ", " << ptrTemp->id;
        }
        ptrTemp = ptrTemp->next;
    }
    cout << endl;
}

Node* newRoda(int n)
{
    //cria uma lista circular de 1 a n
    //retorna o ponteiro pro no 1
    Node* head = newNode(1);
    Node* ptrTemp = head;
    for(int i=2; i<=n; i++)
    {
        ptrTemp->next = newNode(i);
        ptrTemp = ptrTemp->next;
    }
    ptrTemp->next = head;
    return head;
}

void josefo(Node* head, int n, int k)
{
    //n: numero de rodadas
    //k: qual sera morto
    if(n == 0)
    {
        cout << "Sobrevivente(s): ";
        print_alive(head);
        return;
    }
    
    Node* ptrTemp = head;
    int i = 0;
    while(i < k-1)
    {
        ptrTemp = ptrTemp->next;
        if(ptrTemp->is_alive) i++;
    }
    ptrTemp->is_alive = false;
    cout << "Soldado " << ptrTemp->id << " morto" << endl;
    
    while(!ptrTemp->is_alive)
    {
        ptrTemp = ptrTemp->next;
    }
    josefo(ptrTemp, n-1, k);
}

int main()
{
    Node* head = newRoda(1234);
    print_alive(head);
    josefo(head, 1233, 233);

    return 0;
}
