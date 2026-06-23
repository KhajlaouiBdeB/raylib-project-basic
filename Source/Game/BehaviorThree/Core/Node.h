#pragma once

namespace BehaviourTree
{
	enum class NodeState
	{
		RUNNING,
		SUCCESS,
		FAILURE
	};



	class Node
	{	
	public:
		virtual ~Node() = default;
		virtual NodeState tick() = 0;

	private:
		Node() = default;

	};
}



