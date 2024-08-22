#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;

template <typename T = ll> // 반환 타입
class _lis {
public:
    ll n; vector<T> arr;
    vector<T> result, rec;
    vector<T> num;

    _lis(ll n) {
        this->n = n;
        arr.resize(n + 1); rec.resize(n + 1);
    }

    void add(ll n, ll idx) {
        arr[idx] = n;
    }

    void init() {
        for (int i = 1; i <= n; i++) {
            ll cur = arr[i];
            auto nxt = upper_bound(num.begin(), num.end(), cur) - num.begin();
            if (nxt == num.size()) num.push_back(cur);
            else num[nxt] = cur;
            rec[i] = nxt + 1;
        }

        ll cnt = num.size();
        result.resize(cnt);
        for (int i = n; i >= 1; i--) {
            if (rec[i] != cnt) continue;
            cnt--; result[cnt] = arr[i];
        }
    }

    vector <ll> ret() {
        return result;
    }
};
pll arr[MAX];
ll cnt[5 * MAX], rev[5 * MAX];

int main()
{
    fastio;
    cin >> n;
    _lis lis(n);
    memset(cnt, -1, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
        rev[arr[i].second] = arr[i].first;
        cnt[arr[i].first] = 0;
    }
    sort(arr + 1, arr + n + 1);

    for (int i = 1; i <= n; i++) lis.add(arr[i].second, i);
    lis.init(); vector <ll> ret = lis.ret();

    for (auto& i : ret) cnt[rev[i]] = 1;
    
    vector<ll> result;
    for (int i = 1; i <= n; i++) {
        ll cur = arr[i].first;
        if (cnt[cur] == -1 || cnt[cur] == 1) continue;
        result.push_back(cur);
    }

    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for (auto& i : result) cout << i << "\n";
    
         
    return 0;
}