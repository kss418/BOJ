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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
priority_queue <ld, vector<ld>, greater<ld>> pq;

ld deg(pll a){
    ld ret = atan2l(a.x, a.y) * (ld)180 / M_PI;
    ret = fmodl(ret + (ld)360, (ld)360);
    return ret;
}
vector <pld> arr;

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++){
        pll a, b; cin >> a.x >> a.y >> b.x >> b.y;
        if(deg(a) > deg(b)) swap(a, b);
        arr.push_back({deg(a), deg(b)});
    }
    sort(all(arr));

    ll result = 0;
    for(auto& i : arr){
        auto[s, e] = i;
        while(!pq.empty() && pq.top() < s) pq.pop();
        pq.push(e);

        result = max<ll>(result, pq.size());
    }

    cout << result;


    return 0;
}

