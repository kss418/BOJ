#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;
ll fl[MAX], sp[MAX], sum[MAX];
pll arr[MAX];
set <ll> ps, ms;

int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> fl[i] >> sp[i];
        arr[i] = { sp[i], i };
        sum[i] = sum[i - 1] + fl[i];
    }
    sort(arr + 1, arr + n + 1);
    reverse(arr + 1, arr + n + 1);
    ll result = INF;

    for (int i = 1; i <= n; i++) {
        ll l, r;
        if (ps.upper_bound(arr[i].second) == ps.end()) r = n;
        else r = *ps.upper_bound(arr[i].second) - 1;
        ps.insert(arr[i].second);

        if (ms.upper_bound(-arr[i].second) == ms.end()) l = 1;
        else l = -*ms.upper_bound(-arr[i].second) + 1;
        ms.insert(-arr[i].second);

        if (sum[r] - sum[l - 1] < m) continue;
        result = min(result, arr[i].first);
    }
    
    cout << result;

         
    return 0;
}