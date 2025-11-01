// Longest Prefix Suffix (https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1?utm_medium=article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks)

#include<bits/stdc++.h>
using namespace std;

int lps(string s) {
    vector<int> lps(s.size(), 0);
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

    return lps[s.size() - 1];
}

int main() {
    string s = "aabcdaabc";
    cout << lps(s) << endl;
}

// output:
// 4