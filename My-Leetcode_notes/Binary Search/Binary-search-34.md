# Binary Search 周总结
1. **Question Overview**题目分类

* 最**基础的binary search： 
   * (704)[https://leetcode.com/problems/binary-search/]

* 与bs相关的**数学题：
   * 69（https://leetcode.com/problems/sqrtx/）
   * 367（https://leetcode.com/problems/valid-perfect-square/）
* index边界题**intermediate: 插入型找index题35（https://leetcode.com/problems/search-insert-position/）
                 找左右边界index题34（https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/）
* 旋转数组类型**advanced：旋转数组找数字33（https://leetcode.com/problems/search-in-rotated-sorted-array/）
                       33变形题出现重复数字81（https://leetcode.com/problems/search-in-rotated-sorted-array-ii/）
                       旋转数组找最小值153（https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/）
                       153变形题出现重复数字154（https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/）

2. Design and Mindset
important: **overall perspective全局观
            -before writing the code, having the eagle-view of all codes
            -capsulate duplicate codes into the function; important abstraction skills
Interview tips: give more information to the interviewers; try to write the first block of codes
when detecting duplicate codes, quickly rearmed your mind and communicate with the interviewer随机应变，及时沟通

3. Algorithms
-- 本周总结了二分写法的两种形式：
   第一种是while(left <= right), 中间递增条件是left = mid + 1, right = mid - 1
   第二种是while(right - left > 1), 中间递增条件是left = mid, right = mid
   对于某些题而言（704）使用两种写法并无大的区别，但是对于某些题而言，却各自有适用空间。
   - 34题：找两端边界，如果用第一种写法，那么对于元素相等的边界条件的处理，需要细致分析，**推荐
          如果使用第二种写法，可将相等的情形包含在一个阵营，进行粗暴的扩张，最后添加后处理，**推荐
   - 35题： 插入元素的位置，这里也涉及两端的情形，如果用第二种方法，找到边界后再添加后处理，**推荐使用
           如果用第一种方法，需要加以分析退出循环后left和right以及与插入元素的关系
   - 33题：找一个数字，使用第一种方法很便利，定位数组是在chasm处或者单调处，循环终止后直接报未找到，**推荐
           如果使用第二种方法，需要对数组个数进行前处理，对循环终止后进行后处理
   - 81题：与33题相似，添加mid与left相等的特殊情况下线性处理，**推荐
   - 153题：寻找断层，与边界相关，使用第二种方法明显简便，**推荐
   - 154题：与153相似，只需添加mid与right相等的特殊情况下线性处理，**推荐
**总结：寻找边界最后收缩到两个端点处加以判断就肯定找到answer的题，优先选第二种
       仅仅寻找一个数字用第一种方法能省去前处理和后处理的一些麻烦
       *使用第二种的时候注意能否照顾到数组中只有一个和两个元素的情形，如果是旋转数组题要考虑能否照顾到未旋转数组*
       *使用第一种的时候要注意mid与target相等情况的分析*


                