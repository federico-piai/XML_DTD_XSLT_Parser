# Paths
BINNAME=xslstruct
ISLIBRARY=yes

BINPATH=./bin
LIBPATH=./lib
OBJPATH=./obj
SRCPATH=./src
STATICLIBS=
TESTPATH=./tests
TESTBINNAME=make run

# Build
CXX=g++
CXXFLAGS=-ansi -pedantic -W -Wall -I../xml/src
ifdef DEBUG
CXXFLAGS:=$(CXXFLAGS) -DXSL_TRANSFORM_TRACE
endif
LD=g++
LDFLAGS=-L$(LIBPATH)
LIBLD=ar
LIBLDFLAGS=cr

SRCS=$(shell find $(SRCPATH) -type f -regex '.*\.cpp')

