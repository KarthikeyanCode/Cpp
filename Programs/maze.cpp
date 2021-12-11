//finding way out of maze

#include<iostream>
using namespace std;

int x,y;
int x_path[50]; //stores the x coordinate of path
int y_path[50]; //stores the y coordinate of path 
//start with (0,0) and move towards (x-1, y-1)
int travel(int x_pos, int y_pos)
{

}

int main(void)
{
    cout << "Enter the x dimension of maze" << "\n";
    cin >> x;
    cout << "Enter the y dimension of maze" << "\n";
    cin >> y;
    int maze[x][y];
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
    //travel(0,0, maze);
    return 0;
}