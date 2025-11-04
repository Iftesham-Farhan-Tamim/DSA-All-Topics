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
    } else {  // matched
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
// count vowels

#include<bits/stdc++.h>
using namespace std;

int count(string str, int index) {
    if(index == -1) {
        return 0;
    }

    // if vowel
    if(str[index] == 'a' || str[index] == 'e' || str[index] == 'i' || 
       str[index] == 'o' || str[index] == 'u') {
        return 1 + count(str, index - 1);
    } else {  // if not
        return count(str, index - 1);
    }
}

int main() {
    // count vowels
    string str = "helloworld";
    cout << count(str, 5) << endl;
}

// output:
// 2
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
    string str = "hello";
    rev(str, 0, 4);
    cout << str << endl;
}

// output:
// olleh
// ............................................................................................
// lower case to upper case

#include<bits/stdc++.h>
using namespace std;

void lowerToUpper(string &str, int index) {
    if(index == -1) {
        return;
    }

    str[index] = 'A' + str[index] - 'a';
    lowerToUpper(str, index - 1);
}

int main() {
    string str = "hello";
    lowerToUpper(str, 4);
    cout << str << endl;
}

// output:
// HELLO