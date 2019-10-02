// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "parser.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "grammar.hh"

// User implementation prologue.

#line 51 "parser.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 32 "lake.yy" // lalr1.cc:413

   #include <iostream>
   #include <cstdlib>
   #include <fstream>

   /* include for interoperation between scanner/parser */
   #include "scanner.hpp"

#undef yylex
#define yylex scanner.yylex

#line 65 "parser.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "lake.yy" // lalr1.cc:479
namespace lake {
#line 132 "parser.cc" // lalr1.cc:479

  /// Build a parser object.
  Parser::Parser (lake::Scanner  &scanner_yyarg, lake::ProgramNode** root_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      root (root_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
    value = other.value;
  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value (v)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 169 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.programNode) = new ProgramNode(new DeclListNode((yystack_[0].value.declListNode)));
  *root = (yylhs.value.programNode);
}
#line 563 "parser.cc" // lalr1.cc:859
    break;

  case 3:
#line 176 "lake.yy" // lalr1.cc:859
    {
  (yystack_[1].value.declListNode)->push_back((yystack_[0].value.declNode));
  (yylhs.value.declListNode) = (yystack_[1].value.declListNode);
  std::cout<<"Value 1: "<<(yystack_[1].value.declListNode);
  std::cout<<"Value 2: "<<(yystack_[0].value.declNode);
  std::cout<<"ProductionValue: "<<(yylhs.value.declListNode);
}
#line 575 "parser.cc" // lalr1.cc:859
    break;

  case 4:
#line 182 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.declListNode) = new std::list<DeclNode *>();
}
#line 583 "parser.cc" // lalr1.cc:859
    break;

  case 5:
#line 188 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.declNode) = (yystack_[0].value.varDeclNode);
		//Make sure to fill out this rule
}
#line 592 "parser.cc" // lalr1.cc:859
    break;

  case 6:
#line 191 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.declNode) = (yystack_[0].value.fnDeclNode);
}
#line 600 "parser.cc" // lalr1.cc:859
    break;

  case 7:
#line 196 "lake.yy" // lalr1.cc:859
    {
  (yystack_[1].value.varDeclListNode)->push_back((yystack_[0].value.varDeclNode));
  (yylhs.value.varDeclListNode) = (yystack_[1].value.varDeclListNode);
}
#line 609 "parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 199 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.varDeclListNode) = new std::list<VarDeclNode *>();
}
#line 617 "parser.cc" // lalr1.cc:859
    break;

  case 9:
#line 205 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.varDeclNode) = new VarDeclNode((yystack_[2].value.typeNode), (yystack_[1].value.idNode));
}
#line 625 "parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 211 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.fnDeclNode) = new FnDeclNode(new TypeNode((yystack_[3].value.typeNode)->lineNum, (yystack_[3].value.typeNode)->colNum),
  (yystack_[2].value.idNode), (yystack_[1].value.formalsNode), (yystack_[0].value.fnBodyNode));
}
#line 634 "parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 218 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.formalsNode) = new FormalsListNode(new std::list<FormalDeclNode *>());
}
#line 642 "parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 220 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.formalsNode) = new FormalsListNode((yystack_[1].value.formalsList));
}
#line 650 "parser.cc" // lalr1.cc:859
    break;

  case 13:
#line 226 "lake.yy" // lalr1.cc:859
    {
  std::list<FormalDeclNode *> * list = new std::list<FormalDeclNode *>();
  list->push_back((yystack_[0].value.formalDeclNode));
  (yylhs.value.formalsList) = list;
}
#line 660 "parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 230 "lake.yy" // lalr1.cc:859
    {
  (yystack_[0].value.formalsList)->push_back((yystack_[2].value.formalDeclNode));
  (yylhs.value.formalsList) = (yystack_[0].value.formalsList);
}
#line 669 "parser.cc" // lalr1.cc:859
    break;

  case 15:
#line 237 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.formalDeclNode) = new FormalDeclNode((yystack_[1].value.typeNode), (yystack_[0].value.idNode));
}
#line 677 "parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 242 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.fnBodyNode) = new FnBodyNode((yystack_[3].value.tokenValue)->_line, (yystack_[3].value.tokenValue)->_column, new VarDeclListNode((yystack_[2].value.varDeclListNode)), new StmtListNode((yystack_[1].value.stmtListNode)));
}
#line 685 "parser.cc" // lalr1.cc:859
    break;

  case 17:
#line 247 "lake.yy" // lalr1.cc:859
    {
  (yystack_[1].value.stmtListNode)->push_back((yystack_[0].value.stmtNode));
  (yylhs.value.stmtListNode) = (yystack_[1].value.stmtListNode);
}
#line 694 "parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 250 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.stmtListNode) = new std::list<StmtNode *>();
}
#line 702 "parser.cc" // lalr1.cc:859
    break;

  case 19:
#line 255 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.stmtNode) = new AssignStmtNode((yystack_[1].value.assignNode));
}
#line 710 "parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 257 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.stmtNode) = new PostIncStmtNode((yystack_[2].value.expNode));
}
#line 718 "parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 259 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.stmtNode) = new PostDecStmtNode((yystack_[2].value.expNode));
}
#line 726 "parser.cc" // lalr1.cc:859
    break;

  case 22:
#line 261 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.stmtNode) = new ReadStmtNode((yystack_[1].value.expNode));
}
#line 734 "parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 263 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.stmtNode) = new WriteStmtNode((yystack_[1].value.expNode));
}
#line 742 "parser.cc" // lalr1.cc:859
    break;

  case 24:
#line 265 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.stmtNode) = new IfStmtNode((yystack_[7].value.tokenValue)->_line, (yystack_[7].value.tokenValue)->_column, (yystack_[5].value.expNode), new VarDeclListNode((yystack_[2].value.varDeclListNode)), new StmtListNode((yystack_[1].value.stmtListNode)));
}
#line 750 "parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 267 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.stmtNode) = new IfElseStmtNode((yystack_[10].value.expNode), new VarDeclListNode((yystack_[7].value.varDeclListNode)), new StmtListNode((yystack_[6].value.stmtListNode)), new VarDeclListNode((yystack_[2].value.varDeclListNode)), new StmtListNode((yystack_[1].value.stmtListNode)));
}
#line 758 "parser.cc" // lalr1.cc:859
    break;

  case 26:
#line 269 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.stmtNode) = new WhileStmtNode((yystack_[7].value.tokenValue)->_line, (yystack_[7].value.tokenValue)->_column, (yystack_[5].value.expNode), new VarDeclListNode((yystack_[2].value.varDeclListNode)), new StmtListNode((yystack_[1].value.stmtListNode)));
}
#line 766 "parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 271 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.stmtNode) = new ReturnStmtNode((yystack_[2].value.tokenValue)->_line, (yystack_[2].value.tokenValue)->_column, (yystack_[1].value.expNode));
}
#line 774 "parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 273 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.stmtNode) = new ReturnStmtNode((yystack_[1].value.tokenValue)->_line, (yystack_[1].value.tokenValue)->_column, nullptr);
}
#line 782 "parser.cc" // lalr1.cc:859
    break;

  case 29:
#line 275 "lake.yy" // lalr1.cc:859
    {
  (yylhs.value.stmtNode) = new CallStmtNode((yystack_[1].value.callExpNode));
}
#line 790 "parser.cc" // lalr1.cc:859
    break;

  case 30:
#line 280 "lake.yy" // lalr1.cc:859
    {
}
#line 797 "parser.cc" // lalr1.cc:859
    break;

  case 31:
#line 285 "lake.yy" // lalr1.cc:859
    {

}
#line 805 "parser.cc" // lalr1.cc:859
    break;

  case 32:
#line 287 "lake.yy" // lalr1.cc:859
    {

}
#line 813 "parser.cc" // lalr1.cc:859
    break;

  case 33:
#line 289 "lake.yy" // lalr1.cc:859
    {

}
#line 821 "parser.cc" // lalr1.cc:859
    break;

  case 34:
#line 291 "lake.yy" // lalr1.cc:859
    {

}
#line 829 "parser.cc" // lalr1.cc:859
    break;

  case 35:
#line 293 "lake.yy" // lalr1.cc:859
    {

}
#line 837 "parser.cc" // lalr1.cc:859
    break;

  case 36:
#line 295 "lake.yy" // lalr1.cc:859
    {

}
#line 845 "parser.cc" // lalr1.cc:859
    break;

  case 37:
#line 297 "lake.yy" // lalr1.cc:859
    {

}
#line 853 "parser.cc" // lalr1.cc:859
    break;

  case 38:
#line 299 "lake.yy" // lalr1.cc:859
    {

}
#line 861 "parser.cc" // lalr1.cc:859
    break;

  case 39:
#line 301 "lake.yy" // lalr1.cc:859
    {

}
#line 869 "parser.cc" // lalr1.cc:859
    break;

  case 40:
#line 303 "lake.yy" // lalr1.cc:859
    {

}
#line 877 "parser.cc" // lalr1.cc:859
    break;

  case 41:
#line 305 "lake.yy" // lalr1.cc:859
    {

}
#line 885 "parser.cc" // lalr1.cc:859
    break;

  case 42:
#line 307 "lake.yy" // lalr1.cc:859
    {

}
#line 893 "parser.cc" // lalr1.cc:859
    break;

  case 43:
#line 309 "lake.yy" // lalr1.cc:859
    {

}
#line 901 "parser.cc" // lalr1.cc:859
    break;

  case 44:
#line 311 "lake.yy" // lalr1.cc:859
    {

}
#line 909 "parser.cc" // lalr1.cc:859
    break;

  case 45:
#line 313 "lake.yy" // lalr1.cc:859
    {

}
#line 917 "parser.cc" // lalr1.cc:859
    break;

  case 46:
#line 315 "lake.yy" // lalr1.cc:859
    {

}
#line 925 "parser.cc" // lalr1.cc:859
    break;

  case 47:
#line 320 "lake.yy" // lalr1.cc:859
    {

}
#line 933 "parser.cc" // lalr1.cc:859
    break;

  case 48:
#line 322 "lake.yy" // lalr1.cc:859
    {

}
#line 941 "parser.cc" // lalr1.cc:859
    break;

  case 49:
#line 324 "lake.yy" // lalr1.cc:859
    {

}
#line 949 "parser.cc" // lalr1.cc:859
    break;

  case 50:
#line 326 "lake.yy" // lalr1.cc:859
    {

}
#line 957 "parser.cc" // lalr1.cc:859
    break;

  case 51:
#line 328 "lake.yy" // lalr1.cc:859
    {

}
#line 965 "parser.cc" // lalr1.cc:859
    break;

  case 52:
#line 330 "lake.yy" // lalr1.cc:859
    {

}
#line 973 "parser.cc" // lalr1.cc:859
    break;

  case 53:
#line 332 "lake.yy" // lalr1.cc:859
    {

}
#line 981 "parser.cc" // lalr1.cc:859
    break;

  case 54:
#line 337 "lake.yy" // lalr1.cc:859
    { // fn call with no args

}
#line 989 "parser.cc" // lalr1.cc:859
    break;

  case 55:
#line 339 "lake.yy" // lalr1.cc:859
    { // with args

}
#line 997 "parser.cc" // lalr1.cc:859
    break;

  case 56:
#line 344 "lake.yy" // lalr1.cc:859
    {

}
#line 1005 "parser.cc" // lalr1.cc:859
    break;

  case 57:
#line 346 "lake.yy" // lalr1.cc:859
    {

}
#line 1013 "parser.cc" // lalr1.cc:859
    break;

  case 58:
#line 351 "lake.yy" // lalr1.cc:859
    { (yylhs.value.typeNode) = new IntNode((yystack_[0].value.tokenValue)->_line, (yystack_[0].value.tokenValue)->_column); }
#line 1019 "parser.cc" // lalr1.cc:859
    break;

  case 59:
#line 367 "lake.yy" // lalr1.cc:859
    {

}
#line 1027 "parser.cc" // lalr1.cc:859
    break;

  case 60:
#line 369 "lake.yy" // lalr1.cc:859
    {
}
#line 1034 "parser.cc" // lalr1.cc:859
    break;

  case 61:
#line 373 "lake.yy" // lalr1.cc:859
    { (yylhs.value.idNode) = new IdNode((yystack_[0].value.idTokenValue)); }
#line 1040 "parser.cc" // lalr1.cc:859
    break;


#line 1044 "parser.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char Parser::yypact_ninf_ = -87;

  const signed char Parser::yytable_ninf_ = -1;

  const short int
  Parser::yypact_[] =
  {
     -87,    16,    14,   -87,   -87,   -87,   -87,   -87,    18,   -87,
      45,     8,   -87,    10,   -87,    19,    47,    18,   -87,   -87,
     -87,    14,   -87,    14,   -87,   -87,   233,    18,    21,    52,
      46,     1,   -87,   114,     1,   -87,    51,    55,   -20,    64,
      63,   114,   114,   -87,   -87,   -87,   -87,   114,   -87,    66,
     114,   -87,   181,   -87,   -87,    54,   -87,   -87,   201,    65,
     -87,   -87,    67,    76,   114,    94,   119,   140,   161,   -87,
     -87,   -87,   -87,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   -87,   -87,   -87,   -87,   261,
     -87,   261,    48,    70,    82,   -87,    27,    27,   -87,   -87,
     287,   274,     7,     7,     7,     7,     7,     7,   -87,   114,
     -87,   -87,   261,    14,    14,   243,   253,    93,   -87,    87,
     -87,    14,   263,   -87
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       4,     0,     2,     1,    58,     3,     5,     6,     0,    61,
       0,     0,     9,     0,    11,     0,    13,     0,     8,    10,
      12,     0,    15,    18,    14,     7,     0,     0,     0,     0,
       0,     0,    16,     0,     0,    17,     0,     0,     0,    59,
       0,     0,     0,    50,    51,    48,    49,     0,    28,     0,
       0,    31,     0,    46,    53,    47,    60,    59,     0,     0,
      19,    29,     0,     0,     0,     0,     0,     0,     0,    45,
      47,    36,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    22,    20,    21,    30,
      54,    56,     0,     0,     0,    52,    32,    33,    34,    35,
      37,    38,    39,    40,    41,    42,    43,    44,    55,     0,
       8,     8,    57,    18,    18,     0,     0,    24,    26,     0,
       8,    18,     0,    25
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -87,   -87,   -87,   -87,   -86,   103,   -87,   -87,    85,   -87,
     -87,   -58,   -87,   -24,   -32,    62,   -22,   -87,     9,   -26,
      -5
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     1,     2,     5,    23,    25,     7,    13,    15,    16,
      19,    26,    35,    51,    52,    53,    54,    92,    27,    55,
      39
  };

  const unsigned char
  Parser::yytable_[] =
  {
      38,    58,    36,    10,    37,    56,    62,    63,    59,    66,
      67,     8,    22,     4,     9,    68,     3,    31,    71,     4,
      17,    64,    40,    70,   113,   114,    57,    18,    14,    57,
      17,     9,    89,    91,   121,    73,    74,    75,    76,    20,
      41,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    43,    44,   115,   116,    75,    76,     9,
      45,    46,    31,   122,    11,    47,    12,    48,   108,    21,
     109,    42,    60,    43,    44,    49,    61,   112,    50,     9,
      45,    46,    31,    65,    12,    47,    86,   110,    87,    38,
      38,    36,    36,    37,    37,    64,    38,    88,    36,   111,
      37,    43,    44,   119,   120,     6,    24,     9,    45,    46,
      31,    69,     0,    47,    90,     0,     0,     0,     0,     0,
       0,    43,    44,    49,     0,     0,    50,     9,    45,    46,
      31,     0,     0,    47,     0,     0,     0,     0,     0,    93,
       0,     0,     0,    49,     0,     0,    50,    73,    74,    75,
      76,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      94,     0,     0,     0,     0,     0,     0,     0,    73,    74,
      75,    76,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    95,     0,     0,     0,     0,     0,     0,     0,    73,
      74,    75,    76,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    72,     0,     0,     0,     0,     0,     0,    73,
      74,    75,    76,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     0,     0,     0,     0,     0,     0,    73,
      74,    75,    76,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    28,     0,    29,    30,     9,     0,     0,    31,
       0,    32,    28,     0,    29,    30,     9,    33,    34,    31,
       0,   117,    28,     0,    29,    30,     9,    33,    34,    31,
       0,   118,    28,     0,    29,    30,     9,    33,    34,    31,
       0,   123,     0,     0,     0,     0,     0,    33,    34,    73,
      74,    75,    76,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    73,    74,    75,    76,     0,    77,     0,    79,
      80,    81,    82,    83,    84,    73,    74,    75,    76,     0,
       0,     0,    79,    80,    81,    82,    83,    84
  };

  const signed char
  Parser::yycheck_[] =
  {
      26,    33,    26,     8,    26,    31,    26,    27,    34,    41,
      42,     2,    17,     5,    13,    47,     0,    16,    50,     5,
      11,    41,    27,    49,   110,   111,    31,    17,    20,    34,
      21,    13,    64,    65,   120,    28,    29,    30,    31,    20,
      19,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     7,     8,   113,   114,    30,    31,    13,
      14,    15,    16,   121,    19,    19,    21,    21,    20,    22,
      22,    19,    21,     7,     8,    29,    21,   109,    32,    13,
      14,    15,    16,    19,    21,    19,    21,    17,    21,   115,
     116,   115,   116,   115,   116,    41,   122,    21,   122,    17,
     122,     7,     8,    10,    17,     2,    21,    13,    14,    15,
      16,    49,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,     7,     8,    29,    -1,    -1,    32,    13,    14,    15,
      16,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    29,    -1,    -1,    32,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    21,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    21,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,     9,    -1,    11,    12,    13,    -1,    -1,    16,
      -1,    18,     9,    -1,    11,    12,    13,    24,    25,    16,
      -1,    18,     9,    -1,    11,    12,    13,    24,    25,    16,
      -1,    18,     9,    -1,    11,    12,    13,    24,    25,    16,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    28,    29,    30,    31,    -1,    33,    -1,    35,
      36,    37,    38,    39,    40,    28,    29,    30,    31,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    43,    44,     0,     5,    45,    47,    48,    60,    13,
      62,    19,    21,    49,    20,    50,    51,    60,    17,    52,
      20,    22,    62,    46,    50,    47,    53,    60,     9,    11,
      12,    16,    18,    24,    25,    54,    55,    58,    61,    62,
      62,    19,    19,     7,     8,    14,    15,    19,    21,    29,
      32,    55,    56,    57,    58,    61,    61,    62,    56,    61,
      21,    21,    26,    27,    41,    19,    56,    56,    56,    57,
      61,    56,    21,    28,    29,    30,    31,    33,    34,    35,
      36,    37,    38,    39,    40,    21,    21,    21,    21,    56,
      20,    56,    59,    20,    20,    20,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    20,    22,
      17,    17,    56,    46,    46,    53,    53,    18,    18,    10,
      17,    46,    53,    18
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    42,    43,    44,    44,    45,    45,    46,    46,    47,
      48,    49,    49,    50,    50,    51,    52,    53,    53,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      55,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    58,    58,    59,    59,    60,    61,
      61,    62
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     1,     1,     2,     0,     3,
       4,     2,     3,     1,     3,     2,     4,     2,     0,     2,
       3,     3,     3,     3,     8,    13,     8,     3,     2,     2,
       3,     1,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     4,     1,     3,     1,     1,
       2,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"newline\"", "BOOL", "INT",
  "VOID", "TRUE", "FALSE", "IF", "ELSE", "WHILE", "RETURN", "ID",
  "INTLITERAL", "STRINGLITERAL", "DEREF", "LCURLY", "RCURLY", "LPAREN",
  "RPAREN", "SEMICOLON", "COMMA", "DOT", "WRITE", "READ", "CROSSCROSS",
  "DASHDASH", "CROSS", "DASH", "STAR", "SLASH", "NOT", "AND", "OR",
  "EQUALS", "NOTEQUALS", "LESS", "GREATER", "LESSEQ", "GREATEREQ",
  "ASSIGN", "$accept", "program", "declList", "decl", "varDeclList",
  "varDecl", "fnDecl", "formals", "formalsList", "formalDecl", "fnBody",
  "stmtList", "stmt", "assignExp", "exp", "term", "fncall", "actualList",
  "type", "loc", "id", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   169,   169,   176,   182,   188,   191,   196,   199,   205,
     211,   218,   220,   226,   230,   237,   242,   247,   250,   255,
     257,   259,   261,   263,   265,   267,   269,   271,   273,   275,
     280,   285,   287,   289,   291,   293,   295,   297,   299,   301,
     303,   305,   307,   309,   311,   313,   315,   320,   322,   324,
     326,   328,   330,   332,   337,   339,   344,   346,   351,   367,
     369,   373
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
    };
    const unsigned int user_token_number_max_ = 296;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "lake.yy" // lalr1.cc:1167
} // lake
#line 1493 "parser.cc" // lalr1.cc:1167
#line 374 "lake.yy" // lalr1.cc:1168


void
lake::Parser::error(const std::string &err_message ) {
   std::cerr << "Error: " << err_message << "\n";
}
