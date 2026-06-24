#pragma once
#include "CompositeNode.h"

namespace BehaviourTree
{
	class Sequence : public CompositeNode
	{
	public:
		Sequence() = default;
		~Sequence() override = default;

		NodeState tick() override
		{
			for (Node* child : _nodes)
			{
				NodeState state = child->tick();
				if (state != NodeState::SUCCESS)
				{
					return state;
				}
			}
			return NodeState::SUCCESS;
		}
	};
}
