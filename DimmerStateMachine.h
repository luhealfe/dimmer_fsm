// #pragma once
#ifndef DIMMERSM_H
#define DIMMERSM_H

// #include <boost/sml.hpp>
#include "thirdy_party/boost/sml.hpp"
#include "Dimmer.h"
#include <iostream>

namespace dimmer {
struct ev_switch {};

struct DimmerStateMachineWrapper {
  explicit DimmerStateMachineWrapper(Dimmer& dimmer) : dimmer_(dimmer) {}

  template <class SM, class TEvent>
  auto log_process_event(const TEvent&) -> void {}

  template <class SM, class TGuard, class TEvent>
  auto log_guard(const TGuard&, const TEvent&, bool result) -> void {}

  template <class SM, class TAction, class TEvent>
  auto log_action(const TAction&, const TEvent&) -> void {}

  template <class SM, class TSrcState, class TDstState>
  auto log_state_change(const TSrcState& src, const TDstState& dst) -> void {
    std::cout << "DimmerStateMachine: " << src.c_str() << " -> " << dst.c_str() << std::endl;
  }

  Dimmer& dimmer_;
};

class DimmerStateMachine {
  public:
    auto operator()() const {
    using namespace boost::sml;

    constexpr auto error = state<class error>;

    auto on_entry_action = [](DimmerStateMachineWrapper wrapper) {
      wrapper.dimmer_.SetBrightness(MAX_BRIGHTNESS);
    };

    auto off_entry_action = [](DimmerStateMachineWrapper wrapper) {
      wrapper.dimmer_.SetBrightness(0);
    };

    auto error_action = [](DimmerStateMachineWrapper wrapper) {};

    return make_transition_table(
        *"Off"_s + event<ev_switch> / on_entry_action = "On"_s,
        "On"_s + event<ev_switch> / off_entry_action = "Off"_s,

        // Orthogonal state machine to detected unexpected events
        *"error_handling"_s + unexpected_event<_> / error_action = error);
  }  
};
}
#endif