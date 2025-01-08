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
deque <ll> even, odd;

vector <ll> dnc(ll n){
    vector <ll> ret;
    if(n == 1){
        ret.push_back(1);
        return ret;
    }

    vector <ll> odd = dnc((n + 1) >> 1ll);
    vector <ll> even = dnc(n >> 1ll);

    for(auto& i : odd) ret.push_back(2 * i - 1);
    for(auto& i : even) ret.push_back(2 * i);

    return ret;
}

void run(){
    cin >> n;
    for(auto& i : dnc(n)) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}