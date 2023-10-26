#include <iostream>
#include <exception>
#include <set>
#include <map>
using namespace std;

#define tab "\t"

//#define STL_SET

void main() 
{
	setlocale(LC_ALL, "");
#if 0
	try {
		throw std::exception("throwing exception from main()");
		int a, b;
		cout << "¬ведите два числа: "; cin >> a >> b;
		cout << a / b << endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << endl;
	}
	catch (...) {
		//универсальный обработчик, который выполн€етс€, если не подошел ни  один другой обработчик.
		//универсальный обработчик не распознает типы исключени€.
		std::cerr << "Error: что-то пошло не так :(" << endl;
	}
#endif // 0

#ifdef STL_SET
	std::multiset<int> set = { 50,25,75,16,32,64,80 };
	for (std::set<int>::iterator it = set.begin(); it != set.end(); ++it) {
		cout << *it << endl;
	}
	cout << endl;
#endif // STL_SET

	std::map<int, std::string> week = {
		std::pair<int, std::string>(0,"Sunday"),
		std::pair<int, std::string>(1,"Monday"),
		std::pair<int, std::string>(2,"Tuesday"),
		{3, "Wednesday"},
		{4, "Thursday"},
		{5, "Friday"},
		{5, "Friday"},
		{5, "Friday"},
		{5, "Friday"},
		{6, "Sturday"},
		{6, "Sturday"},
		{6, "Sturday"},
		std::pair<int, std::string>(7,"Sunday"),
		{6, "Sturday"}
	};

	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it) {
		cout << it->first << tab << it->second << endl;
	}

}