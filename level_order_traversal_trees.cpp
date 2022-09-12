class Solution {
public:
    //We need to apply Breadth first Search for this given tree.
    // That is why we need a Queue for DS for our problem .
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {}; // if Tree is Empty
        vector<vector<int>> ans;
        
        // We are taking Queue to do Level Order Traversal
        queue<TreeNode*>q ;
        q.push(root);
        
        // We are suppose to set some indication for one level to end , here we chose NULL
        q.push(NULL);
        vector<int> temp ; // vector to keep current array of items
        while(!q.empty())
        {   
            TreeNode *ptr = q.front();
            q.pop(); // Removing front item and will be adding children for same front element
            //Check for Level Order and push current vector to main answer.
            if(ptr == NULL)
            {
                ans.push_back(temp);
                temp.clear();
                if(!q.empty()) q.push(NULL); // check if atleast one parent element left in queue.
            }
            else
            {
                temp.push_back(ptr->val);
                
                // pushing childens of current front element.
                if(ptr->left) q.push(ptr->left);
                if(ptr->right) q.push(ptr->right);
            }
            
        }
        
        return ans;
    }
};