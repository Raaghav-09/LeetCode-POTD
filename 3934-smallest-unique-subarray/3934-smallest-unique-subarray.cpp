using ll = long long ; 
class Hashing{
public:
    vector<int> arr ; 
    int n ; 
    int primes ; 
    int base = 100003 ; 
    vector<ll> hashPrimes = {1000000000+7 , 1000000000+9} ; 
    vector<vector<ll>> hashes ; 
    vector<vector<ll>> powerOfBase ; 
    Hashing(vector<int>& arr){
        this->arr = arr ; 
        n = arr.size() ; 
        primes = hashPrimes.size() ; 

        hashes.assign(primes,vector<ll>(n+1,0)) ; 
        powerOfBase.assign(primes,vector<ll>(n+1,1)) ; 
        for(int i=0 ; i<primes ; i++){
            for(int j=0 ; j<n ; j++){
                powerOfBase[i][j+1] = (powerOfBase[i][j] * base) % hashPrimes[i] ; 
                hashes[i][j+1] = (hashes[i][j]*base + arr[j]) % hashPrimes[i] ; 
            }
        }
    }

    vector<ll> subArrayHash(int l , int r){
        vector<ll> hash(primes) ; 
        int len = r - l + 1 ; 
        for(int i=0 ; i<primes ; i++){
            ll val = (hashes[i][l] * powerOfBase[i][len]) % hashPrimes[i] ; 
            hash[i] = (hashes[i][r+1] - val + hashPrimes[i]) % hashPrimes[i] ; 
        }
        return hash ; 
    }
};
class Solution {
public:
    bool check(Hashing& hs , int len , int n){
        vector<pair<ll,ll>> hashes(n-len+1) ; 
        int i = 0 , j = len-1 , idx = 0 ; 
        while(j<n){
            vector<ll> hash = hs.subArrayHash(i,j) ; 
            hashes[idx] = make_pair(hash[0],hash[1]) ; 
            i++ , j++ ; 
            idx++ ;
        }
        sort(hashes.begin(),hashes.end()) ; 

        for(int k=0 ; k<n-len+1 ; k++){
            bool reject = false ; 
            if(k > 0 && hashes[k] == hashes[k-1]){
                reject = true ; 
            }
            if(k<n-len && hashes[k] == hashes[k+1]){
                reject = true ; 
            }

            if(!reject){
                return true ; 
            }
        }

        return false ; 
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size() ; 
        Hashing hs(nums) ; 

        int low = 1 , high = n ; 
        int ans = n ;
        // FFFTTT
        while(low<=high){
            int mid = low + (high - low)/2 ; 
            if(check(hs,mid,n)){
                ans = mid ; 
                high = mid-1 ; 
            }
            else{
                low = mid + 1 ; 
            }
        }

        return ans ; 
    }
};