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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> pal;

void init(){
    for(int i = 1;i < 10000;i++){
        string now = to_string(i);
        string rev = now; reverse(all(rev));
        pal.push_back(stoll(now + rev));

        reverse(all(rev)); rev.pop_back();
        reverse(all(rev));
        pal.push_back(stoll(now + rev));
    }
    sort(all(pal));
}

bool prime(ll cur){
    for(int i = 2;i * i <= cur;i++){
        if(cur % i == 0) return 0;
    }
    return 1;
}

void run(){
    cin >> n >> m; init();

    for(auto& i : pal) {
        if(i < n) continue;
        if(i > m) break;
        if(!prime(i)) continue;

        cout << i << "\n";
    }
    cout << -1;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

