// // Copied from MY CP Template 
// using ll = long long ; 
// ll expo(ll a , ll b , ll mod){
//     ll res = 1 ; 
//     while(b){
//         if(b&1) res *= a ; 
//         a *= a ; 
//         b >>= 1 ; 
//     }

//     return res ; 
// }

// ll mod_mul(ll a , ll b , ll mod){
//     return (a*b)%mod ; 
// }

// void extendgcd(ll a, ll b, ll*v){
//     if (b == 0){
//         v[0] = 1; 
//         v[1] = 0; 
//         v[2] = a; 
//         return ;
//     } 
//     extendgcd(b, a % b, v); 
//     ll x = v[1]; 
//     v[1] = v[0] - v[1] * (a / b); 
//     v[0] = x; 
//     return;
// } //pass an arry of size1 3

// ll modinv(ll a, ll b){
//     ll arr[3]; 
//     extendgcd(a, b, arr); 
//     return (arr[0] + b) % b;
// } //for non prime b

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 1));
        long long mod = 12345;
        
        long long pref = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = pref;
                pref = (pref * grid[i][j]) % mod;
            }
        }
        
        long long suff = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                ans[i][j] = (ans[i][j] * suff) % mod; 
                suff = (suff * grid[i][j]) % mod;
            }
        }
        
        return ans; 
    }
};