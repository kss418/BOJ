#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
typedef long long ll;
using namespace std;
vector <int> arr[200001];
int indegree[200001];
int visit[200001];
int v[200001];
int notcycle[200001];
int comp[200001];


void dfs(int cur, int cnt) {
    if (v[cur]) {
        return;
    }
    v[cur] = 1;
    comp[cur] = cnt;

    for (auto nxt : arr[cur]) {
        if (!notcycle[nxt]) {
            continue;
        }

        if (!v[nxt]) {
            dfs(nxt, cnt);
        }
    }

    v[cur] = 0;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int st, en;
        cin >> st >> en;
        arr[st].push_back(en);
        arr[en].push_back(st);
        indegree[st]++;
        indegree[en]++;
    }

    deque <int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 1) {
            q.push_back(i);
            notcycle[i] = 1;
        }
    }


    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();

        if (visit[cur]) {
            continue;
        }
        visit[cur] = 1;

        for (auto nxt : arr[cur]) {
            if (visit[nxt]) {
                continue;
            }

            indegree[nxt]--;
            if (indegree[nxt] == 1) {
                q.push_back(nxt);
                notcycle[nxt] = 1;
            }
        }
    }

    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (!notcycle[i]) {
            dfs(i, cnt);
            cnt++;
        }
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        if (!notcycle[a] && !notcycle[b]) {
            cout << 2 << "\n";
        }
        else {
            if (comp[a] == comp[b]) {
                cout << 1 << "\n";
            }
            else {
                cout << 2 << "\n";
            }
        }
    }


    return 0;
}