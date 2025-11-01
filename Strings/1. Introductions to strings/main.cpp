#include<bits/stdc++.h>
using namespace std;

int main() {
    char arr[] = {'a', 'p', 'p', 'l', 'e'};
    for(int i=0; i<5; i++) {
        cout << arr[i];
    }
    cout << endl;
}

// output:
// apple
// ............................................................................................
#include<bits/stdc++.h>
using namespace std;

int main() {
    char arr[20];
    // cin >> arr;
    cin.getline(arr, 20);
    cout << arr;
}

// input:
// hello world

// output:
// hello world
// ............................................................................................
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s = "Tamim";
    cout << s << endl;
}

// output:
// Tamim
// ............................................................................................
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    cout << s << endl;
    cout << s.size() << endl;
}

// input:
// hello world

// output:
// hello world
// 11
// ............................................................................................
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1 = "hello ", s2 = "world";
    string s3 = s1 + s2;
    string s4 = s1.append(s2);
    cout << s3 << endl;
    cout << s4 << endl;
}

// output:
// hello world
// hello world
// ............................................................................................
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1 = "hello";
    s1.push_back('p');
    // s1 = s1 + "p";
    // s1 = s1 + 'p';
    cout << s1 << endl;
}

// output:
// hellop
// ............................................................................................
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1 = "hello";
    s1.pop_back();
    cout << s1 << endl;
}

// output:
// hell
// ............................................................................................
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s = "ABC is a \"good\" boy";
    string p = "\\0";
    cout << s << endl;
    cout << p << endl;
}

// output:
// ABC is a "good" boy
// \0
// ............................................................................................
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s = "hello";

    int start = 0, end = s.size() - 1;

    while(start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }

    cout << s;

    int size = 0;
    while(s[size] != '\0') {
        size++;
    }

    cout << endl;
    cout << size << " ";

    string s2 = "madam";
    start = 0, end = s2.size() - 1;

    while(start < end) {
        if(s2[start] != s2[end]) {
            cout << "Not a palindrome";
            return 0;
        }
        start++;
        end--;
    }

    cout << "It's a palindrome";
}

// output:
// olleh
// 5
// ............................................................................................
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s2 = "madam";
    int start = 0, end = s2.size() - 1;

    while(start < end) {
        if(s2[start] != s2[end]) {
            cout << "Not a palindrome";
            return 0;
        }
        start++;
        end--;
    }

    cout << "It's a palindrome" << endl;
}

// output:
// It's a palindrome