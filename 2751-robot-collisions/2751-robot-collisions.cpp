class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size() ; 

        /* if pos[i] < pos[j] && pos[i] == 'R' && pos[j] == 'L' 
        it is sure that only one of them will survive (distance decrease)

            else if pos[i] < pos[j] && pos[i] == 'L' && pos[j] == 'R'
        both may be alive (distance increases)

            else if pos[i] > pos[j] && pos[i] == 'R' && pos[j] == 'L' 
        both may be alive (distance increase)
        */

        /*
        Apporoach can be like first sorting the indices according to the values given in positions -> Using custom sort 

        Then , maintain a stack of pair<int,int> which describes health , index 

        (Completely intitutive yet)
        */

        vector<int> ind(n) ; 
        for(int i=0 ; i<n ; i++) ind[i] = i ; 

        sort(ind.begin() , ind.end() , [&](int i1 , int i2){
            return positions[i1] < positions[i2] ;
        }) ; 

        stack<pair< pair<int,int> , int> > st ; // health , ind , direction (0 -> L && 1 -> R)

        st.push(make_pair(make_pair(healths[ind[0]] , ind[0]) , directions[ind[0]] == 'R')) ; 
        vector<int> res(n,0) ; 
        res[ind[0]] = healths[ind[0]] ; 
        int i = 1 ; 
        while(i<n){
            if(st.size() == 0){
                st.push(make_pair(make_pair(healths[ind[i]] , ind[i]) , directions[ind[i]] == 'R')) ; 
                res[ind[i]] = healths[ind[i]] ;
                i++ ; 
                continue ; 
            }
            auto p = st.top() ; 

            int health = p.first.first , idx = p.first.second , dir = p.second ; 

            int curHealth = healths[ind[i]] , curIdx = ind[i] , curDir = (directions[ind[i]] == 'R') ; 

            if(dir == curDir || dir == 0){
                st.push(make_pair(make_pair(curHealth , curIdx) , curDir)) ; 
                res[curIdx] = curHealth ; 
                i++ ; 
                continue ; 
            }

            if(health > curHealth){
                st.pop() ; 
                st.push(make_pair(make_pair(health - 1 , idx),dir)) ; 
                res[idx]-- ; 
                i++ ;
            }
            else if(health == curHealth){
                st.pop() ; 
                res[idx] = 0 ; 
                i++ ; 
            }
            else{ // health < curHealth 
                int h = curHealth ;
                while(st.size() && st.top().second == 1 && h > st.top().first.first){
                    h-- ; 
                    res[st.top().first.second] = 0 ; 
                    st.pop() ; 
                }
                if(st.size() && st.top().second == 1){
                    if(h == st.top().first.first){
                        res[st.top().first.second] = 0 ; 
                        h = 0 ; 
                        st.pop() ; 
                    }
                    else if(h < st.top().first.first){
                        res[st.top().first.second]-- ; 
                        int topHealth = st.top().first.first ;
                        int topIdx = st.top().first.second ;
                        int topDir = st.top().second ;
                        st.pop() ;
                        st.push(make_pair(make_pair(topHealth - 1, topIdx), topDir)) ;
                        h = 0 ;
                    }
                }
                if(h > 0){
                    res[curIdx] = h ; 
                    st.push(make_pair(make_pair(h,curIdx) , directions[curIdx] == 'R')) ; 
                }
                i++ ; 
            }
        }

        vector<int> ans ; 
        for(int i=0 ; i<n ; i++){
            if(res[i] != 0) ans.push_back(res[i]) ; 
        }

        return ans ; 
    }
};