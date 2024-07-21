#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
private: 
    vector<int> parent,size;
    int cnt,maxsize;
public:
    UnionFind(int n) : parent(n+1),size(n+1,1),maxsize(1),cnt(n) {
        for (int i=0;i<=n;i++) {
            parent[i]=i;
        }
    }

    int find(int x) {
        return parent[x]==x?parent[x]:parent[x]=find(parent[x]);
    }

    void unite(int x,int y) {
        int rX=find(x),rY=find(y);
        if (rX!=rY) {
            if (size[rX]<size[rY]) swap(rX,rY);
            size[rX]+=size[rY];
            parent[rY]=rX;
            cnt--,maxsize=max(maxsize,size[rX]);
        }
    }
    pair<int,int> retSizeAndMaxsize() {
        return {cnt,maxsize};
    }
};

int main() {
    int n,m;cin>>n>>m;
    UnionFind uf(n);
    int size,maxsize;
    for (int i=0;i<m;i++) {
        int x,y;cin>>x>>y;
        uf.unite(x,y);
        auto [size,maxsize]=uf.retSizeAndMaxsize();
        cout<<size<<' '<<maxsize<<'\n';
    }
}