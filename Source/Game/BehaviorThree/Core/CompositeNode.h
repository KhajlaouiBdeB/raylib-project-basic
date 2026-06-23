#pragma once
#include <vector>
#include "Node.h"

namespace BehaviourTree
{
	class CompositeNode : public Node
	{
		public:
		virtual ~CompositeNode() 
		{
			for (Node* node : _nodes) 
			{
				delete node;
			}
		}

		void addNode(Node* node) 
		{
			_nodes.push_back(node);
		}

		protected:
		CompositeNode()  = default;
		std::vector<Node*> _nodes;

	};
}




