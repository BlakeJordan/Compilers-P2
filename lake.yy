%skeleton "lalr1.cc"
%require  "3.0"
%debug
%defines
%define api.namespace {lake}
%define parser_class_name {Parser}
%output "parser.cc"
%token-table

%code requires{
   #include <list>
   #include "tokens.hpp"
   #include "ast.hpp"
   namespace lake {
      class Scanner;
   }

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

}

%parse-param { lake::Scanner  &scanner  }
%parse-param { lake::ProgramNode** root }

%code{
   #include <iostream>
   #include <cstdlib>
   #include <fstream>

   /* include for interoperation between scanner/parser */
   #include "scanner.hpp"

#undef yylex
#define yylex scanner.yylex
}

/*%define api.value.type variant*/
%union {
	lake::Token * tokenValue;
	lake::IDToken * idTokenValue;
	lake::ASTNode * astNode;
	lake::ProgramNode * programNode;
	std::list<DeclNode *> * declListNode;
  std::list<FormalDeclNode *> * formalsList;
	lake::DeclNode * declNode;
  std::list<VarDeclNode *> * varDeclListNode;
	lake::VarDeclNode * varDeclNode;
	lake::TypeNode * typeNode;
	lake::IdNode * idNode;
  std::list<StmtNode *> * stmtListNode;
  lake::StmtNode * stmtNode;
  lake::FnBodyNode * fnBodyNode;
  lake::FormalsListNode * formalsListNode;
  lake::FormalsListNode * formalsNode;
  lake::FormalDeclNode * formalDeclNode;
  lake::FnDeclNode * fnDeclNode;
  lake::DerefNode * indirect;
  lake::AssignNode * assignNode;
  lake::ExpNode * expNode;
  lake::IfStmtNode * ifStmtNode;
  lake::CallExpNode * callExpNode;
}

%define parse.assert

%token                  END    0     "end of file"
%token                  NEWLINE "newline"
%token <tokenValue>     BOOL
%token <tokenValue>     INT
%token <tokenValue>     VOID
%token <tokenValue>     TRUE
%token <tokenValue>     FALSE
%token <tokenValue>     IF
%token <tokenValue>     ELSE
%token <tokenValue>     WHILE
%token <tokenValue>     RETURN
%token <idTokenValue>   ID
%token <intLitToken>    INTLITERAL
%token <StringLitToken> STRINGLITERAL
%token <tokenValue>     DEREF
%token <tokenValue>     LCURLY
%token <tokenValue>     RCURLY
%token <tokenValue>     LPAREN
%token <tokenValue>     RPAREN
%token <tokenValue>     SEMICOLON
%token <tokenValue>     COMMA
%token <tokenValue>     DOT
%token <tokenValue>     WRITE
%token <tokenValue>     READ
%token <tokenValue>     CROSSCROSS
%token <tokenValue>     DASHDASH
%token <tokenValue>     CROSS
%token <tokenValue>     DASH
%token <tokenValue>     STAR
%token <tokenValue>     SLASH
%token <tokenValue>     NOT
%token <tokenValue>     AND
%token <tokenValue>     OR
%token <tokenValue>     EQUALS
%token <tokenValue>     NOTEQUALS
%token <tokenValue>     LESS
%token <tokenValue>     GREATER
%token <tokenValue>     LESSEQ
%token <tokenValue>     GREATEREQ
%token <tokenValue>     ASSIGN

/* Nonterminals
*  NOTE: You will need to add more nonterminals
*  to this list as you add productions to the grammar
*  below.
*/
/* TODO: Add classes for these nodes */
%type <programNode> program
%type <declListNode> declList
%type <declNode> decl
%type <varDeclListNode> varDeclList
%type <varDeclNode> varDecl
%type <fnDeclNode> fnDecl
%type <formalsNode> formals
%type <formalsList> formalsList
%type <formalDeclNode> formalDecl
%type <fnBodyNode> fnBody
%type <stmtListNode> stmtList
%type <stmtNode> stmt
%type <assignNode> assignExp
%type <expNode> exp
/* %type <term> ??? */
/* %type <CallExpNode> fnCall */
/* %type <actualListNode> ??? */
%type <primTypeNode> primType
%type <typeNode> type
%type <indirectNode> indirect
%type <expNode> loc
%type <idNode> id
%type <ifStmtNode> ifStmt
%type <callExpNode> fncall


/* NOTE: Make sure to add precedence and associativity
 * declarations!
*/
%right ASSIGN
%left OR
%left AND
%left EQUALS NOTEQUALS LESS GREATER LESSEQ GREATEREQ
%left CROSS DASH
%left STAR SLASH
%left NOT
/* highest precedence */
%left DEREF

%%

/* STEPS:
  1. Add rules from lake.grammar to lake.yy
  2. Create node subclasses
  3. Override unparse method for node
  4. Add precedence and associativity
*/

/* COMPLETE */
program : declList {
  $$ = new ProgramNode(new DeclListNode($1));
  *root = $$;
}
  	;

/* COMPLETE */
declList : declList decl {
  $1->push_back($2);
  $$ = $1;
  std::cout<<"Value 1: "<<$1;
  std::cout<<"Value 2: "<<$2;
  std::cout<<"ProductionValue: "<<$$;
} | /* epsilon */ {
  $$ = new std::list<DeclNode *>();
}
	;

/* TODO */
decl : varDecl {
  $$ = $1;
		//Make sure to fill out this rule
} | fnDecl {
  $$ = $1;
}
  ;
/* TODO */
varDeclList : varDeclList varDecl {
  $1->push_back($2);
  $$ = $1;
} | /* epsilon */ {
  $$ = new std::list<VarDeclNode *>();
}
  ;

/* COMPLETE */
varDecl : type id SEMICOLON {
  $$ = new VarDeclNode($1, $2);
}
  ;

/* TODO */
fnDecl : type id formals fnBody {
  $$ = new FnDeclNode(new TypeNode($1->lineNum, $1->colNum),
  $2, $3, $4);
}
  ;

/* TODO */
formals : LPAREN RPAREN {
  $$ = new FormalsListNode(new std::list<FormalDeclNode *>());
} | LPAREN formalsList RPAREN {
  $$ = new FormalsListNode($2);
}
  ;

/* TODO */
formalsList : formalDecl {
  std::list<FormalDeclNode *> * list = new std::list<FormalDeclNode *>();
  list->push_back($1);
  $$ = list;
} | formalDecl COMMA formalsList {
  $3->push_back($1);
  $$ = $3;
}
  ;

/* TODO */
formalDecl : type id {
  $$ = new FormalDeclNode($1, $2);
}

/* TODO */
fnBody : LCURLY varDeclList stmtList RCURLY {
  $$ = new FnBodyNode($1->_line, $1->_column, new VarDeclListNode($2), new StmtListNode($3));
}

/* TODO */
stmtList : stmtList stmt {
  $1->push_back($2);
  $$ = $1;
} | /* epsilon */ {
  $$ = new std::list<StmtNode *>();
}

/* TODO */
stmt : assignExp SEMICOLON {
  $$ = new AssignStmtNode($1);
} | loc CROSSCROSS SEMICOLON {
  $$ = new PostIncStmtNode($1);
} | loc DASHDASH SEMICOLON {
  $$ = new PostDecStmtNode($1);
} | READ loc SEMICOLON {
  $$ = new ReadStmtNode($2);
} | WRITE exp SEMICOLON {
  $$ = new WriteStmtNode($2);
} | IF LPAREN exp RPAREN LCURLY varDeclList stmtList RCURLY {
  $$ = new IfStmtNode($1->_line, $1->_column, $3, new VarDeclListNode($6), new StmtListNode($7));
} | IF LPAREN exp RPAREN LCURLY varDeclList stmtList RCURLY ELSE LCURLY varDeclList stmtList RCURLY {
  $$ = new IfElseStmtNode($3, new VarDeclListNode($6), new StmtListNode($7), new VarDeclListNode($11), new StmtListNode($12));
} | WHILE LPAREN exp RPAREN LCURLY varDeclList stmtList RCURLY {
  $$ = new WhileStmtNode($1->_line, $1->_column, $3, new VarDeclListNode($6), new StmtListNode($7));
} | RETURN exp SEMICOLON {
  $$ = new ReturnStmtNode($1->_line, $1->_column, $2);
} | RETURN SEMICOLON {
  $$ = new ReturnStmtNode($1->_line, $1->_column, nullptr);
} | fncall SEMICOLON {
  $$ = new CallStmtNode($1);
}

/* TODO */
assignExp : loc ASSIGN exp {
}
  ;

/* TODO */
exp : assignExp {

} | exp CROSS exp {

} | exp DASH exp {

} | exp STAR exp {

} | exp SLASH exp {

} | NOT exp {

} | exp AND exp {

} | exp OR exp {

} | exp EQUALS exp {

} | exp NOTEQUALS exp {

} | exp LESS exp {

} | exp GREATER exp {

} | exp LESSEQ exp {

} | exp GREATEREQ exp {

} | DASH term {

} | term {

}

/* TODO */
term : loc {

} | INTLITERAL {

} | STRINGLITERAL {

} | TRUE {

} | FALSE {

} | LPAREN exp RPAREN {

} | fncall {

}

/* TODO */
fncall : id LPAREN RPAREN { // fn call with no args

} | id LPAREN actualList RPAREN { // with args

}

/* TODO */
actualList : exp {

} | actualList COMMA exp {

}

/* COMPLETE */
type : INT { $$ = new IntNode($1->_line, $1->_column); }

/* COMPLETE */
primType : INT { $$ = new IntNode($1->_line, $1->_column); }
         | BOOL { $$ = new BoolNode($1->_line, $1->_column); }
         | VOID { $$ = new VoidNode($1->_line, $1->_column); }

/* TODO */
indirect : indirect DEREF {
  $1->push_back($2);
  $$ = $1;
} | /* epsilon */ {
  $$ = new DerefNode(NULL, 0);
}

/* TODO */
loc : id {

} | DEREF loc {
}

/* COMPLETE */
id : ID { $$ = new IdNode($1); }
%%

void
lake::Parser::error(const std::string &err_message ) {
   std::cerr << "Error: " << err_message << "\n";
}
