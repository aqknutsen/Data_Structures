#include <iostream>
#include <sstream>
#include "DoubleLinkedList.h"

class Test
{
public:
	Test(std::ostream& os);
	void runTests();

private:
	std::ostream& os;
	std::stringstream ss_redirect;
	std::streambuf* os_rdbuf;

	inline void redirectOS();
	inline void restoreOS();

	bool test1();
	bool test2();
	bool test3();
	bool test4();
	bool test5();
	bool test6();
	bool test7();
};
