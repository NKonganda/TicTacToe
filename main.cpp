#include <iostream>
#include <string>

using namespace std;

void displayGrid(char aGrid[3][3]) {
    int ctr = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(aGrid[i][j] == 'X' || aGrid[i][j] == 'O') {
                cout << "|\t" << aGrid[i][j] << "\t";
            }
            else {
                cout << "|\t" << ctr << "\t";
            }
            ctr++;
        }
        cout << "|\n";
    }
    
}
bool CheckForWinner(char aGrid[3][3]){
    if(aGrid[0][0] == aGrid[0][1] && aGrid[0][0] == aGrid[0][2]) {
        return true;
    }
    else if(aGrid[1][0] == aGrid[1][1] && aGrid[1][0] == aGrid[1][2]) {
        return true;
    }
    else if(aGrid[2][0] == aGrid[2][1] && aGrid[2][0] == aGrid[2][2]) {
        return true;
    }
    else if(aGrid[0][0] == aGrid[1][0] && aGrid[0][0] == aGrid[2][0]) {
        return true;
    }
    else if(aGrid[0][1] == aGrid[1][1] && aGrid[0][1] == aGrid[2][1]) {
        return true;
    }
    else if(aGrid[0][2] == aGrid[1][2] && aGrid[0][2] == aGrid[2][2]) {
        return true;
    }
    else if(aGrid[0][0] == aGrid[1][1] && aGrid[0][0] == aGrid[2][2]) {
        return true;
    }
    else if(aGrid[2][0] == aGrid[1][1] && aGrid[2][0] == aGrid[0][2]) {
        return true;
    }
    else {
        return false;
    }
    
}
bool CheckForValidInput(int val, char aGrid[3][3]) {
    if(val < 0 || val > 8) {
        cout << "Please enter a valid number\n";
        return false;
    }
    return true;
}
int main() {
    bool GameOver = false;
    bool xTurn = true;
    char grid[3][3];
    char ctr = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][i] = ctr++ + '0';
        }
        
    }
    
    while(!GameOver) {
        if(xTurn) {
            cout << "It is X's turn\n";
        }
        else {
            cout << "It is O's turn\n";
        }
        int input = 0;
        displayGrid(grid);
        do {
            cout << "Enter a number:\n";
            cin >> input;
        }
        while(!CheckForValidInput(input, grid));

        int row = input / 3;
        int col = input % 3;

        if(xTurn){
            grid[row][col] = 'X';
        } else {
            grid[row][col] = 'O';
        }
        if (CheckForWinner(grid) == true) {
            if (xTurn) {
                cout << "X won the Game!";
            }
            else {
                cout << "O won the Game!";
            }
            exit(0);
        }
        xTurn = !xTurn;
    }



    return 0;
}