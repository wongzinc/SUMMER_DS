 #include <iostream>
#include <vector>
using namespace std;
#include <ctime>

int partition(vector<int> &vec,int l,int r) {
    int pivotIndex=l+rand() % (r-l+1);
    swap(vec[pivotIndex],vec[r]);

    int i=l;
    for (int j=l;j<=r-1;j++) {
        if (vec[j]<=vec[r]) {
            swap(vec[i++],vec[j]);
        } 
    }
    swap(vec[r],vec[i]);
    return i;
}

int quickSelect(vector<int> &vec,int l,int r,int k) {
    if (l==r) return vec[l];
    int pivotIndex=partition(vec,l,r);
    if (pivotIndex==k) {
        return vec[pivotIndex];
    } else if (pivotIndex<k) return quickSelect(vec,pivotIndex+1,r,k);
    else if (pivotIndex>k) return quickSelect(vec,l,pivotIndex-1,k);

}

int main()
{
    srand(time(NULL));
    int n;cin>>n;
    vector<int> vec(n);
    for (int i=0;i<n;i++) cin>>vec[i];
    if (n%2==1) {
        cout<<quickSelect(vec,0,n-1,n/2)<<'\n';
    } else {
        int leftMid=quickSelect(vec,0,n-1,n/2-1);
        int rightMid=quickSelect(vec,0,n-1,n/2);
        cout<<(leftMid+rightMid)/2<<'\n';
    }
    return 0;
}