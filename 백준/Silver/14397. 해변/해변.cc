#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
string st[MAX];
ll dx1[6] = {0, 0, -1, 1, 1, 1}, dy[6] = {1, -1, 0, 0, 1, -1};
ll dx2[6] = {0, 0, -1, 1, -1, -1};

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];

    ll result = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(st[i][j] == '#') continue;
            for(int k = 0;k < 6;k++){
                ll nx = j, ny = i + dy[k];
                if(i % 2) nx += dx1[k]; else nx += dx2[k];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(st[ny][nx] == '#') result++;
            }
        }
    }

    cout << result;


    return 0;
}