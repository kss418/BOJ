#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, m, a, b, v, st, en;
int d[1001];
vector <pair<int, int>> arr[1001];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    fill(d, d + 1001, 2000000000);
    while (m--) {
        cin >> a >> b >> v;
        arr[a].push_back(make_pair(b,v));
    }
    cin >> st >> en;
    d[st] = 0;
    priority_queue < pair <int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(d[st],st));
    while (q.size() > 0) {
        int cur = q.top().second;
        if (d[cur] != q.top().first) {
            q.pop();
            continue;
        }
        q.pop();
        for (int i = 0; i < arr[cur].size(); i++) {
            if (d[arr[cur][i].first] > d[cur] + arr[cur][i].second) {
                d[arr[cur][i].first] = d[cur] + arr[cur][i].second;
                q.push(make_pair(d[arr[cur][i].first], arr[cur][i].first));
            }
        }
    }


    cout << d[en];
    return 0;
}