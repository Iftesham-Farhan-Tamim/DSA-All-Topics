#include<bits/stdc++.h>
using namespace std;

int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};
string dir = "UDLR";

bool valid(int i, int j, int n) {
    return i >= 0 && j >= 0 && i < n && j < n;
}

void total(vector<vector<int> > &matrix, int i, int j, int n, string &path, vector<string> &ans, vector<vector<bool> > &visited) {
    // base case
    if(i == n - 1 && j == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[i][j] = 1;

    for(int k = 0; k < 4; k++) {
        if(valid(i + row[k], j + col[k], n) && matrix[i + row[k]][j + col[k]] && !visited[i + row[k]][j + col[k]]) {
            path.push_back(dir[k]);
            total(matrix, i + row[k], j + col[k], n, path, ans, visited);
            path.pop_back();
        }
    }

    visited[i][j] = 0;

    // up
    if(valid(i - 1, j, n) && matrix[i - 1][j] && !visited[i - 1][j]) {
        path.push_back('U');
        total(matrix, i - 1, j, n, path, ans, visited);
    }

    // down
    if(valid(i + 1, j, n) && matrix[i + 1][j] && !visited[i + 1][j]) {
        path.push_back('D');
        total(matrix, i + 1, j, n, path, ans, visited);
    }

    // left
    if(valid(i, j - 1, n) && matrix[i][j - 1] && !visited[i][j - 1]) {
        path.push_back('L');
        total(matrix, i, j - 1, n, path, ans, visited);
    }

    // right
    if(valid(i, j + 1, n) && matrix[i][j + 1] && !visited[i][j + 1]) {
        path.push_back('R');
        total(matrix, i, j + 1, n, path, ans, visited);
    }
}

vector<string> findPath(vector<vector<int> > &m, int n) {
    vector<vector<bool> > visited(n, vector<bool>(n, 0));
    vector<string> ans;
    string path;

    if(m[0][0] == 0 || m[n - 1][n - 1] == 0) {
        return ans;
    }

    total(m, 0, 0, n, path, ans, visited);
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int> > matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<string> result = findPath(matrix, n);

    if (result.empty()) {
        cout << "No path found";
    } else {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i != result.size() - 1) {
                cout << " "; // add space between paths
            }
        }   
    }
}