
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* First part of user declarations.  */




#include "parser.hh"

/* User implementation prologue.  */


/* Unqualified %code blocks.  */


#include "core/driver.h"




#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace clever {

#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  Parser::Parser (Driver& driver_yyarg, ScannerState& state_yyarg, Compiler& c_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg),
      state (state_yyarg),
      c (c_yyarg)
  {
  }

  Parser::~Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
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
#endif

  int
  Parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
{
yylloc.begin.filename = yylloc.end.filename = driver.getFile();
}


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc, driver, state);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

    { c.init(driver.getFile()); }
    break;

  case 3:

    { c.setAST((yysemantic_stack_[(2) - (2)].block)); }
    break;

  case 4:

    { (yyval.block) = new ast::Block(yyloc); }
    break;

  case 5:

    { (yysemantic_stack_[(2) - (1)].block)->append((yysemantic_stack_[(2) - (2)].node));       }
    break;

  case 26:

    { (yyval.block) = (yysemantic_stack_[(3) - (2)].block); }
    break;

  case 27:

    { (yyval.inst) = new ast::Instantiation((yysemantic_stack_[(3) - (1)].type), NULL, yyloc); }
    break;

  case 28:

    { (yyval.inst) = new ast::Instantiation((yysemantic_stack_[(6) - (1)].type), (yysemantic_stack_[(6) - (5)].narray),   yyloc); }
    break;

  case 29:

    { (yyval.break_) = new ast::Break(yyloc); }
    break;

  case 30:

    { (yyval.continue_) = new ast::Continue(yyloc); }
    break;

  case 31:

    {
#ifndef CLEVER_THREADS
		error(yyloc, "Cannot use process block syntax, threads is disabled!"); YYABORT;
#else
		(yyval.threadblock) = new ast::ThreadBlock((yysemantic_stack_[(3) - (3)].block), (yysemantic_stack_[(3) - (2)].ident), yyloc);
#endif
	}
    break;

  case 32:

    {
#ifndef CLEVER_THREADS
		error(yyloc, "Cannot use process block syntax, threads is disabled!"); YYABORT;
#else
		(yyval.threadblock) = new ast::ThreadBlock((yysemantic_stack_[(6) - (6)].block), (yysemantic_stack_[(6) - (2)].ident), (yysemantic_stack_[(6) - (4)].node), yyloc);
#endif
	}
    break;

  case 33:

    {
#ifndef CLEVER_THREADS
		error(yyloc, "Cannot use critical block syntax, threads is disabled!"); YYABORT;
#else
		(yyval.criticalblock) = new ast::CriticalBlock((yysemantic_stack_[(2) - (2)].block), yyloc);
#endif
	}
    break;

  case 44:

    { (yyval.node) = (yysemantic_stack_[(3) - (2)].node); }
    break;

  case 61:

    { (yysemantic_stack_[(1) - (1)].property)->setWriteMode(); }
    break;

  case 63:

    { (yyval.node) = new ast::Subscript((yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (3)].node), yyloc); }
    break;

  case 64:

    { (yyval.node) = new ast::Arithmetic(ast::Arithmetic::MOP_SUB, new ast::IntLit(0, yyloc), (yysemantic_stack_[(2) - (2)].node), yyloc); }
    break;

  case 65:

    { (yyval.node) = new ast::Arithmetic(ast::Arithmetic::MOP_ADD, new ast::IntLit(0, yyloc), (yysemantic_stack_[(2) - (2)].node), yyloc); }
    break;

  case 66:

    { (yyval.node) = new ast::Boolean(ast::Boolean::BOP_NOT, (yysemantic_stack_[(2) - (2)].node), yyloc);                                  }
    break;

  case 67:

    { (yyval.node) = new ast::Bitwise(ast::Bitwise::BOP_NOT, (yysemantic_stack_[(2) - (2)].node), yyloc);                                  }
    break;

  case 68:

    { (yyval.class_) = new ast::ClassDef((yysemantic_stack_[(6) - (2)].type), (yysemantic_stack_[(6) - (4)].narray), (yysemantic_stack_[(6) - (5)].narray), yyloc); }
    break;

  case 69:

    { (yyval.narray) = NULL; }
    break;

  case 71:

    { (yyval.narray) = new ast::NodeArray(yyloc); }
    break;

  case 72:

    { (yyval.narray) = (yysemantic_stack_[(3) - (1)].narray); }
    break;

  case 73:

    { (yyval.narray) = (yysemantic_stack_[(1) - (1)].narray); }
    break;

  case 75:

    { (yyval.narray) = (yysemantic_stack_[(1) - (0)].narray); }
    break;

  case 77:

    { (yyval.narray) = (yysemantic_stack_[(1) - (0)].narray); }
    break;

  case 87:

    { (yysemantic_stack_[(1) - (0)].narray)->append((yysemantic_stack_[(1) - (1)].attr)); }
    break;

  case 88:

    { (yysemantic_stack_[(3) - (0)].narray)->append((yysemantic_stack_[(3) - (3)].attr)); }
    break;

  case 89:

    { (yyval.attr) = new ast::AttrDecl((yysemantic_stack_[(3) - (1)].ident), (yysemantic_stack_[(3) - (3)].node), false, yyloc); }
    break;

  case 90:

    { (yyval.attr) = new ast::AttrDecl((yysemantic_stack_[(1) - (1)].ident), NULL, false, yyloc);     }
    break;

  case 91:

    { (yyval.narray) = new ast::NodeArray(yyloc); (yyval.narray)->append((yysemantic_stack_[(1) - (1)].attr)); }
    break;

  case 92:

    { (yysemantic_stack_[(3) - (1)].narray)->append((yysemantic_stack_[(3) - (3)].attr)); }
    break;

  case 93:

    { (yyval.attr) = new ast::AttrDecl((yysemantic_stack_[(3) - (1)].ident), (yysemantic_stack_[(3) - (3)].node), true, yyloc);   }
    break;

  case 94:

    { (yyval.narray) = NULL; }
    break;

  case 96:

    { (yyval.narray) = new ast::NodeArray(yyloc); (yyval.narray)->append((yysemantic_stack_[(1) - (1)].fdecl)); }
    break;

  case 97:

    { (yysemantic_stack_[(2) - (1)].narray)->append((yysemantic_stack_[(2) - (2)].fdecl)); }
    break;

  case 98:

    { (yyval.inst) = new ast::Instantiation(CSTRING("Array"), (yysemantic_stack_[(3) - (2)].narray), yyloc); }
    break;

  case 99:

    { (yyval.narray) = new ast::NodeArray(yyloc); (yyval.narray)->append((yysemantic_stack_[(3) - (1)].strlit)); (yyval.narray)->append((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 100:

    { (yysemantic_stack_[(5) - (1)].narray)->append((yysemantic_stack_[(5) - (3)].strlit)); (yysemantic_stack_[(5) - (1)].narray)->append((yysemantic_stack_[(5) - (5)].node));                                 }
    break;

  case 101:

    { (yyval.inst) = new ast::Instantiation(CSTRING("Map"), NULL, yyloc); }
    break;

  case 102:

    { (yyval.inst) = new ast::Instantiation(CSTRING("Map"), (yysemantic_stack_[(3) - (2)].narray), yyloc);   }
    break;

  case 103:

    { (yyval.throw_) = new ast::Throw((yysemantic_stack_[(2) - (2)].node), yyloc); }
    break;

  case 105:

    { (yyval.narray) = new ast::NodeArray(yyloc); (yyval.narray)->append((yysemantic_stack_[(1) - (1)].catch_)); }
    break;

  case 106:

    { (yysemantic_stack_[(2) - (1)].narray)->append((yysemantic_stack_[(2) - (2)].catch_));                                 }
    break;

  case 107:

    { (yyval.catch_) = new ast::Catch((yysemantic_stack_[(5) - (3)].ident), (yysemantic_stack_[(5) - (5)].block), yyloc); }
    break;

  case 108:

    { (yyval.block) = NULL; }
    break;

  case 109:

    { (yyval.block) = (yysemantic_stack_[(2) - (2)].block);   }
    break;

  case 110:

    { (yyval.except) = new ast::Try((yysemantic_stack_[(4) - (2)].block), (yysemantic_stack_[(4) - (3)].narray), (yysemantic_stack_[(4) - (4)].block), yyloc); }
    break;

  case 111:

    { (yyval.property) = new ast::Property((yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].ident), yyloc); }
    break;

  case 112:

    { (yyval.property) = new ast::Property((yysemantic_stack_[(3) - (1)].type), (yysemantic_stack_[(3) - (3)].ident), yyloc); }
    break;

  case 113:

    { (yyval.property) = new ast::Property((yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].ident), yyloc); }
    break;

  case 114:

    { (yyval.property) = new ast::Property((yysemantic_stack_[(3) - (1)].type), (yysemantic_stack_[(3) - (3)].ident), yyloc); }
    break;

  case 115:

    { (yyval.mcall) = (yysemantic_stack_[(0) - (0)].mcall); }
    break;

  case 116:

    { (yyval.mcall) = new ast::MethodCall((yysemantic_stack_[(6) - (0)].node), (yysemantic_stack_[(6) - (3)].ident), (yysemantic_stack_[(6) - (5)].narray), yyloc); }
    break;

  case 117:

    { (yyval.property) = new ast::Property((yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].ident), yyloc); }
    break;

  case 118:

    { (yyval.property) = new ast::Property((yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].ident), yyloc); (yyval.property)->setStatic(); }
    break;

  case 119:

    { (yyval.node) = new ast::MethodCall((yysemantic_stack_[(6) - (1)].node), (yysemantic_stack_[(6) - (3)].ident), (yysemantic_stack_[(6) - (5)].narray), yyloc); }
    break;

  case 120:

    { (yyval.node) = (yysemantic_stack_[(8) - (8)].node); }
    break;

  case 121:

    { (yyval.node) = new ast::MethodCall((yysemantic_stack_[(6) - (1)].type), (yysemantic_stack_[(6) - (3)].ident), (yysemantic_stack_[(6) - (5)].narray), yyloc); }
    break;

  case 122:

    { (yyval.node) = (yysemantic_stack_[(8) - (8)].node); }
    break;

  case 123:

    { (yyval.inc_dec) = new ast::IncDec(ast::IncDec::POS_INC, (yysemantic_stack_[(2) - (1)].node), yyloc); }
    break;

  case 124:

    { (yyval.inc_dec) = new ast::IncDec(ast::IncDec::POS_DEC, (yysemantic_stack_[(2) - (1)].node), yyloc); }
    break;

  case 125:

    { (yyval.inc_dec) = new ast::IncDec(ast::IncDec::PRE_INC, (yysemantic_stack_[(2) - (2)].node), yyloc); }
    break;

  case 126:

    { (yyval.inc_dec) = new ast::IncDec(ast::IncDec::PRE_DEC, (yysemantic_stack_[(2) - (2)].node), yyloc); }
    break;

  case 127:

    { (yyval.comp) = new ast::Comparison(ast::Comparison::COP_EQUAL,   (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 128:

    { (yyval.comp) = new ast::Comparison(ast::Comparison::COP_NEQUAL,  (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 129:

    { (yyval.comp) = new ast::Comparison(ast::Comparison::COP_GREATER, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 130:

    { (yyval.comp) = new ast::Comparison(ast::Comparison::COP_GEQUAL,  (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 131:

    { (yyval.comp) = new ast::Comparison(ast::Comparison::COP_LESS,    (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 132:

    { (yyval.comp) = new ast::Comparison(ast::Comparison::COP_LEQUAL,  (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 133:

    { (yyval.boolean) = new ast::Boolean(ast::Boolean::BOP_OR, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc);  }
    break;

  case 134:

    { (yyval.boolean) = new ast::Boolean(ast::Boolean::BOP_AND, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 135:

    { (yyval.logic) = new ast::Logic(ast::Logic::LOP_OR, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc);      }
    break;

  case 136:

    { (yyval.logic) = new ast::Logic(ast::Logic::LOP_AND, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc);     }
    break;

  case 137:

    { (yyval.arithmetic) = new ast::Arithmetic(ast::Arithmetic::MOP_ADD, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 138:

    { (yyval.arithmetic) = new ast::Arithmetic(ast::Arithmetic::MOP_SUB, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 139:

    { (yyval.arithmetic) = new ast::Arithmetic(ast::Arithmetic::MOP_MUL, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 140:

    { (yyval.arithmetic) = new ast::Arithmetic(ast::Arithmetic::MOP_DIV, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 141:

    { (yyval.arithmetic) = new ast::Arithmetic(ast::Arithmetic::MOP_MOD, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 142:

    { (yyval.bitwise) = new ast::Bitwise(ast::Bitwise::BOP_AND, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc);    }
    break;

  case 143:

    { (yyval.bitwise) = new ast::Bitwise(ast::Bitwise::BOP_OR, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc);     }
    break;

  case 144:

    { (yyval.bitwise) = new ast::Bitwise(ast::Bitwise::BOP_XOR, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc);    }
    break;

  case 145:

    { (yyval.bitwise) = new ast::Bitwise(ast::Bitwise::BOP_LSHIFT, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 146:

    { (yyval.bitwise) = new ast::Bitwise(ast::Bitwise::BOP_RSHIFT, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 147:

    { (yyval.narray) = (yysemantic_stack_[(2) - (2)].narray); }
    break;

  case 148:

    { (yyval.narray) = (yysemantic_stack_[(2) - (2)].narray); }
    break;

  case 149:

    { (yyval.narray) = new ast::NodeArray(yyloc); (yyval.narray)->append((yysemantic_stack_[(1) - (1)].vardecl)); }
    break;

  case 150:

    { (yysemantic_stack_[(3) - (1)].narray)->append((yysemantic_stack_[(3) - (3)].vardecl)); }
    break;

  case 151:

    { (yyval.vardecl) = new ast::VariableDecl((yysemantic_stack_[(3) - (1)].ident), new ast::Assignment((yysemantic_stack_[(3) - (1)].ident), (yysemantic_stack_[(3) - (3)].node), yyloc), false, yyloc); }
    break;

  case 152:

    { (yyval.vardecl) = new ast::VariableDecl((yysemantic_stack_[(1) - (1)].ident), new ast::Assignment((yysemantic_stack_[(1) - (1)].ident), NULL, yyloc), false, yyloc); }
    break;

  case 153:

    { (yyval.narray) = new ast::NodeArray(yyloc); (yyval.narray)->append((yysemantic_stack_[(1) - (1)].vardecl)); }
    break;

  case 154:

    { (yysemantic_stack_[(3) - (1)].narray)->append((yysemantic_stack_[(3) - (3)].vardecl)); }
    break;

  case 155:

    { (yyval.vardecl) = new ast::VariableDecl((yysemantic_stack_[(3) - (1)].ident), new ast::Assignment((yysemantic_stack_[(3) - (1)].ident), (yysemantic_stack_[(3) - (3)].node), yyloc), true, yyloc); }
    break;

  case 156:

    { (yyval.assignment) = new ast::Assignment((yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node), yyloc); }
    break;

  case 157:

    { (yyval.ident) = (yysemantic_stack_[(1) - (1)].ident); }
    break;

  case 158:

    { (yysemantic_stack_[(3) - (1)].ident)->append('.', (yysemantic_stack_[(3) - (3)].ident)); (yyval.ident) = (yysemantic_stack_[(3) - (1)].ident); }
    break;

  case 159:

    { (yyval.import) = new ast::Import((yysemantic_stack_[(4) - (2)].ident), yyloc);     }
    break;

  case 160:

    { (yyval.import) = new ast::Import((yysemantic_stack_[(4) - (2)].ident), yyloc);     }
    break;

  case 161:

    { (yyval.import) = new ast::Import((yysemantic_stack_[(4) - (2)].ident), (yysemantic_stack_[(4) - (4)].ident), yyloc); }
    break;

  case 162:

    { (yyval.import) = new ast::Import((yysemantic_stack_[(4) - (2)].ident), (yysemantic_stack_[(4) - (4)].type), yyloc); }
    break;

  case 163:

    { (yyval.import) = new ast::Import((yysemantic_stack_[(2) - (2)].ident), yyloc); (yyval.import)->setNamespaced(true); }
    break;

  case 164:

    { (yyval.vardecl) = new ast::VariableDecl((yysemantic_stack_[(4) - (1)].ident), new ast::Assignment((yysemantic_stack_[(4) - (1)].ident), NULL, yyloc), false, yyloc); }
    break;

  case 165:

    { (yyval.fdecl) = new ast::FunctionDecl((yysemantic_stack_[(5) - (2)].ident), NULL, (yysemantic_stack_[(5) - (5)].block), NULL, false, yyloc); }
    break;

  case 166:

    { (yyval.fdecl) = new ast::FunctionDecl((yysemantic_stack_[(5) - (2)].type), NULL, (yysemantic_stack_[(5) - (5)].block), NULL, yyloc); }
    break;

  case 167:

    { (yyval.fdecl) = new ast::FunctionDecl((yysemantic_stack_[(6) - (2)].ident), NULL, (yysemantic_stack_[(6) - (6)].block), (yysemantic_stack_[(6) - (4)].vardecl), false, yyloc); }
    break;

  case 168:

    { (yyval.fdecl) = new ast::FunctionDecl((yysemantic_stack_[(6) - (2)].type), NULL, (yysemantic_stack_[(6) - (6)].block), (yysemantic_stack_[(6) - (4)].vardecl), yyloc); }
    break;

  case 169:

    { (yyval.fdecl) = new ast::FunctionDecl((yysemantic_stack_[(6) - (2)].ident), (yysemantic_stack_[(6) - (4)].narray), (yysemantic_stack_[(6) - (6)].block), NULL, false, yyloc); }
    break;

  case 170:

    { (yyval.fdecl) = new ast::FunctionDecl((yysemantic_stack_[(6) - (2)].type), (yysemantic_stack_[(6) - (4)].narray), (yysemantic_stack_[(6) - (6)].block), NULL, yyloc); }
    break;

  case 171:

    { (yyval.fdecl) = new ast::FunctionDecl((yysemantic_stack_[(8) - (2)].ident), (yysemantic_stack_[(8) - (4)].narray), (yysemantic_stack_[(8) - (8)].block), (yysemantic_stack_[(8) - (6)].vardecl), false, yyloc); }
    break;

  case 172:

    { (yyval.fdecl) = new ast::FunctionDecl((yysemantic_stack_[(8) - (2)].type), (yysemantic_stack_[(8) - (4)].narray), (yysemantic_stack_[(8) - (8)].block), (yysemantic_stack_[(8) - (6)].vardecl), yyloc); }
    break;

  case 173:

    { (yyval.fdecl) = new ast::FunctionDecl(NULL, NULL, (yysemantic_stack_[(4) - (4)].block), NULL, true, yyloc); }
    break;

  case 174:

    { (yyval.fdecl) = new ast::FunctionDecl(NULL, NULL, (yysemantic_stack_[(5) - (5)].block), (yysemantic_stack_[(5) - (3)].vardecl), true, yyloc); }
    break;

  case 175:

    { (yyval.fdecl) = new ast::FunctionDecl(NULL, (yysemantic_stack_[(5) - (3)].narray), (yysemantic_stack_[(5) - (5)].block), NULL, true, yyloc); }
    break;

  case 176:

    { (yyval.fdecl) = new ast::FunctionDecl(NULL, (yysemantic_stack_[(7) - (3)].narray), (yysemantic_stack_[(7) - (7)].block), (yysemantic_stack_[(7) - (5)].vardecl), true, yyloc); }
    break;

  case 177:

    { (yyval.narray) = NULL; }
    break;

  case 179:

    { (yyval.narray) = new ast::NodeArray(yyloc); (yyval.narray)->append((yysemantic_stack_[(1) - (1)].node)); }
    break;

  case 180:

    { (yysemantic_stack_[(3) - (1)].narray)->append((yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 181:

    { (yyval.fcall) = (yysemantic_stack_[(0) - (0)].fcall); }
    break;

  case 182:

    { (yyval.fcall) = new ast::FunctionCall((yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (3)].narray), yyloc); }
    break;

  case 184:

    { (yysemantic_stack_[(3) - (1)].ident)->append(':', (yysemantic_stack_[(3) - (3)].ident)); (yyval.ident) = (yysemantic_stack_[(3) - (1)].ident); }
    break;

  case 185:

    { (yysemantic_stack_[(6) - (1)].ident)->append(':', (yysemantic_stack_[(6) - (3)].ident)); (yyval.fcall) = new ast::FunctionCall((yysemantic_stack_[(6) - (1)].ident), (yysemantic_stack_[(6) - (5)].narray), yyloc); }
    break;

  case 186:

    { (yyval.fcall) = (yysemantic_stack_[(8) - (8)].fcall); }
    break;

  case 187:

    { (yysemantic_stack_[(5) - (1)].ident)->append(':', (yysemantic_stack_[(5) - (3)].type)); (yyval.inst) = new ast::Instantiation((yysemantic_stack_[(5) - (1)].ident), NULL, yyloc); }
    break;

  case 188:

    { (yysemantic_stack_[(8) - (1)].ident)->append(':', (yysemantic_stack_[(8) - (3)].type)); (yyval.inst) = new ast::Instantiation((yysemantic_stack_[(8) - (1)].ident), (yysemantic_stack_[(8) - (7)].narray),   yyloc); }
    break;

  case 189:

    { (yyval.fcall) = new ast::FunctionCall((yysemantic_stack_[(4) - (1)].ident), (yysemantic_stack_[(4) - (3)].narray), yyloc); }
    break;

  case 190:

    { (yyval.fcall) = (yysemantic_stack_[(6) - (6)].fcall); }
    break;

  case 191:

    { (yyval.ret) = new ast::Return((yysemantic_stack_[(2) - (2)].node), yyloc); }
    break;

  case 192:

    { (yyval.ret) = new ast::Return(NULL, yyloc); }
    break;

  case 193:

    { (yyval.while_loop) = new ast::While((yysemantic_stack_[(5) - (3)].node), (yysemantic_stack_[(5) - (5)].block), yyloc); }
    break;

  case 195:

    { (yysemantic_stack_[(6) - (0)].ifcond)->addConditional((yysemantic_stack_[(6) - (4)].node), (yysemantic_stack_[(6) - (6)].block)); }
    break;

  case 196:

    { (yyval.ifcond) = (yysemantic_stack_[(0) - (0)].ifcond); }
    break;

  case 197:

    { (yysemantic_stack_[(2) - (0)].ifcond)->setElseNode((yysemantic_stack_[(2) - (2)].node)); (yyval.ifcond) = (yysemantic_stack_[(2) - (0)].ifcond); }
    break;

  case 198:

    { (yyval.ifcond) = new ast::If((yysemantic_stack_[(5) - (3)].node), (yysemantic_stack_[(5) - (5)].node), yyloc); }
    break;

  case 199:

    { (yyval.ifcond) = (yysemantic_stack_[(7) - (6)].ifcond); }
    break;

  case 200:

    { (yyval.ifcond) = (yysemantic_stack_[(9) - (9)].ifcond); }
    break;



	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
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

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int Parser::yypact_ninf_ = -229;
  const short int
  Parser::yypact_[] =
  {
      -229,    15,  -229,  -229,   184,    14,   -20,   125,  -229,  -229,
    -229,   -15,    13,  -229,    76,   260,  -229,  -229,    48,   171,
     116,    54,   272,   272,  -229,    54,   260,  -229,  -229,   120,
     260,    35,   260,  -229,  -229,    55,    86,    95,  -229,  -229,
     128,   112,   114,  -229,  -229,  -229,    97,  -229,   145,   106,
     124,   140,   157,   159,  -229,    73,   165,   166,   169,  -229,
    -229,   143,   164,  -229,    51,   260,   260,   260,  -229,    63,
     172,   260,   260,   260,   260,    35,  -229,   128,   564,   162,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,   188,   193,  -229,   177,   178,   132,  -229,  -229,   192,
     200,   207,   207,   224,   564,   210,   564,   197,   227,   225,
     217,    25,   104,   412,  -229,  -229,  -229,  -229,  -229,    46,
     260,   260,  -229,  -229,  -229,  -229,  -229,  -229,   203,  -229,
    -229,  -229,   260,    14,   216,   228,  -229,   226,   433,   488,
      18,    29,     6,  -229,  -229,  -229,  -229,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,    48,     8,
       9,   260,  -229,    49,    50,   232,   244,   224,  -229,     7,
    -229,   260,   260,  -229,  -229,   293,  -229,  -229,   233,  -229,
     564,   335,   245,   237,   564,  -229,   260,   260,  -229,    54,
      54,  -229,  -229,  -229,  -229,  -229,    60,    54,   -40,   238,
      24,    24,    24,    24,   195,   195,   271,   271,   652,   585,
     620,   640,   675,   707,   730,   151,   151,  -229,  -229,  -229,
     564,  -229,    54,    52,   239,    54,   103,   240,   356,  -229,
    -229,   313,    54,  -229,  -229,   278,    79,    90,   564,   564,
     262,   260,  -229,   274,   260,   251,   263,  -229,  -229,  -229,
     276,  -229,   337,    54,    54,  -229,   337,    54,    54,  -229,
     337,    54,    54,    54,   268,  -229,   281,   278,  -229,    90,
    -229,  -229,   282,   260,   270,   280,   283,  -229,  -229,   285,
    -229,   297,   286,  -229,  -229,   287,  -229,  -229,   288,  -229,
    -229,  -229,    54,  -229,  -229,   300,   372,   373,  -229,   564,
    -229,   260,  -229,  -229,   260,   368,  -229,    54,    54,    54,
    -229,  -229,   325,   327,  -229,   328,   330,  -229,  -229,   307,
    -229,   326,   315,   317,   382,  -229,  -229,  -229,   158,   372,
     158,   373,   326,  -229,   285,    57,  -229,   260,    54,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,  -229,   324,  -229,   509,  -229,   260,    54,   329,  -229,
    -229
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         2,     0,     4,     1,     3,     0,     0,    34,    37,    38,
      36,     0,     0,    29,     0,   192,    40,    41,     0,     0,
       0,     0,     0,     0,    39,     0,     0,    30,    35,     0,
     177,     4,     0,     5,    16,     0,     0,     0,    17,    18,
       0,     0,    45,    23,    43,    42,     0,    22,    46,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,    14,
      13,   152,   147,   149,     0,   177,     0,     0,   157,   163,
       0,     0,     0,     0,     0,     0,    57,    47,   191,     0,
      48,    58,    54,    53,    52,    50,    49,    51,    56,    59,
      55,     0,   148,   153,     0,     0,     0,     4,    33,     0,
      34,   125,   126,     0,   103,     0,   179,     0,   178,     0,
       0,     0,     0,     0,    25,    20,    21,   123,   124,     0,
       0,     0,    19,    10,    15,     7,     8,     6,     0,    24,
       9,    12,     0,     0,   112,    27,   114,     0,     0,     0,
       0,     0,     0,    64,    65,    66,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,   108,   104,   105,    69,
      98,     0,     0,   101,    26,     0,   102,    44,   111,   113,
     156,     0,     0,   184,   151,   150,   177,   177,   189,     0,
       0,   162,   161,   160,   158,   159,   152,     0,     0,     0,
     132,   130,   131,   129,   146,   145,   127,   128,   133,   135,
     134,   136,   143,   144,   142,   138,   137,   139,   140,   141,
     155,   154,     0,     0,     0,     0,     0,     0,     0,   112,
     111,     0,     0,   110,   106,    94,    70,     0,   180,    99,
       0,   177,    63,     0,   177,     0,     0,   181,   193,   198,
       0,   173,     0,     0,     0,   166,     0,     0,     0,   165,
       0,     0,     0,     0,     0,   109,     0,    95,    96,     0,
      75,    77,     0,     0,     0,   187,     0,   121,    28,   190,
     194,     0,     0,   175,   174,     0,   170,   168,     0,   169,
     167,    32,     0,    68,    97,     0,     0,     0,    72,   100,
     119,   177,   185,   115,   177,   199,   164,     0,     0,     0,
     107,    74,    90,    76,    87,     0,    78,    91,   115,     0,
     181,   122,     0,     0,   196,   176,   172,   171,     0,     0,
       0,     0,   120,   188,   186,     0,   182,     0,     0,   200,
      79,    82,    83,    81,    85,    86,    84,    80,    89,    88,
      93,    92,   117,   118,     0,   197,   177,     0,     0,   195,
     116
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
      -229,  -229,  -229,   402,  -229,   -21,    -1,  -229,  -229,  -229,
    -229,    -2,   -14,     1,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,   126,  -229,  -229,    67,  -229,    69,  -229,    68,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,   234,  -229,  -229,
    -229,    82,     2,  -229,  -229,     3,  -229,  -229,  -229,  -229,
    -229,  -229,   -96,  -108,  -229,   246,  -229,  -229,  -229,  -143,
    -228,  -229,   -41,  -229,    85,  -229,     4,  -229,     5,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,     1,     2,   111,    33,    34,    76,    36,    37,    38,
      39,    77,   106,    79,    42,    80,    43,   245,   246,   247,
     279,   282,   306,   307,   358,   323,   324,   326,   327,   276,
     277,    44,   112,    45,    46,   176,   177,   178,   243,    47,
      48,   331,    81,   328,   313,    82,    83,    84,    85,    86,
      87,    51,    62,    63,    92,    93,    52,    69,    53,   209,
      54,    88,   107,   108,   289,    55,    89,   330,    90,   257,
      58,    59,   315,   349,    60,   290,   334
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int Parser::yytable_ninf_ = -184;
  const short int
  Parser::yytable_[] =
  {
        98,    78,    40,    35,   103,    41,    49,    50,    56,    57,
     -71,   206,   104,   206,   206,     3,   262,   278,   113,    61,
     101,   102,   201,   202,   137,   195,   234,   237,     5,     6,
       7,     8,     9,    10,   204,    11,    12,   263,  -184,  -184,
    -184,  -184,   151,   109,   152,    64,   208,    13,   -71,   304,
      14,   188,   138,   139,   239,   240,   134,   143,   144,   145,
     146,    66,   362,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   233,   236,   172,    25,    26,    27,    28,
      29,    68,   -73,   207,   203,   232,   235,   162,   163,    67,
     164,   165,   166,   280,   110,   205,    30,    31,   184,   135,
     189,    32,    91,   136,   189,   136,   190,   191,   266,    40,
      35,   363,    41,    49,    50,    56,    57,   132,   194,   292,
     -73,    96,   140,   295,   105,   260,    97,   298,   141,   267,
     114,   281,   128,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   195,   255,   256,   238,   195,   270,
     185,   115,   195,   350,   351,   352,   353,   248,   249,   120,
     116,   -62,   122,   117,   118,    94,    95,   186,   258,   259,
     271,   123,   -60,   121,  -183,   -62,   261,     5,     6,     7,
       8,     9,    10,   119,    11,    12,   -60,   354,   355,   124,
     132,    65,   -61,   171,    97,   356,    13,   192,   193,    14,
     284,   265,   357,   286,   269,   125,   -61,   164,   165,   166,
     133,   275,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   126,   121,   127,    25,    26,    27,    28,    29,
     129,   130,   293,   294,   131,   167,   296,   297,   142,   168,
     299,   300,   301,   169,   170,    30,    31,   173,   162,   163,
      32,   164,   165,   166,     6,     7,     8,     9,    10,   309,
     329,   -60,   174,   332,   175,   180,    99,   100,     8,     9,
      10,   320,   179,   181,   182,   147,   148,   149,   150,   151,
     183,   152,   196,   242,  -184,  -184,   335,   336,   337,    16,
      17,   250,    70,   198,   197,    22,    23,    24,   241,   251,
     253,    16,    17,   254,    28,   264,   268,   272,   274,    24,
      19,   283,   285,    71,    72,   368,    28,   365,   287,    73,
      74,    30,    75,   364,   162,   163,    32,   164,   165,   166,
     288,   291,   206,    30,    75,   302,   369,   310,    32,   147,
     148,   149,   150,   151,   303,   152,   311,   308,   153,   154,
     312,   314,   316,   317,   318,   319,   155,   156,   157,   158,
     147,   148,   149,   150,   151,   321,   152,   322,   325,   153,
     154,   333,   338,   339,   343,   340,   341,   155,   156,   157,
     158,   345,   346,   347,   348,   159,   160,   161,   162,   163,
     366,   164,   165,   166,     4,   305,   370,   360,   359,   361,
     342,   244,     0,   252,   231,   344,   159,   160,   161,   162,
     163,     0,   164,   165,   166,     0,   147,   148,   149,   150,
     151,     0,   152,     0,   273,   153,   154,     0,     0,     0,
       0,     0,     0,   155,   156,   157,   158,   147,   148,   149,
     150,   151,     0,   152,     0,     0,   153,   154,     0,     0,
       0,     0,     0,     0,   155,   156,   157,   158,     0,     0,
       0,     0,   159,   160,   161,   162,   163,     0,   164,   165,
     166,     0,     0,     0,     0,     0,     0,     0,     0,   187,
       0,     0,     0,   159,   160,   161,   162,   163,     0,   164,
     165,   166,   147,   148,   149,   150,   151,     0,   152,     0,
     199,   153,   154,     0,     0,     0,     0,     0,     0,   155,
     156,   157,   158,   147,   148,   149,   150,   151,     0,   152,
       0,     0,   153,   154,     0,     0,     0,     0,     0,     0,
     155,   156,   157,   158,     0,     0,     0,     0,   159,   160,
     161,   162,   163,     0,   164,   165,   166,     0,     0,     0,
       0,     0,     0,     0,     0,   200,     0,     0,     0,   159,
     160,   161,   162,   163,     0,   164,   165,   166,   147,   148,
     149,   150,   151,     0,   152,     0,   367,   153,   154,     0,
       0,     0,     0,     0,     0,   155,   156,   157,   158,   147,
     148,   149,   150,   151,     0,   152,     0,     0,   153,   154,
       0,     0,     0,     0,     0,     0,   155,     0,   157,   158,
       0,     0,     0,     0,   159,   160,   161,   162,   163,     0,
     164,   165,   166,     0,   147,   148,   149,   150,   151,     0,
     152,     0,     0,   153,   154,   159,   160,   161,   162,   163,
       0,   164,   165,   166,   147,   148,   149,   150,   151,     0,
     152,     0,     0,   153,   154,     0,   147,   148,   149,   150,
     151,   155,   152,   157,     0,   153,   154,     0,     0,     0,
     159,   160,   161,   162,   163,   157,   164,   165,   166,   147,
     148,   149,   150,   151,     0,   152,     0,     0,   153,   154,
     159,   160,   161,   162,   163,     0,   164,   165,   166,     0,
       0,     0,   159,   160,   161,   162,   163,     0,   164,   165,
     166,   147,   148,   149,   150,   151,     0,   152,     0,     0,
     153,   154,     0,     0,     0,     0,   160,   161,   162,   163,
       0,   164,   165,   166,   147,   148,   149,   150,   151,     0,
     152,     0,     0,   153,   154,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   161,
     162,   163,     0,   164,   165,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   162,   163,     0,   164,   165,   166
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
        21,    15,     4,     4,    25,     4,     4,     4,     4,     4,
       3,     5,    26,     5,     5,     0,    56,   245,    32,     5,
      22,    23,     4,     5,    65,   133,   169,   170,     3,     4,
       5,     6,     7,     8,     5,    10,    11,    77,    14,    15,
      16,    17,    18,     8,    20,    65,   142,    22,    41,   277,
      25,     5,    66,    67,     5,     5,     5,    71,    72,    73,
      74,    76,     5,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,   169,   170,    96,    51,    52,    53,    54,
      55,     5,     3,    77,    66,    77,    77,    63,    64,    76,
      66,    67,    68,     3,    59,    66,    71,    72,    73,    48,
      54,    76,    54,    54,    54,    54,   120,   121,    56,   111,
     111,    54,   111,   111,   111,   111,   111,    57,   132,   262,
      41,     5,    59,   266,     4,    65,    72,   270,    65,    77,
      75,    41,    59,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   262,   196,   197,   171,   266,    56,
      56,    75,   270,     5,     6,     7,     8,   181,   182,    57,
      75,    57,    75,    45,    46,     4,     5,    73,   199,   200,
      77,    75,    57,    71,    59,    71,   207,     3,     4,     5,
       6,     7,     8,    65,    10,    11,    71,    39,    40,    75,
      57,    76,    57,    71,    72,    47,    22,     4,     5,    25,
     251,   232,    54,   254,   235,    75,    71,    66,    67,    68,
      56,   242,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    75,    71,    75,    51,    52,    53,    54,    55,
      75,    75,   263,   264,    75,    57,   267,   268,    76,    56,
     271,   272,   273,    76,    76,    71,    72,    65,    63,    64,
      76,    66,    67,    68,     4,     5,     6,     7,     8,   283,
     311,    71,    65,   314,    50,    78,     4,     5,     6,     7,
       8,   302,    72,    56,    59,    14,    15,    16,    17,    18,
      73,    20,    76,    49,    23,    24,   317,   318,   319,    39,
      40,     8,    42,    77,    76,    45,    46,    47,    76,    76,
      65,    39,    40,    76,    54,    77,    77,    77,     5,    47,
      42,    59,    48,    63,    64,   366,    54,   348,    77,    69,
      70,    71,    72,   347,    63,    64,    76,    66,    67,    68,
      77,    65,     5,    71,    72,    77,   367,    77,    76,    14,
      15,    16,    17,    18,    73,    20,    76,    75,    23,    24,
      77,    76,    65,    77,    77,    77,    31,    32,    33,    34,
      14,    15,    16,    17,    18,    75,    20,     5,     5,    23,
      24,    13,    57,    56,    77,    57,    56,    31,    32,    33,
      34,    65,    77,    76,    12,    60,    61,    62,    63,    64,
      76,    66,    67,    68,     2,   279,    77,   340,   339,   341,
     328,   177,    -1,    78,   168,   330,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    -1,    14,    15,    16,    17,
      18,    -1,    20,    -1,    78,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    14,    15,    16,
      17,    18,    -1,    20,    -1,    -1,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    64,    -1,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    14,    15,    16,    17,    18,    -1,    20,    -1,
      77,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    14,    15,    16,    17,    18,    -1,    20,
      -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    14,    15,
      16,    17,    18,    -1,    20,    -1,    77,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    14,
      15,    16,    17,    18,    -1,    20,    -1,    -1,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    34,
      -1,    -1,    -1,    -1,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    -1,    14,    15,    16,    17,    18,    -1,
      20,    -1,    -1,    23,    24,    60,    61,    62,    63,    64,
      -1,    66,    67,    68,    14,    15,    16,    17,    18,    -1,
      20,    -1,    -1,    23,    24,    -1,    14,    15,    16,    17,
      18,    31,    20,    33,    -1,    23,    24,    -1,    -1,    -1,
      60,    61,    62,    63,    64,    33,    66,    67,    68,    14,
      15,    16,    17,    18,    -1,    20,    -1,    -1,    23,    24,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    -1,
      -1,    -1,    60,    61,    62,    63,    64,    -1,    66,    67,
      68,    14,    15,    16,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      -1,    66,    67,    68,    14,    15,    16,    17,    18,    -1,
      20,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    64,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    66,    67,    68
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,    80,    81,     0,    82,     3,     4,     5,     6,     7,
       8,    10,    11,    22,    25,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    51,    52,    53,    54,    55,
      71,    72,    76,    83,    84,    85,    86,    87,    88,    89,
      90,    92,    93,    95,   110,   112,   113,   118,   119,   121,
     124,   130,   135,   137,   139,   144,   145,   147,   149,   150,
     153,     5,   131,   132,    65,    76,    76,    76,     5,   136,
      42,    63,    64,    69,    70,    72,    85,    90,    91,    92,
      94,   121,   124,   125,   126,   127,   128,   129,   140,   145,
     147,    54,   133,   134,     4,     5,     5,    72,    84,     4,
       5,    90,    90,    84,    91,     4,    91,   141,   142,     8,
      59,    82,   111,    91,    75,    75,    75,    45,    46,    65,
      57,    71,    75,    75,    75,    75,    75,    75,    59,    75,
      75,    75,    57,    56,     5,    48,    54,   141,    91,    91,
      59,    65,    76,    91,    91,    91,    91,    14,    15,    16,
      17,    18,    20,    23,    24,    31,    32,    33,    34,    60,
      61,    62,    63,    64,    66,    67,    68,    57,    56,    76,
      76,    71,    84,    65,    65,    50,   114,   115,   116,    72,
      78,    56,    59,    73,    73,    56,    73,    77,     5,    54,
      91,    91,     4,     5,    91,   132,    76,    76,    77,    77,
      77,     4,     5,    66,     5,    66,     5,    77,   131,   138,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,   134,    77,   131,   138,    77,   131,   138,    91,     5,
       5,    76,    49,   117,   116,    96,    97,    98,    91,    91,
       8,    76,    78,    65,    76,   141,   141,   148,    84,    84,
      65,    84,    56,    77,    77,    84,    56,    77,    77,    84,
      56,    77,    77,    78,     5,    84,   108,   109,   139,    99,
       3,    41,   100,    59,   141,    48,   141,    77,    77,   143,
     154,    65,   138,    84,    84,   138,    84,    84,   138,    84,
      84,    84,    77,    73,   139,   100,   101,   102,    75,    91,
      77,    76,    77,   123,    76,   151,    65,    77,    77,    77,
      84,    75,     5,   104,   105,     5,   106,   107,   122,   141,
     146,   120,   141,    13,   155,    84,    84,    84,    57,    56,
      57,    56,   120,    77,   143,    65,    77,    76,    12,   152,
       5,     6,     7,     8,    39,    40,    47,    54,   103,   105,
     103,   107,     5,    54,    91,    84,    76,    77,   141,    84,
      77
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    44,    61,   311,    58,
     124,    94,    38,    45,    43,    46,    42,    47,    37,    33,
     126,    91,   123,   125,   312,    59,    40,    41,    93
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    79,    81,    80,    82,    82,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    84,    85,    85,    86,
      87,    88,    88,    89,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      92,    92,    92,    93,    94,    94,    94,    94,    95,    96,
      96,    98,    97,    99,    97,   101,   100,   102,   100,   103,
     103,   103,   103,   103,   103,   103,   103,   104,   104,   105,
     105,   106,   106,   107,   108,   108,   109,   109,   110,   111,
     111,   112,   112,   113,   114,   115,   115,   116,   117,   117,
     118,   119,   119,   119,   119,   120,   120,   120,   120,   122,
     121,   123,   121,   124,   124,   124,   124,   125,   125,   125,
     125,   125,   125,   126,   126,   127,   127,   128,   128,   128,
     128,   128,   129,   129,   129,   129,   129,   130,   130,   131,
     131,   132,   132,   133,   133,   134,   135,   136,   136,   137,
     137,   137,   137,   137,   138,   139,   139,   139,   139,   139,
     139,   139,   139,   140,   140,   140,   140,   141,   141,   142,
     142,   143,   143,   144,   144,   146,   145,   145,   145,   148,
     147,   149,   149,   150,   151,   151,   152,   152,   154,   155,
     153
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     0,     2,     0,     2,     2,     2,     2,     2,
       2,     1,     2,     1,     1,     2,     1,     1,     1,     2,
       2,     2,     1,     1,     2,     2,     3,     3,     6,     1,
       1,     3,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     2,     2,     2,     2,     6,     0,
       1,     0,     3,     0,     4,     0,     3,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     3,     3,     0,     1,     1,     2,     3,     3,
       5,     3,     3,     2,     1,     1,     2,     5,     0,     2,
       4,     3,     3,     3,     3,     0,     6,     3,     3,     0,
       8,     0,     8,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       3,     3,     1,     1,     3,     3,     3,     1,     3,     4,
       4,     4,     4,     2,     4,     5,     5,     6,     6,     6,
       6,     8,     8,     4,     5,     5,     7,     0,     1,     1,
       3,     0,     4,     1,     3,     0,     8,     5,     8,     0,
       6,     2,     1,     5,     0,     6,     0,     2,     0,     0,
       9
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "\"var\"",
  "\"type specification\"", "\"identifier\"", "\"number\"",
  "\"float-number\"", "\"string\"", "\"for\"", "\"while\"", "\"if\"",
  "\"else\"", "\"else if\"", "\"<=\"", "\">=\"", "\"<\"", "\">\"",
  "\">>\"", "\">>=\"", "\"<<\"", "\"<<=\"", "\"break\"", "\"==\"",
  "\"!=\"", "\"import\"", "\"+=\"", "\"*=\"", "\"/=\"", "\"-=\"", "\"%=\"",
  "\"||\"", "\"or\"", "\"&&\"", "\"and\"", "\"&=\"", "\"|=\"", "\"^=\"",
  "\"return\"", "\"true\"", "\"false\"", "\"const\"", "\"function\"",
  "\"spawn\"", "\"critical\"", "\"++\"", "\"--\"", "\"null\"", "\"new\"",
  "\"finally\"", "\"catch\"", "\"try\"", "\"throw\"", "\"continue\"",
  "\"constant identifier\"", "\"class\"", "','", "'='", "XOR_EQUAL", "':'",
  "'|'", "'^'", "'&'", "'-'", "'+'", "'.'", "'*'", "'/'", "'%'", "'!'",
  "'~'", "'['", "'{'", "'}'", "UMINUS", "';'", "'('", "')'", "']'",
  "$accept", "program", "$@1", "statement_list", "statement", "block",
  "instantiation", "break", "continue", "thread_block", "critical_block",
  "object", "rvalue", "lvalue", "subscript", "unary", "class_def",
  "class_attr_decl", "class_attr_list", "@2", "@3",
  "non_empty_class_attr_list", "@4", "@5", "attr_rvalue",
  "class_attr_decl_list", "class_attr_decl_impl",
  "class_attr_const_decl_list", "class_attr_const_decl_impl",
  "class_method_decl", "class_method_list", "array", "key_value_list",
  "map", "throw", "catch", "not_empty_catch", "catch_impl", "finally",
  "try_catch_finally", "property_access", "mcall_chain", "mcall", "@6",
  "@7", "inc_dec", "comparison", "boolean", "logic", "arithmetic",
  "bitwise", "variable_decl", "variable_decl_list", "variable_decl_impl",
  "const_decl_list", "const_decl_impl", "assignment", "import_ident_list",
  "import", "vararg", "fdecl", "anonymous_fdecl", "call_args",
  "non_empty_call_args", "fcall_chain", "fully_qualified_name",
  "fully_qualified_call", "@8", "fcall", "@9", "return_stmt", "while",
  "elseif", "else", "if", "@10", "@11", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        80,     0,    -1,    -1,    81,    82,    -1,    -1,    82,    83,
      -1,   137,    75,    -1,   130,    75,    -1,   135,    75,    -1,
     147,    75,    -1,   121,    75,    -1,   139,    -1,   149,    75,
      -1,   153,    -1,   150,    -1,   124,    75,    -1,    84,    -1,
      88,    -1,    89,    -1,   113,    75,    -1,    86,    75,    -1,
      87,    75,    -1,   118,    -1,    95,    -1,   145,    75,    -1,
      85,    75,    -1,    72,    82,    73,    -1,     4,    65,    48,
      -1,     4,    65,    48,    76,   141,    77,    -1,    22,    -1,
      53,    -1,    43,     5,    84,    -1,    43,     5,    71,    91,
      78,    84,    -1,    44,    84,    -1,     5,    -1,    54,    -1,
       8,    -1,     6,    -1,     7,    -1,    47,    -1,    39,    -1,
      40,    -1,   112,    -1,   110,    -1,    76,    91,    77,    -1,
      93,    -1,   119,    -1,    90,    -1,    94,    -1,   128,    -1,
     127,    -1,   129,    -1,   126,    -1,   125,    -1,   124,    -1,
     147,    -1,   140,    -1,    85,    -1,   121,    -1,   145,    -1,
       5,    -1,   119,    -1,    93,    -1,    92,    71,    91,    78,
      -1,    63,    91,    -1,    64,    91,    -1,    69,    91,    -1,
      70,    91,    -1,    55,     4,    72,    96,   108,    73,    -1,
      -1,    97,    -1,    -1,    98,   100,    75,    -1,    -1,    97,
      99,   100,    75,    -1,    -1,     3,   101,   104,    -1,    -1,
      41,   102,   106,    -1,     5,    -1,    54,    -1,     8,    -1,
       6,    -1,     7,    -1,    47,    -1,    39,    -1,    40,    -1,
     105,    -1,   104,    56,   105,    -1,     5,    57,   103,    -1,
       5,    -1,   107,    -1,   106,    56,   107,    -1,     5,    57,
     103,    -1,    -1,   109,    -1,   139,    -1,   109,   139,    -1,
      71,   141,    78,    -1,     8,    59,    91,    -1,   111,    56,
       8,    59,    91,    -1,    72,    59,    73,    -1,    72,   111,
      73,    -1,    52,    91,    -1,   115,    -1,   116,    -1,   115,
     116,    -1,    50,    76,     5,    77,    84,    -1,    -1,    49,
      84,    -1,    51,    84,   114,   117,    -1,    90,    65,     5,
      -1,     4,    65,     5,    -1,    90,    65,    54,    -1,     4,
      65,    54,    -1,    -1,   120,    65,     5,    76,   141,    77,
      -1,   120,    65,     5,    -1,   120,    65,    54,    -1,    -1,
      90,    65,     5,    76,   141,    77,   122,   120,    -1,    -1,
       4,    65,     5,    76,   141,    77,   123,   120,    -1,    90,
      45,    -1,    90,    46,    -1,    45,    90,    -1,    46,    90,
      -1,    91,    23,    91,    -1,    91,    24,    91,    -1,    91,
      17,    91,    -1,    91,    15,    91,    -1,    91,    16,    91,
      -1,    91,    14,    91,    -1,    91,    31,    91,    -1,    91,
      33,    91,    -1,    91,    32,    91,    -1,    91,    34,    91,
      -1,    91,    64,    91,    -1,    91,    63,    91,    -1,    91,
      66,    91,    -1,    91,    67,    91,    -1,    91,    68,    91,
      -1,    91,    62,    91,    -1,    91,    60,    91,    -1,    91,
      61,    91,    -1,    91,    20,    91,    -1,    91,    18,    91,
      -1,     3,   131,    -1,    41,   133,    -1,   132,    -1,   131,
      56,   132,    -1,     5,    57,    91,    -1,     5,    -1,   134,
      -1,   133,    56,   134,    -1,    54,    57,    91,    -1,    92,
      57,    91,    -1,     5,    -1,   136,    65,     5,    -1,    25,
     136,    65,    66,    -1,    25,   136,    59,    66,    -1,    25,
     136,    59,     5,    -1,    25,   136,    59,     4,    -1,    25,
     136,    -1,     5,    65,    65,    65,    -1,    42,     5,    76,
      77,    84,    -1,    42,     4,    76,    77,    84,    -1,    42,
       5,    76,   138,    77,    84,    -1,    42,     4,    76,   138,
      77,    84,    -1,    42,     5,    76,   131,    77,    84,    -1,
      42,     4,    76,   131,    77,    84,    -1,    42,     5,    76,
     131,    56,   138,    77,    84,    -1,    42,     4,    76,   131,
      56,   138,    77,    84,    -1,    42,    76,    77,    84,    -1,
      42,    76,   138,    77,    84,    -1,    42,    76,   131,    77,
      84,    -1,    42,    76,   131,    56,   138,    77,    84,    -1,
      -1,   142,    -1,    91,    -1,   142,    56,    91,    -1,    -1,
     143,    76,   141,    77,    -1,     5,    -1,   144,    59,     5,
      -1,    -1,   144,    59,     5,    76,   141,    77,   146,   143,
      -1,   144,    59,     4,    65,    48,    -1,   144,    59,     4,
      65,    48,    76,   141,    77,    -1,    -1,     5,    76,   141,
      77,   148,   143,    -1,    38,    91,    -1,    38,    -1,    10,
      76,    91,    77,    84,    -1,    -1,   151,    13,    76,    91,
      77,    84,    -1,    -1,    12,    84,    -1,    -1,    -1,    11,
      76,    91,    77,    84,   154,   151,   155,   152,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     4,     7,     8,    11,    14,    17,    20,
      23,    26,    28,    31,    33,    35,    38,    40,    42,    44,
      47,    50,    53,    55,    57,    60,    63,    67,    71,    78,
      80,    82,    86,    93,    96,    98,   100,   102,   104,   106,
     108,   110,   112,   114,   116,   120,   122,   124,   126,   128,
     130,   132,   134,   136,   138,   140,   142,   144,   146,   148,
     150,   152,   154,   156,   161,   164,   167,   170,   173,   180,
     181,   183,   184,   188,   189,   194,   195,   199,   200,   204,
     206,   208,   210,   212,   214,   216,   218,   220,   222,   226,
     230,   232,   234,   238,   242,   243,   245,   247,   250,   254,
     258,   264,   268,   272,   275,   277,   279,   282,   288,   289,
     292,   297,   301,   305,   309,   313,   314,   321,   325,   329,
     330,   339,   340,   349,   352,   355,   358,   361,   365,   369,
     373,   377,   381,   385,   389,   393,   397,   401,   405,   409,
     413,   417,   421,   425,   429,   433,   437,   441,   444,   447,
     449,   453,   457,   459,   461,   465,   469,   473,   475,   479,
     484,   489,   494,   499,   502,   507,   513,   519,   526,   533,
     540,   547,   556,   565,   570,   576,   582,   590,   591,   593,
     595,   599,   600,   605,   607,   611,   612,   621,   627,   636,
     637,   644,   647,   649,   655,   656,   663,   664,   667,   668,
     669
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   210,   210,   210,   214,   215,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   242,   246,   247,   251,
     255,   259,   266,   276,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     318,   319,   320,   324,   328,   329,   330,   331,   335,   339,
     340,   344,   344,   345,   345,   349,   349,   350,   350,   354,
     355,   356,   357,   358,   359,   360,   361,   365,   366,   370,
     371,   375,   376,   380,   384,   385,   389,   390,   394,   398,
     399,   403,   404,   408,   412,   416,   417,   421,   425,   426,
     430,   434,   435,   436,   437,   441,   442,   443,   444,   448,
     448,   449,   449,   453,   454,   455,   456,   460,   461,   462,
     463,   464,   465,   469,   470,   474,   475,   479,   480,   481,
     482,   483,   487,   488,   489,   490,   491,   495,   496,   500,
     501,   505,   506,   510,   511,   515,   519,   523,   524,   528,
     529,   530,   531,   532,   536,   540,   542,   544,   546,   548,
     550,   552,   554,   559,   561,   563,   565,   570,   571,   575,
     576,   580,   581,   585,   586,   590,   590,   591,   592,   596,
     596,   600,   601,   605,   609,   611,   616,   617,   621,   622,
     621
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
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
       2,     2,     2,    69,     2,     2,     2,    68,    62,     2,
      76,    77,    66,    64,    56,    63,    65,    67,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    75,
       2,    57,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    71,     2,    78,    61,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,    60,    73,    70,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    58,    74
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 798;
  const int Parser::yynnts_ = 77;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 3;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 79;

  const unsigned int Parser::yyuser_token_number_max_ = 312;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


} // clever





namespace clever {

void Parser::error(const Parser::location_type& line, const std::string& msg)
{
	driver.error(line, msg);
}

} // clever

