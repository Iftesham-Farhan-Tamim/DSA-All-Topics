// Min Chars to Add for Palindrome (https://www.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1?page=1&difficulty)

#include<bits/stdc++.h>
using namespace std;

int minChar(string str) {
    string rev = str;
    reverse(rev.begin(), rev.end());
    int size = str.size();
    str += '$';  // separator
    str += rev;  // reverse

    // longest prefix
    int n = str.size();
    vector<int> lps(n, 0);

    int pre = 0, suf = 1;

    while(suf < str.size()) {
        if(str[pre] == str[suf]) {
            lps[suf] = pre + 1;
            pre++;
            suf++;
        } else {
            if(pre == 0) {
                suf++;
            } else {
                pre = lps[pre - 1];
            }
        }
    }

    return size - lps[n - 1];
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int ans = minChar(s);
    cout << "Minimum characters to add at front to make it a palindrome: " << ans << endl;
}

// input:
// Enter a string: aacecaaaa

// outut:
// Minimum characters to add at front to make it a palindrome: 2

// input:
// Enter a string: abc
// Minimum characters to add at front to make it a palindrome: 2
// ............................................................................................
// Repeated String Match (https://leetcode.com/problems/repeated-string-match/description/)

#include<bits/stdc++.h>
using namespace std;

void lpsfind(vector<int> &lps, string s) {
    int pre = 0, suf = 1;

    while(suf < s.size()) {
        // match
        if(s[pre] == s[suf]) {
            lps[suf] = pre + 1;
            suf++;
            pre++;
        } else {  // not matched
            if(pre == 0) {
                lps[suf] = 0;
                suf++;
            } else {
                pre = lps[pre - 1];
            }
        }
    }
}

int KMP_MATCH(string haystack, string needle) {
    vector<int> lps(needle.size(), 0);
    lpsfind(lps, needle);

    int first = 0, second = 0;

    while(first < haystack.size() && second < needle.size()) {
        // match
        if(haystack[first] == needle[second]) {
            first++;
            second++;
        } else {
            if(second == 0) {
                first++;
            } else {
                second = lps[second - 1];
            }
        }
    }

    // answer exists
    if(second == needle.size()) {
        return 1;
    }

    return 0;
}

int repeatedStringMatch(string a, string b) {
    if(a == b) {
        return 1;
    }

    int repeat = 1;
    string temp = a;

    while(temp.size() < b.size()) {
        temp += a;
        repeat++;
    }

    // KMP pattern search
    if(KMP_MATCH(temp, b) == 1) {
        return repeat;
    }

    // Temp+a, KMP search
    if(KMP_MATCH(temp+a, b) == 1) {
        return repeat + 1;
    }

    return -1;
}

int main() {
    string a, b;
    cout << "Enter string a: ";
    cin >> a;
    cout << "Enter string b: ";
    cin >> b;

    int result = repeatedStringMatch(a, b);
    cout << "Minimum repeats needed: " << result << endl;
}

// input:
// Enter string a: abcd
// Enter string b: cdabcdab

// output:
// Minimum repeats needed: 3

// input:
// Enter string a: a
// Enter string b: aa

// output:
// Minimum repeats needed: 2