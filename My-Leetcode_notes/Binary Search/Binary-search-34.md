# Binary Search 34
1. Question Overview
This question requires using two binary searches to find the first and last position of the target

2. Design and Mindset
important: overall perspective全局观
            -before writing the code, having the eagle-view of all codes
            -capsulate duplicate codes into the function; important abstraction skills
Interview tips: give more information to the interviewers; try to write the first block of codes
when detecting duplicate codes, quickly rearmed your mind and communicate with the interviewer随机应变，及时沟通

3. Algorithms
a. find the first and last position using binary search
b. there's two cases where we encounter the first target:
    -the mid element is the first element
    -the element to the left of the mid index is not equal to the mid element
c. we can set a helper function for the main function and add a boolean to decide whether we want to find the first or the last position
  `int left = 0, right = n - 1;
  `              
