#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;
string st[MAX], result;
char f[201];
ll use[201];
ll cnt[201][201];

int main()
{
    fastio;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> st[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < st[i].size() - 1; j++) {
            cnt[st[i][j]][st[i][j + 1]]++;
        }
    }

    for (int i = 1; i <= 200; i++) {
        ll cur = 0, mx = 0;
        for (int j = 1; j <= 200; j++) {
            if (mx >= cnt[i][j]) continue;
            mx = cnt[i][j]; cur = j;
        }

        f[i] = cur;
    }
    f[']'] = '[';

    char cur = '[';
    ll st = 1, en;
    while (!use[cur]) {
        use[cur] = st++;
        result.push_back(cur);
        cur = f[cur];
    }
    en = st;
    st = use[cur];
    st--; en -= 2; m--;

    for (int i = m; i <= m + k - 1; i++) {
        if (result.back() == ']') {
            if (i >= result.size()) cout << ".";
            else cout << result[i];
        }

        else if (result.back() != ']') {
            if (i < st) cout << result[i];
            else cout << result[(i - st) % (en - st + 1) + st];
        }
    }

         
    return 0;
}