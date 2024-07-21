#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n,k;cin>>n>>k;
    priority_queue<int,vector<int>,less<int>> pq;
    vector<pair<int,int>> vec(n);
    for (int i=0;i<n;i++) cin>>vec[i].first>>vec[i].second;
    sort(vec.begin(),vec.end());
    int minSum=INT_MAX;
    for (int i=0;i<n;i++) {
        pq.push(vec[i].second);
        if (pq.size()>k) {
            pq.pop();
        }
        if (pq.size()==k) {
            int maX=vec[i].first;
            int maY=pq.top();
            minSum=min(minSum,maX+maY);
        }
    }
    cout<<minSum<<'\n';
}