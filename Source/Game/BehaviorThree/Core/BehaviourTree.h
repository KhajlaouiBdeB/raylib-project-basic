#pragma once
#include <raylib.h>

#include "Node.h"

namespace BehaviourTree
{
	class BehaviourTree
	{
	public:
		BehaviourTree() = default;
		~BehaviourTree() = default;

		NodeState tick() const
		{
			TraceLog(LOG_DEBUG, "BehaviourTree tick");
			if (_rootNode)
				return _rootNode->tick();

			return NodeState::FAILURE;
		}

	private:
		Node* _rootNode = nullptr;

	};
}


