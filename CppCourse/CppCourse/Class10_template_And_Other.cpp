#include "Class10_template_And_Other.h"

/*
static ��̬
������data members(��Ա����) �� member functions(��Ա����)
���ڱ������߶��� �ǿ��Դ��ڶ���� ���ڴ�ռ��У�ÿ�����ݶ��Ὺ��һ�οռ�
���ں��� ֻ�����һ�� �ڴ�ռ���Ҳֻ�����һ���ռ�

������һ��������ʱ��
{
tempClass c1;
c1.function();
//�ȼ���
tempClass::funciotn(&c1);
}
����ĺ����ڲ�����һ��thisָ�� ָ����ĳ�Ա����

��һ�����ݱ�static����֮�� ���ڴ�ռ����������ֻ����һ��
��һ��������Ҫ��һ�����ݲ�Ӧ�ô��ڶ����Ӧ�������ж���ֻ����һ������ʱ���Ϳ���ʹ�þ�̬����

��һ��������static����֮�� ͬ�����ڴ�ռ���ֻ��һ��
���ǲ�ͬ���ǣ���̬����������thisָ�룬Ҳ�Ͳ��ܵ��ó�Ա����
���ǿ��Ե��þ�̬���ݣ����ǻ�����۵ġ�
*/

//static ��ʹ�ã�
class Account//�˻�
{
public:
	static double m_rate; //����  �������У������Ƕ����ģ������˻�����һ������
	static void set_rate(const double& x) { m_rate = x; };//ֻ����m_rate ���޸ĺ���
};
double Account::m_rate = 8.0;//��������̬����֮��������Ҫ�������ݣ������ڴ����ڴ�ռ䣬��ֵ���Բ���

/*
static�����ĵ��������֣�
��һ�����ж����ʱ��ĵ��ã�
Account a;
a.set_rate(5.0);
�ڶ�����û�ж���ʱ��ĵ��ã�
Account::set_rate(7.0);
*/

/*
����static ��һ�����ģʽ��Singleton ����ģʽ
�����ȴ���һ��˽�еĹ����������ٴ���һ��˽�еľ�̬����
�����̬������û�д��������ͨ����֮ǰ�ʹ����ˣ���ֻ��һ��
Ȼ��дһ�����еľ�̬�������ؾ�̬����
�����Ե���������еľ�̬�������ؾ�̬����Ȼ�������ͨ������

A::getInstance().funciton();
*/
class A
{
public:
	static A& getInstance() { return a; };//һ�����еľ�̬�����ӿڣ��Խ�a
	void function() {};//��ͨ�ĺ���
private:
	A();//��������
	A(const A& rhs);//������������
	static A a; //һ��˽�еľ�̬����a��������˽�еĹ�������
};

/*
��������д����ȱ��
�Ǿ�����û��ʹ��������ʱ��Ҳ���ھ�̬����a
���Խ���̬����a�Ĵ�������Ψһ��̬�ӿ�getInstance�����

A& A::getInstance()
{
	static A a;//��ʱ��ֻ�е��ýӿڵ�ʱ��Ŵ�������ֻ��һ��
	return a;
}

*/

/*
ģ��template
����ģ��ͺ���ģ��

template <typename T>
typename ����дΪclass

����ģ���У�һ�����������Բ�ͬ��������в�ͬ���÷���
��ʱ�������ģ�壬ʵ�ֲ�ͬ���͵����ݵĴ���

Ҳ����ʹ�ú���ģ��
��һ�������ĺ���ʹ��ģ�壬���磺
template <class T>
inline const T& min(const T& a,const T& b)
{
	return a < b ? a : b;
}
���ǵ�T��һ���࣬�Ҿ��г��������ʱ��������Ӧ�����������<
����class stone :
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