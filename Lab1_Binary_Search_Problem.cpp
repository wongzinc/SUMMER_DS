
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

// non-increasing
// return true or false then write corresponding answer ""Y or N"

bool binary_search(vector<LL> &vec,LL target) {
    int left=0,right=vec.size()-1;
    while (left<=right) {
        int mid=(left+right)/2;
        if (vec[mid]<target) {
            right=mid-1;
        } else if (vec[mid]>target) {
            left=mid+1;
        } else {
            return true;
        }
    }
    return false;
}

int main()
{
    int size,num_inputs;
    cin>>size>>num_inputs;
    // vector<LL> vec(size);
    vector<LL> vec;
    // for (int i=0;i<size;i++) {
    //     cin>>vec[i];
    // }
    LL x;
    for (int i=0;i<size;i++) {
        cin>>x;
        vec.emplace_back(x);
    }
    
    for (int i=0;i<num_inputs;i++) {
        cin>>x;
        if (binary_search(vec,x)) {
            cout<<"Y ";
        } else {
            cout<<"N ";
        }
    }
    return 0;
}