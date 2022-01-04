
#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;

#define separatorChar ' '

char * RevertWordsInString(char *input);
 
int main()
{
    char input[] = "Graviola       Games  is  the  best  game developer ever";
    char * ret = RevertWordsInString(input);
    printf("\nOutput= %s \n",ret);

}

char *RevertWordsInString(char *input)
{

    int inputLen = strlen(input);
    stack<char *> wordStack;
    char *tempString = new char[inputLen+1];
    int tempIndex = 0;
    int outputStringSize = 0;
    printf("\nInput = ");
    for(int i = 0;i <= inputLen;i++)
    {
        printf("%c",input[i]);
        if( (input[i]!=separatorChar) && (i<inputLen) )
        {
            tempString[tempIndex] = input[i];
            tempIndex++;
            tempString[tempIndex] = 0;
        }
        else if(tempIndex > 0 ) //tempString contains a word 
        {
            char *word = new char[strlen(tempString)+1];
            sprintf(word,"%s ",tempString); //The detected word with an space
            outputStringSize += strlen(word);
            wordStack.push(word);
            tempIndex = 0;
            tempString[tempIndex]= 0; //Delete the temp string
        }
        
    }
    printf("\n");
    //Recover the words in a new string:
    char *outputString = new char[outputStringSize+1];
    tempIndex = 0;
    while(!wordStack.empty())
    {
        char *word = wordStack.top();
        wordStack.pop();
        strcpy(&outputString[tempIndex],word);
        tempIndex += strlen(word);
        delete word;
    }
    delete tempString;
    return outputString;
}