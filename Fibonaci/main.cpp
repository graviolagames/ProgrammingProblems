#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int Fibonaci(int input);
void printfib(int *fib,int len);
int main()
{
  for(int i = 0;i < 10;i++)
  { 
    int ret =Fibonaci(i);
    printf("fibonaci de %d = %d\n",i,ret);
  }
  return 0;
}


int Fibonaci(int input)
{
    int *fib = new int[input+1];
    int num = 0;
    int ret = 0;
    while(num <= input)
    {

       switch(num)
       {
            case 0:
              {
                fib[num] = 0;   
              }
            break;
            case 1:
              {
                fib[num] = 1;   
              }
            break;
            case 2:
              {
                fib[num] = 1;
              }
            break;
            default:
            {
                fib[num]=fib[num-1]+fib[num-2];
            }

       }
       ret = fib[num];
       num++;
    }
    delete fib;
    return ret;
}

// f(n) = f(n-1) + f(n-2)
// f(0) = 0
// f(1) = 1
// f(2) = 1
// f(3) = 2
// f(4) = 3
// f(5) = 5
// f(6) = 8
// f(20) = 6765
// f(50) = 12586269025
// f(100) = 354224848179261915075

