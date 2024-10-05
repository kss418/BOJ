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
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010;
constexpr ll MOD = 998244353;
string st[MAX];
bool v[MAX][MAX];
ll result, dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

void dfs(ll cy, ll cx){
    if(cy < 0 || cx < 0 || cx >= m || cy >= n) return;
    if(v[cy][cx]) return; v[cy][cx] = 1;
    if(st[cy][cx] == 'X') return;
    else if(st[cy][cx] == 'P') result++;

    for(int i = 0;i < 4;i++){
        ll ny = cy + dy[i];
        ll nx = cx + dx[i];
        dfs(ny, nx);
    }
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];

    ll cx, cy;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) if(st[i][j] == 'I') cx = j, cy = i;
    }
    dfs(cy, cx);

    if(result) cout << result;
    else cout << "TT";


    return 0;
}