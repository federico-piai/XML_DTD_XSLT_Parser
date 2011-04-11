#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

#include "Node.hh"
#include "TextNode.hh"
#include "MarkupNode.hh"
#include "CompositeMarkupNode.hh"
#include "OutputVisitor.hh"
#include "DotOutputVisitor.hh"

int xmlparse(void);
int dtdparse(void);

extern xml::CompositeMarkupNode* root;

extern FILE * xmlin;
extern FILE * dtdin;

int exportMode;

using namespace std;

int handleDTD(char* filename) {
	int err;
	FILE* inputFile = (FILE*)fopen(filename, "r");
	if(!exportMode) cout << "** Parsing de " << filename << "..." << endl;
	if(inputFile == NULL) {
		cout << "Fichier inexistant." << endl;
		exit(1);
	}

	dtdin = inputFile;	
	err = dtdparse();
	fclose(dtdin);

	if (err != 0) cout << err << " erreurs de syntaxe détectées !" << endl; 
	else if(!exportMode) 
		cout << "Aucune erreur détectée." << endl; 

	return 0;
}

xml::CompositeMarkupNode* handleElement(xml::CompositeMarkupNode** proxy, string NS, string name, xml::MarkupNode::Attributes attbs, list<void*>* children) {
	xml::CompositeMarkupNode::Children currentChildren
		=  *((list<xml::Node*>*)children);

	xml::CompositeMarkupNode** newProxy 
		= new xml::CompositeMarkupNode*; newProxy = 0;

	return  new xml::CompositeMarkupNode(newProxy, NS, name, attbs, *proxy, currentChildren);
}

int main(int argc, char** argv) {
	int err;

	if(argc < 2){
		cout << "Veuillez entrez un nom de fichier." << endl;
		exit(0);
	}

	exportMode = (argc == 3);

	FILE* inputFile = (FILE*)fopen(argv[1], "r");
	if(!exportMode) cout << "** Parsing de " << argv[1] << "..." << endl;
	if(inputFile == NULL) {
		cout << "Fichier inexistant." << endl;
		exit(1);
	}

	xmlin = inputFile;	
	err = xmlparse();
	fclose(xmlin);

	if(exportMode) {
		xml::DotOutputVisitor dvisitor(cout, "xmlTree");
		dvisitor.writeDot(root);
	}

	if (err != 0) cout << err << " erreurs de syntaxe détectées !" << endl; 
	else if(!exportMode) cout << "Aucune erreur détectée." << endl; 

	return 0;
}
