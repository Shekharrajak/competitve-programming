#include <bits/stdc++.h>
using namespace std;

int dp[(1<<11) + 1][(1<<11) + 1][12], n, m;
int _not_blocks[12];
int go(int bl, int br, int c){
    if(c == n)return 1;
    int &ret = dp[bl][br][c];
    if(ret != -1)return ret;
    ret = 0;
    bl &= _not_blocks[c];
    br &= _not_blocks[c];
    for(int i = 0; i < m; i++){
        if((_not_blocks[c] & 1<<i) == 0 || (bl & 1<<i) || (br & 1<<i))continue;
        int rb = br<<1;
        int lb = bl>>1;
        if(i > 0)lb |= 1<<(i - 1);
        lb = lb & ((1<<m) - 1);
        if(i < m - 1)rb |= 1<<(i + 1);
        rb = rb & ((1<<m) - 1);
        ret += go(lb, rb, c + 1);
    }
    return ret;
}
char grid[12][12];
main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
        for(int j = 0; j < m; j++) if(grid[i][j] == '.') _not_blocks[i] |= 1<<j;
    }
    cout << go(0, 0, 0) << endl;
}
