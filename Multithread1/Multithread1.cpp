#include <windows.h>
#include <iostream>
using namespace std;

struct Data
{
	int res, sz;
	int* M;
};

void thread(void* A) //Finds smalest int in array
{
	Data* n = (Data*)A;
	n->res = n->M[0];
	for (int i = 0; i < n->sz; i++)
	{
		Sleep(100);
		if (n->M[i] < n->res)
		{
			n->res = n->M[i];
		}
	}

	A = (void*)n;
}

int main()
{
	HANDLE	Hthread;
	DWORD	IDthread;
	srand(time(0));
	setlocale(LC_ALL, "rus");

	int sz, res = INT32_MIN;
	cout << "Размер массива:" << endl;
	cin >> sz;

	if (sz < 1) {
		cout << "Invalid size";
		return -1;
	}

	int* a = new int[sz];

	for (int i = 0; i < sz; i++)
	{
		cin >> a[i];
		//cout << a[i] << " ";
	}

	Data* data = new Data{ res, sz, a };

	Hthread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread, (void*)data, 0, &IDthread);
	if (Hthread == NULL) {
		cout << "Error in thread creation!";
		return GetLastError();
	}
	WaitForSingleObject(Hthread, INFINITE);
	
	CloseHandle(Hthread);
	cout << "Наименьшее число:" << data->res;
	
	delete[] a;
	delete data;
	return 0;
}
