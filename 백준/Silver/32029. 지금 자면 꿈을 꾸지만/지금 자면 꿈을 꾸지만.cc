#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
ll arr[MAX], result;


int main()
{
    fastio;

    ll a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + n + 1);

    for (int x = 0; x < a; x++) {
        for (int j = 0; j <= n; j++) {
            ll t = 0; ll cur = 0;
            for (int l = 1; l <= j; l++) {
                if (arr[l] < t + a) continue;
                t += a; cur++;
            }

            t += b * x;
            for (int l = j + 1; l <= n; l++) {
                if (arr[l] < t + a - x) continue;
                t += a - x; cur++;
            }

            result = max(result, cur);
        }
    }

    cout << result;


    return 0;
}
