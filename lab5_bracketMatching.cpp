#include <iostream>
using namespace std;
#include <vector>
#include <stack>

int main() {
    int n;cin>>n;
    for (int i=0;i<n;i++) {
        string str;
        cin>>str;
        if (str=="") {cout<<"Y"<<endl;continue;}
        stack<char> st;
        bool valid=true;
        for (char c: str) {
            if (c=='(' || c=='[') {
                st.push(c);
            } else {
                if (c==']'&& !st.empty()) {
                    if (st.top()=='[') st.pop();
                    else {valid=false; break;}
                } else if (c==')' && !st.empty()) {
                    if (st.top()=='(') st.pop();
                    else {valid=false;break;}
                } else {
                    valid=false;break;
                }
            }
        }
        if (i<n-1) {
            if (!st.empty()||!valid) cout<<'N'<<endl;
            else cout<<'Y'<<endl;
        } else {
            if (!st.empty()||!valid) cout<<'N';
            else cout<<'Y';
        }


    }
    
}