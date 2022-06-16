#include<iostream>
#include"string.h"
class Human
{
public://属性全部设置为公有
    char name[4]="";
    bool gender;
    uint8_t age;
    Human(char* name,bool gender=0 ,uint8_t age=0);
    void showInfo();
    ~Human();
};
Human::Human(char* name,bool gender,uint8_t age)
{
    strcpy(name,"");
    this->gender=gender;
    this->age=age;
    strcpy(this->name,name);
}
Human::~Human()
{
    printf("delete");
}
class Student :public Human //公有方式继承
{
public:

    void showInfo()//子类重写showInfo
    {
        
        printf("Name:%s,Gender:%d Age: %d ",name,gender,age);//由于是公有继承 且这三个都是公有变量所以可以直接用
    }
    Student(char* Name ,bool Gender,uint8_t Age)//子类调用父类构造函数进行赋值
    {
        Human human=Human(Name,Gender,Age);

    }
};
int main()
{
   Student student("zyf",1,21);
    student.showInfo();
    return 0;
}
