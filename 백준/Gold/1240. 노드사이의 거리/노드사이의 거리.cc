#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <stack>
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1010;
vector <pll> arr[MAX];
ll p[MAX][16], d[MAX], dist[MAX];


void dfs(int node, int parent, int co) {
    p[node][0] = parent;
    d[node] = d[parent] + 1;
    dist[node] = co;
    for (int i = 1; i < 16; i++) {
        p[node][i] = p[p[node][i - 1]][i - 1];
    }
    for (auto i : arr[node]) {
        ll nxt = i.first;
        ll cst = i.second;
        if (nxt == parent) continue;
        dfs(nxt, node, cst + co);   
    }
}

ll lca(int a, int b) {
    ll tmp;
    ll result1 = 0, result2 = INF;
    if (d[a] != d[b]) {
        if (d[a] > d[b]) {
            tmp = a;
            a = b;
            b = tmp;
        }
        for (int i = 15; i >= 0; i--) {
            if (p[b][i] != 0 && d[a] <= d[p[b][i]]) {
                b = p[b][i];
            }
        }
    }

    ll lca = a;
    if (a != b) {
        for (int i = 15; i >= 0; i--) {
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
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i < n; i++) {
        ll st, en, cost;
        cin >> st >> en >> cost;
        arr[st].push_back({ en,cost });
        arr[en].push_back({ st,cost });
	}
	
    dfs(1, 0, 0);
    while (m--) {
        ll a, b;
        cin >> a >> b;
        cout << dist[a] + dist[b] - 2 * dist[lca(a, b)] << "\n";
    }


	return 0;
}