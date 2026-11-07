
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> a;

        priority_queue<tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>> b;

        int n = servers.size(), m = tasks.size();

        for(int i = 0; i < n; i++)
            a.push({servers[i], i});

        vector<int> ans(m);
        long long t = 0;

        for(int i = 0; i < m; i++) {
            t = max(t, (long long)i);

            if(a.empty())
                t = max(t, get<0>(b.top()));

            while(!b.empty() && get<0>(b.top()) <= t) {
                auto [f, w, id] = b.top();
                b.pop();
                a.push({w, id});
            }

            auto [w, id] = a.top();
            a.pop();

            ans[i] = id;
            b.push({t + tasks[i], w, id});
        }

        return ans;
    }
};
