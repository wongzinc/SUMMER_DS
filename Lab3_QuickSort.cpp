#include <iostream>
using namespace std;
#include <vector>

int partition(vector<int> &vec,int l,int r)
{
    // int pivot=vec[r];
    int i=l;
    for (int j=l;j<=r-1;j++) {
        if (vec[j]<=vec[r]) {
            swap(vec[j],vec[i++]);
        }
    }
    swap(vec[i],vec[r]);
    return i;
}

int quickSelect(vector<int> &vec,int l,int r,int k)
{
    // if (l<r) {
    //     int pivot=partition(vec,l,r);
    //     quickSort(vec,l,pivot-1);
    //     quickSort(vec,pivot+1,r);
    // }
    if (l==r) return vec[l];
    int pivot=partition(vec,l,r);
    int length=pivot-l+1;
    if (k==length) return vec[pivot];
    else if (k<length) return quickSelect(vec,l,pivot-1,k);
    else return quickSelect(vec,pivot+1,r,k-length);
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    for (auto &x: vec) cin>>x;
    cout<< quickSelect(vec,0,n-1,n-k+1)<<endl;

    return 0;
}