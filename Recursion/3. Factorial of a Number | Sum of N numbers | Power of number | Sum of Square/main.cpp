// Factorial of a Number 

#include<bits/stdc++.h>
using namespace std;

int fact(int n) {
    // base case
    if(n == 1 || n == 0) {
        return 1;
    }

    return n * fact(n - 1);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    int n;
    cout << "Input: ";
    cin >> n;
    if(n < 0) {
        cout << "Factorial is not possible" << endl;
        return 0;
    }
    
    cout << "Output: " << fact(n) << endl;
}

// Input: 5
// Output: 120
// ............................................................................................
// Sum of N numbers

#include<bits/stdc++.h>
using namespace std;

int sum(int n) {
    // base case
    if(n == 1) {
        return 1;
    }

    return n + sum(n - 1);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output: " << sum(n) << endl;
}

// Input: 50
// Output: 1275
// ............................................................................................
// Power of number

#include<bits/stdc++.h>
using namespace std;

int pow(int num, int n) {
    // base case

    if(n == 0) {
        return 1;
    }

    return num * pow(num, n - 1);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output: " << pow(2, n) << endl;
}

// Input: 5
// Output: 32
// ............................................................................................
// Sum of Square

#include <bits/stdc++.h>
using namespace std;

int sumOfSquares(int n) {
    // base case
    if (n == 0) {
        return 0;
    }

    return n * n + sumOfSquares(n - 1);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Sum of squares: " << sumOfSquares(n) << endl;
    return 0;
}

// Input: 5
// Sum of squares: 55