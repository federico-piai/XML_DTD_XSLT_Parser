# Paths
BINNAME=dtdparser
ISLIBRARY=yes

BINPATH=./bin
LIBPATH=./lib
OBJPATH=./obj
SRCPATH=./src
STATICLIBS=
TESTPATH=./tests
TESTBINNAME=make run

EXTRA_INCLUDES=../generic_lex_yacc_makefile

# Build
CXX=g++
CXXFLAGS=-ansi -pedantic -W -Wall -I../dtd/src -I../xml/src
LD=g++
LDFLAGS=-L$(LIBPATH)
LIBLD=ar
LIBLDFLAGS=cr

# Lex & Yacc
LEX=flex
YACC=bison
LEXPREFIX=dtd
YACCPREFIX=dtd

include ../generic_lex_yacc_settings

# Sources
SRCS=$(shell find $(SRCPATH) -type f -regex '.*\.cpp') $(LEXTARGET) $(YACCTARGET)
