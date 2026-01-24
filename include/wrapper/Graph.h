#pragma once

#include <string>
#include <map>
#include <functional>

namespace graph { class Node; }

namespace wrapper
{

class Graph
{
public:
	void RegNodeGetCompCB(const std::string& name, std::function<void(const graph::Node&)> func);
	std::function<void(const graph::Node&)> GetRegNodeGetCompCB(const std::string& name);

public:
	static Graph* Instance();

private:
	Graph();
	~Graph();

private:
	std::map<std::string, std::function<void(const graph::Node&)>> m_node_get_comp;

	static Graph* m_instance;

}; // Graph

}