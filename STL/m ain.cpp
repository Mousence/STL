#include <iostream>
#include <array>
#include <vector>
using namespace std;

#define tab "\t"

template<typename T>void vector_properties(const std::vector<T>& vec);
template<typename T>void vector_insert(std::vector<T>& vec, int index, T value);
template<typename T>void vector_erase(std::vector<T>& vec, int index);

//#define STL_ARRAY
#define STL_VECTOR
//define STL_DEQUE

int main() 
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	//array - это контейнер, который хранит данные в виде статического массива.
	const int N = 5;
	std::array<int, N> arr = { 3,5,8 };
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << tab;
	}
	cout << endl;
#endif //STL_ARRAY

#ifdef STL_VECTOR
	//vector - это контейнер, который хранит данные в ввиде динамического массива
	std::vector<double> vec = { 0,1,2,3,5,8,13,21,34 };
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << tab;
	}
	cout << endl;
	vector_properties(vec);


	int index;
	double data;
	cout << "Index - "; cin >> index;
	cout << "Data - "; cin >> data;
	//vec.insert(vec.begin() + index, data);
	vector_insert(vec, index, data);
	try {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec.at(i) << tab;
			//cout << vec[i] << tab;
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}
	vector_properties(vec);

	cout << "Index - "; cin >> index;
	//vec.insert(vec.begin() + index, data);
	vector_erase(vec, index);
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << tab;
		}
	vector_properties(vec);


#endif //STL_VECTOR

#ifdef STL_DEQUE
#endif // STL_DEQUE


}

template<typename T>void vector_properties(const std::vector<T>& vec) {
	cout << "Size:\t" << vec.size() << endl;
	cout << "Capacity:\t" << vec.capacity() << endl;
	cout << "Max size:\t" << vec.max_size() << endl;
}

template<typename T>void vector_insert(std::vector<T>& vec, int index, T value) {
    if (index >= 0 && index <= vec.size())
        vec.insert(vec.begin() + index, value);
	else
		return;
	vec.pop_back();
}
template<typename T>void vector_erase(std::vector<T>& vec, int index) {
	if (index >= 0 && index <= vec.size())
		vec.erase(vec.begin() + index);
	else
		return;
}
