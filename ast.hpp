#ifndef LAKE_AST_HPP
#define LAKE_AST_HPP

#include <ostream>
#include <list>
#include "tokens.hpp"

//Here is a suggestion for some of the different kinds of AST nodes
// and what kinds of children you might want to give them.
// All of these kinds of AST nodes are subclasses of ASTNode.
// Please note that you do NOT have to use this AST structure and
// you should feel free to include additional classes or not use
// the ones provided here. All that matters for P2 is that you
// unparse the tree as the oracle does.

//
// Indentation indicates further subclassing:
//
//     Subclass		Children
//     --------		------
//     ProgramNode	DeclListNode
//     DeclListNode	linked list of DeclNode
//     DeclNode
//       VarDeclNode	TypeNode, IdNode, int
//       FnDeclNode	TypeNode, IdNode, FormalsListNode, FnBodyNode
//       FormalDeclNode    TypeNode, IdNode
//
//     FormalsListNode     linked list of FormalDeclNode
//     FnBodyNode          DeclListNode, StmtListNode
//     StmtListNode        linked list of StmtNode
//     ExpListNode         linked list of ExpNode
//
//     TypeNode:
//       IntNode           -- none --
//       BoolNode          -- none --
//       VoidNode          -- none --
//       PtrNode           IdNode (base type), (int for indirection level)
//
//     StmtNode:
//       AssignStmtNode      AssignNode
//       PostIncStmtNode     ExpNode
//       PostDecStmtNode     ExpNode
//       ReadStmtNode        ExpNode
//       WriteStmtNode       ExpNode
//       IfStmtNode          ExpNode, DeclListNode, StmtListNode
//       IfElseStmtNode      ExpNode, DeclListNode, StmtListNode,
//                                    DeclListNode, StmtListNode
//       WhileStmtNode       ExpNode, DeclListNode, StmtListNode
//       CallStmtNode        CallExpNode
//       ReturnStmtNode      ExpNode
//
//     ExpNode:
//       IntLitNode          -- none --
//       StrLitNode          -- none --
//       TrueNode            -- none --
//       FalseNode           -- none --
//       IdNode              -- none --
//       DerefNode           ExpNode, IdNode
//       AssignNode          ExpNode, ExpNode
//       CallExpNode         IdNode, ExpListNode
//       UnaryExpNode        ExpNode
//         UnaryMinusNode
//         NotNode
//       BinaryExpNode       ExpNode ExpNode
//         PlusNode
//         MinusNode
//         TimesNode
//         DivideNode
//         AndNode
//         OrNode
//         EqualsNode
//         NotEqualsNode
//         LessNode
//         GreaterNode
//         LessEqNode
//         GreaterEqNode
//
//
// Here are the different kinds of AST nodes again, organized according to
// whether they are leaves, internal nodes with linked lists of children, or
// internal nodes with a fixed number of children:
//
// (1) Leaf nodes:
//        IntNode,   BoolNode,  VoidNode,  IntLitNode,  StrLitNode,
//        TrueNode,  FalseNode, IdNode
//
// (2) Internal nodes with (possibly empty) lists of children:
//        DeclListNode, FormalsListNode, StmtListNode, ExpListNode
//
// (3) Internal nodes with fixed numbers of direct descendants:
//        ProgramNode,     VarDeclNode,     FnDeclNode,     FormalDeclNode,
//        FnBodyNode,      AssignStmtNode,
//        PostIncStmtNode, PostDecStmtNode, ReadStmtNode,   WriteStmtNode
//        IfStmtNode,      IfElseStmtNode,  WhileStmtNode,  CallStmtNode
//        ReturnStmtNode,  CallExpNode,
//        UnaryExpNode,    BinaryExpNode,   UnaryMinusNode, NotNode,
//        PlusNode,        MinusNode,       TimesNode,      DivideNode,
//        AndNode,         OrNode,          EqualsNode,     NotEqualsNode,
//        LessNode,        GreaterNode,     LessEqNode,     GreaterEqNode
//
// **********************************************************************

// **********************************************************************
// ASTnode class (base class for all other kinds of nodes)
// **********************************************************************

namespace lake{

/* You may find it useful to forward declare AST subclasses
   here so that you don't have to worry about the order
   in which you declare your subclasses below */

class ProgramNode;
class DeclListNode;
class DeclNode;
class VarDeclNode;
class FnDeclNode;
class FormalDeclNode;
class FnBodyNode;
class StmtListNode;
class ExpListNode;
class TypeNode;
class IntNode;
class BoolNode;
class VoidNode;
class PtrNode;
class StmtNode;
class AssignStmtNode;
class PostIncStmtNode;
class PostDecStmtNode;
class ReadStmtNode;
class WriteStmtNode;
class IfStmtNode;
class IfElseStmtNode;
class WhileStmtNode;
class CallStmtNode;
class ReturnStmtNode;
class ExpNode;
class IntLitNode;
class StrLitNode;
class TrueNode;
class FalseNode;
class IdNode;
class DerefNode;
class AssignNode;
class CallExpNode;
class UnaryExpNode;
class UnaryMinusNode;
class NotNode;
class BinaryExpNode;
class PlusNode;
class MinusNode;
class TimesNode;
class DivideNode;
class AndNode;
class OrNode;
class EqualsNode;
class NotEqualsNode;
class LessNode;
class GreaterNode;
class LessEqNode;
class GreaterEqNode;
class DeclListNode;

/* COMPLETE */
class ASTNode{
public:
	ASTNode(size_t lineIn, size_t colIn){
		this->line = lineIn;
		this->col = colIn;
	}
	virtual void unparse(std::ostream& out, int indent) = 0;
	void doIndent(std::ostream& out, int indent){
		for (int k = 0 ; k < indent; k++){ out << " "; }
	}
	size_t getLine(){ return line; }
	size_t getCol() { return col; }
private:
	size_t line;
	size_t col;
};

/* COMPLETE */
class ProgramNode : public ASTNode{
public:
	ProgramNode(DeclListNode * declsIn) : ASTNode(0, 0){
		myDeclList = declsIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	DeclListNode * myDeclList;
};

/* COMPLETE */
class DeclListNode : public ASTNode{
public:
	DeclListNode(std::list<DeclNode *> * declsIn) : ASTNode(0, 0){
		myDecls = declsIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	std::list<DeclNode *> * myDecls;
};

/* VERIFY */
class DeclNode : public ASTNode{
public:
	DeclNode(size_t line, size_t col) : ASTNode(line, col){}
};

/* VERIFY */
class VarDeclListNode : public ASTNode{
public:
	VarDeclListNode(std::list<varDeclNode *> * varDeclsIn) : ASTNode(0, 0){
		myVarDecls = varDeclsIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	std::list<VarDeclNode *> * myVarDecls;
};

/* COMPLETE */
class VarDeclNode : public DeclNode{
public:
	VarDeclNode(TypeNode * type, IdNode * id) : DeclNode(type->getLine(), type->getCol()){
		myType = type;
		myId = id;
	}
	void unparse(std::ostream& out, int indent);
private:
	TypeNode * myType;
	IdNode * myId;
};

/* TODO */
class FnDeclNode : public DeclNode {
public:
	FnDeclNode(TypeNode * type, IdNode * id, formalsNode * formals, fnBodyNode * fnBody) {

	}
	void unparse(std::ostream);
};

/* VERIFY */
class FnBodyNode : public ASTNode {
public:
	FnBodyNode() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class StmtListNode : public ASTNode {
public:
	StmtListNode() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class ExpListNode : public ASTNode {
public:
	ExpListNode() {
	}
	void unparse(std::ostream)
};

/* COMPLETE */
class TypeNode : public ASTNode{
public:
	TypeNode(size_t lineIn, size_t colIn) : ASTNode(lineIn, colIn){
	}
	virtual void unparse(std::ostream& out, int indent) = 0;
};

/* COMPLETE */
class IntNode : public TypeNode{
public:
	IntNode(size_t lineIn, size_t colIn): TypeNode(lineIn, colIn){ }
	void unparse(std::ostream& out, int indent);
};

/* COMPLETE */
class BoolNode : public TypeNode{
public:
	BoolNode(size_t lineIn, size_t colIn): TypeNode(lineIn, colIn){ }
	void unparse(std::ostream& out, int indent);
};

/* COMPLETE */
class IdNode : public ExpNode{
public:
	IdNode(IDToken * token) : ExpNode(token->_line, token->_column){
		myStrVal = token->value();
	}
	void unparse(std::ostream& out, int indent);
private:
	std::string myStrVal;
};

/* VERIFY */
class PtrNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class StmtNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class AssignStmtNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class PostIncStmtNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class PostDecStmtNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class ReadStmtNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class WriteStmtNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class IfStmtNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class IfElseStmtNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class WhileStmtNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class CallStmtNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class ReturnStmtNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* COMPLETE */
class ExpNode : public ASTNode{
public:
	ExpNode(size_t line, size_t col) : ASTNode(line, col){}
};

/* VERIFY */
class IntLitNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class StrLitNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class TrueNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class FalseNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class IdNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class DerefNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class AssignNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class CallExpNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class UnaryExpNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class UnaryMinusNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class NotNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class BinaryExpNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class PlusNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class MinusNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class TimesNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class DivideNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class AndNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class OrNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class EqualsNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class NotEqualsNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class LessNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class GreaterNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class LessEqNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class GreaterEqNode : public ASTNode {
public:
	Node() {
	}
	void unparse(std::ostream)
};

/* VERIFY */
class DeclListNode;

/* VERIFY */
class FormalsNode: public DeclNode {
public:
	FormalsNode(size_t line, size_t col) : ASTNode(line, col){}
};

} //End namespace lake

#endif
