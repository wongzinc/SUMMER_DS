#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定義矩形結構
struct Rectangle {
    int min_dim;
    int max_dim;
};

// 合併並計算滿足條件的對數
long long merge_and_count(vector<Rectangle>& rectangles, int left, int mid, int right) {
    vector<Rectangle> left_part(rectangles.begin() + left, rectangles.begin() + mid + 1);
    vector<Rectangle> right_part(rectangles.begin() + mid + 1, rectangles.begin() + right + 1);

    int i = 0, j = 0, k = left;
    long long count = 0;

    while (i < left_part.size() && j < right_part.size()) {
        if (left_part[i].max_dim <= right_part[j].max_dim) {
            count += right_part.size() - j; // 所有右邊部分剩下的矩形都可以容納左邊的這個矩形
            rectangles[k++] = left_part[i++];
        } else {
            rectangles[k++] = right_part[j++];
        }
    }

    // 將剩餘部分加入
    while (i < left_part.size()) {
        rectangles[k++] = left_part[i++];
    }
    while (j < right_part.size()) {
        rectangles[k++] = right_part[j++];
    }

    return count;
}

long long merge_sort_and_count(vector<Rectangle>& rectangles, int left, int right) {
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;
    long long count = 0;

    count += merge_sort_and_count(rectangles, left, mid);
    count += merge_sort_and_count(rectangles, mid + 1, right);
    count += merge_and_count(rectangles, left, mid, right);

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<Rectangle> rectangles(n);

    for (int i = 0; i < n; ++i) {
        int u, r;
        cin >> u >> r;
        rectangles[i].min_dim = min(u, r);
        rectangles[i].max_dim = max(u, r);
    }

    // 按照最小邊排序，如果最小邊相同則按照最大邊排序
    sort(rectangles.begin(), rectangles.end(), [](const Rectangle& a, const Rectangle& b) {
        if (a.min_dim == b.min_dim) return a.max_dim < b.max_dim;
        return a.min_dim < b.min_dim;
    });

    long long result = merge_sort_and_count(rectangles, 0, n - 1);
    cout << result << endl;

    return 0;
}
