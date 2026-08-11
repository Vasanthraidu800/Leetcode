class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v;

        for(int x : asteroids) {
            // positive asteroid never collides with previous one
            if(x > 0) {
                v.push_back(x);
                continue;
            }
            // if x is negative
            bool alive = true;

            while(!v.empty() && v.back() > 0 && alive) {

                // previous asteroid is smaller
                if(v.back() < -x) {
                    v.pop_back();
                }
                // both have same size
                else if(v.back() == -x) {
                    v.pop_back();
                    alive = false;
                }
                // previous asteroid is bigger
                else {
                    alive = false;
                }
            }
            // negative asteroid survived
            if(alive)
                v.push_back(x);
        }

        return v;
    }
};