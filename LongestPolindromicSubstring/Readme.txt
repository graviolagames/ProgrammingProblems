Given an string s of n characters, find the longuest polidronic substring.

Note: A polydromic string is one that is equaly read forward or backward. 

Example:  aba  WAiAW 


Solution History Log: 

January 02 2022: 
Proposed solution: 

1) Generate a coincidence matrix: 

    The coincidence nxn matrix is formed considering  one of dymentions as the indexes of the 
    Direct string (D), and the other as the indexes of the reverse string(R). Each value V(x,y) on the 
    matrix is true if D[x]==R[y]. 


    Example: 

    s =   1 2 3 3 3 1 2 3 4 5 4 w w 3 w w 0 9 8 7 6 5 6

    Coincidence matrix
directString = 12333123454ww3ww0987656
reverseString = 6567890ww3ww45432133321
1| .         .                                   
2|   .         .                                 
3|     . . .     .           .                   
3|     . . .     .           .                   
3|     . . .     .           .                   
1| .         .                                   
2|   .         .                                 
3|     . . .     .           .                   
4|                 .   .                         
5|                   .                       .   
4|                 .   .                         
w|                       . .   . .               
w|                       . .   . .               
3|     . . .     .           .                   
w|                       . .   . .               
w|                       . .   . .               
0|                                 .             
9|                                   .           
8|                                     .         
7|                                       .       
6|                                         .   . 
5|                   .                       .   
6|                                         .   . 
 |1 2 3 3 3 1 2 3 4 5 4 w w 3 w w 0 9 8 7 6 5 6
                                               
 2) Filter: Create a new coincidence matrix of the same size, and copy only the true positions that  
 have a true naighbour at (x+1,y+1) or (x-1,y-1).

 result:

 directString = 12333123454ww3ww0987656
reverseString = 6567890ww3ww45432133321
1|                                               
2|                                               
3|       . .                                     
3|     . . .                                     
3|     . .                                       
1|                                               
2|                                               
3|                                               
4|                     .                         
5|                   .                           
4|                 .                             
w|                         .     .               
w|                       .     .                 
3|                           .                   
w|                         .     .               
w|                       .     .                 
0|                                               
9|                                               
8|                                               
7|                                               
6|                                             . 
5|                                           .   
6|                                         .     
 |1 2 3 3 3 1 2 3 4 5 4 w w 3 w w 0 9 8 7 6 5 6 



3) Project the points on the X axe, getting the polidromic array of n boolean values 

                   directString = 12333123454ww3ww0987656
reverseString = 6567890ww3ww45432133321
1|                                               
2|                                               
3|       . .                                     
3|     . . .                                     
3|     . .                                       
1|                                               
2|                                               
3|                                               
4|                     .                         
5|                   .                           
4|                 .                             
w|                         .     .               
w|                       .     .                 
3|                           .                   
w|                         .     .               
w|                       .     .                 
0|                                               
9|                                               
8|                                               
7|                                               
6|                                             . 
5|                                           .   
6|                                         .     
 |1 2 3 3 3 1 2 3 4 5 4 w w 3 w w 0 9 8 7 6 5 6 
Polidromic Array
 |    . . .       . . . . . . . .         . . . 


4) Analyse the polidromic array to find the larger subarray with repeating true values. 
 this subarray will have the same indexes of the larger polidromic substring. 


Problem-> As we can see, superposed projections may exist on the polidromic array, resulting in incorrect 
no polidromic substring.
==============================================================================================
January 03 2022
I have an idea to solve this issue: Note that the polidromes can be identified by the 
diagonal lines formed. So, instead of storing boolean on the coincidence matrix, we can
store char values. Those value may have special meaning: 

0 = No coincidence (False)
S = Coincidence  and start of diagonal line.
C = coincidence and inside of diagonal line
E = Coincidence and end of diagonal line. 

This way, we could identify the superpositions on the polidromic array.

Results: 

Coincidence Matrix
directString = 12333123454ww3ww0987656
reverseString = 6567890ww3ww45432133321
1| C         C                                   
2|   C         C                                 
3|     C C C     C           C                   
3|     C C C     C           C                   
3|     C C C     C           C                   
1| C         C                                   
2|   C         C                                 
3|     C C C     C           C                   
4|                 C   C                         
5|                   C                       C   
4|                 C   C                         
w|                       C C   C C               
w|                       C C   C C               
3|     C C C     C           C                   
w|                       C C   C C               
w|                       C C   C C               
0|                                 C             
9|                                   C           
8|                                     C         
7|                                       C       
6|                                         C   C 
5|                   C                       C   
6|                                         C   C 
 |1 2 3 3 3 1 2 3 4 5 4 w w 3 w w 0 9 8 7 6 5 6 
Polidromic Array
 |                                              
Filtered Coincidence Matrix
directString = 12333123454ww3ww0987656
reverseString = 6567890ww3ww45432133321
1|                                               
2|                                               
3|       E E                                     
3|     S C E                                     
3|     S S                                       
1|                                               
2|                                               
3|                                               
4|                     E                         
5|                   C                           
4|                 S                             
w|                         E     E               
w|                       S     C                 
3|                           C                   
w|                         C     E               
w|                       S     S                 
0|                                               
9|                                               
8|                                               
7|                                               
6|                                               
5|                                           C   
6|                                               
 |1 2 3 3 3 1 2 3 4 5 4 w w 3 w w 0 9 8 7 6 5 6 
Polidromic Array
 |    S E E       S C E S E C C E           C  


As we can see, We still have problems. The fact is that Polidromic array is no more necessary, 
as we can now find the points marked as S on the matrix. and than count its positive diagonal 
neighbours until the marked with E, and so evaluate each polidrome. 

