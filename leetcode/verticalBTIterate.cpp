/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        return search(root);
    }
private:
    vector<vector<int>> search(TreeNode * curr) {
        int min = 0;
        queue<TreeNode *> nodeQ;
        queue<int> nodeI;
        
        nodeQ.push(curr);
        nodeI.push(0);
        vector<vector<int>> ret = {};
        unordered_map<int, vector<int>> wmap;
        
        while (!nodeQ.empty()) {
            int k = nodeQ.size();
            unordered_map<int, vector<int>> umap;

            while(k--) {            
                curr = nodeQ.front();
                int index = nodeI.front();
                if (index < min) {
                    min = index;
                }
                nodeQ.pop();
                nodeI.pop();


                if (curr == NULL) {
                    continue;
                }

                umap[index].push_back(curr->val);
                sort(umap[index].begin(), umap[index].end());
                nodeQ.push(curr->left);
                nodeI.push(index - 1);

                nodeQ.push(curr->right);
                nodeI.push(index + 1);
            }
            
            for (auto &v : umap) {
                if (wmap.find(v.first) == wmap.end()) {
                    wmap[v.first] = {};
                }
                wmap[v.first].insert(wmap[v.first].end(),umap[v.first].begin(), umap[v.first].end());
            }
        }
        
            for (auto &v : wmap) {
                cout << "index = " << (v.first - min) << endl;
                if (v.first - min >= ret.size()) {
                    ret.resize(v.first - min);
                }
                ret[v.first - min - 1] = v.second;
            }

        return ret;
    }
};