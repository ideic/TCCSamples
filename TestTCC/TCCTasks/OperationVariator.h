#pragma once
#include <vector>

namespace Task1
{
	class OperationVariator
	{
	public:
		OperationVariator();
		~OperationVariator();

		bool NextVariation(std::vector<bool> &operationDescriptor);
	};
}
