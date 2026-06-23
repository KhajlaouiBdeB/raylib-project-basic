#pragma once
#include "Node.h"

namespace BehaviourTree
{
	class BehaviourTree
	{
	public:
		BehaviourTree() = default;
		~BehaviourTree();

		NodeState tick() const
		{
			if (_rootNode)
				return _rootNode->tick();

			return NodeState::FAILURE;
		}

	private:
		Node* _rootNode = nullptr;

	};
}


