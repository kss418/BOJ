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
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
vector <ll> vec;
ll all, result = INF;

void cal(string &pre, ll b){
    ll ret = 0; string nxt = st[b];
    for(int i = 0;i < min(pre.size(), nxt.size());i++){
        ll now = 1;
        for(int j = 0;j <= i;j++){
            if(nxt[j] != pre[pre.size() - i - 1 + j]) now = 0;
        }

        if(now) ret = i + 1;
    }

    for(int i = ret;i < nxt.size();i++) pre.push_back(nxt[i]);
}

void run(){
    cin >> n; vec.resize(n); iota(all(vec), 0);
    for(int i = 0;i < n;i++) cin >> st[i], all += st[i].size();

    while(1){
        string str = st[vec[0]];
        for(int i = 1;i < n;i++) cal(str, vec[i]);
        result = min<ll>(result, str.size());
        if(!next_permutation(all(vec))) break;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

