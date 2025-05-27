#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    if(x < 2) {
        return x;
    }

    int start = 0, end = x, mid, ans;

    while(start <= end) {
        mid = start + (end - start) / 2;

        if(mid == x / mid) {
            return mid;
        } else if(mid < x / mid) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
	int x;
	cin >> x;

	cout << mySqrt(x) << endl;
}

// input:
// 4

// output:
// 2

// input:
// 8

// output:
// 2