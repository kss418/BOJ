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
constexpr ll MAX = 31;
constexpr ll MOD = 998244353;
ll result[MAX];
stack <ll> st;

bool chk(string& s){
    ll cnt = 0;
    for(auto& i : s){
        if(i == '(' || i == '[') cnt++, st.push(i);
        else {
            cnt--; if(cnt < 0) return 0;
            if(i == ')'){
                if(st.top() == '[') return 0;
                if(st.top() == '(') st.pop();
            }
            else{
                if(st.top() == '(') return 0;
                if(st.top() == '[') st.pop();
            }
        }
    }

    return !cnt;
}

int main() {
    fastio;

    cin >> s;
    ll cnt = 0, flag = 1;

    if(!chk(s)){
        cout << 0; return 0;
    }

    for(int i = 0;i < s.size();i++){
        if(s[i] == '(' || s[i] == '[') cnt++;
        else if(s[i] == ')') {
            cnt--;
            result[cnt] += 2 * max(result[cnt + 1], 1ll);
            result[cnt + 1] = 0;
        }
        else{
            cnt--;
            result[cnt] += 3 * max(result[cnt + 1], 1ll);
            result[cnt + 1] = 0;
        }
    }

    cout << result[0];
    

    return 0;
}