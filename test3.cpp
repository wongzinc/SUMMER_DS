#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rectangle {
    int u, r;
    Rectangle() : u(0), r(0) {}
    Rectangle(int _u, int _r) : u(_u), r(_r) {}
};

long long merge_count(vector<Rectangle>& arr, int left, int mid, int right) {
    vector<Rectangle> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    long long count = 0;

    while (i <= mid && j <= right) {
        if (arr[i].r <= arr[j].r) {
            temp[k++] = arr[i++];
        } else {
            count += (mid - i + 1);  // All elements from i to mid can form valid pairs with arr[j]
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int p = 0; p < k; p++) {
        arr[left + p] = temp[p];
    }

    return count;
}

long long merge_sort_and_count(vector<Rectangle>& arr, int left, int right) {
    long long count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        count += merge_sort_and_count(arr, left, mid);
        count += merge_sort_and_count(arr, mid + 1, right);
        count += merge_count(arr, left, mid, right);
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<Rectangle> rectangles;

    for (int i = 0; i < n; ++i) {
        int u, r;
        cin >> u >> r;
        rectangles.emplace_back(u, r);
    }

    // Sort by 'u' coordinate and count
    sort(rectangles.begin(), rectangles.end(), [](const Rectangle& a, const Rectangle& b) {
        return a.u < b.u;
    });
    long long count = merge_sort_and_count(rectangles, 0, n - 1);

    // Count for the rotated case
    for (auto& rect : rectangles) {
        swap(rect.u, rect.r);
    }
    sort(rectangles.begin(), rectangles.end(), [](const Rectangle& a, const Rectangle& b) {
        return a.u < b.u;
    });
    count += merge_sort_and_count(rectangles, 0, n - 1);

    cout << count << endl;
    return 0;
}
