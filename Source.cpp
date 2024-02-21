#include <iostream>
#include <vector>

enum class Player { X, O };

const int BOARD_SIZE = 3;

using namespace std;

// Function prototypes
void initializeBoard(vector<vector<char>>& board);
void printBoard(const vector<vector<char>>& board);
bool isMoveValid(const vector<vector<char>>& board, int row, int col);
bool isBoardFull(const vector<vector<char>>& board);
bool hasPlayerWon(const vector<vector<char>>& board, char player);
Player togglePlayer(Player current);
void makeMove(vector<vector<char>>& board, int row, int col, Player player);

int main() {
    vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, ' '));
    Player currentPlayer = Player::X;

    initializeBoard(board);
    printBoard(board);

    while (!isBoardFull(board)) {
        int row, col;
        cout << "Player " << (currentPlayer == Player::X ? 'X' : 'O') << "'s turn. Enter row and column (0-2): ";
        cin >> row >> col;

        if (isMoveValid(board, row, col)) {
            makeMove(board, row, col, currentPlayer);
            printBoard(board);

            if (hasPlayerWon(board, currentPlayer == Player::X ? 'X' : 'O')) {
                cout << "Player " << (currentPlayer == Player::X ? 'X' : 'O') << " wins!" << endl;
                break;
            }

            currentPlayer = togglePlayer(currentPlayer);
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    return 0;
}

void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j];
            if (j < BOARD_SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < BOARD_SIZE - 1) cout << "---------" << endl;
    }
}

bool isMoveValid(const vector<vector<char>>& board, int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ';
}

bool isBoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

bool hasPlayerWon(const vector<vector<char>>& board, char player) {
    // Implement your winning logic here
}

Player togglePlayer(Player current) {
    return (current == Player::X) ? Player::O : Player::X;
}

void makeMove(vector<vector<char>>& board, int row, int col, Player player) {
    board[row][col] = (player == Player::X) ? 'X' : 'O';
}
