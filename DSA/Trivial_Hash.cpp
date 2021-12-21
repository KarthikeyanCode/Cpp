//Trivial Hashing 

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define max 10

int hash_[max][2];

void insertion(int num)
{
    if(abs(num) > 9)
    {
        cout << "The number is out of range" << "\n";
    }
    else if(num>0)
    {
        if(hash_[num][0] != 1)
        {
            hash_[num][0] = 1;
        }
        else
        {
            cout << "The number already hashed" << "\n";
        }
    }
    else
    {
        if(hash_[abs(num)][0] != 1)
        {
            hash_[abs(num)][0] = 1;
        }
        else
        {
            cout << "The number already hashed" << "\n";
        }
    }
    return;
}

bool Delete(int num)
{
    if(abs(num) > 9)
    {
        return false;
    }
    else if(num > 0)
    {
        if(hash_[num][0] == 1)
        {
            hash_[num][0] = 0;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(hash_[abs(num)][1] == 1)
        {
            hash_[abs(num)][1] = 0;
            return true;
        }
        else
        {
            return false;
        }
    }
}

void Display()
{
    cout << "The hash: " << "\n";
    for(int i=0;i<2;i++)
    {
        if(i=1) //negative numbers
        {
            for(int j=max;j>0;j--)
            {
                if(hash_[j][i] == 1)
                {
                    cout << -j << " ";
                }
            }
        }
        else //positive numbers 
        {
            for(int j=0;j<max;j++)
            {
                if(hash_[j][i] == 1)
                {
                    cout << j << " ";
                }
            }
        }
    }
    cout << "\n";
}

int main(void)
{
    int opt, opt1, num;
    while(1)
    {
        cout << "choose:" << "\n";
        cout << "1.Insert" << "\n";
        cout << "2.Delete" << "\n";
        cout << "3.Display" << "\n";
        cout << "4.Exit" << "\n";
        cin >> opt;
        switch (opt)
        {
            case 1:
            {   
                cout << "Enter the value (range -9 to 9):" << "\n";
                cin >> num;
                insertion(num);
                break;
            }
            case 2:
            {
                cout << "Enter the value to delete (range -9 to 9)" << "\n";
                cin >> num;
                if(Delete(num) == true)
                {
                    cout << "The number has been deleted" << "\n";
                }
                else
                {
                    cout << "The number could not be found" << "\n";
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
                cout << "Thankyou" << "\n";
                goto exit;
                break;
            }
            default:
            {
                cout << "Enter only valid numbers " << "\n";
                continue;
            }
        } 
    }
    exit:
    cout << "Closing the program" << "\n";
    return 0;
}