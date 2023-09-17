#include<bits/stdc++.h>
#include <iostream>
#include <iostream>
#include <thread> // For std::this_thread::sleep_for
#include <chrono>
using namespace std;

void display_loading_bar(int duration_seconds) {
    cout << "  Loading: ";
    cout << "\033[1;47m"; // Set background color to green
    cout.flush();
    
    for (int i = 0; i < 20; ++i) {
        cout << " "; // Display spaces to simulate the loading bar
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(duration_seconds * 1000 / 20));
    }
    
    cout << "\033[0m"; // Reset the terminal colors to default
    cout << endl;
}
// Array for the board
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

// Variable Declaration
int choice;
int row, column;
char turn = 'X';
bool draw = false;

// Function to show the current status of the gaming board
void display_board() {
    system("clear"); // Clear the screen (for Linux/Unix)
    //system("cls"); // Clear the screen (for Windows)
    
    cout << "\033[1;32m"; // Set text color to green
    cout << "\n\tTic-Tac-Toe Game\n\n";
    cout << "\033[1;34m"; // Set text color to blue
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << "\033[0m"; // Reset text color to default
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "  ";
            if (board[i][j] == 'X') {
                cout << "\033[1;31m"; // Set text color to red for X
            } else if (board[i][j] == 'O') {
                cout << "\033[1;36m"; // Set text color to cyan for O
            }
            cout << board[i][j] << " ";
            cout << "\033[0m"; // Reset text color to default
            if (j < 2) {
                cout << " |";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "_____|_____|_____" << endl;
        }
    }
    cout << endl;
}


// Function to get the player input and update the board
void player_turn() {
    cout << "\033[1;34m"; // Set text color to blue
    if (turn == 'X') {
        cout << "Player 1 (X) - Enter a position (1-9): ";
    } else {
        cout << "Player 2 (O) - Enter a position (1-9): ";
    }
    cout << "\033[0m"; // Reset the terminal colors to default

    cin >> choice;

    switch (choice) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "Invalid Move. Please choose a valid position (1-9)." << endl;
            player_turn();
            return; // Return to prevent further execution
    }

    if (board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = turn;
        if (turn == 'X') {
            turn = 'O';
        } else {
            turn = 'X';
        }
    } else {
        cout << "Box already filled! Please choose another." << endl;
        player_turn();
    }
}

// Function to check if the game is over
bool gameover() {
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return false;
        }
    }

    // Check diagonals for a win
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return false;
    }

    // Check if the game is still in progress
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return true;
            }
        }
    }

    // If all positions are filled and no winner, it's a draw
    draw = true;
    return false;
}

int main() {
    cout << "\033[1;32m"; // Set text color to green
    cout << "\n\tTic-Tac-Toe Game\n\n";
     
    display_loading_bar(3);
     
     
    while (gameover()) {
        display_board();
        player_turn();
    }

    display_board();
    
    this_thread::sleep_for(chrono::seconds(2));
    
    system("clear");
    
    cout << "\n\n\n";
    cout << "\033[1;32m"; // Set text color to green
    display_loading_bar(2);
    cout << "\033[0m"; // Reset text color to default
    
    
    system("clear");

    if (draw) {
        cout << "It's a draw!" << endl;
    } else {
        if (turn == 'X') {
            cout << "\033[1;32m"; // Set text color to green
            cout << "\n\nPlayer 2 (O) wins! Congratulations!" << endl;
            cout << "\033[0m"; // Reset text color to default
        } else {
            cout << "\033[1;32m"; // Set text color to green
            cout << "\n\nPlayer 1 (X) wins! Congratulations!" << endl;
            cout << "\033[0m"; // Reset text color to default
        }
    }

    // Add a delay before terminating the program
    this_thread::sleep_for(chrono::seconds(2));

    return 0;
}