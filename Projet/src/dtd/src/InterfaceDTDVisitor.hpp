/*************************************************************************
 * InterfaceDTDVisitor  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <InterfaceDTDVisitor> (fichier InterfaceDTDVisitor.hh) ------
#if ! defined ( INTERFACEDTDVISITOR_HH_ )
#define INTERFACEDTDVISITOR_HH_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "AttributesList.hh"

namespace dtd
{
class Content;
class AnyContent;
class EmptyContent;
class MixedContent;
class TextContent;
class ElementReference;
class Choice;
class Sequence;
class OptionalContent;
class RepeatableContent;
class RepeatedContent;

class InterfaceDTDVisitor
{
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques
	virtual void visitElement(const std::string & ns,
			const std::string & elementName, const Content& content) = 0;
	virtual void visitAttributesList(const std::string & ns,
			const std::string & elementName, const AttributesList& attlist) = 0;

	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur
	virtual ~InterfaceDTDVisitor()
	// Mode d'emploi (destructeur) :
	//	Ne fait rien (interface).
	// Contrat :
	//	Aucun.
	{
		// Vide
	}

protected:
	friend class AnyContent;
	friend class EmptyContent;
	friend class MixedContent;
	friend class TextContent;
	friend class ElementReference;
	friend class Choice;
	friend class Sequence;
	friend class OptionalContent;
	friend class RepeatableContent;
	friend class RepeatedContent;

	virtual void visit(const AnyContent & content) = 0;
	virtual void visit(const EmptyContent & content) = 0;
	virtual void visit(const MixedContent & content) = 0;
	virtual void visit(const TextContent & content) = 0;
	virtual void visit(const ElementReference & element) = 0;
	virtual void visit(const Choice & content) = 0;
	virtual void visit(const Sequence & content) = 0;
	virtual void visit(const OptionalContent & content) = 0;
	virtual void visit(const RepeatableContent & content) = 0;
	virtual void visit(const RepeatedContent & content) = 0;
	// Mode d'emploi :
	//	Visite l'objet donné en paramètre, pour inspection.
	// Contrat :
	//	L'objet visité doit appeler cette méthode avec son type réel
	//	(non hérité) lorsqu'on fait appel à sa méthode accept().

};

} // namespace dtd

#endif // INTERFACEDTDVISITOR_HH_
