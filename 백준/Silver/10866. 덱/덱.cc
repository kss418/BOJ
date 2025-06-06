#include <iostream>
#include <deque>
using namespace std;

deque <int> dq;

int main() {
    int n; cin >> n;
    for(int i = 1;i <= n;i++){
        string s; cin >> s;
        if(s == "push_back"){
            int v; cin >> v;
            dq.push_back(v);
        }
        else if(s == "push_front"){
            int v; cin >> v;
            dq.push_front(v);
        }
        else if(s == "front"){
            if(dq.empty()) cout << -1 << "\n";
            else cout << dq.front() << "\n";
        }
        else if(s == "back"){
            if(dq.empty()) cout << -1 << "\n";
            else cout << dq.back() << "\n";
        }
        else if(s == "empty") cout << dq.empty() << "\n";
        else if(s == "pop_back"){
            if(dq.empty()) cout << -1 << "\n";
            else{
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if(s == "pop_front"){
            if(dq.empty()) cout << -1 << "\n";
            else{
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else cout << dq.size() << "\n";
    }

    return 0;
}

