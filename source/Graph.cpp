#include "wrapper/Graph.h"

namespace wrapper
{

Graph* Graph::m_instance = NULL;

Graph* Graph::Instance()
{
	if (!m_instance) {
		m_instance = new Graph();
	}
	return m_instance;
}

Graph::Graph()
{
}

Graph::~Graph()
{
}

void Graph::RegNodeGetCompCB(const std::string& name, std::function<void(const graph::Node&)> func)
{
	m_node_get_comp.insert({ name, func });
}

std::function<void(const graph::Node&)> Graph::GetRegNodeGetCompCB(const std::string& name)
{
	auto itr = m_node_get_comp.find(name);
	return itr == m_node_get_comp.end() ? nullptr : itr->second;
}

}