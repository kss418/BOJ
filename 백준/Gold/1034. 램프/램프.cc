#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 51;
constexpr ll MOD = 1e9 + 7;
string st[MAX];
map <string, ll> num[1010];

int main() {
    fastio;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> st[i]; ll cnt = 0;
        for (auto& j : st[i]) if (j == '0') cnt++;
        
        num[cnt][st[i]]++;
    }

    cin >> k;
    ll result = 0;
    for (int i = k; i >= 0; i -= 2) {
        for (const auto& j : num[i]) {
            result = max(result, j.second);
        }
    }

    cout << result;
    

    return 0;
}