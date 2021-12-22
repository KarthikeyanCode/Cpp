//skip list

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N=3; //each 5 nodes there will be one node in express lane 
int find_node;

class node
{
    private:

    public:
    int data;
    node* next;
    node* express;
}*head=NULL;

void Express_lane()
{
    int counter=1;
    node* n = head;
    node* prev;
    while(n->next != NULL)
    {   
        n = n->next;
        counter++;
    }
    n = head;
    for(int i=0;i<counter;i++)
    {
        if(i%N==0)
        {
            if(i==0)
            {
                prev = n;
            }
            else
            {
                prev->express = n;
                prev = n;
            }
        }
        n = n->next;
    }
}

void insertion(node* Node)
{
    if(head == NULL)
    {
        head = Node;
    }
    else
    {
        node* n = head;
        while(n->next != NULL)
        {
            n = n->next;
        }
        n->next = Node;
    }
    Node->next = NULL;
    Node->express = NULL;
    Express_lane();
}

int search(node* Node)
{
    int flag=0;
    int index=1;
    if(head == NULL)
    {
        return 0;
    }
    node* n = head;
    while(n != NULL)
    {   
        if(find_node == n->data)
        {
            flag=1;
            break;
        }
        if(n->express != NULL)
        {
            if(find_node >= n->express->data)
            {
                n = n->express;
                index += N;
                continue;
            }
        }
        n = n->next;
        index++;
    }
    if(flag==1)
    {
        return index;
    }   
    else
    {
        return 0;
    }
}

void Display()
{
    if(head == NULL)
    {
        cout << "The linked list is empty" << "\n";
        return;
    }
    cout << "The linked list: " << "\n";
    node* n = head;
    while(n->next != NULL)
    {
        cout << n->data << " -> ";
        n = n->next;
    }
    cout << n->data << "\n";
    n = head;
    cout << "Express Lane: " << "\n";
    while(n->express != NULL)
    {
        cout << n->data << " -> ";
        n = n->express;
    }
    cout << n->data << "\n";
 }

int main(void)
{
    int opt,opt1;
    while(1)
    {
        cout << "Choose: " << "\n";
        cout << "1. insert" << "\n";
        cout << "2. Search" << "\n";
        cout << "3. Display" << "\n";
        cout << "4. Exit" << "\n";
        cin >> opt;
        switch (opt)
        {
            case 1:
            {
                node* Node = (node*)malloc(sizeof(node));
                cout << "Enter the data:" << "\n";
                cin >> Node->data;
                insertion(Node);
                break;
            }
            case 2:
            {
                cout << "Enter the data to search the node: " << "\n";
                cin >> find_node;
                int index = search(head);
                if(index == 0)
                {
                    cout << "The node was not found" << "\n";
                }
                else
                {
                    cout << "The element was found in index: " << index << "\n";
                }
                break;
            }
            case 3:
            {   
                Display();
                break;  
            }
            case 4:
            {
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

