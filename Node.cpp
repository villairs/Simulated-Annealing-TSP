#include "Node.hpp"

Node::Node(){}

Node::Node(int x,int y, std::string name):m_x(x),m_y(y),m_name(name){
//validList = std::list<int>();
}

Node::Node(const Node & n):m_x(n.m_x),m_y(n.m_y),m_name(n.m_name){
//validList = n.validList;
}
