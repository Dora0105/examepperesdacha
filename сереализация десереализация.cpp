// сереализация десереализация.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using namespace std;
template<class T>
class A
{
private:
	int size;
	T* array = nullptr;
public:
	A(int size1, T* array1) :size(size1)
	{
		array = new T[size1];
		for (int i = 0; i < size; i++) { array[i] = array1[i]; }
	}
	void write(const char* name)
	{
		ofstream fout(name);
		fout << "<array numElem='" << size << "'>" << endl;
		for (int i = 0; i < size; i++)
		{
			fout << "<item>" << array[i] << "</item>" << endl;
		}
		fout.close();
	}
	~A()
	{
		delete[] array;
	}
};

int main()
{
	int arr[3];
	arr[0] = 1; arr[1] = 2; arr[2] = 3;
	A<int> example(3, arr);
	example.write("hello.txt");
}