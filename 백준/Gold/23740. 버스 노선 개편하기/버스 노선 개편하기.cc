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
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
class node{
public:
    ll l, r, c;
    bool operator <(node& ot){
        if(l == ot.l) return r < ot.r;
        return l < ot.l;
    }
};
vector <node> arr, result;

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++){
        ll l, r, c;
        cin >> l >> r >> c;
        arr.push_back({l, r, c});
    }
    sort(all(arr));
    ll st = arr[0].l, en = arr[0].r, c = arr[0].c;

    for(int i = 1;i < n;i++){
        if(arr[i].l > en){
            result.push_back({st, en, c});
            st = arr[i].l; en = arr[i].r; c = arr[i].c;
        }
        else{
            en = max(arr[i].r, en); c = min(c, arr[i].c);
        }
    }
    result.push_back({st, en, c});

    cout << result.size() << "\n";
    for(int i = 0;i < result.size();i++){
        cout << result[i].l << " " << result[i].r << " " << result[i].c << "\n";
    }

  
    return 0;
}

