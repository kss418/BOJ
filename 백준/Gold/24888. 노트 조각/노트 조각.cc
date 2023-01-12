#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <utility>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>

#define INF 1e9
#define endl '\n'
#define ll long long
using namespace std;

vector<pair<ll, ll>> arr[201010];
ll cost[201010];
ll dis[201010];
ll dp[201010];
ll seq[201010];
vector<ll> path;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        arr[u].push_back({ v,w });
        arr[v].push_back({ u,w });
    }

    ll note = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> cost[i];
        note += cost[i];
    }

    memset(dis, 0x3f, sizeof(dis));
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
    dis[1] = 0;
    que.push({ 0,1 });

    dp[1] = cost[1];
    ll curD; ll cur;
    while (!que.empty())
    {
        tie(curD, cur) = que.top();
        que.pop();
        if (dis[cur] != curD) {
            continue;
        }

        for (auto i : arr[cur]) {
            ll next = i.first;
            ll nextD = i.second;
            if (nextD + curD < dis[next]) {
                dis[next] = nextD + curD;
                dp[next] = dp[cur] + cost[next];
                que.push({ nextD + curD,next });
                   seq[next] = cur;
            }
            else if (nextD + curD == dis[next]) {
                if (dp[next] < dp[cur] + cost[next]) {
                    dp[next] = max(dp[next], dp[cur] + cost[next]);
                    que.push({ nextD + curD,next });
                    seq[next] = cur;
                }
            }
        }
    }

    if (dp[n] != note) {
        cout << -1;
        return 0;
    }

    ll x = n;
    while (1) {
        path.push_back(x);
        if (x == 1) {
            break;
        }
        x = seq[x];
    }
    reverse(path.begin(),path.end());


    cout << path.size() << endl;
    for (auto i : path) {
        cout << i << " ";
    }


    return 0;
}