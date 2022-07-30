#include "Class12_virtual_and_inheritance.h"
#include <vector>
#include <string>

using namespace std;

/*
面向对象有三种模式：
composition 组合 表示 has-a
Delegation 委托
Inheritance 继承 表示 is-a

组合的方式，
是在一个类中，创建另一个类的对象，来组合使用
委托的方式，
是在一个类中，创建另一个类的指针，将本类的功能委托给指针的类来实现
继承的方式，
是一个子类继承一个基类，基类实现了基本功能，子类来根据自己的情况实现更多功能
*/

/*
virtual function 虚函数
虚函数是为了配合多态来使用的

在继承的关系中
数据可以被继承，占用了内存的一部分
函数可以被继承，但在内存中还是独立一份，继承的是调用权

虚函数分三种：
non-virtual 非虚函数  不希望子类重新定义(override 重写)它
virtual 虚函数		  希望子类重新定义(override 重写)它，且已经有默认定义
pure virtual 纯虚函数 子类一定要定义它

*/

//比如一个形状基类：
class Shape
{
public:
	virtual void draw() const = 0;//纯虚函数 =0 是关键
	virtual void error(const string& msg);//虚函数 当出错时，报出一个错误信息
	int objectID()const;//非虚函数 objectID 含义是类的ID，特殊标志 不希望子类重新定义
};
//定义
void Shape::error(const string& msg) {}
int Shape::objectID() const {return 0;}
//矩形
class Rectangle : public Shape{};
//椭圆
class Ellipse : public Shape{};