//
// Created by kyleeichlin on 3/3/21.
//

#ifndef GODOT_NETWORKSTATE_H
#define GODOT_NETWORKSTATE_H

#include <core/object/reference.h>
class NetworkState : public Reference {
public:
	struct State {
		Array data;
		int booleans;
		int system_time;
	};

	static Variant state_to_array(State state);
	static State array_to_state(Array state_array);

	NetworkState();
};

#endif //GODOT_NETWORKSTATE_H
