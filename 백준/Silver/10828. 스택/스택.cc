#include <iostream>
#include <stack>
using namespace std;

stack <int> st;
int main() {
    int n; cin >> n;
    for(int i = 1;i <= n;i++){
        string s; cin >> s;
        if(s == "push"){
            int v; cin >> v;
            st.push(v);
        }
        else if(s == "pop"){
            if(st.empty()) cout << -1 << "\n";
            else{
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if(s == "size") cout << st.size() << "\n";
        else if(s == "empty") cout << st.empty() << "\n";
        else{ // top
            if(st.empty()) cout << -1 << "\n";
            else cout << st.top() << "\n";
        }
    }

    return 0;
}

