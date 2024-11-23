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
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;

ld deg(pll a){
    ld ret = atan2l(a.y, a.x) * (ld)180 / M_PI;
    ret = fmodl(ret + (ld)360, ld(360));
    return ret;
}
vector <pld> arr;
vector <ld> line;

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++){
        pll s, e; cin >> s.x >> s.y >> e.x >> e.y;
        if(deg(s) > deg(e)) swap(s, e);
        arr.push_back({deg(s), deg(e)});
    }
    sort(all(arr));

    cin >> m;
    for(int i = 1;i <= m;i++){
        pll a; cin >> a.x >> a.y;
        line.push_back(deg(a));
    }
    sort(all(line));

    ll idx = 0, result = n;
    for(auto& i : arr){
        auto[s, e] = i;
        while(s > line[idx] && idx < m) idx++;
        if(idx == m) break;
        result -= (e >= line[idx]);
    }

    cout << result;


    return 0;
}

