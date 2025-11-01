// Defanging an IP Address (https://leetcode.com/problems/defanging-an-ip-address/description/)

#include<bits/stdc++.h>
using namespace std;

string defangIPaddr(string address) {
    string ans;
    int index = 0;

    while(index < address.size()) {
        if(address[index] == '.') {
            ans+="[.]";
        } else {
            ans+=address[index];
        }

        index++;
    }

    return ans;
}

int main() {
    string ip1 = "192.168.1.1";
    string ip2 = "1.1.1.1";

    string defanged1 = defangIPaddr(ip1);
    cout << "Original: " << ip1 << endl;
    cout << "Defanged: " << defanged1 << endl << endl;

    string defanged2 = defangIPaddr(ip2);
    cout << "Original: " << ip2 << endl;
    cout << "Defanged: " << defanged2 << endl;
}

// Original: 192.168.1.1
// Defanged: 192[.]168[.]1[.]1

// Original: 1.1.1.1
// Defanged: 1[.]1[.]1[.]1
// ............................................................................................
// Check if string is rotated by two places (https://www.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1?utm_medium=article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks)

#include<bits/stdc++.h>
using namespace std;

void rotateAntiClockWise(string &s) {
    char c = s[0];
    int index = 1;

    while(index < s.size()) {
        s[index - 1] = s[index];
        index++;
    }

    s[s.size() - 1] = c;
}

void rotateClockWise(string &s) {
    char c = s[s.size() - 1];
    int index = s.size() - 2;

    while(index >= 0) {
        s[index + 1] = s[index];
        index--;
    }

    s[0] = c;
}

bool isRotated(string str1, string str2) {
    if(str1.size() != str2.size()) {
        return 0;
    }

    string clockWise, antiClockWise;

    clockWise = str1;
    rotateAntiClockWise(antiClockWise);
    rotateAntiClockWise(antiClockWise);

    if(antiClockWise == str2) {
        return 1;
    }

    antiClockWise = str1;
    rotateAntiClockWise(antiClockWise);
    rotateAntiClockWise(antiClockWise);

    if(antiClockWise == str2) {
        return 1;
    }

    return 0;
}

int main() {
    string str1 = "geeksforgeeks";
    string str2 = "geeksgeeksfor";

    if (isRotated(str1, str2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

// output:
// Yes
// ............................................................................................
// Check if the Sentence Is Pangram (https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/)

#include<bits/stdc++.h>
using namespace std;

bool checkIfPangram(string sentence) {
    vector<bool>alpha(26, 0);

    // for(int i = 0; i < sentence.size(); i++) {  // for leetcode only
    //     alpha[sentence[i] - 'a'] = 1;
    // }

    for(int i = 0; i < sentence.size(); i++) {
        char c = tolower(sentence[i]);
        if(c >= 'a' && c <= 'z') {
            alpha[c - 'a'] = 1;
        }
    }

    for(int i = 0; i < 26; i++) {
        if(alpha[i] == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    string s = "thequickbrownfoxjumpsoverthelazydog";

    if(checkIfPangram(s)) {
        cout << "Yes, it is a pangram" << endl;
    } else {
        cout << "No, it is not a pangram" << endl;
    }
}

// output:
// Yes, it is a pangram
// ............................................................................................
// Sort a String (https://www.geeksforgeeks.org/problems/sort-a-string2943/1?utm_medium=article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks)

#include<bits/stdc++.h>
using namespace std;

string sort(string s) {
    vector<int> alpha(26, 0);
    for(int i=0; i<s.size(); i++) {
        alpha[s[i] - 'a']++;
    }

    string ans;
    for(int i=0; i<26; i++) {
        char c = 'a' + i;
        while(alpha[i]) {
            ans+=c;
            alpha[i]--;
        }
    }

    return ans;
}

int main() {
    string s = "edcab";
    cout << sort(s) << endl;
}

// output:
// abcde