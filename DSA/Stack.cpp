//stack - LIFO Data structure 

#include<vector>
#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

#define capacity 10

vector<string> Stack;

void push()
{
    string data;
    cout << "Enter the data in terms of string" << "\n";
    cin >> data;
    Stack.push_back(data);
}

void pop()
{
    Stack.pop_back();
}

void display()
{
    for(int i=0;i<Stack.size();i++)
    {
        cout << Stack[i] << " ";
    }
    cout << "\n";
}

int main(void)
{
    int opt, opt1, opt2;
    while(1)
    {
        cout << "Choose: " << "\n";
        cout << "1. Push " << "\n";
        cout << "2. Pop " << "\n";
        cout << "3. Display" << "\n";
        cout << "4. Exit" << "\n";
        cin >> opt;

        switch(opt)
        {
            case 1:
            {
                if(Stack.size() == capacity)
                {
                    cout << "The stack is full" << "\n";
                    continue;
                }
                push();
                break;
            }
            case 2:
            {
                if(Stack.size() == 0)
                {
                    cout << "Stack is empty" << "\n";
                    continue;
                }
                pop();
                break;
            }
            case 3:
            {
                if(Stack.size() == 0)
                {
                    cout << "The stack is empty" << "\n";
                    continue;
                }
                display();
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
                cout << "Enter only valid numbers" << "\n";
                continue;
            }
        }

    }
    exit:
    cout << "Closing the program" << "\n";
    return 0;
}