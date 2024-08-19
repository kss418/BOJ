#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 501010;
constexpr ll MOD = 1e9 + 7;
ll arr[501];

int main()
{
    fastio;
    cin >> n;

    if (n <= 7) { cout << -1; return 0; }
    arr[0] = 4; arr[1] = 2; arr[n - 1] = 5; arr[2] = 6;
    for (int i = 3; i < n / 2 - 1; i++) arr[i] = 2 * i + 4;
    arr[n / 2 - 1] = 8; arr[n / 2] = 7; arr[n / 2 + 1] = 1; arr[n / 2 + 2] = 3;

    ll cur = 9;
    for (int i = n / 2 + 3; i < n - 1; i++) arr[i] = cur, cur += 2;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[(i + j) % n] << " ";
        }
        cout << "\n";
    }
   

    return 0;
}