// Print N-bit binary numbers having more 1s than 0 (https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1)

#include<bits/stdc++.h>
using namespace std;

void find(int n, vector<string> &ans, string temp, int zero, int one) {
    if(temp.size() == n) {
        ans.push_back(temp);
        return;
    }

    if(zero < one) {
        temp.push_back('0');
        find(n, ans, temp, zero + 1, one);
        temp.pop_back();
    }

    temp.push_back('1');
    find(n, ans, temp, zero, one + 1);
    temp.pop_back();
}

vector<string> nbitBinary(int n) {
    vector<string> ans;
    string temp;
    find(n, ans, temp, 0, 0);
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<string> result = nbitBinary(n);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}

// input:
// 2

// output:
// 10
// 11