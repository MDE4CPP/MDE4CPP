
#include <iostream>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "copyTest/copyTestFactory.hpp"
#include "copyTest/copyTestPackage.hpp"

#include "copyTest/Base.hpp"
#include "copyTest/Sub1.hpp"
#include "copyTest/Sub2.hpp"
#include "copyTest/Merge.hpp"

#include "copyTest/impl/MergeImpl.hpp"
#ifdef _WIN32
	#include "windows.h"
#endif

// Start of user code includes 
// You may manually edit additional includes, won't be overwritten upon generation.

// End of user code

using namespace copyTest;

// Start of user code functions 
// You may manually edit additional functions, won't be overwritten upon generation.

// End of user code

int main ()
{
	//Create Model Factory
	std::shared_ptr<copyTestFactory> factory = copyTestFactory::eInstance();


	std::cout << "init _____" << std::endl;
	std::shared_ptr<Merge> m1 = factory->createMerge();
	std::shared_ptr<Merge> m2 = factory->createMerge();
	std::shared_ptr<Merge> e1 = factory->createMerge();
	std::shared_ptr<Merge> e2 = factory->createMerge();

	m1->init(1);
	m2->init(2);
	e1->init(3);
	e2->init(4);

	std::cout << "m1:" <<m1->toString();
	std::cout << "m2:" <<m2->toString();
	std::cout << "e1:" <<e1->toString();
	std::cout << "e2:" <<e2->toString();

	std::cout << "copy _____" << std::endl;
	std::shared_ptr<Merge> m3(new MergeImpl(*(std::dynamic_pointer_cast<MergeImpl>(m1))));
	std::shared_ptr<Merge> m4(std::dynamic_pointer_cast<Merge>(m2->copy()));
	std::shared_ptr<Sub1> s1(std::dynamic_pointer_cast<Sub1>(m2->copy()));
	std::shared_ptr<Sub2> s2(new Sub2Impl(*(std::dynamic_pointer_cast<Sub2Impl>(m2))));

	std::cout << "m3:" << m3->toString();
	std::cout << "m4:" << m4->toString();
	std::cout << "s1:" << s1->toString();
	std::cout << "s2:" << s2->toString() << std::endl;

	std::cout << "assignment using = operator _____" << std::endl;
	*e1=(*m1);
	std::shared_ptr<Sub2> e2Sub2Ptr=e2;
	*e2Sub2Ptr=(*s2);

	std::cout << "e1:" << e1->toString();
	std::cout << "Attention! partial =operator" << std::endl;
	std::cout << "e2:" << e2->toString();

	std::cout << "Test: " << std::endl;
#ifdef _WIN32
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE) { return GetLastError(); }
	DWORD dwMode = 0;
	if (!GetConsoleMode(hOut, &dwMode)) { return GetLastError(); }
	dwMode |=  0x0004; //ENABLE_VIRTUAL_TERMINAL_PROCESSING
	if (!SetConsoleMode(hOut, dwMode)) { return GetLastError(); }
#endif
	std::string testResult1="b:1,s1:1,b:1,s2:1,m:1\n";
	std::string testResult2="b:2,s1:2,b:2,s2:2,m:2\n";
	std::string testResult3="b:2,s2:2,";
	std::string testResult4="b:2,s1:4,b:2,s2:2,m:4\n";
	if(
		  (m3->toString() == testResult1)
		&&(m4->toString() == testResult2)
		&&(s1->toString() == testResult2)
		&&(s2->toString() == testResult3)
		&&(e1->toString() == testResult1)
		&&(e2->toString() == testResult4)
	)
	{
		std::cout << "\033[92m" << "success" << "\033[0m" << std::endl;
	}
	else
	{
		std::cout << "\033[91m" << "failure!" << "\033[0m" << std::endl;
		std::cout << "Result should be:"<< std::endl;
		std::cout << "m3:" << testResult1;
		std::cout << "m4:" << testResult2;
		std::cout << "s1:" << testResult2;
		std::cout << "s2:" << testResult3<< std::endl;
		std::cout << "e1:" << testResult1;
		std::cout << "e2:" << testResult4;
		return -1;
	}

// Start of user code main
// You may manually edit the following lines, won't be overwritten upon generation.

// End of user code

    return 0;

}
