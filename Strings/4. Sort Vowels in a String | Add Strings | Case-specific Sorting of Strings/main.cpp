// Sort Vowels in a String (https://leetcode.com/problems/sort-vowels-in-a-string/description/)

#include<bits/stdc++.h>
using namespace std;

string sortVowels(string s) {
    vector<int>lower(26, 0);
    vector<int>upper(26, 0);

    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            lower[s[i] - 'a']++;
            s[i] = '#';
        } else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            upper[s[i] - 'A']++;
            s[i] = '#';
        }
    }

    string vowel;
    // upper
    for(int i=0; i<26; i++) {
        char c = 'A' + i;
        while(upper[i]) {
            vowel+=c;
            upper[i]--;
        }
    }

    // lower
    for(int i=0; i<26; i++) {
        char c = 'a' + i;
        while(lower[i]) {
            vowel+=c;
            lower[i]--;
        }
    }

    int first = 0, second = 0;

    while(second < vowel.size()) {
        if(s[first] == '#') {
            s[first] = vowel[second];
            second++;
        }

        first++;
    }

    return s;
}

int main() {
    string s = "lEetcOde";
    cout << sortVowels(s) << endl;
}

// output:
// lEOtcede
// ............................................................................................
// Add Strings (https://leetcode.com/problems/add-strings/description/)

#include<bits/stdc++.h>
using namespace std;

string add(string num1, string num2) {
    string ans;
    int index1 = num1.size() - 1, index2 = num2.size() - 1;
    int sum, carry = 0;

    // index2 >= 0

    while(index2 >= 0) {
        sum = (num1[index1] - '0') + (num2[index2] - '0') + carry;
        carry = sum / 10;
        char c = '0' + sum % 10;
        ans += c;
        index2--;
        index1--;
    }

    // index1 >= 0

    while(index1 >= 0) {
        sum = (num1[index1] - '0') + carry;
        carry = sum / 10;
        char c = '0' + sum % 10;
        ans += c;
        index1--;
    }

    if(carry) {
        ans += '1';
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

string addStrings(string num1, string num2) {
    if(num1.size() < num2.size()) {
        return add(num2, num1);
    } else {
        return add(num1, num2);
    }
}

int main() {
    string num1 = "456";
    string num2 = "77";
    cout << addStrings(num1, num2) << endl;
}

// output:
// 533
// ............................................................................................
// Case-specific Sorting of Strings (https://www.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1?page=2&difficulty)

#include<bits/stdc++.h>
using namespace std;

string caseSort(string &s) {

    int n = s.length();
    vector<char> lower, upper;

    for (int i = 0; i < n; i++) {
        char ch = s[i];
        if (islower(ch)) {
            lower.push_back(ch);
        } else {
            upper.push_back(ch);
        }
    }

    sort(lower.begin(), lower.end());
    sort(upper.begin(), upper.end());

    string result = s;
    int lowerIndex = 0, upperIndex = 0;

    for (int i = 0; i < n; i++) {
        if (islower(s[i])) {
            result[i] = lower[lowerIndex++];
        } else {
            result[i] = upper[upperIndex++];
        }
    }

    return result;
}

int main() {
    string s = "GEekS";
    cout << caseSort(s) << endl;  
}

// output:
// EGekS