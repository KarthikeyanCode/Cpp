//Doubly linked list
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

class node
{
    private:

    public:

        int data;
        node* next;
        node* prev;

}*head=NULL;

void insert_beginning(node* Node)
{
    if(head == NULL)
    {
        head = Node;
        Node->next = NULL;
    }
    else
    {
        Node->next = head;
        head->prev = Node;
        head = Node;
    }
    cout << "Insertion Completed" << "\n";
}

void insert_end(node* Node)
{
    if(head == NULL)
    {
        head = Node;
        Node->next = NULL;    
    }
    else
    {
        node* n = head; 
        while(n->next != NULL)
        {
            n = n->next;
        }
        n->next = Node;
        Node->prev = n;
        Node->next = NULL;
    }
    cout << "Insertion Completed" << "\n";
}

void Delete(int pos)
{
    int counter=1;
    node* n = head;
    while(n->next != NULL)
    {
        if(counter == pos)
        {
            break;
        }
        n = n->next;
        counter++;
    }

    if(n->next == NULL)
    {
        if(counter == 1)
        {
            head = NULL;    
        }
        else
        {
            n->prev->next = NULL;
        }
        free(n);
    }
    else
    {
        if(pos == 1)
        {
            head = n->next;
        }
        else
        {
            n->prev->next = n->next;
            n->next->prev = n->prev;
        }
        free(n);
    }
    cout << "Deletion Completed" << "\n";
}
    

void Display()
{

    node* n = head;
    cout << "The linked list is: " << "\n";
    while(n->next != NULL)
    {
        cout << n->data << " -> ";
        n = n->next;
    }
    cout << n->data << "\n";
}

int length()
{
    int counter = 1;
    node* n = head;
    while(n->next != NULL)
    {
        n = n->next;
        counter++;
    }
    return counter;
}

int main(void)
{
    int option1, option2, data, pos, count;
    while(1)
    {
        cout << "Choose: " << "\n";
        cout << "1. Insert" << "\n";
        cout << "2. Delete" << "\n";
        cout << "3. Display" << "\n";
        cout << "4. Lenght" << "\n";
        cout << "5. Exit" << "\n";
        cin >> option1;
        switch (option1)
        {
            case 1: //insert
            {
                cout << "Enter the data of node" << "\n";
                cin >> data;
                node* Node = (node*)malloc(sizeof(node));
                Node->data = data;
                cout << "Choose" << "\n";
                cout << "1. Insert at beginning" << "\n";
                cout << "2. Insert at end" << "\n";
                cin >> option2;
                switch (option2)
                {
                    case 1:
                    {
                        insert_beginning(Node);
                        break;
                    }
                    case 2:
                    {
                        insert_end(Node);
                        break;
                    }
                    default:
                    {
                        cout << "Enter only valid numbers" << "\n";
                        continue;
                    }
                }
                break;
            }
            case 2: //Delete
            {
                count = 1;
                if(head == NULL)
                {
                    cout << "The linked list is empty" << "\n";
                    continue;   
                }
                cout << "Enter the position to delete from (index starts from 1)" << "\n";
                cin >> pos;
                node* n = head;
                while(n->next != NULL)
                {
                    n = n->next;
                    count++;
                }
                if(pos<=0 || pos>count)
                {
                    cout << "Index out of range" << "\n";
                    cout << "Enter valid index, checkout lenght of linked list" << "\n";
                    continue;
                }
                Delete(pos);
                break;
            }
            case 3: //Display
            {
                if(head == NULL)
                {
                    cout << "Linked List is empty" << "\n";
                    continue;
                }
                Display();
                break;
            }
            case 4: //length of linked list
            {
                if(head == NULL)
                {
                    cout << "Length: 0" << "\n"; 
                }
                else
                {
                    cout << "Lenght: " << length() << "\n";
                }
                break;
            }
            case 5: //Exit
            {
                cout << "Thankyou" << "\n";
                goto exit;
                break;
            }
            default:
            {
                cout << "Enter only valid numbers" << "\n";
                continue;
            }
        }
    }
    exit:
    cout << "Closing the program" << "\n";
    return 0;
}