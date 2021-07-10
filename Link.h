#pragma once
#include"Transaction.h"

class Link
{
	friend class List;

private:
	Transaction* X;
	Link* Next;

public:
	Link(Transaction *px);

};

