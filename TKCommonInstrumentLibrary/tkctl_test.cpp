#include <iostream>
#include <vector>
#include "tkctl.h"

int main()
{
	std::cout << "" << std::endl;

	std::vector<TKCTL> tkctl;
	tkctl.push_back(TKCTL::TKCTL());

	tkctl[0][3].GetModule();
	//tkctl[0].stream();

	return 0;
}
