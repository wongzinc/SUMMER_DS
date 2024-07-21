#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll counts = 0;

void merge(vector<pair<int,int>>& vec, int l, int mid, int r) {
    vector<pair<int,int>> tmp(r - l + 1);
    int i = l, j = mid + 1, k = 0;

    int right=mid+1;
    for (int left=l;left<=mid;left++) {
        while (right<=r && bi<=bj) {
            right++;
        }
        invCounts+=right-(mid+1);
    }

    while (i <= mid && j <= r) {
        bi = max(vec[i].first, vec[i].second);
        bj = max(vec[j].first, vec[j].second);
        if (bi <= bj) {
            // counts += r - j + 1;  // 计数
            tmp[k++] = vec[i++];
        } else {
            tmp[k++] = vec[j++];
        }
    }
    while (i <= mid) tmp[k++] = vec[i++];
    while (j <= r) tmp[k++] = vec[j++];
    
    // 复制回原数组
    for (int p = 0; p < k; p++) {
        vec[l + p] = tmp[p];
    }
}

void mergeSort(vector<pair<int,int>>& vec, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(vec, l, mid);
    mergeSort(vec, mid + 1, r);
    merge(vec, l, mid, r);
}

int main() {
    int n; cin >> n;
    vector<pair<int,int>> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i].first >> vec[i].second;
        if (vec[i].first > vec[i].second) {
            swap(vec[i].first, vec[i].second);
        }
    }
    
    // 按 ai 排序
    sort(vec.begin(), vec.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return min(a.first, a.second) < min(b.first, b.second);
    });
    
    mergeSort(vec, 0, n-1);
    cout << counts << endl;
    return 0;
}