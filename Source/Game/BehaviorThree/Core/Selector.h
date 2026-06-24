#pragma once
#include "CompositeNode.h"
namespace BehaviourTree
{
	class Selector : public CompositeNode
	{
	public:
		Selector() = default;
		~Selector() override = default;

		NodeState tick() override
		{
			for (Node* child : _nodes)
			{
				NodeState state = child->tick();
				if (state != NodeState::FAILURE)
				{
					return state;  
				}
			}

			return NodeState::FAILURE;
		}
	};
}