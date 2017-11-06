#pragma once
#include <list>
#include <string>
//node that represents a cell in the sudoku grid
class Node{
public:
Node();
Node(int x,int y, std::string name);
Node(const Node& n);

int m_x,m_y;//m_value;
std:: string m_name;
//bool m_init;
//std::list<int> validList;
};
