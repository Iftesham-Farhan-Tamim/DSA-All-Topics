// Trapping Rain Water (https://leetcode.com/problems/trapping-rain-water/description/)

#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height) {
    int n = height.size(), water = 0;
    int leftmax = 0, rightmax = 0, maxheight = height[0], index = 0;

    for(int i = 1; i < n; i++) {
        if(maxheight < height[i]) {
            maxheight = height[i];
            index = i;
        }
    }

    // left part

    for(int i = 0; i < index; i++) {
        if(leftmax > height[i]) {
            water += leftmax - height[i];
        } else {
            leftmax = height[i];
        }
    }

    // right part

    for(int i = n - 1; i > index; i--) {
        if(rightmax > height[i]) {
            water += rightmax - height[i];
        } else {
            rightmax = height[i];
        }
    }

    return water;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(height) << endl;
}

// output:
// 6
//............................................................................................
// Triplet Sum in Array or 3 sum (https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1?utm_medium=article_practice_tab&utm_campaign=article_practice_tab&utm_source=geeksforgeeks)

#include<bits/stdc++.h>
using namespace std;

bool find3numbers(int a[], int n, int x) {
    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            if(a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }

    for(int i = 0; i < n - 2; i++) {
        int ans = x - a[i];
        int start = i + 1, end = n - 1;

        while(start < end) {
            if(a[start] + a[end] == ans) {
                return 1;
            } else if(a[start] + a[end]) {
                end--;
            } else {
                start++;
            }
        }
    }

    return 0;
}

int main() {
    int arr[] = { 1, 4, 45, 6, 10, 8 }; 
    int target = 13; 

    if(find3numbers(arr, 6, target)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

// output:
// true
//............................................................................................
// Four Elements or 4 sum (https://www.geeksforgeeks.org/problems/four-elements2452/1)

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
    
// }
//............................................................................................
// Array 3 Pointers (https://www.interviewbit.com/problems/array-3-pointers/)

