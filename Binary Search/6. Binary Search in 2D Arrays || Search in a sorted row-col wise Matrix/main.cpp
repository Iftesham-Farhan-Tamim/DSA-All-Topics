// Search a 2D Matrix (https://leetcode.com/problems/search-a-2d-matrix/description/)

#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int row_index, col_index, start = 0, end = n * m - 1, mid;

    while(start <= end) {
        mid = start + (end - start) / 2;
        row_index = mid / m;
        col_index = mid % m;

        if(matrix[row_index][col_index] == target) {
            return 1;
        } else if(matrix[row_index][col_index] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    vector<vector<int> > matrix = {
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 60}
	};

	int target = 3;

	if (searchMatrix(matrix, target)) {
		cout << "Found" << endl;
	} else {
		cout << "Not Found" << endl;
	}
}

// output:
// found
// ............................................................................................
// Search in a sorted Matrix (https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1?utm_medium=article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks)

#include <bits/stdc++.h>
using namespace std;

bool search(vector<vector<int> > &matrix, int n, int m, int x) {
	int row = 0, col = m - 1;

	while (row < n && col >= 0) {
		if (matrix[row][col] == x) {
			return 1;
		} else if (matrix[row][col] < x) {
			row++;
		} else {
			col--;
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<int> > mat = {
		{1, 5, 9},
		{14, 20, 21},
		{30, 34, 43}
	};

	int x = 14;

	int n = mat.size();
	int m = mat[0].size();

	if (search(mat, n, m, x)) {
		cout << "true";
	} else {
		cout << "false";
	}
}

// output:
// true