#include<bits/stdc++.h>
using namespace std;

void fun(int n) {
    if(n == 0) {
        return;
    }

    cout << n << ". Happy Birthday!" << endl;
    fun(n - 1);
}

int main() {
    fun(5);
}

// output:
// 5. Happy Birthday!
// 4. Happy Birthday!
// 3. Happy Birthday!
// 2. Happy Birthday!
// 1. Happy Birthday!
// ............................................................................................
#include<bits/stdc++.h>
using namespace std;

void printEven0(int n) {  // from n to base
    if(n == 0) {
        return;
    }

    cout << n << " ";
    printEven0(n - 2);
}

void printEven1(int n) {  // from base to n
    if(n == 0) {
        return;
    }

    printEven1(n - 2);
    cout << n << " ";
}

int main() {
    printEven0(10);
    cout << endl;
    printEven1(10);
}

// output:
// 10 8 6 4 2
// 2 4 6 8 10