#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll num[1010101], a[MAX][3];

bool chk(ll cur){
    bool ret = num[a[cur][0]] | num[a[cur][1]] | num[a[cur][2]]; 
    for(int i = 0;i < 3;i++) num[a[cur][i]] = 1;
    return ret ^ 1;
}

int main() {
    fastio;

    cin >> n; ll result = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 3;j++) cin >> a[i][j];
        result += chk(i);
    }

    cout << result;

    
    return 0;
}

