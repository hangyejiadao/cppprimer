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
	//Basketʹ�úϳɵ�Ĭ�Ϲ��캯���Ϳ������Ƴ�Ա
	void add_item(const std::shared_ptr<Quote>&sale) {}
	//��ӡÿ������ܼۺ͹���������������ܼ�
	double total_receipt(ostream&)const;
private:
	//�ú������ڱȽ�shared_ptr,multiset��Ա���õ���
	static bool compare(const shared_ptr<Quote>&lhs, const shared_ptr<Quote>&rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	multiset<shared_ptr<Quote>, decltype(compare)*>items{ compare };
};

