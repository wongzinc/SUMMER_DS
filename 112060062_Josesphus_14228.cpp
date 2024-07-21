#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <list>

int main() {
    // int n;cin>>n;
    // queue<int> q;
    // for (int i=1;i<=n;i++) q.push(i);
    // while (q.size()>1) {
    //     q.push(q.front());
    //     q.pop();
    //     cout<<q.front()<<' ';
    //     q.pop();
    // }
    // cout<<q.front();
    // q.pop();

    // int n;cin>>n;
    // vector<int> killed(n,0);
    // int now=-1;
    // for (int i=0;i<n;i++) {
    //     int cnt=2;
    //     while (cnt) {
    //         now=(now+1)%n;
    //         if (!killed[now]) cnt--;
    //     }
    //     killed[now]=1;
    //     cout<<now+1;
    //     if (i<n-1) cout<<' ';
    // }

    int n;cin>>n;
    if (n==1) {
        cout<<1;
        return 0;
    }
    list<int> li;
    for (int i=1;i<=n;i++) {
        li.push_back(i);
    }
    list<int>::iterator it;
    it=li.begin();
    it++;
    for (int i=0;i<n;i++) {
        cout<< *it;
        if (i<n-1) cout<<' ';
        it=li.erase(it);
        if (it==li.end()) it=li.begin();
        it++;
        if (it==li.end()) it=li.begin();
        
    }
    return 0;
}