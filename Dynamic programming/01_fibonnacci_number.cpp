#include<bits/stdc++.h>

using namespace std;

int solve(int n, vector<int>& cost, vector<int>&dp) {
        if (n >= cost.size())
            return 0;
        
        if(dp[n]!=-1) return dp[n];
        int oneStepCost = solve(n + 1, cost, dp);
        cout <<"1->" << oneStepCost << " ";
        int twoStepCost = solve(n + 2, cost, dp);
        cout <<"2->" << twoStepCost << " ";
        cout << min(oneStepCost, twoStepCost) << endl;
        

        return dp[n] = cost[n] +  min(oneStepCost, twoStepCost);
    }

int main(){

	vector<int> cost = {10, 15, 20};
	vector<int> dp(cost.size()+1, -1);
     int ans = min(solve(0, cost, dp), solve(1, cost, dp));


     cout << "======ans======" << endl;
     cout << ans;
}