# LinkedList 周总结
1. **Question Overview**题目分类
* LinkedList 基本操作
* 翻转：基础
   * 使用三个指针，prev，curr，next
   * [206](https://leetcode.com/problems/reverse-linked-list/)

* Merge: 基础
   * 类似两个sorted array的merge
   * [21](https://leetcode.com/problems/merge-two-sorted-lists/)

* Swap nodes: 进阶
   * 这里步骤多且饶，要有一定的抽象想象思维，同时切记是先swap顺序再连入list中
   * [24](https://leetcode.com/problems/swap-nodes-in-pairs/)

* 找交叉：基础的双指针technique
   * 基础的龟兔赛跑双指针法，找到两者路径相同的时候，如果速度一致，那么肯定会在某个同一时间相遇
   * [160](https://leetcode.com/problems/intersection-of-two-linked-lists/)

* 回文数：进阶
   * module题：先用快慢指针找中点，然后翻转剩下一半，然后用双指针比较两半
   * [234](https://leetcode.com/problems/palindrome-linked-list/)

* 去重：
   * 这里的trick是如果有重复，当前指针不需要变化
   * [83](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

* 奇偶数重排列：
   * 这里的trick与上题类似，不需要每次判别是奇数还是偶数，间隔交替进行操作即可
   * [328](https://leetcode.com/problems/odd-even-linked-list/)

* 去除第N个元素：
   * 类似快慢指针法，让两指针间距刚好差N
   * [19](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

* 排序：
   * module题：先分后合考察merge sort
   * [148](https://leetcode.com/problems/sort-list/)

2. Algorithms
-- LinkedList题目的常用技巧：
   -
   -

**总结**：
       *dfs写的时候想好base case，一定注意考虑几种特殊情况（null，叶子，一边为null）*
       *写递归方程的时候也想想特殊情况会不会有影响，需不需要分类考虑*
       *bfs写层序遍历注意level是上一层的，如果返回当前层的记得返回正确的值*


                