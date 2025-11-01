// Roman to Integer (https://leetcode.com/problems/roman-to-integer/description/)

#include<bits/stdc++.h>
using namespace std;

int num(char c) {
    if(c == 'I') {
        return 1;
    } else if(c == 'V') {
        return 5;
    } else if(c == 'X') {
        return 10;
    } else if(c == 'L') {
        return 50;
    } else if(c == 'C') {
        return 100;
    } else if(c == 'D') {
        return 500;
    } else {
        return 1000;
    }
}

int romanToInt(string s) {
    int sum = 0, index = 0;

    while(index < s.size() - 1) {
        if(num(s[index]) < num(s[index + 1])) {
            sum -= num(s[index]);
        } else {
            sum += num(s[index]);
            index++;
        }
    }

    sum += num(s[index]);
    return sum;
}

int main() {
    string s;
    cin >> s;
    cout << romanToInt(s) << endl;
}

// input:
// III

// output:
// 3

// input:
// LVIII

// output:
// 58
// ............................................................................................
// Factorial of Large Number (https://www.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1?page=1&category=Strings&difficulty=Medium&sortBy=submissions)

#include<bits/stdc++.h>
using namespace std;

vector<int> factorial(int n) {
    vector<int> ans(1, 1);

    while(n > 1) {
        int carry = 0, res, size = ans.size();

        for(int i=0; i<size; i++) {
            res = ans[i] * n + carry;
            ans[i] = res % 10;
            carry = res / 10;
        }

        while(carry) {
            ans.push_back(carry % 10);
            carry /= 10;
        }

        n--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n;
    cin >> n; 

    vector<int> result = factorial(n); 

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }

    cout << endl;
}

// input:
// 5

// output:
// 120

// input:
// 10

// output:
// 3628800
// ............................................................................................
// Integer to Roman (https://leetcode.com/problems/integer-to-roman/description/)

#include<bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
    const vector<pair<int, string>> valueSymbols {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},   {1, "I"}
    };

    string res;

    for (int i = 0; i < valueSymbols.size(); i++) {
        int value = valueSymbols[i].first;
        string symbol = valueSymbols[i].second;

        while (num >= value) {
            res += symbol;
            num -= value;
        }
    }

    return res;        
}

int main() {
    int num;
    cin >> num; 
    cout << intToRoman(num) << endl;
}

// input:
// 3749

// output:
// MMMDCCXLIX

// input:
// 58

// output:
// LVIII