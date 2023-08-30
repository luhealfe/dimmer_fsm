#include "Dimmer.h"
#include <iostream>

using namespace std;
using namespace dimmer;

int main() {
  Dimmer d = Dimmer();
	cout << "Brightness=" << d.GetBrightness() << endl;
  
  d.Switch();
	cout << "Brightness=" << d.GetBrightness() << endl;

	for(int i = 0; i < 5; i++) {
  	d.ChangeBrightness();
	}
	cout << "Brightness=" << d.GetBrightness() << endl;

  d.Switch();
	cout << "Brightness=" << d.GetBrightness() << endl;

	return 0;
}