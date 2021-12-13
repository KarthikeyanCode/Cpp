//single linked list 
#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

class node
{
    private:

    public:
        int data;
        node* next;

}*head=NULL;

void insert_beginning(node* Node)
{
    int data;
    cout << "Enter the data of the node" << "\n";
    cin >> data;
    Node->data = data;
    if(head == NULL)
    {
        head = Node;
        Node->next = NULL;
    }
    else
    {
        Node->next = head;
        head = Node;
    }
    cout << "Insertion Complete" << "\n";
}

void insert_end(node* Node)
{
    int data;
    cout << "Enter the data of the node" << "\n";
    cin >> data;
    Node->data = data;
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
        Node->next = NULL;
    }
    cout << "Insertion Complete" << "\n";
}

void Delete(int pos)
{
    int counter=1;
    node* n = head;
    node* prev = NULL;
    if(pos == 1)
    {
        if(head->next == NULL)
        {
            head = NULL;
            free(n);
            return;
        }
        head = n->next;
        free(n);
    }
    else
    {
        while(n->next != NULL)
        {
            if(counter == pos)
            {
                if(n->next == NULL)
                {
                    prev = NULL;
                    free(n);
                }
                else
                {
                    prev->next = n->next;
                    free(n);
                }
            }
            prev = n;
            n = n->next;
            counter++;
        }
    }
    cout << "Deletion Complete" << "\n";
}

void Display()
{
    node* n = head;
    if(n == NULL)
    {
        cout << "The linked list is empty" << "\n";
        return;
    }
    cout << "The linked list: " << "\n";
    while(n->next != NULL)
    {
        cout << n->data << " -> ";
        n = n->next;
    }
    cout << n->data << "\n";
}

int main(void)
{
    int option1, option2;
    int data, count, pos;
    while(1)
    {
        cout << "Choose:" << "\n";
        cout << "1.Insert" << "\n";
        cout << "2.Delete" << "\n";
        cout << "3.Print" << "\n";
        cout << "4.Exit" << "\n";
        cin >> option1;

        switch (option1)
        {
            case 1://insert
            {
                node* Node = (node*)malloc(sizeof(node));//initialising pointer object to instance of class
                cout << "Choose: " << "\n";
                cout << "1. Insert at beginning " << "\n";
                cout << "2. Insert at end" << "\n";
                cin >> option2;
                switch (option2)
                {
                    case 1://insert at beginning 
                    {
                        insert_beginning(Node);
                        break;
                    }
                    case 2://insert at end
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
            case 2://delete 
            {
                count = 1;
                if(head == NULL)
                {
                    cout << "Linked List is empty" << "\n";
                }
                else
                {
                    node* n = head;
                    while(n->next != NULL)
                    {
                        n = n->next;
                        count++;
                    }
                    cout << "Enter the position to delete" << "\n"; 
                    cin >> pos;
                    if(pos<=0 || pos>count)
                    {
                        cout << "index out of range" << "\n";
                        continue;
                    }
                    Delete(pos);
                }
                break;
            }
            case 3://print
            {
                Display();
                break;
            }
            case 4:
            {
                cout << "Thankyou" << "\n";
                goto exit;
            }
            default:
            {
                cout << "Enter only valid numbers" << "\n";
                continue;
            }
        }
    }
    exit:
    cout << "Closing the Porgram" << "\n";
    return 0;
}