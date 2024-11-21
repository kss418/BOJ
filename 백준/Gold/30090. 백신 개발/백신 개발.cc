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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
vector <ll> seq;

ll match(string& a, string& b){
    for(int i = min(a.size(), b.size()) - 1;i >= 0;i--){
        string pre = a.substr(0, i + 1);
        string suf = b.substr(b.size() - i - 1, i + 1);
        if(pre == suf) return i + 1;
    }

    return 0;
}

int main() {
    fastio;

    ll all = 0, result = INF;
    cin >> n; seq.resize(n); iota(all(seq), 0);
    for(int i = 0;i < n;i++) cin >> st[i], all += st[i].size();

    while(1){
        ll now = all;
        for(int i = 1;i < n;i++){
            string cur = st[seq[i]], pre = st[seq[i - 1]];
            now -= match(cur, pre);
        }

        result = min(result, now);
        if(!next_permutation(all(seq))) break;
    }

    cout << result;
    
     
    return 0;
}