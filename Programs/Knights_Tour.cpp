//Knights tour problem
//Implementing using backtracking algorithm

#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;


int N;
int area;
int flag = 0;//final finish flag check

int move(int position, int path[], int area)
{
    static int trail = 0;
    int flag_1=0;//position overlap check 
    int next;
    path[trail] = position;
    for(int i=1;i<=8;i++)
    {
        switch (i)
        {
            case 1:
            {
                next = (position+1)+(2*N);
                break;
            }
            case 2:
            {
                next = (position+1)-(2*N);
                break;
            }
            case 3:
            {
                next = (position-1)+(2*N);
                break;
            }
            case 4:
            {
                next = (position-1)-(2*N);
                break;
            }
            case 5:
            {
                next = (position+N)+2;
                break;
            }
            case 6:
            {
                next = (position+N)-2;
                break;
            }
            case 7:
            {
                next = (position-N)+2;
                break;
            }
            case 8:
            {
                next = (position-N)-2;
                break;
            }
            case 9:
            {
                next = (position+2)+N;
                break;
            }
            case 10:
            {
                next = (position+2)-N;
                break;
            }
            case 11:
            {
                next = (position-2)+N;
                break;
            }
            case 12:
            {
                next = (position-2)-N;
                break;
            }
            case 13:
            {
                next = (position+(2*N))+1;
                break;
            }
            case 14:
            {
                next = (position+(2*N))-1;
                break;
            }
            case 15:
            {
                next = (position-(2*N))+1;
                break;
            }
            case 16:
            {
                next = (position-(2*N))-1;
                break;
            }
            default:
            {

            }
        }
        for(int j=0;j<=trail;j++)
        {
            if(path[j] == next)
            {
                flag_1 = 1;
            }
        }
        if(flag_1 == 1)
        {
            continue;
        }
        else
        {
            trail++;
            move(next, path, area);
        }
    }
        
}

int main(void)
{
    cout << "Enter the size of the board" << "\n";
    cin >> N;
    area = N*N; //position goes from 0 to area-1
    int path[area];
    int board[area];
    for(int i=0;i<area;i++)
    {
        board[i] = i;
    }
    for(int i=0;i<area;i++)
    {
        move(i, path, area);
        if(flag == 1)
        {
            break;
        }
    }
    return 0;
}