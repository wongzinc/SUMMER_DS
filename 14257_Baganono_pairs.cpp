#include <iostream>
using namespace std;
#include <vector>
typedef long long ll;
ll invCounts;

void merge(vector<int> &vec,int l,int mid,int r,int k) {
    vector<int> tmp;
    int i=l,j=mid+1;

    // for (int left=l;left<=mid;left++) {
    //     int right=mid+1;
    //     while (right<=r && vec[left]>vec[right]*k) {
    //         invCounts++;
    //         right++;
    //     }
    // }
    int right=mid+1;
    for (int left=l;left<=mid;left++) {
        while (right<=r && vec[left]>vec[right]*k) {
            right++;
        }
        invCounts+=right-(mid+1);
    }

    while (i<=mid && j<=r) {
        if (vec[i]>vec[j]) {
            tmp.emplace_back(vec[j++]);
        } else {
            tmp.emplace_back(vec[i++]);
        }
    }
    while (i<=mid) {
        tmp.emplace_back(vec[i++]);
    }
    while (j<=r) {
        tmp.emplace_back(vec[j++]);
    }
    for (int k=0;k<tmp.size();k++) {
        vec[l+k]=tmp[k];
    }

}

void mergeSort(vector<int> &vec,int l,int r,int k) {
    if (l==r) return;
    int mid=l+(r-l)/2;
    mergeSort(vec,l,mid,k);
    mergeSort(vec,mid+1,r,k);
    merge(vec,l,mid,r,k);
}

int main()
{
    int n,k; cin>>n>>k;
    vector<int> vec(n);
    for (auto &x: vec) cin>>x;
    invCounts=0;
    mergeSort(vec,0,vec.size()-1,k);
    cout<<invCounts<<'\n';
    return 0;
}