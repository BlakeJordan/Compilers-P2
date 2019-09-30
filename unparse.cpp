#include "ast.hpp"

namespace lake{

void ProgramNode::unparse(std::ostream& out, int indent){
	myDeclList->unparse(out, indent);
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

/* VERIFY */
void DeclNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void VarDeclNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */

/* TODO */
void FnDeclNode::unparse(std::ostream& out, int indent) {}

void FormalDeclNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void FnBodyNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void StmtListNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void ExpListNode;
void TypeNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */

void IntNode::unparse(std::ostream& out, int indent){
	out << "int";
}

void BoolNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void VoidNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void PtrNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void StmtNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void AssignStmtNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void PostIncStmtNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void PostDecStmtNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void ReadStmtNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void WriteStmtNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void IfStmtNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void IfElseStmtNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void WhileStmtNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void CallStmtNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void ReturnStmtNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void ExpNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void IntLitNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void StrLitNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void TrueNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void FalseNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */

void IdNode::unparse(std::ostream& out, int indent){
	out << this->myStrVal;
}

void DerefNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void AssignNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void CallExpNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void UnaryExpNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void UnaryMinusNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void NotNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void BinaryExpNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void PlusNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void MinusNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void TimesNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void DivideNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void AndNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void OrNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void EqualsNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void NotEqualsNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void LessNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void GreaterNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void LessEqNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void GreaterEqNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */
void DeclListNode::unparse(std::ostream& out, int indent) {

}
/* VERIFY */

} // End namespace lake
