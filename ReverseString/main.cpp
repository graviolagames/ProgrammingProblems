#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

char * ReverseString(char *input);

int main() {
	//cout<<"Hello";
  char input[] = "Reverse_it";
  
  char *ret = ReverseString(input);
  //printf("%s\n",ret);
  cout<<ret;
	return 0;
}

char * ReverseString(char *input)
{
  
  char * ret;
  int len = strlen(input);
  ret = new char[len+1];
  ret[len] = 0;  //Garante que o último character do retorno é zero
  for(int i=0; i< len; i++)
  {
      ret[i] = input[len-1-i]; //Inverte a posição de todos os caracteres, menos o último, que é zero
  }
  return ret;

}

