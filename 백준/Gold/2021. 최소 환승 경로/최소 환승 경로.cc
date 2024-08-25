#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;
vector <int> arr[MAX];
vector <int> line[MAX];
deque <pair<int,int>> q;
int d[MAX];
bool v[MAX];


int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        while (1) {
            cin >> k;
            if (k == -1) break;
            arr[i].push_back(k);
            line[k].push_back(i);
        }
    }
    memset(d, 0x3f, sizeof(d));

    ll st, en;
    cin >> st >> en;
    ll result = 101010;

    for (auto& i : line[st]) {
        q.push_back({ i, 0 });
        v[i] = 1;
    }
    while (!q.empty()) {
        auto [cur, dist] = q.front(); q.pop_front();
        if (d[cur] <= dist) continue;
        d[cur] = dist;
        
        for (auto& nxt : arr[cur]) {
            if (nxt == en) {
                result = min<int>(result, d[cur]);
                break;
            }
            for (auto& nl : line[nxt]) {
                if (v[nl]) continue;
                v[nl] = 1;
                q.push_back({ nl, dist + 1 });
            }
        } 
    }

    if (result == 101010) cout << -1;
    else cout << result;


    return 0;
}