/*  
    String Queue: 
    Queue of size 10 (can be changed by changing capacity value)
    Stores string of size 30 characters (can be changed by changing data size inside class)
    Operations: Enqueue, Dequeue, Display 
*/
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

#define capacity 10

class node
{
    private:
        
    public:
        char data[30];
        int index;
        node* next;

}*start=NULL;

int length(node* Node)
{
    int len=0;
    if(Node == NULL)
    {
        return 0;
    }
    len = length(Node->next);
    return len+1;
}

void Enqueue(node* Node)
{
    if(start == NULL)
    {
        start = Node;
        Node->index = 1; 
        //cout << "test" << "\n";
    }
    else
    {
        node* n = start;
        while(n->next != NULL)
        {
            n = n->next;
        }
        n->next = Node;
        Node->index = (n->index)+1;
    }
    Node->next = NULL;  
}

void Dequeue()
{
    node* n = start;
    node* prev;
    if(start->next == NULL)
    {
        start = NULL;
        return;
    }
    while(n->next != NULL)
    {
        prev = n;
        n = n->next;
    }
    prev->next = NULL;
    free(n);
}

void Display()
{
    node* n = start;
    cout << "The queue: " << "\n";
    while(n->next != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << n->data << "\n";
}

int main(void)
{
    int option, option1, option2;
    while(1)
    {
        cout << "Choose " << "\n";
        cout << "1. Enqueue" << "\n";
        cout << "2. Dequeue" << "\n";
        cout << "3. Display" << "\n";
        cout << "4. Exit" << "\n";
        cin >> option;
        switch(option)
        {
            case 1:
            {
                if(length(start) == capacity)
                {
                    cout << "The queue is full, dequeue to proceeed further" << "\n";
                    continue;
                }
                node* Node = (node*)malloc(sizeof(node));
                cout << "Enter the data in form of string (max 30 characters)" << "\n";
                cin >> Node->data;
                Enqueue(Node);
                break;
            }
            case 2:
            {
                if(start == NULL)
                {
                    cout << "Queue is empty" << "\n";
                    continue;
                }
                else
                {
                    Dequeue();
                }
                break;
            }
            case 3:
            {
                if(start == NULL)
                {
                    cout << "Queue is empty" << "\n";
                    continue;
                }
                Display();
                break;
            }
            case 4:
            {
                cout << "Thankyou" << "\n";
                goto Exit;
                break;
            }
            default:
            {
                cout << "Enter only valid numbers " << "\n";
                continue;
            }
        }
    }
    Exit:
    cout<< "Closing the program" << "\n";
    return 0;
}