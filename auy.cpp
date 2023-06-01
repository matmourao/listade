#include <iostream>

using namespace std;

struct Node
{
    string data;
    Node* next;
    Node* prev;
};

Node* newNode(string str)
{
    Node* ptrTemp = (Node*) malloc(sizeof(Node));
    ptrTemp -> next = nullptr;
    ptrTemp -> prev = nullptr;
    ptrTemp -> data = str;
    return ptrTemp;
}

bool is_valid(string str)
{
    char arrVogais[3] = {'A', 'U', 'Y'};
    char arrConsoantes[5] = {'B', 'J', 'S', 'R', 'T'};
    
    bool vogal = false;
    bool consoante = false;
    
    for(int j=0; j<3; j++)
    {
        if(str[0] == arrVogais[j])
        {
            vogal = true;
            break;
        }
    }
    if(!vogal)
    {
        for(int j=0; j<5; j++)
        {
            if(str[0] == arrConsoantes[j])
            {
                consoante = true;
                break;
            }
        }
    }
    if(!vogal && !consoante) return false;
    
    int i = 1;
    while(str[i] != '\0')
    {
        if(consoante)
        {
            for(int j=0; j<3; j++)
            {
                if(str[i] == arrVogais[j])
                {
                    vogal = true;
                    consoante = false;
                    break;
                }
            }
            if(consoante) return false;
        }
        
        else if(vogal)
        {
            for(int j=0; j<5; j++)
            {
                if(str[i] == arrConsoantes[j])
                {
                    consoante = true;
                    vogal = false;
                    break;
                }
            }
            if(vogal) return false;
        }
        
        if(i>7) return false;
        i++;
    }
    
    if(i>1) return true;
    else return false;
}

void insert(Node* head, string str)
{
    if(is_valid(str))
    {
        Node* ptrNew = newNode(str);
        Node* ptrTemp = head;
        
        while(ptrTemp->next != nullptr)
        {
            ptrTemp = ptrTemp->next;
        }
        
        ptrTemp->next = ptrNew;
        ptrNew->prev = ptrTemp;
    }
    else cout << "palavra invalida" << endl;
}

bool find(Node* head, string str)
{
    Node* ptrTemp = head;
    while(ptrTemp != nullptr)
    {
        if(str == ptrTemp->data) return true;
        ptrTemp = ptrTemp->next;
    }
    return false;
}

void del(Node** head, string str)
{
    Node* ptrDel = *head;
    while(ptrDel != nullptr)
    {
        if(str == ptrDel->data) break;
        ptrDel = ptrDel->next;
    }
    if(ptrDel->data != str)
    {
        cout << "a palavra nao esta na lista" << endl;
        return;
    }
    
    if((*head)->next == nullptr)
    {
        *head = nullptr;
    }
    else if(ptrDel == *head)
    {
        *head = ptrDel->next;
        (*head)->prev = nullptr;
    }
    else if(ptrDel->next == nullptr)
    {
        ptrDel->prev->next = nullptr;
    }
    else
    {
        ptrDel->prev->next = ptrDel->next;
        ptrDel->next->prev = ptrDel->prev;
    }
    free(ptrDel);
}

void print(Node* head)
{
    if(head == nullptr)
    {
        cout << "lista vazia" << endl;
        return;
    }
    
    Node* ptrTemp = head;
    while(ptrTemp->next != nullptr)
    {
        cout << ptrTemp->data << ", ";
        ptrTemp = ptrTemp->next;
    }
    cout << ptrTemp->data << endl;
}

bool comparison(string str1, string str2)
{
    //retorna true se str1 precede str2
    //retorna false caso contrario
    
    if(!is_valid(str1) || !is_valid(str1))
    {
        cout << "palavra(s) invalida(s)" << endl;
        return false;
    }
    
    char arrAlfabeto[8] = {'T', 'R', 'S', 'J', 'B', 'Y', 'U', 'A'};
    
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0')
    {
        int iVal1;
        int iVal2;
        
        for(int j=0; j<8; j++)
        {
            if(str1[i] == arrAlfabeto[j])
            {
                iVal1 = j;
            }
            if(str2[i] == arrAlfabeto[j])
            {
                iVal2 = j;
            }
        }
        if(iVal1 > iVal2) return true;
        if(iVal1 < iVal2) return false;
        
        i++;
    }
    
    return false;
}

int main()
{
    Node* head = newNode("ABUJY");
    insert(head, "PARALELEPIPEDO");
    cout << comparison("SURATURY", "TURA");
    
    return 0;
}
