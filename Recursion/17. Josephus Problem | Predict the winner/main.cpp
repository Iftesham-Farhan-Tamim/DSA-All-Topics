// Find the Winner of the Circular Game Simulation / Brute Force Approach (https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/)

#include<bits/stdc++.h>
using namespace std;

int winner(vector<bool> &person, int n, int index, int person_left, int k) {
    if(person_left == 1) {
        for(int i = 0; i < n; i++) {
            if(person[i] == 0) {
                return i;
            }
        }
    }

    // find the position kill
    int kill = (k - 1) % person_left;

    while(kill--) {
        index = (index + 1) % n;
        while(person[index] == 1) {
            index = (index + 1) % n;  // skip the killed person
        }

        person[index] = 1;
        // next alive person
        while(person[index] == 1) {
            index = (index + 1) % n;
        }
    }

    return winner(person, n, index, person_left - 1, k);
}

int findTheWinner(int n, int k) {
    vector<bool>person(n, 0);
    return winner(person, n, 0, n, k) + 1;
}

int main() {
    int n = 5, k = 2;
    cout << findTheWinner(n, k) << endl;
}

// output:
// 3
// ............................................................................................
// Mathematical / Recursive Formula Approach

#include<bits/stdc++.h>
using namespace std;

int winner(int n, int k) {
    // base case
    if(n == 1) {
        return 0;
    }

    return (winner(n - 1, k) + k) % n;
}

int findTheWinner(int n, int k) {
    return winner(n, k) + 1;
}

int main() {
    int n = 5, k = 2;
    cout << findTheWinner(n, k) << endl;
}

// output:
// 3