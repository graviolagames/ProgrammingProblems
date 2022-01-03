

#include <stdio.h>
//Convert roman numeral to integer. 
//Return 0 in case of error ( 0 is not possible in Roman notation)
int ConvertRomanToInteger(char *roman);
//Simbol indexes
enum { invalid,I,V,X,L,C,D,M,MAX_SYMBOLS}; //n is invalid symbol
char symbols[8] = {0,'I','V','X','L','C','D','M'};
int symbolValues[] = {0,1,5,10,50,100,500,1000};
int GetSymbolId(char symbol);
int processSymbol(int symbol,int lastSymbol,int subtractor);
int  main()
{
    char romanValue[] = "MMMCMXCIX";
    
    int ret = ConvertRomanToInteger(romanValue);
    printf("\nRomanValue %s = %d\n",romanValue,ret);
}

int ConvertRomanToInteger(char *roman)
{
    //
    //Note this method assumes that theinputed romman numeral is valid.
    //
    int ret = 0;
    bool finish = false;
    int symbolIndex = 0;
    int lastSymbol = invalid;
    while(!finish)
    {
        int symbol = GetSymbolId(roman[symbolIndex]);
        
        printf("%c",symbols[symbol]);

        if(symbol==0)
        {
            finish = true;
        }
        else
        {    
           switch(symbol)
           {
                case I:
                {
                    ret+=symbolValues[symbol];
                }break; 
                case V:
                case X:
                {
                    ret+= processSymbol(symbol,lastSymbol,I);
                }break;               
                case L:
                case C:
                {
                    ret+= processSymbol(symbol,lastSymbol,X);
                }break;               
                case D:
                case M:
                {
                    ret+= processSymbol(symbol,lastSymbol,C);
                }break;                 
           }
           printf("\nSymbol Value = %d, ret = %d\n",symbolValues[symbol],ret);   
        }
        lastSymbol = symbol;
        symbolIndex++;
    }
    return ret;
}
int processSymbol(int symbol,int lastSymbol,int subtractor)
{
    int ret = 0;
    if(lastSymbol == subtractor)
    {
        ret = (symbolValues[symbol]-2*symbolValues[lastSymbol]);
    }
    else
    {
        ret = symbolValues[symbol];
    }
    return ret;
}
int GetSymbolId(char symbol)
{
    for(int i = 1; i < MAX_SYMBOLS;i++)
    {
        if(symbol == symbols[i])
            return i;
    }
    return 0;
}