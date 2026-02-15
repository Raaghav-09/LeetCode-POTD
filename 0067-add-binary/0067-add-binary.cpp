class Solution {
public:
    // Method 1

    // int binaryToInt(string a){
    //     int n = a.length() ;
    //     int ans = 0 ;
    //     for(int i=n-1 ; i>=0 ; i--){
    //         // cout<<ans<<" ";
    //         ans+=(a[i]-48)*pow(2,n-i-1);
    //     }
    //     // cout<<endl;
    //     // cout<<ans<<endl;
    //     return ans ;
    // }
    // string intToBinary(int b){
    //     string ans = "" ;
    //     while(b){
    //         ans+=to_string(b%2);
    //         b/=2 ;
    //     }
    //     reverse(ans.begin(),ans.end()) ;
    //     // cout<<ans<<endl;
    //     return ans ;
    // }
    string addBinary(string a, string b) {
        // int val1 = binaryToInt(a) ;
        // int val2 = binaryToInt(b) ;
        // string ans = intToBinary(val1+val2) ;
        // if(ans=="") ans="0";
        // return ans ;

        //Method-2

        int carry = 0;
        string result = "";
        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            result = (sum % 2 == 0 ? "0" : "1") + result;
            carry = sum / 2;
        }
        return result;
    }
};