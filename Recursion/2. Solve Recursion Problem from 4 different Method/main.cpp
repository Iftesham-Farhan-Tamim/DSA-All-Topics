#include<bits/stdc++.h>
using namespace std;

void print(int num, int n) {
    // base case
    if(num == n) {
        cout << num << " ";
        return;
    }

    cout << num << " ";
    print(num + 1, n);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output: ";
    print(1, n);
}

// Input: 5
// Output: 1 2 3 4 5
// ............................................................................................
#include<bits/stdc++.h>
using namespace std;

void print1(int n) {
    // base case
    if(n == 1) {
        cout << 1 << " ";
        return;
    }

    cout << n << " ";
    print1(n - 1);
}

void print2(int n) {
    // base case
    if(n == 1) {
        cout << 1 << " ";
        return;
    }

    print2(n - 1);
    cout << n << " ";
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output: ";
    print1(n);
    cout << endl;
    cout << "Output: ";
    print2(n);
}

// Input: 8
// Output: 8 7 6 5 4 3 2 1 
// Output: 1 2 3 4 5 6 7 8
// ............................................................................................
#include<bits/stdc++.h>
using namespace std;

void printeven(int num, int n) {
    if(num == n) {
        cout << num << endl;
        return;
    }

    cout << num << " ";
    printeven(num + 2, n);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cout << "Input: ";
    cin >> n;

    if(n % 2 == 1) {
        n--;
    }

    cout << "Output: ";
    printeven(2, n);
}

// Input: 13
// Output: 2 4 6 8 10 12
// ............................................................................................
#include<bits/stdc++.h>
using namespace std;

void printeven(int num, int n) {
    if(num > n) {
        return;
    }

    cout << num << " ";
    printeven(num + 2, n);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cout << "Input: ";
    cin >> n;

    cout << "Output: ";
    printeven(2, n);
}

// Input: 13
// Output: 2 4 6 8 10 12
// ............................................................................................
#include<bits/stdc++.h>
using namespace std;

void printeven(int n) {
    if(n == 2) {
        cout << 2 << " ";
        return;
    }

    printeven(n-2);
    cout << n << " ";
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cout << "Input: ";
    cin >> n;

    if(n % 2 == 1) {
       n--;
    }

    cout << "Output: ";
    printeven(n);
}

// Input: 13
// Output: 2 4 6 8 10 12