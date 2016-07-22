#include <iostream>
#include <sstream>
#include "Queue.h"

class Test3{
	
	public: 	
		Test3(std::ostream& os);
	
		/**
		*  @post All test are attempted, though some could segfault.
		*/
		void testQueue();
		
	private:
		bool test1();
		bool test2();
		bool test3();
		bool test4();
		bool test5();
		bool test6();
		bool test7();
		bool test8();
		
		std::ostream& os;
		std::stringstream ss_redirect;
		std::streambuf* os_rdbuf;

		inline void redirectOS();
		inline void restoreOS();
};
