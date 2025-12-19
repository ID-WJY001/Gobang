#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstring>
#include "include/game_state.h"
#include "include/game_rules.h"
#include "include/ai_engine.h"
#include "include/board.h"

using namespace std;

// Helper to print the board
void PrintBoard() {
    // Clear screen (simple way)
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    cout << "   ";
    for (int j = 0; j < 15; j++) {
        if (j < 10) cout << j << "  ";
        else cout << j << " ";
    }
    cout << endl;

    for (int i = 0; i < 15; i++) {
        if (i < 10) cout << i << "  ";
        else cout << i << " ";

        for (int j = 0; j < 15; j++) {
            if (vis[i][j] == 0) cout << ".  ";
            else if (vis[i][j] == 1) cout << "X  "; // Black
            else if (vis[i][j] == 2) cout << "O  "; // White
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // Initialize
    memset(vis, 0, sizeof(vis));
    memset(value, 0, sizeof(value));
    color = true; // Black starts

    cout << "Welcome to Console Gobang!" << endl;
    cout << "1. Human vs Human" << endl;
    cout << "2. Human vs AI (Human is Black)" << endl;
    cout << "3. AI vs Human (Human is White)" << endl;
    cout << "Select mode: ";
    
    int mode;
    cin >> mode;

    bool isHumanTurn = true;
    bool humanIsBlack = true;

    if (mode == 2) {
        humanIsBlack = true;
    } else if (mode == 3) {
        humanIsBlack = false;
    }

    while (true) {
        PrintBoard();

        if (mode == 1) {
            cout << (color ? "Black (X)" : "White (O)") << "'s turn." << endl;
            isHumanTurn = true;
        } else {
            if ((color && humanIsBlack) || (!color && !humanIsBlack)) {
                cout << "Your turn (" << (color ? "Black X" : "White O") << ")." << endl;
                isHumanTurn = true;
            } else {
                cout << "AI is thinking..." << endl;
                isHumanTurn = false;
            }
        }

        int r, c;
        if (isHumanTurn) {
            cout << "Enter row and column (e.g. 7 7): ";
            if (!(cin >> r >> c)) {
                break; // Exit on bad input
            }
            if (r < 0 || r >= 15 || c < 0 || c >= 15 || vis[r][c] != 0) {
                cout << "Invalid move! Try again." << endl;
                system("pause");
                continue;
            }
        } else {
            // AI Move
            node move = GetBestMove(color);
            r = move.x;
            c = move.y;
            // Simple fallback if AI returns invalid move (shouldn't happen if logic is correct)
            if (vis[r][c] != 0) {
                 // Find first empty spot
                 for(int i=0;i<15;i++) for(int j=0;j<15;j++) if(vis[i][j]==0) { r=i; c=j; goto found; }
                 found:;
            }
        }

        // Place piece
        vis[r][c] = color ? 1 : 2;

        // Check Win
        if (Judge_Win(r, c)) {
            PrintBoard();
            cout << (color ? "Black" : "White") << " Wins!" << endl;
            break;
        }

        // Check Forbidden (only for Black)
        if (color && IsForbiddenAt(r, c)) {
             PrintBoard();
             cout << "Black Forbidden Move! White Wins!" << endl;
             break;
        }

        // Switch turn
        color = !color;
    }

    system("pause");
    return 0;
}
