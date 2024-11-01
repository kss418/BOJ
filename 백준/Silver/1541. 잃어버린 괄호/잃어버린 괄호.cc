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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
vector <ll> num;
vector <char> op;

int main() {
    fastio;

    cin >> s;
    
    ll la = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] == '-' || s[i] == '+'){
            string cur = s.substr(la, i - la + 1);
            num.push_back(stoll(cur));
            op.push_back(s[i]); la = i + 1;
            continue;
        }

        if(s[i] == '0' && la == i) {
            la++; continue;
        }
    }

    string cur = s.substr(la, s.size() - la);
    num.push_back(stoll(cur));
    
    ll result = num[0], flag = 1;
    for(int i = 0;i < op.size();i++){
        if(op[i] == '-') flag = -1;
        result += num[i + 1] * flag;
    }

    cout << result;

    
    return 0;
}