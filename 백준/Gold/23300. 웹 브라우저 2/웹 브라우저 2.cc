#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
constexpr ll MAX = 2010;
constexpr ll MOD = 998244353;
deque <ll> pre, nxt, tmp;

int main() {
    fastio;

    cin >> n >> m; ll cur = 0;
    while(m--){
        char c; cin >> c;
        if(c == 'B'){
            if(pre.empty()) continue;
            nxt.push_front(cur);
            cur = pre.back(); pre.pop_back();
        }
        else if(c == 'F'){
            if(nxt.empty()) continue;
            pre.push_back(cur);
            cur = nxt.front(); nxt.pop_front();
        }
        else if(c == 'A'){
            ll num; cin >> num;
            if(cur) pre.push_back(cur);
            cur = num; nxt.clear();
        }
        else{
            while(!pre.empty()){
                ll top = 0, back = pre.back();
                if(!tmp.empty()) top = tmp.front();
                pre.pop_back();

                if(back == top) continue;
                tmp.push_front(back);
            }

            pre = tmp; tmp.clear();
        }
    }

    cout << cur << "\n";
    reverse(all(pre));
    for(auto& i : pre) cout << i << " "; 
    if(pre.empty()) cout << -1; cout << "\n";

    for(auto& i : nxt) cout << i << " ";
    if(nxt.empty()) cout << -1;


    return 0;
}