#include "ast.hpp"

namespace lake{

void ProgramNode::unparse(std::ostream& out, int indent){
	myDeclList->unparse(out, indent);
}

/* TODO */
void FnDeclNode::unparse() {
	
}

void DeclListNode::unparse(std::ostream& out, int indent){
	/*
	Extended for loop: Iterates over every element in
	   *myDecls
	*/
	for (DeclNode * elt : *myDecls){
		elt->unparse(out, indent);
	}
}

void VarDeclNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	this->myType->unparse(out, 0);
	out << " ";
	this->myId->unparse(out, 0);
	out << ";\n";
}

void IdNode::unparse(std::ostream& out, int indent){
	out << this->myStrVal;
}

void IntNode::unparse(std::ostream& out, int indent){
	out << "int";
}

} // End namespace lake