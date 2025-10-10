#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 3010;
const ll INF = 1e12;
ll n, len[55], mx;

char dnc(ll cur, ll sz){
    if(!sz) return (cur == 1 ? 'm' : 'o');

    if(cur <= len[sz - 1]) return dnc(cur, sz - 1);
    else if(cur > len[sz - 1] + sz + 3) return dnc(cur - len[sz - 1] - sz - 3, sz - 1);
    return (cur == len[sz - 1] + 1 ? 'm' : 'o');
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n; len[0] = 3;
    for(int i = 1;i < 55;i++){
        len[i] = 2 * len[i - 1] + i + 3; mx = i;
        if(len[i] > n) break;
    }

    cout << dnc(n, mx);
    return 0;
}

