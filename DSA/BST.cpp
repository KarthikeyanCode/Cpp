//sample trees DSA program 
//Binary tree 
#include<iostream>
#include<stdlib.h>
using namespace std;

//global variable
int num, presence;

class node
{
    private:
        //some code
    public:
        int data;
        node* left;
        node* right;        
}*root=NULL;

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

void insertion(node* Node, node* prevNode)
{
    if(Node->data < prevNode->data)//insert in left 
    {
        if(prevNode->left != NULL)
        {
            insertion(Node, prevNode->left);
        }
        else
        {
            prevNode->left = Node;
        }
    }
    else//insert in right 
    {
        if(prevNode->right != NULL)
        {
            insertion(Node, prevNode->right);
        }
        else
        {
            prevNode->right = Node;
        }
    }
    Node->left = NULL;
    Node->right = NULL;
}

int height(node* Node)
{
    if(Node == NULL)
    {
        return 0;
    }
    else if(Node->left == NULL && Node->right == NULL)
    {
        return 1;
    }
    else
    {
        int left_height = height(Node->left);
        int right_height = height(Node->right);

        if(left_height > right_height)
        {
            return (left_height+1);
        }        
        else
        {
            return (right_height+1);
        }
    }
}

int count(node* Node)
{
    if(Node == NULL)
    {
        return 0;
    }
    return (count(Node->left) + count(Node->right) + 1);
}

void rotate_left()
{
    node* prev_root;

    if(root->right == NULL)
    {
        cout << "rotate left not possible" << "\n";  
        return; 
    }
    
    //left rotation operation 
    prev_root = root;
    root = root->right;
    prev_root->right = root->left;
    root->left = prev_root;
}

void rotate_right()
{
    node* prev_root;

    if(root->left == NULL)
    {
        cout << "right rotate not possible" << "\n";
        return;
    }

    //rotate right operation
    prev_root = root;
    root = root->left;
    prev_root->left = root->right;
    root->right = prev_root;    
}

void search(node* Node)
{
    if(Node==NULL)
    {
        return;
    }
    if(Node->data == num)
    {
        presence++;
    }
    search(Node->left);
    search(Node->right);
}

int main(void)
{
    int option, option1, option2;
    while(1)
    {
        cout << "Choose:" << "\n";
        cout << "1. Insert a Node" << "\n";
        cout << "2. Traversal" << "\n";
        cout << "3. Height/Depth" << "\n";
        cout << "4. Count Nodes" << "\n";
        cout << "5. Rotate " << "\n";
        cout << "6. Search " << "\n";
        cout << "7. Exit" << "\n";
        cin >> option;
        switch (option)
        {
            case 1:
            {
                int value;
                cout << "Enter the value to insert" << "\n";
                cin >> value;
                //pointer object .. points to instance of the class
                //so we need to create and allocate memory with sizeof(class_name) 
                //and make the pointer object point to it
                node* Node = (node*)malloc(sizeof(node));
                Node->data = value;
                Node->left = NULL;
                Node->right = NULL;
                if(root == NULL)
                {
                    root = Node;
                    root->left = NULL;
                    root->right = NULL;
                }
                else
                {
                    insertion(Node, root);
                }
                cout << "Insertion completed" << "\n";
                break;
            }
                
            case 2:
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
                cin >> option1;
                switch (option1)
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
                
            case 3:
            {
                cout << "The height of the tree is : " << height(root) << "\n";
                break;
            }

            case 4:
            {
                cout << "Total Number of Leaf Nodes: " << count(root) << "\n";
                break;
            }

            case 5:
            {
                if(root==NULL)
                {
                    cout << "Tree is empty " << "\n";
                    continue;
                }
                if(root->right==NULL && root->left==NULL)
                {
                    cout << "only root node is present in the tree" << "\n";
                    continue;
                }
                cout << "Choose: " << "\n";
                cout << "1.Rotate left " << "\n";
                cout << "2.Rotate right " << "\n";
                cin >> option2;
                
                switch (option2)
                {
                    case 1:
                    {
                        rotate_left();
                        break;
                    }
                    
                    case 2:
                    {
                        rotate_right();
                        break;
                    }

                    default:
                    {
                        cout << "Enter only valid numbers" << "\n";
                        continue;
                    }
                }
            }

            case 6:
            {
                presence=0;
                if(root == NULL)
                {
                    cout << "Tree is empty" << "\n";
                    continue;
                }
                cout << "Enter the data to search " << "\n";
                cin >> num;
                search(root);
                if(presence==0)
                {
                    cout << "data is not present " << "\n";
                }
                else
                {
                    cout << "The data is present " << presence << " times" << "\n";
                }
                break;
            }

            case 7:
            {
                cout << "Thankyou" << "\n";
                goto exit;
                break;    
            }
 
            default:
            {
                cout << "Enter only valid numbers" << "\n";
                break;
            }
        }
    }
    exit:
    cout << "closing the program" << "\n";
    return 0;
}