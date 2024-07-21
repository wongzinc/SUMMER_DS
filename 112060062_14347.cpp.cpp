#include <iostream>
using namespace std;
#include <vector>
typedef long long ll;
ll invcounts=0; 

void merge(vector<ll> &vec,ll l,ll mid,ll r) {
    int i=l,j=mid+1;
    vector<ll> tmp;
    while (i<=mid && j<=r) {
        if (vec[i]<=vec[j]) tmp.emplace_back(vec[i++]);
        else {
            invcounts+=mid-i+1;
            tmp.emplace_back(vec[j++]);
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

void mergeSort(vector<ll> &vec,ll l,ll r) {
    if (l==r) return;
    ll mid=(l+r)/2;
    mergeSort(vec,l,mid);
    mergeSort(vec,mid+1,r);
    merge(vec,l,mid,r);
}

int main()
{
    int n;cin>>n;
    vector<ll> vec(n);
    for (int i=0;i<n;i++) cin>>vec[i];
    mergeSort(vec,0,n-1);
    cout<< invcounts<<endl;
    return 0;
}