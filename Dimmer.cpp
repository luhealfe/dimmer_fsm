#include "Dimmer.h"
#include "DimmerStateMachine.h"

namespace dimmer {

Dimmer::Dimmer() {
	auto state_machine_wrapper = DimmerStateMachineWrapper{*this};
	state_machine_ = std::make_shared<sm_t>(state_machine_wrapper);
}

void Dimmer::SetBrightness(int value) {
	brightness_ = value;
}

int Dimmer::GetBrightness() {
	return brightness_;
}

void Dimmer::ChangeBrightness() {
	if(state_machine_->is("Off"_s)) {
		return;
	}

	if(brightness_ > MIN_BRIGHTNESS) {
		brightness_--;
	} else {
		brightness_ = MAX_BRIGHTNESS;
	}
}

void Dimmer::Switch() {
	state_machine_->process_event(ev_switch{});
}

}