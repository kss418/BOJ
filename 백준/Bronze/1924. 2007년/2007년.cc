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
string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
ll num[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

ll cal(ll m, ll d){
    ll ret = 0;
    for(int i = 1;i < m;i++) ret += num[i];
    return (ret + d) % 7;
}

void run(){
    cin >> n >> m;
    cout << day[cal(n, m)];
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

