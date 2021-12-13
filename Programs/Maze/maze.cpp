/*
    finding way out of maze.
    Please give 0 for entry and exit so the program can enter the maze
    (0,0) is the entry coordinate and (x-1,y-1) is the exit where x and y
    are the x and y coordinates of maze.
*/

#include<iostream>
using namespace std;

int x,y;
int x_path[50]; //stores the x coordinate of path
int y_path[50]; //stores the y coordinate of path 
int maze[50][50];//50x50 is the maximum size of the map 
int no_of_moves = 0;
int x_prev, y_prev;
//start with (0,0) and move towards (x-1, y-1)
int travel(int x_pos, int y_pos, int path)
{
    int previous[2];
    int decision = 1;
    int flag = 1;
    //boundary condition
    if((x_pos == x) || (y_pos == y) || (x_pos<0) || (y_pos<0))
    {
        return 1;
    }
    if(path != 0)
    {
        previous[0] = x_prev;
        previous[1] = y_prev;
    }
    x_prev = x_pos;
    y_prev = y_pos;
    if(maze[x_pos][y_pos]==1)
    {
        return 1;
    }
    if((x_pos == x-1) && (y_pos == y-1))
    {
        //storing the path traversed to exit
        x_path[path] = x_pos;
        y_path[path] = y_pos;
        no_of_moves = path;
        return 0;
    }
    while(flag)
    {
        switch (decision)
        {
            case 1:
            {
                if(x_pos+1 == previous[0] && y_pos == previous[1])
                {
                    goto skip;
                }
                flag = travel(x_pos+1, y_pos, path+1);
                break;
            }
            case 2:
            {
                if(x_pos-1 == previous[0] && y_pos == previous[1])
                {
                    goto skip;
                }
                flag = travel(x_pos-1, y_pos, path+1);
                break;
            }
            case 3:
            {
                if(x_pos == previous[0] && y_pos+1 == previous[1])
                {
                    goto skip;
                }
                flag = travel(x_pos, y_pos+1, path+1);
                break;
            }
            case 4:
            {
                if(x_pos == previous[0] && y_pos-1 == previous[1])
                {
                    goto skip;
                }
                flag = travel(x_pos, y_pos-1, path+1);
                break;
            }
            case 5:
            {
                return 1;
            }
        } 
        skip:
        decision++; 
    }
    //storing the path traversed to exit
    x_path[path] = x_pos;
    y_path[path] = y_pos;
    return 0;
}

int main(void)
{
    int check, counter;
    counter=0;
    cout << "Enter the x dimension of maze" << "\n";
    cin >> x;
    cout << "Enter the y dimension of maze" << "\n";
    cin >> y;
    cout << "Enter 0 for a path and enter 1 for a block" << "\n";
    for(int i=0;i<y;i++)
    {
        for(int j=0;j<x;j++)
        {
            cout << "Enter element (" << j << "," << i << ")\n";
            cin >> maze[j][i];
        }
    }
    cout << "your map" << "\n";
    for(int i=0;i<y;i++)
    {
        for(int j=0;j<x;j++)
        {
            cout << maze[j][i] << " ";
        }
        cout << "\n";
    }
    //traversing
    check = travel(0,0,0);
    if(check == 0)
    {
        cout << "Succesfully traversed from entrance to exit" << "\n";
        cout << "path: " << "\n";
        for(int i=0;i<=no_of_moves;i++)
        {
            cout << "(" << x_path[i] << "," << y_path[i] << ")" << " ";
            counter++;

            if(counter%10 == 0)
            {
                cout << "\n";
            }

        }
    }
    else
    {
        cout << "No routes possible" << "\n";
    }
    return 0;
}