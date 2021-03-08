//
// Created by kyleeichlin on 3/3/21.
//

#ifndef GODOT_NETWORKSYNC_H
#define GODOT_NETWORKSYNC_H

#include <scene/main/node.h>
#include "NetworkState.h"

class NetworkSync : public Node {
	GDCLASS(NetworkSync, Node);

	bool syncing = true;

	enum SyncTypes {
		AUTOMATIC_INTERPOLATION,
		SETTER,
		CUSTOM_INTERPOLATION,
		CUSTOM_SETTER,
	};

protected:
	void sync();

	void _notification(int p_what);
	static void _bind_methods();

private:
	struct SyncedVariable {
		String var_name;
		int sync_type;
	};

	void send_state(Array state);
	void receive_state(Array state);

	NetworkSync();
};

#endif //GODOT_NETWORKSYNC_H
