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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll st[MAX], en[MAX];
vector <pll> rev, swp;

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> st[i] >> en[i];
        if(en[i] >= st[i]) continue;
        rev.push_back({en[i], st[i]});
    }
    
    ll result = m; pll cur = { -1, -1 };
    sort(all(rev));
    for(auto& i : rev){
        auto[s, e] = i;
        if(s <= cur.second && e > cur.second) cur.second = e;
        else if(s > cur.second) {
            if(cur.first != -1) result += 2 * (cur.second - cur.first); 
            cur = i;
        }
    }
    if(cur.first != -1) result += 2 * (cur.second - cur.first);


    cout << result;
}

int main() {
    fastio;

    // cin >> t;
    while(t--) run();
    

    return 0;
}