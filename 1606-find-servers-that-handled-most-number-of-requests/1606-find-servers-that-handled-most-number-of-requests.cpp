class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> s;
        priority_queue<pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>> pq;

        vector<int> cnt(k, 0);

        for(int i = 0; i < k; i++)
            s.insert(i);

        for(int i = 0; i < arrival.size(); i++) {
            long long t = arrival[i];

            while(!pq.empty() && pq.top().first <= t) {
                s.insert(pq.top().second);
                pq.pop();
            }

            if(s.empty())
                continue;

            int id = i % k;
            auto it = s.lower_bound(id);

            if(it == s.end())
                it = s.begin();

            int j = *it;
            s.erase(it);

            cnt[j]++;
            pq.push({t + load[i], j});
        }

        int mx = *max_element(cnt.begin(), cnt.end());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            if(cnt[i] == mx)
                ans.push_back(i);
        }

        return ans;
    }
};