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
	std::list<DeclNode *> * declList;
	lake::DeclNode * declNode;
	lake::VarDeclNode * varDeclNode;
	lake::TypeNode * typeNode;
	lake::IdNode * idNode;
}

%define parse.assert

%token               END    0     "end of file"
%token               NEWLINE "newline"
%token <tokenValue>  BOOL
%token <tokenValue>  INT
%token <tokenValue>  VOID
%token               TRUE
%token               FALSE
%token               IF
%token               ELSE
%token               WHILE
%token               RETURN
%token <idTokenValue> ID
%token               INTLITERAL
%token               STRINGLITERAL
%token               DEREF
%token               LCURLY
%token               RCURLY
%token               LPAREN
%token               RPAREN
%token               SEMICOLON
%token               COMMA
%token               DOT
%token               WRITE
%token               READ
%token               CROSSCROSS
%token               DASHDASH
%token               CROSS
%token               DASH
%token               STAR
%token               SLASH
%token               NOT
%token               AND
%token               OR
%token               EQUALS
%token               NOTEQUALS
%token               LESS
%token               GREATER
%token               LESSEQ
%token               GREATEREQ
%token               ASSIGN

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
%type <formalsListNode> formalsList
%type <formalDeclNode> formalDecl
%type <fnBodyNode> fnBody
%type <stmtListNode> stmtList
%type <stmtNode> stmt
%type <AssignNode> assignExp
%type <ExpNode> exp
/* %type <term> ??? */
/* %type <CallExpNode> fnCall */
/* %type <actualListNode> ??? */
%type <primTypeNode> primType
%type <typeNode> type
/* %type <indirectNode> ??? */
/* %type <locNode> ??? */
%type <idNode> id


/* NOTE: Make sure to add precedence and associativity
 * declarations!
*/

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
} | /* epsilon */ {
  $$ = new std::list<DeclNode *>();
}
	;

/* TODO */
decl : varDecl {
  $$ = new DeclNode(varDeclNode($1));
		//Make sure to fill out this rule
} | fnDecl {
  $$ = new DeclNode(fnDecl($1));
}

/* TODO */
varDeclList : varDeclList varDecl {

} | /* epsilon */ {
  $$ = new std::list<varDeclNode *>();
}

/* COMPLETE */
varDecl : type id SEMICOLON {
  $$ = new VarDeclNode($1, $2);
}

/* TODO */
fnDecl : type id formals fnBody {
  $$ = new ???
}


/* TODO */
formals : LPAREN RPAREN {

} | LPAREN formalsList RPAREN {

}

/* TODO */
formalsList : formalDecl {

} | formalDecl COMMA formalsList {

}

/* TODO */
formalDecl : type id {

}

/* TODO */
fnBody : LCURLY RCURLY {}

/* TODO */
stmtList : stmtList stmt {

} | /* epsilon */ {
  $$ = new std::list<stmtNode *>();
}

/* TODO */
stmt : assignExp SEMICOLON {

} | loc CROSSCROSS SEMICOLON {

} | loc DASHDASH SEMICOLON {

} | READ loc SEMICOLON {

} | WRITE exp SEMICOLON {

} | IF LPAREN exp RPAREN LCURLY varDeclList stmtList RCURLY {

} | IF LPAREN exp RPAREN LCURLY varDeclList stmtList RCURLY ELSE LCURLY varDeclList stmtList RCURLY {

} | WHILE LPAREN exp RPAREN LCURLY varDeclList stmtList RCURLY {

} | RETURN exp SEMICOLON {

} | RETURN SEMICOLON {

} | fncall SEMICOLON {

}

/* TODO */
assignExp : loc ASSIGN exp {

}

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

} | /* epsilon */ {

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
