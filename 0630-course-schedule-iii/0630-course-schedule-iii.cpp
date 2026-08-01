class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size() ; 
        /*
    =>  If ending at same lastday , arrange them such that smallest duration course is done first . 
    =>  What if i sort it completely using shorter duration 
    =>  100 200 , 1000 1250 , 200 1300 , 2000 3200
    =>  200___________1250___1300_________________3200
        100           1000   200                  2000
    =>         1050        50         1900
    =>   

        */
        sort(courses.begin(),courses.end(),[&](vector<int>& v1 , vector<int>& v2){
            if(v1[1] != v2[1]) return v1[1] < v2[1] ; 
            return v1[0] < v2[0]; 
        });

        priority_queue<int> pq ; 
        int t = 0 ; 

        for(int i=0 ; i<n ; i++){
            int d = courses[i][0] ; 
            int l = courses[i][1] ; 

            if(t + d <= l){
                t += d ; 
                pq.push(d) ; 
            }
            else if(pq.size() && pq.top() > d){
                t += d ; 
                t -= pq.top() ; 
                pq.pop() ; 
                pq.push(d) ; 
            }
        }

        return pq.size() ; 
    }
};