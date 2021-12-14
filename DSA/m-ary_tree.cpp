#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

#include<iostream>
#include<vector>

using namespace std;

int m;

class node
{
    private:

    public:
        
        int data;
        vector<node*> branch;

}*root=NULL;

//we have to insert at a particular position depending upon the data contained in the Node
void insertion(node* prev_Node, node* Node)//insertion
{
    int flag=0;
    if(prev_Node->branch.size()<m)
    {
        for(int i=0;i<prev_Node->branch.size();i++)
        {
            if(Node->data < prev_Node->branch[i]->data)
            {
                prev_Node->branch.insert(prev_Node->branch.begin() + i, Node);
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            prev_Node->branch.push_back(Node);
        }
    }
    else
    {
        for(int i=0;i<prev_Node->branch.size();i++)
        {
            if(Node->data < prev_Node->branch[i]->data)
            {
                insertion(prev_Node->branch[i], Node);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            insertion(prev_Node->branch[prev_Node->branch.size()-1], Node);
        }
    }
}

int Height(node* Node)
{
    if(Node->branch.size() == 0)
    {
        return 1;
    }
    vector<int> height;
    for(int i=0;i<Node->branch.size();i++)
    {
        height.push_back(Height(Node->branch[i]));
        sort(height.begin(), height.end());
    }
    return (height.back()+1);//return the maximum height 
}

int Count_Nodes(node* Node)
{
    int sum=1;
    for(int i=0;i<Node->branch.size();i++)
    {
        sum += Count_Nodes(Node->branch[i]);
    }
    return sum;
}

int main(void)
{
    int option1, option2;
    int data;
    cout << "Enter the value of m" << "\n";
    cin >> m;
    while(1)
    {
        cout << "Choose" << "\n";
        cout << "1. Insert" << "\n";
        cout << "2. Delete" << "\n";
        cout << "3. Height/Depth" << "\n";
        cout << "4. Count Nodes" << "\n";
        cout << "5. Traversal" << "\n";
        cout << "6. Exit" << "\n";
        cin >> option1;
        switch (option1)
        {
            case 1: //insertion
            {
                cout << "Enter the data" << "\n";
                cin >> data;
                node* Node = (node*)malloc(sizeof(node));
                insertion(root, Node);
                break;
            }
            case 2: //Deletion
            {
                break;
            }
            case 3: //height/Depth
            {
                cout << "Maximum Height of the tree is " << Height(root) << "\n";
                break;
            }
            case 4: //Count Nodes
            {
                cout << "No of Nodes: " << Count_Nodes(root) << "\n";
                break;
            }
            case 5: //traversal
            {
                break;
            }
            case 6:
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
