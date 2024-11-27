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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
map <string,ll> mp;
char c[4][2] = {{'I', 'V'}, {'X', 'L'}, {'C', 'D'}, {'M', 'M'}};

ll num(string& s){
    return mp[s];
}

string st(ll num){
    string cur = to_string(num);
    reverse(all(cur));
    vector <string> arr;

    for(int i = 0;i < cur.size();i++){
        ll now = cur[i] - '0'; string st;
        if(now == 9){
            st.push_back(c[i][0]); st.push_back(c[i + 1][0]);
        }
        else if(now >= 5){
            st.push_back(c[i][1]);
            for(int j = 1;j <= now % 5;j++) st.push_back(c[i][0]);
        }
        else if(now == 4) for(int j = 0;j <= 1;j++) st.push_back(c[i][j]);
        else for(int j = 1;j <= now;j++) st.push_back(c[i][0]);

        arr.push_back(st);
    }
    reverse(all(arr));
    
    string ret; 
    for(auto& i : arr){
        for(auto& j : i) ret.push_back(j);
    }

    return ret;
}

void init(){
    for(int i = 1;i < 4000;i++) mp[st(i)] = i;
}

int main() {
    fastio;
    
    init();
    string a, b; cin >> a >> b;
    ll sum = num(a) + num(b);
    cout << sum << "\n" << st(sum);

     
    return 0;
}