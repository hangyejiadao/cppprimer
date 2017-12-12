#include "Basket.h"
 double Basket::total_receipt(ostream &os)const
 {
	 double sum = 0.0;
	 //iter指向isbn相同的一批元素中的第一个
	 //upper_bound返回一个迭代器 该迭代器指向这批元素的尾后位置
	 for (auto iter = items.cbegin(); iter !=items.cend(); iter=items.upper_bound(*iter))
	 {
		 sum += print_total(os, **iter, items.count(*iter));
	 }
	 os << "Total Sale: " << sum << endl;//打印最终的总价格
	 return sum;
 }