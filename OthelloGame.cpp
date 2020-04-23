//
// Created by Erina Lara on 2/14/20.
//
#include <iostream>
#include "OthelloGame.h"

using namespace std;

void PrintBoard(const OthelloMatrix &board) {
    cout << "- " << "0 " << "1 " << "2 " << "3 " << "4 " << "5 " << "6 " << "7 " << endl;

    for (int r = 0; r < board.size(); r++) {
        cout << r << " ";
        for (int c = 0; c < board.size(); c++) {
            if (board[r][c] == 1) {
                cout << "B ";
            }
            else if (board[r][c] == -1) {
                cout << "W ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

bool InBounds(int row, int col) {
    return ((row >= 0 & row <= 7) && (col >= 0 & col <= 7));
}

bool IsValidMove(const OthelloMatrix &board, int row, int col) {
    return ((InBounds(row, col)) & (board[row][col] == 0 )) || (row ==-1 & col ==-1);
}

void GetMove(int &row, int &col) {
    string format = "(,)";

    cin >> format[0] >> row >> format[1] >> col >> format[3];
}

void ApplyMove(OthelloMatrix &board, int row, int col, char currentPlayer) {
    board[row][col] = currentPlayer;

    for (int k = -1; k < 2; k++) {
        for (int i = -1; i < 2; i++) {

            int counter = 0, totalK = k, totalI = i;

            while (board[row + totalK][col + totalI] == (currentPlayer * -1)) {
                counter++;
                totalK += k;
                totalI += i;

            }
            if (board[row + totalK][col + totalI] == currentPlayer) {
                while (counter != 0) {
                    counter--;
                    totalK -= k;
                    totalI -= i;
                    board[row + totalK][col + totalI] = currentPlayer;
                }
            }
        }
    }
}

int GetValue(const OthelloMatrix &board) {
    int sum = 0;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            sum += (int) board[i][j];
        }
    }
    return sum;
}

