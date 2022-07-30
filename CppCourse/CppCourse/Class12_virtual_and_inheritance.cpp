#include "Class12_virtual_and_inheritance.h"
#include <vector>
#include <string>

using namespace std;

/*
�������������ģʽ��
composition ��� ��ʾ has-a
Delegation ί��
Inheritance �̳� ��ʾ is-a

��ϵķ�ʽ��
����һ�����У�������һ����Ķ��������ʹ��
ί�еķ�ʽ��
����һ�����У�������һ�����ָ�룬������Ĺ���ί�и�ָ�������ʵ��
�̳еķ�ʽ��
��һ������̳�һ�����࣬����ʵ���˻������ܣ������������Լ������ʵ�ָ��๦��
*/

/*
virtual function �麯��
�麯����Ϊ����϶�̬��ʹ�õ�

�ڼ̳еĹ�ϵ��
���ݿ��Ա��̳У�ռ�����ڴ��һ����
�������Ա��̳У������ڴ��л��Ƕ���һ�ݣ��̳е��ǵ���Ȩ

�麯�������֣�
non-virtual ���麯��  ��ϣ���������¶���(override ��д)��
virtual �麯��		  ϣ���������¶���(override ��д)�������Ѿ���Ĭ�϶���
pure virtual ���麯�� ����һ��Ҫ������

*/

//����һ����״���ࣺ
class Shape
{
public:
	virtual void draw() const = 0;//���麯�� =0 �ǹؼ�
	virtual void error(const string& msg);//�麯�� ������ʱ������һ��������Ϣ
	int objectID()const;//���麯�� objectID ���������ID�������־ ��ϣ���������¶���
};
//����
void Shape::error(const string& msg) {}
int Shape::objectID() const {return 0;}
//����
class Rectangle : public Shape{};
//��Բ
class Ellipse : public Shape{};