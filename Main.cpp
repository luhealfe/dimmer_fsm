#include "Dimmer.h"
#include <iostream>
// namespace{
using namespace std;
using namespace dimmer;

// class Dimmer;

int main() {
  Dimmer d = Dimmer();
  
  d.Switch();

	for(int i = 0; i < 5; i++) {
  	d.ChangeBrightness();
	}

	cout << "Brightness=" << d.GetBrightness() << endl;

	return 0;
}
// }