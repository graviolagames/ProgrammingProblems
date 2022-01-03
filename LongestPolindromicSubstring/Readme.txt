Given an string s of n characters, find the longuest polidronic substring.

Note: A polydromic istring is one that is equaly read forward or backward. 

Example:  aba  WAiAW 

Solution: 

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


Problem-> Superposed projections may exist on the polidromic array, resulting in incorrect 
resulting substring.


