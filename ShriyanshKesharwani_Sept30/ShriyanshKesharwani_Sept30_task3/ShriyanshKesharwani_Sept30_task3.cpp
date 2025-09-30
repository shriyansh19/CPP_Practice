#include <iostream>
using namespace std;

const int SIZE = 12;

void printMaze(char maze[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool mazeTraverse(char maze[SIZE][SIZE], int x, int y, int startX, int startY) {
    if (x < 0 || y < 0 || x >= SIZE || y >= SIZE) 
    {
        return false; // out of bounds
    }

    if (maze[x][y] == '#' || maze[x][y] == 'X')
    {
        return false;   // wall or visited
    }

    maze[x][y] = 'X';  // mark current cell as visited
    printMaze(maze);

    // Exit is a boundary cell that is not the start
    if ((x == 0 || y == 0 || x == SIZE - 1 || y == SIZE - 1) && !(x == startX && y == startY)) 
    {
        return true; // exit found
    }

    // Explore neighbors: right, down, left, up
    if (mazeTraverse(maze, x, y + 1, startX, startY)) 
    {
        return true;
    }

    if (mazeTraverse(maze, x + 1, y, startX, startY)) 
    {
        return true;
    }

    if (mazeTraverse(maze, x, y - 1, startX, startY)) 
    {
        return true;
    }

    if (mazeTraverse(maze, x - 1, y, startX, startY)) 
    {
        return true;
    }

    maze[x][y] = '.';  // backtrack
    return false;
}

int main() {
    char maze[SIZE][SIZE] = {
        { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
        { '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#' },
        { '.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#' },
        { '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#' },
        { '#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.' },
        { '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#' },
        { '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#' },
        { '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#' },
        { '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#' },
        { '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#' },
        { '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#' },
        { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' }
    };

    int startX = 2, startY = 0;
    if (mazeTraverse(maze, startX, startY, startX, startY))
    {
        cout << "Maze solved!" << endl;
    }
    else
    {
        cout << "No exit found." << endl;
    }

    return 0;
}
