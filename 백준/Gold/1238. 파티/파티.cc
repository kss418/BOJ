#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
priority_queue <pair <int, int>, vector <pair<int, int>>, greater<pair<int, int>>> pq;
vector <pair <int,int>> arr[1001];
int n, m, x, cost, a, b;
int cur_loc, cur_cost;
int d[1001][1001];

int main() {
    cin >> n >> m >> x;
    while (m--) {
        cin >> a >> b >> cost;
        arr[a].push_back({ b, cost });
        d[a][b] = cost;
    }
    fill(&d[0][0], &d[1000][1001], 100000000);
    
    for (int i = 1; i < n + 1; i++) {
        pq.push({ 0 , i});
        d[i][i] = 0;
        while (!pq.empty()) {
            pair <int, int> cur = pq.top();
            pq.pop();
            cur_loc = cur.second;
            cur_cost = cur.first;
            for (int j = 0; j < arr[cur_loc].size(); j++) {
                if (d[i][arr[cur_loc][j].first] > d[i][cur_loc] + arr[cur_loc][j].second) {
                    d[i][arr[cur_loc][j].first] = d[i][cur_loc] + arr[cur_loc][j].second;
                    pq.push({ d[i][arr[cur_loc][j].first],arr[cur_loc][j].first });
                }
            }
        }
    }

    int result = 0;
    for (int i = 1; i < n + 1; i++) {
        result = max(result, d[i][x] + d[x][i]);
    }
    cout << result;

    return 0;
}