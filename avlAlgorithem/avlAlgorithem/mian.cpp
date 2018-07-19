#pragma once
#include "stdafx.h"
#include "avlDS.h"
#include <vector>
#include <iostream>





int main()
{
	std::vector<int>  arrs = { 4, 6, 33, 73, 99, 56, 77, 66, 88, 112, 44, 66, 29 };
	BTnode*   root = nullptr;
	for (auto ptr = arrs.begin(); ptr != arrs.end(); ptr++)
	{
		InsertNode(root, *ptr);
	}	
	midTraval(root);

	if (isBalance(root))
	{
		std::cout << "test";
	}
	

	return 0;
}