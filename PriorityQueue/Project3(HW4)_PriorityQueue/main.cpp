#include <iostream>
using namespace std;

//#include <time.h>
#include <string>
#include <sstream>

#include "Array.h"
#include "PriorityQueue.h"

//----------------------------------------------------------
//for detecting memory leaks:
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif 
//----------------------------------------------------------

void test()
{
	PriorityQueue<int> pq_int;
	for (int i = 0; i < 5; i++)
		pq_int.push(i);
	cout << "top = " << pq_int.top() << endl;
	cout << "int queue: " << endl;
	cout << pq_int;
	cout << endl;                                                                      //added
	cout << "and to make sure you didn't change the queue: " << endl;
	cout << pq_int;
	cout << endl;                                                                      //added
	//---------------------------------------------------------
	PriorityQueue<string> pq_str;
	pq_str.push("This");
	pq_str.push("is");
	pq_str.push("project");
	pq_str.push("3");
	cout << "top = " << pq_str.top() << endl;
	cout << "str queue: " << endl;
	cout << pq_str;
	cout << endl;                                                                      //added
	//---------------------------------------------------------
	Array<double> da1(5);
	for (int i = 0; i < 5; i++)
		da1[i] = i;
	Array<double> da2(2);
	for (int i = 0; i < 2; i++)
		da2[i] = i;
	PriorityQueue<Array<double>> pq_array;
	pq_array.push(da1);
	pq_array.push(da2);
	cout << "Array queue reversed: " << endl;
	print_reversed_queue(pq_array);
	cout << endl;                                                              //added
	//---------------------------------------------------------
	Array<PriorityQueue<int>> arr_pq_int;
	arr_pq_int[0] = pq_int;
	arr_pq_int[1] = pq_int;
	cout << "Array of priority queues of ints: " << endl;
	cout << arr_pq_int;
	cout << endl;                                                          //added
}

int main(void)
{
	test();
	//memory leak:
	cout << endl;
	cout << "leaks: " << _CrtDumpMemoryLeaks();

	return 0;
}