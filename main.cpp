#include <iostream>
#include <algorithm>
#include "OthelloGame.h"

using namespace std;

int main() {
    array<array<char,8>,8> board = { { {0}, {0},{0},
                                      {0,0,0,-1,1,0,0,0},
                                      {0,0,0,1,-1,0,0,0},{0},{0},{0} }};
    int row = 0, column = 0, player = 1, playerPass = 0;

    PrintBoard(board);
    while (playerPass != 2) {

        if (player == 1) {
            cout << "Black's turn. " << endl;
        }
        else if (player == -1) {
            cout << "White's turn. " << endl;
        }

        cout << "Please enter a coordinate in (x,y) form: " << endl;
        GetMove(row, column);

        while (!IsValidMove(board, row, column)) {
            cout << "Invalid move. Please enter again: " << endl;
            GetMove(row, column);
            IsValidMove(board, row, column);
        }

        if ((row == -1 & column == -1) && (player == 1)) {
            playerPass += 1;
        }
        else if ((row == -1 & column == -1) && (player == -1)) {
            playerPass += 1;
        }
        else {
            playerPass = 0;
            ApplyMove(board, row, column, player);
        }

        PrintBoard(board);
        player *= -1;

        for (auto r = board[0].begin(); r != board[board.size() - 1].end(); r++) {
            auto found = find(board[0].begin(), board[board.size() - 1].end(), 0);
            found == board[board.size() - 1].end()? playerPass = 2 : playerPass += 0;
        }

    }

    if (GetValue(board) > 0) {
        cout << "Black wins!";
    }
    else if (GetValue(board) < 0) {
        cout << "White wins!";
    }
    else {
        cout << "Tie.";
    }

    return 0;
}
