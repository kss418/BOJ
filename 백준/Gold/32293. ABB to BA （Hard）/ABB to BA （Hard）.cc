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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
vector <char> st;

bool chk(){
    ll si = st.size();
    if(si < 3) return 0;
    if(st[si - 1] == 'A') return 0;
    if(st[si - 2] == 'A') return 0;
    if(st[si - 3] == 'B') return 0;

    return 1;
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> s; st.clear();
        for(auto& i : s){
            st.push_back(i); ll cnt = 0;
            while(chk()){
                st.pop_back(); st.pop_back(); st.pop_back();
                cnt++; st.push_back('B');
            }

            for(int j = 1;j <= cnt;j++) st.push_back('A');
        }
        
        for(auto& i : st) cout << i; cout << "\n";
    }
    

    return 0;
}

