#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    ll count = 0;
    int i = left, j = mid + 1, k = left;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            for (int p = i; p <= mid; p++) {
                if (arr[p] < arr[j]) {
                    count += right - j + 1;
                } else {
                    break;
                }
            }
            temp[k++] = arr[j++];
        }
    }
    
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    
    return count;
}

ll mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    if (left >= right) return 0;
    
    int mid = left + (right - left) / 2;
    ll count = 0;
    
    count += mergeSortAndCount(arr, temp, left, mid);
    count += mergeSortAndCount(arr, temp, mid + 1, right);
    count += mergeAndCount(arr, temp, left, mid, right);
    
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;
    
    vector<int> temp(n);
    ll result = mergeSortAndCount(arr, temp, 0, n - 1);
    cout << result << '\n';
    
    return 0;
}