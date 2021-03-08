//
// Created by kyleeichlin on 3/3/21.
//

#include "register_types.h"
#include "NetworkSync.h"
#include "NetworkState.h"
#include <core/object/class_db.h>

void register_network_sync_types() {
	ClassDB::register_class<NetworkSync>();
	ClassDB::register_class<NetworkState>();
}

void unregister_network_sync_types() {}