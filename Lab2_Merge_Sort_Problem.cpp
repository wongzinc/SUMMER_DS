#include <iostream>
using namespace std;
#include <vector>
typedef long long LL;

void merge(vector<LL> &vec,int l,int r) {
    int i=l,mid=(l+r)/2;
    int j=mid+1;
    vector<LL> tmp;
    while (i<=mid && j<=r) {
        if (vec[i]>vec[j]) tmp.emplace_back(vec[i++]);
        else if (vec[i]<vec[j]) tmp.emplace_back(vec[j++]);
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

void merge_sort(vector<LL> &vec,int l,int r) {
    // divide and conquer
    if (l==r) return;
    int mid=(l+r)/2;
    merge_sort(vec,l,mid);
    merge_sort(vec,mid+1,r);
    merge(vec,l,r);
}

int main()
{
    int n;cin>>n;
    vector<LL> vec(n);
    for (int i=0;i<n;i++) {
        cin>>vec[i];
    }
    merge_sort(vec,0,n-1);
    for (int i=0;i<vec.size();i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}