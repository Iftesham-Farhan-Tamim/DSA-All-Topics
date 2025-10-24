// check palindrome

#include<bits/stdc++.h>
using namespace std;

bool checkPal(string str, int start, int end) {
    // base case
    if(start >= end) {
        return 1;
    }

    // not matched
    if(str[start] != str[end]) {
        return 0;
    } else {
        return checkPal(str, start + 1, end - 1);
    }
}

int main() {
    string str = "madam";
    cout << checkPal(str, 0, 4) << endl;
}

// output:
// 1
// ............................................................................................
// check vowel

#include<bits/stdc++.h>
using namespace std;

int count(string str, int idx) {
    if(idx == -1) {
        return 0;
    }

    // check voewl
    if(str[idx] == 'a' || str[idx] == 'e' || str[idx] == 'i' || str[idx] == 'o' || str[idx] == 'u') {
        return 1 + count(str, idx - 1);
    } else {
        return count(str, idx - 1);
    }
}

int main() {
    string str = "roeits";
    cout << count(str, 5) << endl;
}

// output:
// 3
// ............................................................................................
// reverse a string

#include<bits/stdc++.h>
using namespace std;

void rev(string &str, int start, int end) {
    if(start >= end) {
        return;
    }

    char c = str[start];
    str[start] = str[end];
    str[end] = c;
    rev(str, start + 1, end - 1);
}

int main() {
    string str = "tamim";
    rev(str, 0, 4);
    cout << str << endl;
}

// output:
// mimat
// ............................................................................................
// String Lowercase to Uppercase Conversion

#include<bits/stdc++.h>
using namespace std;

void lowertoupper(string &str, int idx) {
    if(idx == -1) {
        return;
    }

    str[idx] = 'A' + str[idx] - 'a';
    lowertoupper(str, idx - 1);
}

int main() {
    string str = "tamim";
    lowertoupper(str, 5);
    cout << str << endl;
}

// output:
// TAMIM