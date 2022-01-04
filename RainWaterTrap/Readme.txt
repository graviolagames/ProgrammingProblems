Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

See the png image on this folder. 
 

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9

 

Constraints:

    n == height.length
    1 <= n <= 2 * 104
    0 <= height[i] <= 105
==============================================================================================

Solution history: 

Jan 04 2022: First approach: 

1) Create a [w,h] matrix were width is the size of the array of elevations and height is the larger elevation

2) for each column , corresponding with each elevation value, register each position with 
water (w) or terrain (t) according with the  y value compared with the elevation on that column. 

On the case of first and last column, do not register water value, leaving those positions with 0 

3) For the second to the penultimate column, register 0 on positions that have no confined water. 

   Confined water:    Is a position p(x,y)= w were:
                       p(x-1,y)= t or w
                       and
                       p(x,y+1) = t or w 
Pass this analisis from left to right and from right to left 


4)For all matrix, count how many positions marked with water. and return this value. 

Results: 

Input = 010210132121
Step 2
 ======M=== 
 ==M===MM=M 
 M=MM=MMMMMM
Step 3
       M    
   M===MM=M 
 M=MM=MMMMMM
Trapped water = 6

Input = 010210132121010210132121
Step 2
 ======M===========M=== 
 ==M===MM=M====M===MM=M 
 M=MM=MMMMMM=M=MM=MMMMMM
Step 3
       M===========M    
   M===MM=M====M===MM=M 
 M=MM=MMMMMM=M=MM=MMMMMM
Trapped water = 28


Input = 01021011021210120290132121
Step 2
 ============M========= 
 ============M========= 
 ======M=====M========= 
 ======M=====M==M====== 
 ======M=====M==M====== 
 ======M=====M==M====== 
 ======M=====M==M====== 
 ======M=====M==M====== 
 ======M=====M==M====== 
 ======M=====M==M==M=== 
 ==M===MM=M==M=MM==MM=M 
 M=MM=MMMMMM=M=MM=MMMMMM
Step 3
             M          
             M          
       M=====M          
       M=====M==M       
       M=====M==M       
       M=====M==M       
       M=====M==M       
       M=====M==M       
       M=====M==M       
       M=====M==M==M    
   M===MM=M==M=MM==MM=M 
 M=MM=MMMMMM=M=MM=MMMMMM




