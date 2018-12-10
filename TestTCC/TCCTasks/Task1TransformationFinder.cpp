#include "stdafx.h"
#include "Task1TransformationFinder.h"
#include <vector>
#include <algorithm>
#include "OperationVariator.h"

namespace Task1
{
	Task1TransformationFinder::Task1TransformationFinder()
	{
	}


	Task1TransformationFinder::~Task1TransformationFinder()
	{
	}

	inline bool Task1TransformationFinder::Validate(std::string &initial, const std::string &target) {
		if (initial.size() < 1 || initial.size() > 999) return false;
		if (target.size() < 2 || target.size() > 1000) return false;
		if (initial.size() > target.size()) return false;

		return true;
	}

	bool Task1TransformationFinder::canObtain(std::string &initial, const std::string &target, ControlEnum nextOperation)
	{
		if (!Validate(initial, target)) return false;

		if (initial == target) return true;

		if (nextOperation == ControlEnum::AppendToEnd) {
			initial += "A";
		}
		else {
			std::reverse(begin(initial), end(initial));
			initial += "B";
		}
		return initial == target;
	}

	bool Task1TransformationFinder::bruteForce(std::string initial, const std::string & target, std::vector<bool> operationDescriptor)
	{
		for (auto operation : operationDescriptor) {
			auto result = canObtain(initial, target, operation ? ControlEnum::AppendToEnd : ControlEnum::Reverse);

			if (result) return true;

		}

		return false;
	}

	std::string Task1TransformationFinder::canObtain(std::string &initial, const std::string &target)
	{
		if (!Validate(initial, target)) return impossible;

		std::vector<bool> operationDescriptor(target.size() - initial.size());
		OperationVariator operationVariator;

		size_t lastA = target.find_last_of("A");
		size_t lastB = target.find_last_of("B");

		// If target end with A we know the last transformation is  ControlEnum::AppendToEnd
		if (lastB < lastA) {
			for (size_t idx = lastB - initial.size() + 1; idx < operationDescriptor.size(); idx++) {
				operationDescriptor[idx] = true; //true means ControlEnum::AppendToEnd
			}
		}

		//bruteforce goes through an operation description(instruction), what kind of action should be tried
		//operationVariator.NextVariation creates an new operationDecription
		auto result = false;
		do {
			result = Task1TransformationFinder::bruteForce(initial, target, operationDescriptor);
			if (result) return possible;


		} while (!result && operationVariator.NextVariation(operationDescriptor));

		return impossible;
	}
}