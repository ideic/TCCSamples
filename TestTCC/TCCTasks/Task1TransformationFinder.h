#pragma once
#include <string>
#include <vector>
namespace Task1
{
	enum ControlEnum {
		AppendToEnd,
		Reverse
	};
	class Task1TransformationFinder
	{
	public:
		Task1TransformationFinder();
		~Task1TransformationFinder();
		std::string canObtain(std::string &initial, const std::string &target);
	private:
		const std::string possible = "Possible";
		const std::string impossible = "Impossible";
		bool canObtain(std::string &initial, const std::string &target, ControlEnum nextOperation);
		bool bruteForce(std::string initial, const std::string &target, std::vector<bool> operationDescriptor);
		inline bool Validate(std::string &initial, const std::string &target);
	};

}