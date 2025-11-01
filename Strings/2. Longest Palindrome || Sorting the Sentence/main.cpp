// Longest Palindrome (https://leetcode.com/problems/longest-palindrome/description/)

#include<bits/stdc++.h>
using namespace std;

int longestPalindrome(string s) {
    vector<int>lower(26, 0);
    vector<int>upper(26, 0);

    // frequence updated
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 'a') {
            lower[s[i] - 'a']++;
        } else {
            upper[s[i] - 'A']++;
        }
    }

    int count = 0;
    bool odd = 0;

    for(int i = 0; i < 26; i++) {
        // lower
        if(lower[i] % 2 == 0) {
            count+=lower[i];
        } else {
            count+=lower[i] - 1;
            odd = 1;
        }

        // upper
        if(upper[i] % 2 == 0) {
            count+=upper[i];
        } else {
            count+=upper[i] - 1;
            odd = 1;
        }
    }

    return count + odd;
}

int main() {
    string s;
    getline(cin, s);
    cout << longestPalindrome(s) << endl;
}

// input:
// abccccdd

// output:
// 7
// ............................................................................................
// Sorting the Sentence (https://leetcode.com/problems/sorting-the-sentence/description/)

#include<bits/stdc++.h>
using namespace std;

string sortSentence(string s) {
    s.push_back(' ');
    vector<string> answer(s.size());
    string temp;
    int count = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            int position = temp.back() - '0';
            temp.pop_back();
            answer[position] = temp;
            count++;
            temp.clear();
        } else {
            temp += s[i];
        }
    }

    string result;
    for (int i = 1; i <= count; i++) {
        if (i > 1) {
            result += ' ';
        }
        result += answer[i];
    }

    return result;
}

int main() {
    string s;
    getline(cin, s); 
    cout << sortSentence(s) << endl;
}

// input:
// is2 sentence4 This1 a3

// output:
// This is a sentence