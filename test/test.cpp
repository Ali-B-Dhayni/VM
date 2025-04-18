#include <iostream>
#include <cstdlib>
#include <cstdint>


//implement and test
void 
func(void) 
{
	static int x = 0;
	++x;
	std::cout << x << std::endl;
}

int 
main()
{
	return 0;
}
