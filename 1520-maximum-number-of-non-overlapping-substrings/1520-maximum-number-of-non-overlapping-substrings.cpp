class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size() ; 

        auto isOverlap = [&](int x , int y , int a , int b) -> bool{
            // // case 1 
            // // x a y b 
            // if(x < a && y < b) return true ; 
            // // case 2 
            // // a x b y 
            // if(a < x && b < y) return true ; 
            // // case 3 
            // // a x y b 
            // if(a<x && y < b) return true ; 
            // // case 4 
            // // x a b y 
            // if(x < a && b < y) return true ; 

            // return false ; 

            // a b x y 
            if(b < x) return false ; 
            // x y a b 
            if(y < a) return false ; 
            return true ; 
        };
        /*
        adefaddaccc
        012345678910
        a - [0,7]
        d - [1,6]
        e - [2,2]
        f - [3,3]
        c - [8,10]
        */

        map<char,pair<int,int>> mp ; 
        for(int i=0 ; i<n ; i++){
            if(!mp.count(s[i])){
                mp[s[i]].first = i ; 
            }

            mp[s[i]].second = i ; 
        }

        // auto f = [&](auto&& f , int ind) -> int{

        //     for(int i=ind ; i<n ; i++){

        //     }
        // };

        // maximum non overlapping interval

        vector<pair<int,int>> v ; 
        for(auto [ch,p] : mp) {
            int l = p.first, r = p.second;
            bool valid = true;
            
            for (int i = l; i <= r; i++) {
                if (mp[s[i]].first < l) {
                    valid = false;
                    break;
                }
                r = max(r, mp[s[i]].second); 
            }
            if (valid) {
                v.push_back({l, r});
            }
        }


        /*
        Greedy choices : 
        1. [a,b] [x,y]
        a < x and b > y => chose [x,y]

        2. Does this mean if I sort it by length, I will get the best answer 

        I think the initution is correct . Let's implement this 
        */

        sort(v.begin(),v.end(),[&](auto& p1 , auto& p2){
            int x = p1.first , y = p1.second ; 
            int a = p2.first , b = p2.second ; 
            return y-x < b-a ; 
        });

        int m = v.size() ; 
        vector<bool> consider(m,0) ; 
        for(int i=0 ; i<m ; i++){
            bool flag = true ; 
            for(int j=0 ; j<i ; j++){
                if(consider[j]){
                    if(isOverlap(v[i].first , v[i].second , v[j].first , v[j].second)){
                        flag = false; 
                        break ; 
                    }
                }
            }
            if(flag){
                consider[i] = true ; 
            }
        }

        vector<string> ans ; 
        for(int i=0 ; i<m ; i++){
            if(consider[i]){
                int len = v[i].second - v[i].first + 1 ; 
                ans.push_back(s.substr(v[i].first,len)) ; 
            }
        }

        return ans ; 
    }
};