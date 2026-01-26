class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        map<char,int> mp;
        for(int i = 0; i < tasks.size(); i++){
            mp[tasks[i]]++;
        }

        priority_queue<pair<int,char>> pq; // {freq, char}
        for(auto [ch, freq] : mp){
            pq.push({freq, ch});
        }

        map<char, pair<int,int>> cycles;
        int cyclesYet = 0;

        while(pq.size() || cycles.size()){
            cyclesYet++;

            vector<char> done;
            for(auto &[ch, p] : cycles){
                if(p.first == cyclesYet){
                    pq.push({p.second, ch});
                    done.push_back(ch);
                }
            }
            for(char ch : done) cycles.erase(ch);

            if(pq.size()){
                auto [freq, ch] = pq.top();
                pq.pop();
                freq--;

                if(freq > 0){
                    cycles[ch] = {cyclesYet+n+1, freq};
                }
            }
        }

        return cyclesYet;
    }
};
