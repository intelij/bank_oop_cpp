#pragma once
#include "Link.h"

class List
{
private:
	Link* head;
public:
	List();
	~List();
    int add(Transaction* x);
	void top10transections();
	void display();
	void remove();
	void clear();
	void saveTransactions(string filename);
	void linearSearch(date searchElement);
	void loadTransactions(string filename);
};

