#ifndef QUOTE_H
#define QUOTE_H
#include<memory>
#include<iostream>
#include<string>
#include<cstddef> 
using namespace std;
class Quote
{
	friend istream operator>>(istream&, Quote&);
	friend ostream operator<<(ostream&, const Quote&);
public:
	Quote() :price(0.0){};
	Quote(const std::string&book, double sales_price) :bookNo(book), price(sales_price){};
	virtual ~Quote(){}
	string isbn()const{ return bookNo; }
	virtual double net_price(std::size_t n)const { cout << "Quote::net_price" << endl; return n * price; }
	virtual Quote*clone()const{ return new Quote(*this); }
private:
	string bookNo;
protected:
	double price;
};
class Disc_quote :public Quote
{
public:
	//other members as before
	Disc_quote() :quantity(0), discount(0.0){}
	Disc_quote(const  string& book, double price, size_t qty, double disc) :
		Quote(book, price), quantity(qty), discount(disc){}
	double net_price(size_t)const = 0;
	pair<size_t, double> discount_policy()const
	{
		return make_pair(quantity, discount);
	}
protected:
	size_t quantity;
	double discount;//
};

//double Disc_quote::net_price(size_t t)const
//{
//	return 0;
//}
class Bulk_quote :public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const string&book, double p, size_t qty, double disc) :Disc_quote(book, p, qty, disc){}
	
	double net_price(std::size_t)const override;
	Bulk_quote*clone()const{ return new Bulk_quote(*this); }

};

class Lim_quote :public Disc_quote
{
public:
	Lim_quote(const string&book = "",double sales_price=0.0,size_t qty=0,double disc_rate=0.0):
		Disc_quote(book, sales_price, qty, disc_rate){}

	double net_price(size_t)const;
	Lim_quote*clone()const{ return new Lim_quote(*this); }
};
double print_total(std::ostream &, const Quote&, size_t);
#endif