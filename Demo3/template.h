#pragma once
#ifndef TEMPLATE_H
#define TEMPLATE_H
template<typename T>int compare(const T&v1,const T&v2)
{
	if (v1>v2)
	{
		return 1;
	}
	else { return -1; }
	return 0;
} 
#endif