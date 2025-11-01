// Tower of Hanoi (https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1?utm_medium=article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks)

#include<bits/stdc++.h>
using namespace std;

void tohcal(int n, int sour, int help, int dest) {
    if(n == 1) {
        cout << "move disk " << n << " from rod " << sour << " to rod " << dest << endl; 
        return;
    }

    tohcal(n - 1, sour, dest, help);
    cout << "move disk " << n << " from rod " << sour << " to rod " << dest << endl;
    tohcal(n - 1, help, sour, dest);
}

long long toh(int n, int from, int to, int aux) {
    tohcal(n, from, aux, to);
    return pow(2, n) - 1;
}

int main() {
    int n = 3;
    toh(n, 1, 3, 2);
    cout << "Number of moves required: " << pow(2, n) - 1 << endl;
}

// output:
// move disk 1 from rod 1 to rod 3
// move disk 2 from rod 1 to rod 2
// move disk 1 from rod 3 to rod 2
// move disk 3 from rod 1 to rod 3
// move disk 1 from rod 2 to rod 1
// move disk 2 from rod 2 to rod 3
// move disk 1 from rod 1 to rod 3
// Number of moves required: 7