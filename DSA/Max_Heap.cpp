//Max Heap

#include<iostream>
#include<string>

using namespace std;

class node
{
    private:

    public:

        int data;
        node* left;
        node* right;

}*root=NULL;
           
void insertion(node* Node, node* prev_Node)
{
    //insertion
    int temp;
    if(root == NULL)
    {
        root = Node;
    }
    else
    {
        if(Node->data < prev_Node->data)
        {
            if(prev_Node->left == NULL)
            {
                prev_Node->left = Node;
            }
            else
            {
                insertion(Node, prev_Node->left); 
            }
        }
        else
        {
            if(prev_Node->right == NULL)
            {
                prev_Node->right = Node; //prev Node 3
                temp = prev_Node->data;
                prev_Node->data = Node->data;
                Node->data = temp;
            }
            else
            {
                insertion(Node, prev_Node->right);//prev Node 6,4
                temp = prev_Node->data;
                prev_Node->data = prev_Node->right->data;
                prev_Node->right->data = temp;
            }
        }
    }
    Node->left = NULL;
    Node->right = NULL;
}

void Delete(int data, node* Node, node* prev_Node)
{
    if(Node->data == data)
    {
        if(Node->left == NULL && Node->right == NULL)//leaf node
        {
            if(Node == prev_Node->left)
            {
                prev_Node->left = NULL;
            }
            else
            {
                prev_Node->right = NULL;
            }
        } 
        else if(Node->left == NULL || Node->right == NULL) //node with 1 child 
        {
            if(Node->left == NULL)
            {
                if(Node == prev_Node->left)
                {
                    prev_Node->left = Node->right;
                }
                else
                {
                    prev_Node->right = Node->right;
                }
            }
            else
            {
                if(Node == prev_Node->left)
                {
                    prev_Node->left = Node->left;
                }
                else
                {
                    prev_Node->right = Node->left;
                }
            }
        }
        else //node with 2 childs
        {

        }
        return;
    }
    Delete(data, Node->left, Node);
    Delete(data, Node->right, Node);
}

void PostOrder(node* temp)
{
    if(temp != NULL)
    {
        PostOrder(temp->left);
        PostOrder(temp->right);
        cout << temp->data << " ";
    }
}

void InOrder(node* temp)
{
    if(temp != NULL)
    {
        InOrder(temp->left);
        cout << temp->data << " ";
        InOrder(temp->right);
    }
}

void preOrder(node* temp)
{
    if(temp != NULL)
    {
        cout << temp->data << " ";
        preOrder(temp->left);
        preOrder(temp->right);
    }
}

int main(void)
{
    int opt, opt1, opt2;
    int data;
    while(1)
    {
        cout << "Choose: " << "\n";
        cout << "1. Insertion" << "\n";
        cout << "2. Deletion" << "\n";
        cout << "3. Traversal" << "\n";
        cout << "4. Exit" << "\n";
        cin >> opt;

        switch(opt)
        {
            case 1:
            {
                node* Node = (node*)malloc(sizeof(node));
                cout << "Enter the data of the node" << "\n";
                cin >> Node->data;
                insertion(Node, root);
                break;
            }
            case 2:
            {
                cout << "Enter the data corresponding to the node to be deleted" << "\n";
                cin >> data;
                Delete(data, root, root);
                break;
            }
            case 3:
            {
                if(root == NULL)
                {
                    cout << "There are no elements in the tree" << "\n";
                    continue;
                }
                cout << "Choose:" << "\n";
                cout << "1. Pre-order" << "\n";
                cout << "2. In-order" << "\n";
                cout << "3. Post-order" << "\n";
                cin >> opt1;
                switch (opt1)
                {
                    case 1:
                        preOrder(root);
                    break;

                    case 2:
                        InOrder(root);
                    break;
                        
                    case 3:
                        PostOrder(root);
                    break;

                    default:
                        cout << "Enter only valid numbers" << "\n";
                        continue;
                    break;
                }
                cout << "\n";   
                break;
            }
            case 4:
            {
                cout << "Thankyou" << "\n";
                goto exit;
                break;
            }
            default:
            {
                cout << "Enter only the valid numbers " << "\n";
                continue;
            }
        }
    }
    exit:
    cout << "Closing the program" << "\n";
    return 0;
}

