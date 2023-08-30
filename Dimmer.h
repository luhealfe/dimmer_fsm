// #pragma once
#ifndef DIMMER_H
#define DIMMER_H

#include "thirdy_party/boost/sml.hpp"
#include <memory>
// #include <queue>
// #include "DimmerStateMachine.h"

#define MIN_BRIGHTNESS 1
#define MAX_BRIGHTNESS 10

namespace dimmer {
using namespace boost::sml;

class DimmerStateMachine;
class DimmerStateMachineWrapper;

class Dimmer {
  public:
    explicit Dimmer();

    ~Dimmer() = default;

    void Switch();

    void SetBrightness(int value);

    int GetBrightness();

    void ChangeBrightness();
  private:
    using sm_t = sm<DimmerStateMachine, logger<DimmerStateMachineWrapper>>;
    // sm_t * state_machine_;
    std::shared_ptr<sm_t> state_machine_;
    int brightness_ = 0;
};
}
#endif