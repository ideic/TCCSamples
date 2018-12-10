#include "stdafx.h"
#include "OperationVariator.h"
namespace Task1
{ 
	OperationVariator::OperationVariator()
	{
	}


	OperationVariator::~OperationVariator()
	{
	}

	//Simple incrementor on binary way, 00,01,10,11
	bool OperationVariator::NextVariation(std::vector<bool>& operationDescriptor)
	{
		size_t i = 0;
		while (i < operationDescriptor.size()) {
			if (operationDescriptor[i]) {
				operationDescriptor[i] = false;
			}
			else {
				operationDescriptor[i] = true;
				return true;
			}
			i++;
		}

		return false;
	}
}