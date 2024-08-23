#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
pll arr[MAX];
set <ll> num;

int main()
{
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i].second >> arr[i].first;
    sort(arr + 1, arr + n + 1);
    reverse(arr + 1, arr + n + 1);
    for (int i = 1; i <= n; i++) num.insert(-i);
    
    ll result = 0;
    for (int i = 1; i <= n; i++) {
        auto nxt = num.lower_bound(-arr[i].second);
        if (nxt == num.end()) continue;
        num.erase(nxt);
        result += arr[i].first;
    }

    cout << result;

    return 0;
}