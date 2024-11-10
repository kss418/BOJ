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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
set <ll> sx, sy;
vector <pll> arr;

int main() {
    fastio;

    cin >> m >> n >> t >> k;
    for(int i = 1;i <= t;i++) {
        cin >> a[i].x >> a[i].y;
        sx.insert(a[i].x);
        sy.insert(a[i].y);
        arr.push_back({ a[i].x, a[i].y });
    }
    sx.insert(m - k); sy.insert(n - k);

    ll result = 0, rx = 0, ry = 0;
    for(auto& i : sy){
        if(i + k > n) continue;
        for(auto& j : sx){
            if(j + k > m) continue;
            ll cnt = 0;
            for(auto& l : arr){
                auto[cx, cy] = l;
            
                if(cy - i > k || cy < i) continue;
                if(cx - j > k || cx < j) continue;
                cnt++;
            }

            if(result >= cnt) continue;
            rx = j; ry = i + k;
            result = cnt;
        }
    }

    cout << rx << " " << ry << '\n';
    cout << result;


    return 0;
}

