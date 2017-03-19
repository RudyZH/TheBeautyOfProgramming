#include <iostream>
#include <vector>

using namespace std;

class Sudoku {
public:
	// ±©Á¦»ØËÝ·¨
	void solver(vector<vector<char>>& board) {
		if (board.size() == 0)
			return;
		solve(board);
	}

	bool solve(vector<vector<char>>& board) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == '.') {
					for (char c = '1'; c <= '9'; c++) {
						if (isValid(board, i, j, c)) {
							board[i][j] = c;
							if (solve(board))
								return true;
							else 
								board[i][j] = '.';
						}
					}
					return false;
				}
			}
		}
		return true;
	}

	bool isValid(vector<vector<char>>& board, int row, int col, char c) {
		for (int i = 0; i < 9; i++) {
			if (board[row][i] != '.' && board[row][i] == c)
				return false;
			if (board[i][col] != '.' && board[i][col] == c)
				return false;
			if (board[(row / 3) * 3 + (i / 3)][(col / 3) * 3 + (i % 3)] != '.' &&
				board[(row / 3) * 3 + (i / 3)][(col / 3) * 3 + (i % 3)] == c)
				return false;
		}
		return true;
	}

	// method 2

	void solver2(vector<vector<char>>& board) {
		if (board.size() == 0)
			return;

		util(board, 0);
	}

	bool util(vector<vector<char>>& board, int pos) {
		if (pos >= 81)
			return true;
		int i = pos / 9;
		int j = pos % 9;
		if (board[i][j] != '.')
			return util(board, pos + 1);
		else {
			for (char c = '1'; c <= '9'; c++) {
				if (isValid(board, i, j, c)) {
					board[i][j] = c;
					if (util(board, pos + 1))
						return true;
					else 
						board[i][j] = '.';
				}
			}
			return false;
		}
	}
};

void main() {

	vector<vector<char>> res(9, vector<char>(9, '.'));
	for (vector<char> row : res) {
		for (char col : row) 
			cout << col << " ";
		cout << endl;
	}
	Sudoku s;
	s.solver2(res);
	cout << endl;

	for (vector<char> row : res) {
		for (char col : row) 
			cout << col << " ";
		cout << endl;
	}
}