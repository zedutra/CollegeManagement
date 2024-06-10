#include <exception>
#include <memory>
#include <string>

#include "../include/controller/Controller.h"
#include "../include/system/SysInfo.h"
#include "../include/utils/Utils.h"

using namespace std;

unique_ptr<Controller> ptr_Controller;

void welcome(void);
void bye(void);

int main() {
	welcome();
	try {
		ptr_Controller = make_unique<Controller>();
		ptr_Controller->start();
	} catch (const exception &myException) {
		Utils::printMessage("Unexpected problem. Program aborted. "+ string(myException.what()));
		exit(1);
	}

	bye();
	return 0;
}

void welcome() {
	Utils::printMessage(SysInfo::getFullVersion());
	Utils::printMessage("Running now...");
}

void bye() {
	Utils::printMessage("Finished");
}
