#include "Test.h"

void Test::runTests()
{
	//Test call rewritten in this format to prevent short circuiting
	bool result = test1();
	result = test2() && result;
	result = test3() && result;
	result = test4() && result;
	result = test5() && result;
	result = test6() && result;
	result = test7() && result;

	if(result){
		std::cout << "Result: ";
		std::cout << "COMPLETE" << std::endl;
	}
	else{
		std::cout << "Result: ";
		std::cout << "INCOMPLETE" << std::endl;
	}

}


Test::Test(std::ostream& os) : os(os)
{
}


void Test::redirectOS()
{
	os_rdbuf = os.rdbuf(ss_redirect.rdbuf());
}


void Test::restoreOS()
{
	os.rdbuf(os_rdbuf);
}


bool Test::test1()
{
	DoubleLinkedList<int> dll;

	std::cout << "Test 1: insertAhead on empty list : ";

	bool exceptResult = false;
	try{
		dll.insertAhead(1, 5);
	}
	catch(std::runtime_error& re){
		exceptResult = true;
	}
	catch(...){
		exceptResult = false;
	}

	if(exceptResult && (dll.size() == 0))
		std::cout << "PASS" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	return exceptResult && (dll.size() == 0);

}


bool Test::test2()
{
	DoubleLinkedList<int> dll;
	dll.pushFront(1);
	dll.pushFront(2);
	dll.pushFront(3);

	std::cout << "Test 2: insertAhead with empty list : ";

	bool exceptResult = false;
	try{
		dll.insertAhead(100, 100);
	}
	catch(std::runtime_error& re){
		exceptResult = true;
	}
	catch(...){
		exceptResult = false;
	}

	if(exceptResult && (dll.size() == 3))
		std::cout << "PASS" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	return exceptResult && (dll.size() == 3);
}


bool Test::test3()
{
	DoubleLinkedList<int> dll;
	dll.pushFront(1);
	dll.pushFront(2);
	dll.pushFront(3);

	std::cout << "Test 3: insertAhead of element not in list : ";

	bool exceptResult = false;
	try{
		dll.insertAhead(100, 100);
	}
	catch(std::runtime_error& re){
		exceptResult = true;
	}
	catch(...){
		exceptResult = false;
	}

	if(exceptResult && (dll.size() == 3))
		std::cout << "PASS" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	return exceptResult && (dll.size() == 3);
}


bool Test::test4()
{
	DoubleLinkedList<int> dll;
	dll.pushFront(3);
	dll.pushFront(2);
	dll.pushFront(1);



	std::cout << "Test 4: insertAhead of first element : ";

	bool exceptResult = true;
	try{
		dll.insertAhead(1, 0);
	}
	catch(...){
		exceptResult = false;
	}

	redirectOS();
	dll.printList();
	restoreOS();
	
	bool insertResult = true;
	for(int i = 0; i <= 3; ++i){
		int num;
		ss_redirect >> num;
		if( num != i)
			insertResult = false;
	}
	

	bool result = exceptResult && (dll.size() == 4) && insertResult;
	if(result)
		std::cout << "PASS" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	return result;
}


bool Test::test5()
{
	DoubleLinkedList<int> dll;
	dll.pushFront(3);
	dll.pushFront(2);
	dll.pushFront(0);

	std::cout << "Test 5: insertAhead of middle element : ";

	bool exceptResult = true;
	try{
		dll.insertAhead(2, 1);
	}
	catch(...){
		exceptResult = false;
	}

    	redirectOS();
	ss_redirect.clear();
	dll.printList();
	restoreOS();
	
	bool insertResult = true;
	for(int i = 0; i <= 3; ++i){
		int num;
		ss_redirect >> num;
		if( num != i)
			insertResult = false;
	}
	

	bool result = exceptResult && (dll.size() == 4) && insertResult;
	if(result)
		std::cout << "PASS" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	return result;

}


bool Test::test6()
{
	DoubleLinkedList<int> dll;

	std::cout << "Test 6: printReverse an empty list : ";

	// this test only tries to trigger a seg fault

   	redirectOS();
	ss_redirect.clear();
	dll.printReverse();
	restoreOS();

	std::cout << "PASS" << std::endl;

	return true;
}


bool Test::test7()
{
	DoubleLinkedList<int> dll;
	dll.pushFront(0);	
	dll.pushFront(1);
	dll.pushFront(2);
	dll.pushFront(3);

	std::cout << "Test 7: printReverse on populated list : ";

    redirectOS();
	ss_redirect.clear();
	dll.printReverse();
	restoreOS();

	bool printResult = true;
	for(int i = 0; i <= 3; ++i){
		int num;
		ss_redirect >> num;
		if( num != i)
			printResult = false;
	}

	if(printResult)
		std::cout << "PASS" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	return printResult;
}
