#include "Class10_template_And_Other.h"

/*
static 静态
作用于data members(成员数据) 或 member functions(成员函数)
对于变量或者对象 是可以存在多个的 在内存空间中，每个数据都会开辟一段空间
对于函数 只会存在一个 内存空间中也只会存在一个空间

当调用一个函数的时候：
{
tempClass c1;
c1.function();
//等价于
tempClass::funciotn(&c1);
}
在类的函数内部会有一个this指针 指向类的成员数据

当一个数据被static修饰之后 在内存空间中这个数据只会有一个
当一个类中需要有一个数据不应该存在多个，应该是所有对象只面向一个数据时，就可以使用静态数据

当一个函数被static修饰之后 同样在内存空间中只有一个
但是不同的是，静态函数不存在this指针，也就不能调用成员数据
但是可以调用静态数据，这是环环相扣的。
*/

//static 的使用：
class Account//账户
{
public:
	static double m_rate; //利率  在银行中，利率是独立的，所有账户面向一个利率
	static void set_rate(const double& x) { m_rate = x; };//只面向m_rate 的修改函数
};
double Account::m_rate = 8.0;//在声明静态变量之后，在类外要定义数据，这是在创建内存空间，初值可以不设

/*
static函数的调用有两种：
第一种是有对象的时候的调用：
Account a;
a.set_rate(5.0);
第二种是没有对象时侯的调用：
Account::set_rate(7.0);
*/

/*
对于static 有一种设计模式：Singleton 单例模式
可以先创建一个私有的构建函数，再创建一个私有的静态对象
这个静态对象在没有创建类的普通对象之前就存在了，且只有一个
然后写一个公有的静态函数返回静态对象
外界可以调用这个公有的静态函数返回静态对象然后调用普通函数：

A::getInstance().funciton();
*/
class A
{
public:
	static A& getInstance() { return a; };//一个共有的静态函数接口，对接a
	void function() {};//普通的函数
private:
	A();//构建函数
	A(const A& rhs);//拷贝构建函数
	static A a; //一个私有的静态对象a，创建于私有的构建函数
};

/*
但是这种写法有缺点
那就是在没有使用这个类的时候也存在静态对象a
所以将静态对象a的创建放在唯一静态接口getInstance里更好

A& A::getInstance()
{
	static A a;//这时候，只有调用接口的时候才创建，且只有一个
	return a;
}

*/

/*
模板template
有类模板和函数模板

template <typename T>
typename 可以写为class

在类模板中，一个类的数据针对不同情况或许有不同的用法，
这时候可以用模板，实现不同类型的数据的处理

也可以使用函数模板
对一个单独的函数使用模板，比如：
template <class T>
inline const T& min(const T& a,const T& b)
{
	return a < b ? a : b;
}
但是当T是一个类，且具有抽象意义的时候，类的设计应当重载运算符<
比如class stone :
class stone
{
public:
	stone(int w) : _weight(w) {};
	bool operator < (const stone& rhs) const
	{return _weight < rhs._weight;}
private:
	int _weight;
};

*/