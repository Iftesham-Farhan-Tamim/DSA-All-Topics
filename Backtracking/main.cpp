// N-Queens (https://leetcode.com/problems/n-queens/description/)

#include<bits/stdc++.h>
using namespace std;

bool check(int n, vector<string> &Board, int i, int j) {
    // upper left dign, if there any queen present
    int row = i, col = j;
    while(row > -1 && col > -1) {
        if(Board[row][col] == 'Q') {
            return 0;
        }

        row--, col--;
    }

    // upper right dign
    row = i, col = j;
    while(row > -1 && col < n) {
        if(Board[row][col] == 'Q') {
            return 0;
        }
        row--, col++;
    }

    return 1;
}

void find(int row, int n, vector<vector<string> > &ans, vector<string> &Board, vector<bool> &column) {
    // base case
    if(row == n) {
        ans.push_back(Board);
        return;
    }

    // put queen at any n position
    for(int j=0; j<n; j++) {
        if(column[j] == 0 && check(n, Board, row, j)) {
            column[j] = 1;
            Board[row][j] = 'Q';
            find(row + 1, n, ans, Board, column);
            column[j] = 0;
            Board[row][j] = '.';
        }
    }
}

vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > ans;
    vector<string>Board(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            Board[i].push_back('.');
        }
    }

    vector<bool>column(n, 0);
    find(0, n, ans, Board, column);
    return ans;
}

int main() {
    int n;
    cout << "Enter number of queens (n): ";
    cin >> n;

    vector<vector<string> > result = solveNQueens(n);

    cout << endl << "Total solutions: " << result.size() << endl << endl;

    for (int i = 0; i < result.size(); i++) {
        cout << "Solution " << i + 1 << ":" << endl;
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << endl;
        }
        cout << endl;
    }
}

// input:
// Enter number of queens (n): 4

// output:
// Total solutions: 2

// Solution 1:
// .Q..
// ...Q
// Q...
// ..Q.

// Solution 2:
// ..Q.
// Q...
// ...Q
// .Q..
// ............................................................................................
// N-Queens optimized version

#include<bits/stdc++.h>
using namespace std;

void find(int row, int n, vector<vector<string> > &ans, vector<string> &Board, vector<bool> &column, vector<bool> &LeftDig, vector<bool> &RightDig) {
    // base case
    if(row == n) {
        ans.push_back(Board);
        return;
    }

    // put queen at any n position
    for(int j = 0; j < n; j++) {
        if(column[j] == 0 && LeftDig[n - 1 + j - row] == 0 && RightDig[row + j] == 0) {
            column[j] = 1;
            Board[row][j] = 'Q';
            LeftDig[n - 1 + j - row] = 1;
            RightDig[row + j] = 1;
            find(row + 1, n, ans, Board, column, LeftDig, RightDig);
            column[j] = 0;
            Board[row][j] = '.';
            LeftDig[n - 1 + j - row] = 0;
            RightDig[row + j] = 0;
        }
    }
}

vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > ans;
    vector<string>Board(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            Board[i].push_back('.');
        }
    }

    vector<bool>RightDig(2*n-1, 0);
    vector<bool>LeftDig(2*n-1, 0);

    vector<bool>column(n, 0);
    find(0, n, ans, Board, column, LeftDig, RightDig);
    return ans;
}

int main() {
    int n;
    cout << "Enter number of queens (n): ";
    cin >> n;

    vector<vector<string> > result = solveNQueens(n);

    cout << endl << "Total solutions: " << result.size() << endl << endl;

    for (int i = 0; i < result.size(); i++) {
        cout << "Solution " << i + 1 << ":" << endl;
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << endl;
        }
        cout << endl;
    }
}

// input:
// Enter number of queens (n): 4

// output:
// Total solutions: 2

// Solution 1:
// .Q..
// ...Q
// Q...
// ..Q.

// Solution 2:
// ..Q.
// Q...
// ...Q
// .Q..

// ............................................................................................
// M-Coloring Problem (https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1)

#include<bits/stdc++.h>
using namespace std;

bool DFS(int node, vector<int> &color, bool graph[101][101], int m, int n) {
    for(int i=0; i<m; i++) {
        bool IsPossible = 1;
        for(int j=0; j<n; j++) {
            if(graph[node][j] && color[j] == i) {
                IsPossible = 0;
                break;
            }
        }

        if(IsPossible == 0) {
            continue;
        }

        color[node] = i;

        IsPossible = 1;

        for(int j=0; j<n; j++) {
            if(graph[node][j] && color[j] == -1) {
                if(!DFS(j, color, graph, n, m)) {
                    IsPossible = 0;
                    break;
                }
            }
        }

        if(IsPossible) {
            return 1;
        }

        color[node] = -1;
    }

    return 0;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n, -1);
    for(int i=0; i<n; i++) {
        if(color[i] == -1 && !DFS(i, color, graph, m, n))
        return 0;
    }

    return 1;
}

int main() {
    int n = 4, m = 3; 
    bool graph[101][101] = {0};

    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[3][0] = graph[0][3] = 1;

    if (graphColoring(graph, m, n)) {
        cout << "Yes, possible";
    } else {
        cout << "No, not possible";
    }
}

// output:
// Yes, possible
// ............................................................................................
// M-Coloring Proble optimized version

#include<bits/stdc++.h>
using namespace std;

bool find(int node, bool graph[101][101], int n, int m, vector<int> &color) {
    // base case
    if(node == n) {
        return 1;
    }

    for(int i=0; i<m; i++) {
        bool IsPossible = 1;
        for(int j=0; j<n; j++) {
            if(graph[node][j] && color[j] == i) {
                IsPossible = 0;
                break;
            }
        }

        if(IsPossible) {
            color[node] = i;
            if(find(node + 1, graph, n, m, color)) {
                return 1;
            }

            color[node] = -1;
        }
    }

    return 0;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n, -1);
    return find(0, graph, n, m, color);
}

int main() {
    int n = 4, m = 3; 
    bool graph[101][101] = {0};

    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[3][0] = graph[0][3] = 1;

    if (graphColoring(graph, m, n)) {
        cout << "Yes, possible";
    } else {
        cout << "No, not possible";
    }
}

// output:
// Yes, possible
// ............................................................................................
// Sudoku Solver (https://leetcode.com/problems/sudoku-solver/description/)

#include<bits/stdc++.h>
using namespace std;

bool check(int num, vector<vector<char> > &board, int i, int j) {
    char c = '0' + num;

    // check at same row
    for(int col = 0; col < 9; col++) {
        if(board[i][col] == c) {
            return 0;
        }
    }

    // check at same column
    for(int row = 0; row < 9; row++) {
        if(board[row][j] == c) {
            return 0;
        }
    }

    // check at same box

    int row = i / 3*3, col = j / 3*3;

    for(int a=row; a<row+3; a++) {
        for(int b=col; b<col+3; b++) {
            if(board[a][b] == c) {
                return 0;
            }
        }
    }

    return 1;
}

bool find(int i, int j, vector<vector<char> > &board) {
    // base case
    if(i == 9) {
        return 1;
    }

    if(j == 9) {
        return find(i + 1, 0, board);
    }

    if(board[i][j] != '.') {
        return find(i, j+1, board);
    }

    for(int num=1; num<10; num++) {
        if(check(num, board, i, j)) {
            board[i][j] = '0' + num;
            if(find(i, j+1, board)) {
                return 1;
            }
            board[i][j] = '.';
        }
    }

    return 0;
}

void sloveSudoku(vector<vector<char> > &board) {
    find(0, 0, board);
}

int main() {
    vector<vector<char> > board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    sloveSudoku(board);

    // Traditional loop to print the solved Sudoku
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// output:
// 5 3 4 6 7 8 9 1 2 
// 6 7 2 1 9 5 3 4 8 
// 1 9 8 3 4 2 5 6 7 
// 8 5 9 7 6 1 4 2 3 
// 4 2 6 8 5 3 7 9 1 
// 7 1 3 9 2 4 8 5 6 
// 9 6 1 5 3 7 2 8 4 
// 2 8 7 4 1 9 6 3 5 
// 3 4 5 2 8 6 1 7 9 

// g++ main.cpp --std=c++14 -o run
// ./run