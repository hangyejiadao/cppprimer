#include "Basket.h"
 double Basket::total_receipt(ostream &os)const
 {
	 double sum = 0.0;
	 //iterָ��isbn��ͬ��һ��Ԫ���еĵ�һ��
	 //upper_bound����һ�������� �õ�����ָ������Ԫ�ص�β��λ��
	 for (auto iter = items.cbegin(); iter !=items.cend(); iter=items.upper_bound(*iter))
	 {
		 sum += print_total(os, **iter, items.count(*iter));
	 }
	 os << "Total Sale: " << sum << endl;//��ӡ���յ��ܼ۸�
	 return sum;
 }