#include "Test3.h"
using namespace std;

Test3::Test3(std::ostream& os) : os(os)
{
}

void Test3::redirectOS()
{
	os_rdbuf = os.rdbuf(ss_redirect.rdbuf());
}

void Test3::restoreOS()
{
	os.rdbuf(os_rdbuf);
}


void Test3::testQueue(){
	//Test call rewritten in this format to prevent short circuiting
	bool result = test1();
	result = test2() && result;
	result = test3() && result;
	result = test4() && result;
	result = test5() && result;
	result = test6() && result;
	result = test7() && result;
	result = test8() && result;

	if(result){
		std::cerr << "RESULT: COMPLETE\n";
	}
	else{
		std::cerr << "RESULT: INCOMPLETE\n";
	}
}

bool Test3::test1()
{
	Queue<std::string> queue;		
	//Test Case 1:  check for empty print
	std::cerr << "Test 1: print on empty Queue: ";
	
    	redirectOS();
	ss_redirect.clear();
	queue.print();
	restoreOS();

	std::cerr << "PASS\n";
	//Would segfault is anything was dereferenced
	return(true);	
}

bool Test3::test2()
{
	Queue<int> q;
	bool test3Result = true;
	int num=0;


	std::cerr << "Test 2: print of populated queue: ";
	//populate queue
	q.enqueue(0);	
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	redirectOS();
	ss_redirect.clear();
	q.print();
	restoreOS();
	
	for(int i = 0; i <= 3; ++i){
		ss_redirect >> num;
		if( num != i)
			test3Result = false;
	}

	if(test3Result)
		std::cerr << "PASS\n";
	else
		std::cerr << "FAILED\n";

	return(test3Result);
}

bool Test3::test3()
{
	Queue<std::string> queue;
	
	try
	{
		std::cerr << "Test 3: dequeue on empty queue: ";
		queue.dequeue();
	}
	catch(std::runtime_error rte)
	{
		std::cerr << "PASS\n";
		return (true);

	}
	//if any other kind of exception is thrown, test failed
	catch(...)
	{
		std::cerr << "FAILED\n";
		return (false);

	}

	return(false);
}

bool Test3::test4()
{
	Queue<int> q;
	bool test3Result = true;
	int num=0;


	std::cerr << "Test 4: dequeue on queue of size 1: ";

	//populate queue
	q.enqueue(99); //will be dequeue
	q.dequeue();
	q.enqueue(88);
	q.dequeue();

	if(q.size() == 0)
	{
		std::cerr << "PASS\n";
		return(true);
	}
	else
	{
		std::cerr << "FAILED\n";
		return(false);
	}

	
}

bool Test3::test5()
{
	Queue<int> q;
	bool test3Result = true;
	int num=0;


	std::cerr << "Test 5: dequeue on populated queue: ";
	//populate queue
	q.enqueue(99); //will be dequeue
	q.enqueue(88); //will be dequeue
	q.enqueue(0);	
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	q.dequeue();
	q.dequeue();

	redirectOS();
	ss_redirect.clear();
	q.print();
	restoreOS();
	
	for(int i = 0; i <= 3; ++i){
		ss_redirect >> num;
		if( num != i)
			test3Result = false;
	}

	if(test3Result && q.size() == 4)
	{
		std::cerr << "PASS\n";
		return(true);
	}	
	else
	{
		std::cerr << "FAILED\n";
		return(false);
	}
}


bool Test3::test6()
{
	Queue<std::string> queue;
	
	try
	{
		std::cerr << "Test 6: \"back of the line\" on empty queue: ";
		queue.dequeue();
	}
	catch(std::runtime_error rte)
	{
		std::cerr << "PASS\n";
		return (true);

	}
	//if any other kind of exception is thrown, test failed
	catch(...)
	{
		std::cerr << "FAILED\n";
		return (false);

	}
}

bool Test3::test7()
{
	Queue<int> q;
	bool test3Result = true;
	int num=0;

	std::cerr << "Test 7: \"back of the line\" on queue of size 1: ";
	//populate queue
	q.enqueue(0);
	q.backOfTheLine();
	
	redirectOS();
	ss_redirect.clear();
	q.print();
	restoreOS();
	
	for(int i = 0; i < 1; ++i){
		ss_redirect >> num;
		if( num != i)
			test3Result = false;
	}

	if(test3Result && q.size() == 1)
		std::cerr << "PASS\n";
	else
		std::cerr << "FAILED\n";

	return(test3Result);		
}


bool Test3::test8()
{
	Queue<int> q;
	bool test3Result = true;
	int num=0;

	std::cerr << "Test 8: \"back of the line\" on populated queue: ";
	//populate queue
	q.enqueue(3);	
	q.enqueue(0);
	q.enqueue(1);
	q.enqueue(2);
	q.backOfTheLine();
	
	redirectOS();
	ss_redirect.clear();
	q.print();
	restoreOS();
	
	for(int i = 0; i <= 3; ++i){
		ss_redirect >> num;
		if( num != i)
			test3Result = false;
	}

	if(test3Result)
		std::cerr << "PASS\n";
	else
		std::cerr << "FAILED\n";

	return(test3Result);		
}

/*
bool Test3::testQueue()
{
	Queue<std::string> queue;
	const int COUNT =8;
	

	//Test Case 2:  check for empty dequeue
	//queue.dequeue();

	//Test Case 3: Enqueue operation

		queue.enqueue("Rise");
		queue.enqueue("And");
		queue.enqueue("Rise");
		queue.enqueue("Again");
		queue.enqueue("Until");
		queue.enqueue("Lamb");
		queue.enqueue("Becomes");
		queue.enqueue("Lion!");

	//Test Case 4: Print the Queue
	queue.print();

	//Test Case 5: Size check
	if(COUNT == queue.size())
		std::err<<"Eight words added to the Q! Success"<<endl;
	else
		std::err<<"Size(Enqueue) Operation Failed"<<endl;


	//Test Case 6: Back of the line check
	queue.backOfTheLine();
	queue.backOfTheLine();
	std::err<<"\nTwo Back Of the Line Operations\n";
	queue.print();


	//Test Case 7 Dequeue check

	std::err<<"\n Attempting dequeue on \"Rise\"\n";
	std::string temp = queue.dequeue();
	std::err<<"Size of the queue is: "<<queue.size()<<endl;
	if(temp == "Rise")
		queue.print();

	std::err<<"\n Attempting dequeue on \"Again\"\n";
	temp = queue.dequeue();
	std::err<<"Size of the queue is: "<<queue.size()<<endl;

	if(temp == "Again")
		queue.print();
		
	
}
*/

