/*************************************************************************
 * OutputVisitor  -  Visiteur écrivant un noeud et ses descendants
 * sur un flot.
 * -------------------
 * Début      : mar. 05 avril 2011 14:35:25 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---- Interface de la classe <OutputVisitor> (fichier OutputVisitor.hh) ----
#ifndef OUTPUTVISITOR_HH
#define OUTPUTVISITOR_HH

//--------------------------------------------------- Interfaces utilisées
#include <iosfwd>
#include <string>
#include "InterfaceNodeVisitor.hpp"

namespace xml
{
class TextNode;
class MarkupNode;
class CompositeMarkupNode;

class OutputVisitor: public InterfaceNodeVisitor
{
protected:
	static const char DEFAULT_INDENT_CHAR = ' ';
	static const unsigned char DEFAULT_INDENT_UNIT = 1;

public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques


	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	OutputVisitor(std::ostream & out, char indentChar = DEFAULT_INDENT_CHAR,
			unsigned int indentUnit = DEFAULT_INDENT_UNIT);
	// Mode d'emploi (constructeur) :
	//	Construit un nouveau visiteur écrivant sur "out".
	// Contrat :
	//	Aucun.

	virtual ~OutputVisitor();
	// Mode d'emploi (destructeur) :
	//	Libère les éventuelles ressources allouées par le visiteur.
	// Contrat :
	//	Aucun.

protected:
	static const std::string OPEN_MARKUP_STR;
	static const std::string NS_SEPARATOR_STR;
	static const std::string INSIDE_MARKUP_SPACE_STR;
	static const std::string CLOSING_MARKUP_STR;
	static const std::string CLOSE_MARKUP_STR;
	static const std::string ASSIGN_ATTRIBUTE_VALUE_STR;
	static const std::string OPEN_ATTRIBUTE_VALUE_STR;
	static const std::string CLOSE_ATTRIBUTE_VALUE_STR;

	std::ostream& _out;
	char _indentChar;
	unsigned _indentUnit;
	unsigned int _indent;

	void doIndent();
	// Mode d'emploi :
	//	Indente la ligne courante en fonction de la valeur actuelle de
	//	"_indent" avec le caractère "_indentChar".
	// Contrat :
	//	Aucun.

	void writeMarkupOpening(const MarkupNode& node);
	// Mode d'emploi :
	//	Écrit le début de la balise donnée en paramètres
	//	sur le flot "_out" (càd le namespace, le nom et les attributs).
	// Contrat :
	//	Aucun.

	virtual void visit(const TextNode& node);
	virtual void visit(const MarkupNode& node);
	virtual void visit(const CompositeMarkupNode& node);
	// Mode d'emploi :
	//	Écrit le noeud sur le flot "_out".
	//	La nature des caractères écrits sur le flot dépend du type du noeud.
	//	Les noeuds inclus sont indentés par rapport à leur ancètre.
	// Contrat :
	//	Aucun.

};

} // namespace xml

#endif // OUTPUTVISITOR_HH
