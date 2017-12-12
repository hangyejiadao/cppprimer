#pragma once
#include<algorithm>
#include<share.h>
#include <memory>
#include "Quote.h"
#include <set>
using namespace std;
class Basket
{
public:
	//Basket使用合成的默认构造函数和拷贝控制成员
	void add_item(const std::shared_ptr<Quote>&sale) {}
	//打印每本书的总价和购物篮中所有书的总价
	double total_receipt(ostream&)const;
private:
	//该函数用于比较shared_ptr,multiset成员会用到它
	static bool compare(const shared_ptr<Quote>&lhs, const shared_ptr<Quote>&rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	multiset<shared_ptr<Quote>, decltype(compare)*>items{ compare };
};

