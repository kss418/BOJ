#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 10101;
ll arr[MAX];
vector <pll> num;
vector <ll> result;

int main()
{
    fastio;

    while (1) {
        cin >> n >> m;
        if (!n) break;
        memset(arr, 0, sizeof(arr));
        result.clear(); num.clear();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) cin >> k, arr[k]++;
        }

        for (int i = 1; i < MAX; i++) if (arr[i]) num.push_back({ arr[i], i });
        sort(num.begin(), num.end()); reverse(num.begin(), num.end());
        
        ll v = num[1].first;
        for (int i = 1; i < MAX; i++) if (arr[i] == v) result.push_back(i);
        sort(result.begin(), result.end());

        for (auto& i : result) cout << i << " ";
        cout << "\n";
    }

    return 0;
}
