%{
	using namespace std;

	#include <cstring>
	#include <string>
	#include <cstdio>
	#include <cstdlib>
	#include <unistd.h>
	#include "commun.h"
	#include "xml.tab.h"

	#include <list>

	#include "Node.hh"
	#include "TextNode.hh"
	#include "MarkupNode.hh"
	#include "CompositeMarkupNode.hh"


	void xmlerror(char *msg);
	int xmlwrap(void);
	int xmllex(void);

	int handleDTD(char*);
	xml::CompositeMarkupNode* handleElement(xml::CompositeMarkupNode** , string , string , xml::CompositeMarkupNode::Attributes , list<void*>* );

	xml::CompositeMarkupNode* root;
	xml::CompositeMarkupNode** proxyPtr;

	xml::MarkupNode::Attributes attributes;
%}

%error-verbose
%union {
	char * s;
	ElementName * en;  /* le nom d'un element avec son namespace */
	list<void*>* children;
}

%token EQ SLASH CLOSE END CLOSESPECIAL DOCTYPE
%token <s> ENCODING VALUE DATA COMMENT NAME NSNAME
%token <en> NSSTART START STARTSPECIAL

%type <en> start
%type <children> content empty_or_content close_content_and_end
%%

document 		: declarations element misc_seq_opt 
			;

misc_seq_opt 		: misc_seq_opt misc
			| /*empty*/
			;

misc 			: COMMENT		
			;

declarations 		: declaration
			| /*empty*/
			;

declaration 		: DOCTYPE NAME NAME VALUE CLOSE 			{ handleDTD($4); }
			;

element			: start attributes empty_or_content			{ 
				  							/*root = handleElement(proxyPtr, $1->first, $1->second, attributes, $3);  */
											printf("##ELEMENTNODE(%s, %d)##", $1->second.c_str(), $3->size()); 
			  							}
			| STARTSPECIAL attributes CLOSESPECIAL
			;

attributes		: /* EMPTY */
			| attributes NAME EQ VALUE
			;

start 			: START							{ $$ = $1; }
			| NSSTART						{ $$ = $1; } 
			;

empty_or_content 	: SLASH CLOSE						{ $$ = NULL; }
			| close_content_and_end name_or_nsname_opt CLOSE	{ $$ = $1; } 
			;

name_or_nsname_opt 	: NAME     
			| NSNAME  
			| /* empty */
			;

close_content_and_end 	: CLOSE content END 					{ $$ = $2; }
			;

content 		: content DATA						{ 	$$ = $1; 
				  							/*$1->push_back( (void*)(new xml::TextNode( *proxyPtr, string($2) )) ); */
											printf("##TEXTNODE##"); 
			  							}
			| content misc        
			| content element      
			| /*empty*/         					{ $$ = (list<void*>*)new list<xml::Node*>();/* proxyPtr = new xml::CompositeMarkupNode*;*/ }
			;
%%
int xmlwrap(void) { return 1; }
void xmlerror(char *msg) { fprintf(stderr, "%s\n", msg); }
