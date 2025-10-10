#include <iostream>
#include <vector>
#include <queue> 
using namespace std;
using ll = long long;

const ll MAX = 3010;
const ll INF = 1e12;
ll n, a[MAX][MAX], cnt[3];

void dnc(ll cy, ll cx, ll sz){
    bool flag = 1; ll num = a[cy][cx];
    for(int i = cy;i < cy + sz;i++){
        for(int j = cx;j < cx + sz;j++){
            if(a[i][j] != num) flag = 0;
        }
    }

    if(flag){
        cnt[num + 1]++; return;
    }

    ll nsz = sz / 3;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            dnc(cy + i * nsz, cx + j * nsz, nsz);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) cin >> a[i][j];
    }

    dnc(0, 0, n);
    for(int i = 0;i < 3;i++) cout << cnt[i] << "\n";
    return 0;
}

