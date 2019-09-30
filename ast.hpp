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
class FormalsListNode;
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
	DeclNode(size_t lineIn, size_t colIn) : ASTNode(lineIn, colIn){
	}
	virtual void unparse(std::ostream& out, int indent) = 0;
	size_t getLine(){ return line; }
	size_t getCol() { return col; }
private:
	size_t line;
	size_t col;
};

/* VERIFY */
class VarDeclListNode : public ASTNode{
public:
	VarDeclListNode(std::list<VarDeclNode *> * varDeclsIn) : ASTNode(0, 0){
		myVarDecls = varDeclsIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	std::list<VarDeclNode *> * myVarDecls;
};

/* COMPLETE */
class VarDeclNode : public DeclNode{
public:
	VarDeclNode(TypeNode * type, IdNode * id)
		: DeclNode(0, 0) {
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
	FnDeclNode(TypeNode * type, IdNode * id,
		FormalsListNode * formals, FnBodyNode * fnBody)
		: DeclNode(0, 0) {
			myType = type;
			myId = id;
			myFormals = formals;
			myFnBody = fnBody;
	}
	void unparse(std::ostream& out, int indent);
private:
	TypeNode * myType;
	IdNode * myId;
	FormalsListNode * myFormals;
	FnBodyNode * myFnBody;
};

/* VERIFY */
class FormalDeclNode : public DeclNode {
public:
	FormalDeclNode(TypeNode * type, IdNode * id)
		: DeclNode(0, 0) {
			myType = type;
			myId = id;
	}
	void unparse(std::ostream& out, int indent);
private:
	TypeNode * myType;
	IdNode * myId;
};

/* VERIFY */
class FormalsListNode : public ASTNode {
public:
	FormalsListNode(std::list<FormalDeclNode *> formalDeclsIn)
		: ASTNode(0, 0) {
			myFormals = formalDeclsIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	std::list<FormalDeclNode *> myFormals;
};

/* VERIFY */
class FnBodyNode : public DeclNode {
public:
	FnBodyNode(VarDeclListNode * declList, StmtListNode * stmtList)
	: DeclNode(declList->getLine(), declList->getCol()) {
		myDeclList = declList;
		myStmtList = stmtList;
	}
	void unparse(std::ostream& out, int indent);
private:
	VarDeclListNode * myDeclList;
	StmtListNode * myStmtList;
};

/* VERIFY */
class StmtListNode : public ASTNode {
public:
	StmtListNode(std::list<StmtNode *> * stmtsIn) : ASTNode(0, 0){
		myStmts = stmtsIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	std::list<StmtNode *> * myStmts;
};

/* VERIFY */
class ExpListNode : public ASTNode {
public:
	ExpListNode(std::list<ExpNode *> * expsIn) : ASTNode(0, 0){
		myExps = expsIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	std::list<ExpNode *> * myExps;
};

/* VERIFY */
class TypeNode : public ASTNode{
public:
	size_t lineNum;
	size_t colNum;
	TypeNode(size_t lineIn, size_t colIn) : ASTNode(lineIn, colIn){
		lineNum = lineIn;
		colNum = colIn;
	}
	void unparse(std::ostream& out, int indent);
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

class VoidNode : public TypeNode {
public:
	VoidNode(size_t lineIn, size_t colIn) : TypeNode(lineIn, colIn){ }
	void unparse(std::ostream& out, int index);
};

/* VERIFY */
class PtrNode : public TypeNode {
public:
	PtrNode(IdNode * id, int * indirectionLevel)
	: TypeNode(0, 0) {
		myId = id;
		myIndirectionLevel = indirectionLevel;
	}
	void unparse(std::ostream& out, int indent);
private:
	IdNode * myId;
	int * myIndirectionLevel;
};

/* VERIFY */
class StmtNode : public ASTNode {
public:
	StmtNode(size_t lineIn, size_t colIn) : ASTNode(lineIn, colIn) {
	}
	virtual void unparse(std::ostream& out, int indent) = 0;
};

/* VERIFY */
class AssignStmtNode : public StmtNode {
public:
	AssignStmtNode(AssignNode * assign)
	: StmtNode(0, 0){
		myAssign = assign;
	}
	void unparse(std::ostream& out, int indent);
private:
	AssignNode * myAssign;
};

/* VERIFY */
class PostIncStmtNode : public StmtNode {
public:
	PostIncStmtNode(ExpNode * exp)
	: StmtNode(0, 0) {
		myExp = exp;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode * myExp;
};

/* VERIFY */
class PostDecStmtNode : public StmtNode {
public:
	PostDecStmtNode(ExpNode * exp)
	: StmtNode(0, 0) {
		myExp = exp;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode * myExp;
};

/* VERIFY */
class ReadStmtNode : public StmtNode {
public:
	ReadStmtNode(ExpNode * exp)
	: StmtNode(0, 0) {
		myExp = exp;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode * myExp;
};

/* VERIFY */
class WriteStmtNode : public StmtNode {
public:
	WriteStmtNode(ExpNode * exp)
	: StmtNode(0, 0) {
		myExp = exp;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode * myExp;
};

/* VERIFY */
class IfStmtNode : public StmtNode {
public:
	IfStmtNode(ExpNode * exp, DeclListNode * declList, StmtListNode * stmtList)
	: StmtNode(0, 0) {
		myExp = exp;
		myDeclList = declList;
		myStmtList = stmtList;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode * myExp;
	DeclListNode * myDeclList;
	StmtListNode * myStmtList;
};

/* VERIFY */
class IfElseStmtNode : public StmtNode {
public:
	IfElseStmtNode(ExpNode * exp, DeclListNode * declList, StmtListNode * stmtList,
	DeclListNode * elseDeclList, StmtListNode * elseStmtList)
	: StmtNode(0, 0) {
		myExp = exp;
		myDeclList = declList;
		myStmtList = stmtList;
		myElseDeclList = elseDeclList;
		myElseStmtList = elseStmtList;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode * myExp;
	DeclListNode * myDeclList;
	StmtListNode * myStmtList;
	DeclListNode * myElseDeclList;
	StmtListNode * myElseStmtList;
};

/* VERIFY */
class WhileStmtNode : public StmtNode {
public:
	WhileStmtNode(ExpNode * exp, DeclListNode * declList, StmtListNode * stmtList)
	: StmtNode(0, 0) {
		myExp = exp;
		myDeclList = declList;
		myStmtList = stmtList;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode * myExp;
	DeclListNode * myDeclList;
	StmtListNode * myStmtList;
};

/* VERIFY */
class CallStmtNode : public StmtNode {
public:
	CallStmtNode(CallExpNode * expCall)
	: StmtNode(0, 0) {
		myExpCall = expCall;
	}
	void unparse(std::ostream& out, int indent);
private:
	CallExpNode * myExpCall;
};

/* VERIFY */
class ReturnStmtNode : public StmtNode {
public:
	ReturnStmtNode(ExpNode * exp)
	: StmtNode(0, 0) {
		myExp = exp;
	}
private:
	ExpNode * myExp;
	void unparse(std::ostream& out, int indent);
};

/* COMPLETE */
class ExpNode : public ASTNode{
public:
	ExpNode(size_t line, size_t col) : ASTNode(line, col){}
private:
	virtual void unparse(std::ostream& out, int indent) = 0;
};

/* VERIFY */
class IntLitNode : public ExpNode {
public:
	IntLitNode(size_t line, size_t col) : ExpNode(line, col) {
	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class StrLitNode : public ExpNode {
public:
	StrLitNode(size_t line, size_t col) : ExpNode(line, col) {
	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class TrueNode : public ExpNode {
public:
	TrueNode(size_t line, size_t col) : ExpNode(line, col) {
	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class FalseNode : public ExpNode {
public:
	FalseNode(size_t line, size_t col) : ExpNode(line, col) {
	}
	void unparse(std::ostream& out, int indent);
};

/* COMPLETE */
class IdNode : public ExpNode{
	std::string myStrVal;
public:
	IdNode(IDToken *& token) : ExpNode(token->_line, token->_column){
		myStrVal = token->value();
	}
	void unparse(std::ostream& out, int indent);
private:
};

/* VERIFY */
class DerefNode : public ExpNode {
public:
	DerefNode(ExpNode * exp, IdNode * id) : ExpNode(id->getLine(), id->getCol()) {
	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class AssignNode : public ExpNode {
public:
	AssignNode(ExpNode * lhs, ExpNode * rhs) : ExpNode(0, 0)  {

	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class CallExpNode : public ExpNode {
public:
	CallExpNode() : ExpNode(0, 0) {

	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class UnaryExpNode : public ExpNode {
public:
	UnaryExpNode() : ExpNode(0, 0) {

	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class UnaryMinusNode : public UnaryExpNode {
public:
	UnaryMinusNode() : UnaryExpNode() {

	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class NotNode : public UnaryExpNode {
public:
	NotNode() : UnaryExpNode() {

	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class BinaryExpNode : public ExpNode {
public:
	BinaryExpNode() : ExpNode(0, 0) {
	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class PlusNode : public BinaryExpNode {
public:
	PlusNode() {
	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class MinusNode : public BinaryExpNode {
public:
	MinusNode() {
	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class TimesNode : public BinaryExpNode {
public:
	TimesNode() {
	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class DivideNode : public BinaryExpNode {
public:
	DivideNode() {
	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class AndNode : public BinaryExpNode {
public:
	AndNode() {
	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class OrNode : public BinaryExpNode {
public:
	OrNode() {
	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class EqualsNode : public BinaryExpNode {
public:
	EqualsNode() {
	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class NotEqualsNode : public BinaryExpNode {
public:
	NotEqualsNode() {
	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class LessNode : public BinaryExpNode {
public:
	LessNode() {
	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class GreaterNode : public BinaryExpNode {
public:
	GreaterNode() {
	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class LessEqNode : public BinaryExpNode {
public:
	LessEqNode() {
	}
	void unparse(std::ostream& out, int indent);
};

/* VERIFY */
class GreaterEqNode : public BinaryExpNode {
public:
	GreaterEqNode() {
	}
	void unparse(std::ostream& out, int indent);
};

} //End namespace lake

#endif
