#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,q,V;cin>>n>>q>>V;
    vector<pair<int,int>> stn(n);
    vector<int> places(q);
    for (int i=0;i<n;i++) cin>>stn[i].first>>stn[i].second;
    for (int i=0;i<q;i++) cin>>places[i];

    vector<int>approaDist;
    approaDist.emplace_back(V);
    for (int i=0;i<n;i++) {
        if (approaDist[i]<stn[i].first) approaDist.emplace_back(approaDist[i]);
        else {
            approaDist.emplace_back(approaDist[i]+stn[i].second);
        }
    }
    for (int i=0;i<q;i++) {
        if (places[i]>approaDist[n]) {
            cout<<-1<<'\n';
            continue;
        }
        int l=0,r=n;
        while (l<=r) {
            int mid=l+(r-l)/2;
            if (places[i]<=approaDist[mid]) r=mid-1;
            else l=mid+1;
        }
        cout<<l<<'\n';
    }
}