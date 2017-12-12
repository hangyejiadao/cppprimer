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
	//正确:派生类能访问protected成员
	int f(){ return prot_mem ; }
	//错误 private成员对于派生类来说是不可访问的
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
	//private 不影响派生类的访问权限
	int f1() { return prot_mem ; }
};
struct  Derived_from_Public :public Pub_Derv
{
	//正确：Base::prot_mem在Pub_Derv中仍然是Protected的
	int use_base(){ return prot_mem ; }
};
struct Derived_from_Private :public Priv_Derv
{
	//错误Base::prot_mem在Priv_Derv中是private的
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
	 //int f2(Sneaky s){ return s.; }//错误:Pal不是Sneaky的友元
	//对基类的访问权限由基类本身控制 即使对于派生类的基类部分也是如此
	int f3(Sneaky s){ return s.prot_mem; }//正确:Pal是Base的友元
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
