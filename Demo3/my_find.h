#pragma once
#ifndef MY_FIND_H  
#define MY_FIND_H 
template<typename U,typename T>bool my_find(const U& it1,const U& it2,const T& val)
{
	auto it3 = it1;//�������Ϊconst���������޸�,��Ҫһ����ʱ����!
	for (it3;it3!=it2; ++it3)
	{
		if (*it3==val)
		{
			return true;
		}
	}
	return false;
}
#endif MY_FIND_H