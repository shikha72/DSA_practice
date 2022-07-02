class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int MOD = 1e9+7;

        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());

        long long max_horz_dist=horizontalCuts[0];
        long long max_vert_dist=verticalCuts[0];

        for(int i=1;i<horizontalCuts.size();i++){
            max_horz_dist=max(max_horz_dist, (long long)(horizontalCuts[i]-horizontalCuts[i-1]));
        }

        for(int i=1;i<verticalCuts.size();i++){
            max_vert_dist=max(max_vert_dist, (long long)(verticalCuts[i]-verticalCuts[i-1]));
        }

        return ( ( max_horz_dist % MOD ) * ( max_vert_dist % MOD ) ) % MOD;
    }
};