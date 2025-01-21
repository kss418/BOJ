#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 30101; // SET MAX SIZE
constexpr ll MOD = 998244353;
deque <pll> a;

void run(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++){
        pll now; cin >> now.x >> now.y;
        a.push_back(now);
    }
    sort(all(a));

    ll result = 0;
    while(1){
        if(a.empty() || a.front().x >= k) break;
        result += k - a.front().x ; ll cnt = m;
        while(cnt){
            if(a.empty() || a.front().x >= k) break;
            if(cnt >= a.front().y) cnt -= a.front().y, a.pop_front();
            else { a.front().y -= cnt; break; }
        }
    }

    while(1){
        if(a.empty() || a.back().x <= k) break;
        result += a.back().x - k; ll cnt = m;
        while(cnt){
            if(a.empty() || a.back().x <= k) break;
            if(cnt >= a.back().y) cnt -= a.back().y, a.pop_back();
            else { a.back().y -= cnt; break; }
        }
    }

    cout << 2 * result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

