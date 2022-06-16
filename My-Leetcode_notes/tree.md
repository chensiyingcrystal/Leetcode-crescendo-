# Tree Week Review
**Questions review**

* Tree's Depth：
   * 1. Maximum depth of binary tree
   * [104](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
   * Keypoints: 
        * dfs: basic recursion
        * bfs: level traversing(convert this problem to counting levels of binary tree)

   * 2. Minimum depth of binary tree
   * [111](https://leetcode.com/problems/minimum-depth-of-binary-tree/)
   * Keypoints: 
        * dfs: basic recursion with several base cases!!
        * bfs: level traversing(early return during level traversing)
    
   * 3. Muted problem: 559
   * [559]

* Tree's properties
   * 1. Balanced tree
   * [110](https://leetcode.com/problems/balanced-binary-tree/)
   * Keypoints: 
        * understanding what is a balanced tree
        * need to update two messages during one time dfs traversing
        * trick: can use pair but is better to use one variable to represent two messages!


   * 2. Symmetric tree
   * [101](https://leetcode.com/problems/symmetric-tree/)
   * Keypoints: 
        * dfs: how to design a dfs with two parameters; handle several base cases.
    
* Tree's path
   * 1. Diameter of Binary Tree
   * [543](https://leetcode.com/problems/diameter-of-binary-tree/)
   * Keypoints: 
        * dfs: update one message while returning another message!!


   * 2. Path Sum
   * [112](https://leetcode.com/problems/path-sum/)
   * Keypoints: 
        * dfs: basic recursion; think how to get result based on its subtree's result


   * 3. Path Sum II
   * [113](https://leetcode.com/problems/path-sum-ii/)
   * Keypoints: 
        * basic backtrack: natural logic; design base case reasonably
    
   * 4. Path Sum III
   * [437](https://leetcode.com/problems/path-sum-iii/)
   * Keypoints: 
        * prefix sum: many important details


   * 5. Delete node and return forest
   * [1110] (https://leetcode.com/problems/delete-nodes-and-return-forest/)
   * Keypoints:
        * preprocessing: use unordered_set
        * design dfs: 
            * first write natural base cases
            * if not coming with any base cases, think a recursive case
            * if complicated and not natural recursive case, then process it with several cases 
            and write code naturally with logic; lastly finding ways to optimize code







