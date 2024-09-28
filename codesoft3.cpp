#include <iostream>
#include <array>
#include <string>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const array<array<char, 3>, 3>& board) {
    cout << "  1 2 3\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if there is a winner
char checkWinner(const array<array<char, 3>, 3>& board) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    // No winner
    return ' ';
}

int main() {
    array<array<char, 3>, 3> board = { ' ' }; // Initialize the board with empty spaces
    char currentPlayer = 'X';
    char winner = ' ';
    int moves = 0;

    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Player 1: X\n";
    cout << "Player 2: O\n\n";

    // Game loop
    while (winner == ' ' && moves < 9) {
        displayBoard(board);
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Adjust the indices (subtract 1) to match array indexing
        row--;
        col--;

        // Check if the chosen position is valid and update the board
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            moves++;
            winner = checkWinner(board);
            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move! Try again.\n";
        }
    }

    // Display the final board
    displayBoard(board);

    // Display the result
    if (winner != ' ') {
        cout << "Player " << winner << " wins!\n";
    } else {
        cout << "It's a draw!\n";
    }

    return 0;
}
