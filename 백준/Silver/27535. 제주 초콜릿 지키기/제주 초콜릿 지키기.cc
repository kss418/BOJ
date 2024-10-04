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

ll sum;
char c[5] = {'H', 'T', 'C', 'K', 'G'};

class node{
public:
    ll v; char c;
    bool operator <(node& ot){
        if(v == ot.v) return ot.c < c;
        return ot.v > v;
    }
};
node arr[5];

string trn(ll cur, ll num){
    if(num == 10) return to_string(cur);
    string ret;

    ll mul = 1;
    while(mul <= cur) mul *= num;
    mul /= num;

    while(mul){
        ret.push_back(cur / mul + '0');
        cur -= (ll)(cur / mul) * mul;    
        mul /= num;
    }
    
    if(ret.empty()) return "0";
    return ret;
}


int main() {
    fastio;

    for(int i = 0;i < 5;i++) {
        cin >> arr[i].v;
        arr[i].c = c[i]; sum += arr[i].v;
    }

    cin >> t;
    while(t--){
        vector <node> cur;
        ll pre = sum % 10;
        if(pre <= 1) pre = 10;

        for(int i = 0;i < 5;i++){
            cin >> m;
            arr[i].v -= m; sum -= m;
            cur.push_back({arr[i].v, c[i]});
        }
        sort(all(cur)); reverse(all(cur));

        cout << trn(sum, pre) << "7H\n";
        ll cnt = 0;
        for(auto& i : cur){
            if(i.v <= 0) break;
            cout << i.c; cnt++;
        }
        if(!cnt)cout << "NULL";

        cout << "\n";
    }
    
  
    return 0;
}