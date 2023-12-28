#include <iostream>
#include <vector>
#include <memory>

class node
{
public:
	int m_value;
	std::weak_ptr<node> parent;
	node(int value) : m_value{ value } {};
	~node() { std::cout << "destructor called\n"; }
};

int main()
{
	{
		auto node1 = std::make_shared<node>(1);
		auto node2 = std::make_shared<node>(2);

		std::cout << "refs to node 1 : " << node1.use_count() << std::endl;
		std::cout << "refs to node 2 : " << node2.use_count() << std::endl;

		node1->parent = node2;
		node2->parent = node1;

		std::cout << "refs to node 1 after parent link : " << node1.use_count() << std::endl;
		std::cout << "refs to node 2 after parent link : " << node2.use_count() << std::endl;

		std::cout << "access node 1 parent value : " << node1->parent.lock()->m_value << std::endl;
		std::cout << "access node 2 parent value : " << node2->parent.lock()->m_value << std::endl;

	}

	return 0;
}