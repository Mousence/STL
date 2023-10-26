#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <ostream>
#include <time.h>
#include <ctime>
#include <vector>
#include <list>
#include <map>
using namespace std;

using std::cout;

#define tab "\t"
#define delimiter "/n----------------------------------------------------------/n"
const std::map<int, std::string> VIOLATIONS =
{
	{0, "Не определено"},
	{1, "Превышение скорости"},
	{2, "Парковка в неположенном месте"},
	{3, "Проезд на красный"},
	{4, "Езда в нетрезвом состоянии"},
	{5, "Оскорбление офицера"},
	{6, "Неподчинение приказам офицера"},
	{7, "Пересечение сплошной"},
	{8, "Оставление места ДТП"},
	{9, "Ремень безопасности"}
};

class Crime
{
	int id;            //Номер статьи
	std::string place;
	time_t time;       //Время нарушения

protected:
	int size = 0;
public:
	int get_id()const {
		return id;
	}
	const std::string get_violation()const {
		return VIOLATIONS.at(id);
	}
	std::string get_place()const {
		return place;
	}
	const char* get_time()const {
		return ctime(&time);
	}
	time_t get_timestamp() const {
		return time;
	}

	void set_id(int id) {
		if (id >= VIOLATIONS.size())id = 0;
		this->id = id;
	}
	void set_place(std::string place) {
		this->place = place;
	}
	void set_time(const char time_str[]) {
		const int SIZE = 20;
		char time_str_buffer[SIZE] = {};
		strcpy(time_str_buffer, time_str);
		//HH:MM DD/MM/YYYY
		//HH:MM DD/MM/YYYY
		//YYYY/MM/DD HH:MM
		int units[5] = {};
		char* sz_units[5] = {};
		const char delimiters[] = ":./ ";
		int n = 0;
		for (char* pch = strtok(time_str_buffer, delimiters); pch; pch = strtok(NULL, delimiters))
			units[n++] = std::atoi(pch);
		//for (int i : units)cout << i << tab; cout << endl;
		//for (char* i : sz_units)cout << i << tab; cout << endl;
		int colon_position = strchr(time_str, ':') - time_str;
		if (colon_position > 2) {
			std::reverse(units, units + 5);
			std::swap(units[0], units[1]);
		}
		//for (int i : units)cout << i << tab; cout << endl;

		std::tm tm{};
		tm.tm_hour=units[0];
		tm.tm_min=units[1];
		tm.tm_mday=units[2];
		tm.tm_mon=units[3] - 1;
		tm.tm_year=units[4] - 1900;
		this->time = std::mktime(&tm);
	}

	Crime() : id(0), place(""), time(0) {}
	Crime(int id, const std::string& place, const std::string& time) {
			set_id(id);
			set_place(place);
			set_time(time.c_str()); // из метода получить строку
	}
	~Crime() {}

};

void PrintCrimes(std::map<string, std::vector<Crime>> CrimeMap) {
	for (std::map<string, std::vector<Crime>>::iterator it = CrimeMap.begin(); it != CrimeMap.end(); ++it) {
		cout << it->first << tab << it->second << endl;
	}
}
void PrintIDCrimes(std::string ID, std::map<string, std::vector<Crime>> CrimeMap) {
	if (CrimeMap.find(ID) != CrimeMap.end()) {
		std::vector<Crime> crimes = CrimeMap[ID];
		std::cout << "Преступления " << ID << ": ";
		for (int i = 0; i < CrimeMap[ID].size(); i++) {
			cout << crimes[i] << endl;
		}
	}
	else {
		std::cout << "Преступление с номером " << ID << " не найдено." << std::endl;
	}
}
void Write(std::map<string, std::vector<Crime>> CrimeMap, std::string FileName) {
	std::ofstream fout;
	fout.open(FileName, std::ios_base::app);
	for (std::map<string, std::vector<Crime>>::iterator it = CrimeMap.begin(); it != CrimeMap.end(); ++it) {
		fout << it->first << tab << it->second << endl;
	}
	fout.close();
}
void Load(std::map<string, std::vector<Crime>> CrimeMap, std::string FileName) {

}

std::ostream& operator<<(std::ostream& os, const Crime& obj) {
	const int SIZE = 32;
	char crime_time[SIZE]{};
	strcpy(crime_time, obj.get_time());
	crime_time[strlen(crime_time) - 1] = 0;
	return os << obj.get_time() << ": " << obj.get_place() << ", " << obj.get_violation();
}
std::ostream& operator<<(std::ostream& os, const std::vector<Crime>& crimes) {
	for (const Crime& crime : crimes) {
		os << crime << std::endl;
	}
	return os;
}

void main()
{
	setlocale(LC_ALL, "");

	std::string ID = "54LSD44";

	std::vector<Crime> CrimeList = {};
	std::map<string, std::vector<Crime>> CrimeMap;

	Crime NewCrime(1, "ул. Ленина", "16:20 24/10/2023");
	CrimeList.push_back(NewCrime);
	CrimeMap[ID] = CrimeList;

	PrintIDCrimes(ID, CrimeMap);
}