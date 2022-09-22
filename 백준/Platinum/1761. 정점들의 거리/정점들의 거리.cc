#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, st, en, cost, m, a, b;
vector <pair<int,int>> arr[100001];
int p[100001][20];
int d[100001];
int dis[100001];

void dfs(int node, int parent, int co) {
    p[node][0] = parent;
    d[node] = d[parent] + 1;
    dis[node] = co;
    for (int i = 1; i < 20; i++) {
        p[node][i] = p[p[node][i - 1]][i - 1];
    }
    for (auto i : arr[node]) {
        if (i.first != parent) {
            dfs(i.first, node, i.second + co);
        }
    }
}

int lca(int a, int b) {
    int tmp;
    int result1 = 0, result2 = 100000;
    if (d[a] != d[b]) {
        if (d[a] > d[b]) {
            tmp = a;
            a = b;
            b = tmp;
        }
        for (int i = 19; i > -1; i--) {
            if (p[b][i] != 0 && d[a] <= d[p[b][i]]) {
                b = p[b][i];
            }
        }
    }

    int lca = a;
    if (a != b) {
        for (int i = 19; i > -1; i--) {
            if (p[a][i] != 0 && p[a][i] != p[b][i]) {

                a = p[a][i];
                b = p[b][i];
            }
        }
        lca = p[a][0];
    }
    return lca;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> st >> en >> cost;
        arr[st].push_back({ en, cost });
        arr[en].push_back({ st, cost });
    }

    dfs(1, 0, 0);
    cin >> m;
    while (m--) {
        cin >> a >> b;
        cout << dis[a] + dis[b] - 2 * dis[lca(a, b)] << "\n";
    }
    return 0;
}