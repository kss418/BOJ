#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int n, m, a, b;
int indegree[32001] = {};
int cur;
deque <int> q;
vector <int> arr[32001];
vector <int> result;

int main() {
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        arr[a].push_back(b);
        indegree[b] += 1;
    }
    for (int i = 1; i < n + 1; i++) {
        if (indegree[i] == 0) {
            q.push_back(i);
        }
    }
    while (!q.empty()) {
        cur = q.front();
        q.pop_front();
        result.push_back(cur);
        for (auto i : arr[cur]) {
            indegree[i]--;
            if (indegree[i] == 0) {
                q.push_back(i);
            }
        }
    }
    for (auto i : result) {
        cout << i << " ";
    }
    return 0;
}