// Fibonacci Number (https://leetcode.com/problems/fibonacci-number/description/)

#include<bits/stdc++.h>
using namespace std;

int fib(int n) {
    if(n <= 1) {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output: " << fib(n) << endl;
}

// Input: 10
// Output: 55
// ............................................................................................
// Climbing Stairs (https://leetcode.com/problems/climbing-stairs/description/)

#include<bits/stdc++.h>
using namespace std;

int climb(int n) {
    if(n <= 1) {
        return 1;
    }

    return climb(n - 1) + climb(n - 2);
}

int main() {
    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output: " << climb(n) << endl;
}

// Input: 5
// Output: 8
// ............................................................................................
// GCD of two numbers (https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1?utm_medium=article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks)

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    int x, y;
    cout << "Input of first number: ";
    cin >> x;
    cout << "Input of second number: ";
    cin >> y;
    cout << "GCD of " << x << " and " << y << " is: " << gcd(x, y) << endl;
}

// Input of first number: 24
// Input of second number: 36
// GCD of 24 and 36 is: 12