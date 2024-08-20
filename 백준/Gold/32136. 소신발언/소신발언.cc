#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 301010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX];

ll f(ll cur) {
    ll ret = 0;
    for (int i = 1; i <= n; i++) ret = max(ret, abs(cur - i) * arr[i]);

    return ret;
}

int main()
{
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    ll st = 1, en = n;
    while (en - st >= 3) {
        ll l = (2 * st + en) / 3, r = (st + 2 * en) / 3;
        if (f(l) > f(r)) st = l;
        else en = r;
    }

    ll result = INF;
    for (int i = st; i <= en; i++) result = min(result, f(i));

    cout << result;
  

    return 0;
}