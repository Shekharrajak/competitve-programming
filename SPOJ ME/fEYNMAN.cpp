#include<stdio.h>
int main()
{
 int a;
 while(scanf("%d",&a))
 {
  if(a==0)
   break;
  int sum;
  sum=(a*(a+1)*(2*a+1))/6;
  printf("%d\n",sum);
 }
 return 0;
}
/*

Date: 08/15/97 at 05:46:20
From: Doctor Anthony
Subject: Re: Number problem

Consider the lefthand vertical edge of a square of size 1 x 1.  
This edge can be in any one of 8 positions. Similarly, the top 
edge can occupy any one of 8 positions for a 1 x 1 square.  
So the total number of 1 x 1 squares = 8 x 8 = 64.

For a 2 x 2 square the lefthand edge can occupy 7 positions and 
the top edge 7 positions, giving 7 x 7 = 49 squares of size 2 x 2.

Continuing in this way we get squares of size 3 x 3, 4 x 4 and so on.

We can summarize the results as follows:

   Size Of square      Number of squares
   ---------------     -----------------
      1 x 1               8^2 = 64
      2 x 2               7^2 = 49
      3 x 3               6^2 = 36
      4 x 4               5^2 = 25
      5 x 5               4^2 = 16
      6 x 6               3^2 =  9
      7 x 7               2^2 =  4
      8 x 8               1^2 =  1
                      ---------------
                      Total   = 204

There is a formula for the sum of squares of the integers 
1^2 + 2^2 + 3^2 + ...  + n^2

                n(n+1)(2n+1)
         Sum  = ------------
                     6

In our case, with n = 8, this formula gives 8 x 9 x 17/6 = 204.

As an extension to this problem, you might want to calculate the 
number of rectangles that can be drawn on a chessboard.

*/
