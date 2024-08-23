#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 10101;
constexpr ll MOD = 1e9 + 7;
pll arr[MAX];
ll fuel, en, result;
priority_queue <ll> oil;


int main()
{
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i].first >> arr[i].second;
    cin >> en >> fuel;
    arr[n + 1].first = en;
    sort(arr + 1, arr + n + 2);

    for (int i = 1; i <= n + 1; i++) {
        while (arr[i].first > fuel) {
            if (oil.empty()) { cout << -1; return 0; }
            result++;
            ll cur = oil.top(); oil.pop();
            fuel += cur;
        }

        oil.push(arr[i].second);
    }

    cout << result;

    return 0;
}