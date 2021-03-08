//
// Created by kyleeichlin on 3/3/21.
//

#include "NetworkState.h"
Variant NetworkState::state_to_array(NetworkState::State state) {
	Variant array[3] = {state.data, state.booleans, state.system_time};

	return array;
}
NetworkState::State NetworkState::array_to_state(Array state_array) {
	NetworkState::State state = NetworkState::State();
	state.data = state_array[0];
	state.booleans = state_array[1];
	state.system_time = state_array[2];

	return state;
}
NetworkState::NetworkState() {
}
