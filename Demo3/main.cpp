#include<iostream>
#include<vector> 
#include<functional>
#include<iterator>   
#include <filesystem>
#include "Quote.h"
using namespace std;
using namespace placeholders;
class Base
{
	friend class Pal;
public:
	void pub_mem();//
	size_t size()const{ return n; }
protected: 
	int prot_mem ;
	size_t n;
private:
	char priv_mem(){ cout << "Base priv_mem()" << endl; return 'c'; }
};
struct Pub_Derv :public Base
{
	//��ȷ:�������ܷ���protected��Ա
	int f(){ return prot_mem ; }
	//���� private��Ա������������˵�ǲ��ɷ��ʵ�
	//char g(){ return priv_mem(); }

};
struct Prot_Dery :protected Base
{
	int t(){ return prot_mem ; }
	friend int t1(Prot_Dery &);

};
int t1(Prot_Dery &d)
{
	
	int tem = d.prot_mem ;
	return tem;
}
struct Priv_Derv :private Base
{
	//private ��Ӱ��������ķ���Ȩ��
	int f1() { return prot_mem ; }
};
struct  Derived_from_Public :public Pub_Derv
{
	//��ȷ��Base::prot_mem��Pub_Derv����Ȼ��Protected��
	int use_base(){ return prot_mem ; }
};
struct Derived_from_Private :public Priv_Derv
{
	//����Base::prot_mem��Priv_Derv����private��
	/*int use_base(){ return prot_mem(); }*/
};
class Sneaky :public Base
{
	friend void clobber(Sneaky&);
	friend void clobber(Base&);
	int j;
};
void clobber(Sneaky &s)
{
	s.j = s.prot_mem = 0;
}

void clobber(Base &b)
{
	//b.prot_mem = 0;
}


class Pal
{
public:
	int f(Base b){ return b.prot_mem; }
	 //int f2(Sneaky s){ return s.; }//����:Pal����Sneaky����Ԫ
	//�Ի���ķ���Ȩ���ɻ��౾����� ��ʹ����������Ļ��ಿ��Ҳ�����
	int f3(Sneaky s){ return s.prot_mem; }//��ȷ:Pal��Base����Ԫ
};
class D2 :public Pal
{
public:
	 //int mem(Base b){return b}
};
class Derived :private Base
{
public:
	using Base::size;
protected:
	using Base::n;
};
int main(int argc, char **argv)
{
	 
 	 
	system("pause");
	return 0;
}
