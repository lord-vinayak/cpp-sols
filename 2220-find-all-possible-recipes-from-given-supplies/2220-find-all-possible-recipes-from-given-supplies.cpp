class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {

        unordered_set<string> available(supplies.begin(), supplies.end());

        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        unordered_set<string> recipeSet(recipes.begin(), recipes.end());

        for (int i = 0; i < recipes.size(); i++) {
            for (string &ing : ingredients[i]) {
                if (recipeSet.count(ing)) {
                    graph[ing].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }

        queue<string> q;

        for (int i = 0; i < recipes.size(); i++) {
            if (indegree[recipes[i]] == 0)
                q.push(recipes[i]);
        }

        vector<string> ans;

        while (!q.empty()) {
            string recipe = q.front();
            q.pop();

            auto it = find(recipes.begin(), recipes.end(), recipe);
            int idx = it - recipes.begin();

            bool ok = true;

            for (string &ing : ingredients[idx]) {
                if (!available.count(ing)) {
                    ok = false;
                    break;
                }
            }

            if (!ok)
                continue;

            ans.push_back(recipe);
            available.insert(recipe);

            for (string &next : graph[recipe]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        return ans;
    }
};