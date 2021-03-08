//
// Created by kyleeichlin on 3/3/21.
//

#include "NetworkSync.h"

void NetworkSync::_notification(int p_what) {
	switch (p_what) {
		case NOTIFICATION_READY: {
			if (Engine::get_singleton()->is_editor_hint()) {
				break;
			}

			set_physics_process_internal(true);
		} break;
		case NOTIFICATION_INTERNAL_PHYSICS_PROCESS: {
			if (syncing) {
				sync();
			}
		} break;
	}
}

void NetworkSync::sync() {
	NetworkState::State state = NetworkState::State();
	state.system_time = 10;
	state.booleans = 1;

	NetworkSync::rpc_unreliable("receive_state", NetworkState::state_to_array(state));
}

void NetworkSync::_bind_methods() {}

void NetworkSync::send_state(Array state) {
}

void NetworkSync::receive_state(Array state) {
	print_line("Received State!");
	for(int i = 0; i < state.size(); i++) {
		print_line(state[i]);
	}
}

NetworkSync::NetworkSync() {
	set_physics_process_internal(is_physics_processing_internal());
}