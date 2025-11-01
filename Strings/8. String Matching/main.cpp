// Find the Index of the First Occurrence in a String (https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)

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

int strStr(string haystack, string needle) {
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
        return first - second;
    }

    return -1;
}

int main() {
    string haystack, needle;
    cin >> haystack >> needle; 

    int index = strStr(haystack, needle);
    cout << index << endl;
}

// input:
// sadbutsad
// sad

// output:
// 0

// input:
// leetcode
// leeto

// output:
// -1
// ............................................................................................
// Search Pattern (https://www.geeksforgeeks.org/problems/search-pattern0205/1)
 
#include <bits/stdc++.h>
using namespace std;

void constructLps(string &pat, vector<int> &lps) {
    int len = 0;

    lps[0] = 0;

    int i = 1;
    while (i < pat.length()) {

        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> search(string &pat, string &txt) {
    int n = txt.length();
    int m = pat.length();

    vector<int> lps(m);
    vector<int> res;

    constructLps(pat, lps);
    int i = 0;
    int j = 0;

    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
            if (j == m) {
                res.push_back(i - j);
                j = lps[j - 1];
            }
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return res;
}

int main() {
    string txt = "abcab";
    string pat = "ab";

    vector<int> res = search(pat, txt);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}

// output:
// 0 3