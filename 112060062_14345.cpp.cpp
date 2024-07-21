#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N,Q;cin>>N>>Q;
    vector<int> A(N);
    for (int i=0;i<N;i++) cin>>A[i];
    sort(A.begin(),A.end());
    vector<int>::iterator low,up; // upper bound return last equal element +1
    while (Q--) {
        int L,R;cin>>L>>R;
        low=lower_bound(A.begin(),A.end(),L);
        up=upper_bound(A.begin(),A.end(),R);
        cout<<up-low<<endl;
    }
}