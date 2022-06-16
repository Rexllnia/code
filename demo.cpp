//1803020131 郑宇凡 电信18-1
#include<iostream>
#include"string.h"
using namespace std;
#define  boolean bool
int strcut(char *str, char *front, char *rear, char *re)
{
    char *p1, *p2;
		
    p1 = strstr(str, front);
		if(p1==NULL)
		{
			return 0;
		}
    p1 += strlen(front);
    p2 = strstr(str, rear);
		if(p2==NULL)
		{
			return 0;
		}
		if(front==rear)
		{
			re="";
			return 0;
		}
    while (p1 != p2)
    {
        *re++ = *p1++;
    }
    *re = '\0';
}
char* func(char *str)
{
    int count=0;
    char *p=str;
    
    if(strlen(str)<10)
        return str;
    else
    {
    if(*p>='a'&&*p<='z')
    {
        *p+='A'-'a';
    }
        while(*p++!='\0')
        {
           
            count++;
            if(*p==' ')
            {
                *p='_';
            }
            if(count==10)
                break;
        }
        return str;
    }

}

class System
{

};
class out   
{
    public :void println();
};
class Demo
{
    public: static boolean isLeapYear(long prolepticYear) {
        return ((prolepticYear & 3) == 0) && ((prolepticYear % 100) != 0 || (prolepticYear % 400) == 0);
    }
    public : static void main(char* args)
    {
        
        printf("%d",isLeapYear(2000));
    }
   

};
class Main:public Demo ,public System
{
private:
    /* data */
public:
    Main(char* args);
    ~Main();
};
Main::Main(char* args)
{

    main(args);
}

int main(char* args)
{
    Main main = Main(args);
    System system ;
    
    return 0;
}