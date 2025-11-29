// Merge K sorted linked lists (https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article)

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class compare {
public:
    bool operator()(Node *a, Node *b) {
        return a -> data > b -> data;
    }
};

Node *mergeKLists(Node *arr[], int k) {
    priority_queue<Node *, vector<Node *>, compare> p(arr, arr + k);

    Node *root = new Node(0);
    Node *tail = root;

    Node *temp;

    while(!p.empty()) {
        temp = p.top();
        p.pop();
        tail -> next = temp;
        tail = tail -> next;

        if(temp -> next) {
            p.push(temp -> next);
        }
    }

    return root -> next;
}

int main() {
    int k = 3;

    Node *arr[k];

    arr[0] = new Node(1);
    arr[0]->next = new Node(4);
    arr[0]->next->next = new Node(7);

    arr[1] = new Node(2);
    arr[1]->next = new Node(5);
    arr[1]->next->next = new Node(8);

    arr[2] = new Node(3);
    arr[2]->next = new Node(6);
    arr[2]->next->next = new Node(9);

    Node *result = mergeKLists(arr, k);

    cout << "Merged Linked List: ";
    while(result != NULL) {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;
}

// output:
// Merged Linked List: 1 2 3 4 5 6 7 8 9
// ............................................................................................
// Merge k Sorted Arrays (https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1)

#include<bits/stdc++.h>
using namespace std;

vector<int> mergeKArrays(vector<vector<int> > arr, int k) {
    vector<pair<int, pair<int, int>>> temp;
    for(int i=0; i<k; i++) {
        temp.push_back(make_pair(arr[i][0], make_pair(i, 0)));
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p(temp.begin(), temp.end());

    vector<int> ans;
    pair<int, pair<int, int>> element;
    int i;
    int j;

    while(!p.empty()) {
        element = p.top();
        p.pop();
        ans.push_back(element.first);
        i = element.second.first;
        j = element.second.second;
        if(j + 1 < k) {
            p.push(make_pair(arr[i][j + 1], make_pair(i, j + 1)));
        }
    }

    return ans;
}

int main() {
    int k = 3; 

    vector<vector<int> > arr = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    vector<int> result = mergeKArrays(arr, k);

    cout << "Merged Array: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

// output:
// Merged Array: 1 2 3 4 5 6 7 8 9 
// ............................................................................................
// optimized version

#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
    vector<int>temp(end-start+1);
    int left = start, right = mid + 1, index = 0;

    while(left <= mid && right <= end) {
        if(arr[left] <= arr[right]) {
            temp[index] = arr[left];
            index++;
            left++;
        } else {
            temp[index] = arr[right];
            index++;
            right++;
        }
    }

    // left array is not empty yet
    while (left <= mid) {
        temp[index] = arr[left];
        index++;
        left++;
    }

    // right array is not empty yet
    while(right <= end) {
        temp[index] = arr[right];
        index++; 
        right++;
    }

    index = 0;
    while(start <= end) {
        arr[start] = temp[index];
        start++;
        index++;
    }
}

void mergeSort(int arr[], int start, int end, int portion, int k) {
    // base case
    if(portion < 2) {
        return;
    }

    int mid = start + (portion/2) * k - 1;

    // left side
    mergeSort(arr, start, mid, portion / 2, k);

    // right side
    mergeSort(arr, mid+1, end, portion-portion/2, k);
    
    merge(arr, start, mid, end);
}

vector<int> mergeKArrays(vector<vector<int> > arr, int k) {
    vector<int> ans;
    // for(int i = 0; i < k; i++) {
    //     for(int j = 0; j < k; j++) {
    //         ans.push_back(arr[i][j]);
    //     }
    // }

    for(int i = 0; i < arr.size(); i++) {  // arr.size() → number of rows = 3
        for(int j = 0; j < arr[i].size(); j++) {  // arr[i].size() → number of elements in row i = 4
            ans.push_back(arr[i][j]);
        }
    }
    
    mergeSort(ans.data(), 0, ans.size() - 1, k, k);
    return ans;
}

int main() {
    int k = 3;
    vector<vector<int>> arr = {
        {1, 3, 5},
        {2, 4, 6},
        {0, 7, 8}
    };

    vector<int> ans = mergeKArrays(arr, k);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

// output:
// 0 1 2 3 4 5 6 7 8 9 10 11 