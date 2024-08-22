#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 51;
constexpr ll MOD = 1e9 + 7;
string st[MAX];
multiset <string> arr;

int main()
{
    fastio;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> st[i];

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) arr.insert(st[j].substr(0, i));
        
        ll cur = INF;
        for (auto& now : arr) {
            cur = min(cur, (ll)arr.count(now));
        }

        if (cur > k) continue;
        cout << i << "\n";
        for (auto& now : arr) {
            if (arr.count(now) != cur) continue;
            for (auto& s : now) {
                if (s == 'P') cout << 'R';
                else if (s == 'S') cout << 'P';
                else cout << 'S';
            }
            return 0;
        }
    }

    cout << -1;

    return 0;
}