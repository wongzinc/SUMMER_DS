#include <iostream>
using namespace std;
#include <queue>

int main() {
    int q;cin>>q;
    priority_queue<int,vector<int>,greater<int>> pq;
    while (q--) {
        int op;cin>>op;
        int x;
        if (op==1) {
            cin>>x;
            pq.push(x);
        } else if (op==2) {
            if (!pq.empty()) pq.pop();
        } else if (op==3) {
            if (pq.empty()) cout<<"EMPTY\n";
            else {
                cout<<pq.top()<<endl;
            }
        }
    }
}