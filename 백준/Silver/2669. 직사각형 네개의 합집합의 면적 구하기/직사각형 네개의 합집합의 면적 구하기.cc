#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
ll arr[MAX][MAX];

int main() {
    fastio;

    for(int i = 1;i <= 4;i++){
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1;i < x2;i++){
            for(int j = y1;j < y2;j++){
                arr[i][j] = 1;
            }
        }
    }

    ll cnt = 0;
    for(int i = 0;i <= 100;i++){
        for(int j = 0;j <= 100;j++) if(arr[i][j]) cnt++;
    }

    cout << cnt;


    return 0;
}