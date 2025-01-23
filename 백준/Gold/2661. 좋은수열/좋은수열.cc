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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> vec; ll f;

bool chk(){
    for(int i = 1;i <= vec.size() / 2;i++){
        vector <ll> pre(i), nxt(i);
        copy(vec.begin() + vec.size() - i, vec.end(), nxt.begin());
        copy(vec.begin() + vec.size() - 2 * i, vec.begin() + vec.size() - i, pre.begin());
        if(pre == nxt) return 1;
    }
    return 0;
}

void bt(){
    if(f || chk()) return;
    if(vec.size() == n){
        for(auto& i : vec) cout << i;
        f = 1; return;
    }

    for(int i = 1;i <= 3;i++){
        if(!vec.empty() && vec.back() == i) continue;
        vec.push_back(i);
        bt();
        vec.pop_back();
    }
}

void run(){
    cin >> n; bt();
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

