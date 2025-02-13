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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], all, la;
deque <ll> num[MAX];
set <pll> cnt, idx;
vector <ll> result;

void er(ll v){
    la = v;
    ll fr = num[v].front();
    result.push_back(fr);

    cnt.erase({num[v].size(), v});
    idx.erase({fr, v});
    num[v].pop_front();

    if(num[v].empty()) return;
    cnt.insert({num[v].size(), v});
    idx.insert({num[v].front(), v});
}

bool chk(){
    if(result.size() != n) return 0;
    for(int i = 0;i < n - 1;i++){
        if(a[result[i]] == a[result[i + 1]]) return 0;
    }
    return 1;
}

void run(){
    cin >> n; all = n;
    for(int i = 1;i <= n;i++) cin >> a[i], num[a[i]].push_back(i);
    for(int i = 1;i <= n;i++){
        if(num[i].empty()) continue;
        cnt.insert({num[i].size(), i});
        idx.insert({num[i][0], i});
    }

    while(all){
        if(2 * (--cnt.end())->x > all) {
            auto[now, cur] = *--cnt.end(); er(cur);
        }
        else{
            if(idx.begin()->y == la){
                auto fi = *idx.begin(); idx.erase(idx.begin());
                if(idx.empty()) break;
                auto[now, cur] = *idx.begin(); er(cur);
                idx.insert(fi);
            }
            else {
                auto[now, cur] = *idx.begin(); er(cur);
            }
        }

        all--;
    }

    if(chk()) for(auto& i : result) cout << i << " ";
    else cout << -1;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

