/*************************************************************************
 * DTD  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <DTD> (fichier DTD.hh) ------
#if ! defined ( DTD_HH_ )
#define DTD_HH_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include "Node.hh"
#include "InterfaceNodeVisitor.hpp"
#include "AttributesList.hh"

namespace dtd
{
class InterfaceDTDVisitor;
class Content;

class DTD: public xml::InterfaceNodeVisitor
{
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types
	void accept (InterfaceDTDVisitor & visitor);
	// Mode d'emploi :
	//	Permet à un visiteur d'inspecter ce contenu sous sa vraie identité
	//	(en lui révélant son type réel).
	// Contrat :
	//	Aucun.

	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//	
	// Contrat :
	//	

	void addElement(const std::string & ns, const std::string & elementName,
			Content& content);
	// Mode d'emploi :
	//	Ajoute un element à la DTD. Si aucun AttributesList n'existe pour
	//	cet élément, il sera créé (vide).
	//	L'élément sera détruit par la DTD.
	// Contrat :
	//	Aucun.

	void addAttributesList(const std::string & ns,
			const std::string & elementName, const AttributesList& attribute);
	// Mode d'emploi :
	//	Ajoute une liste d'attributs à la DTD. Si une liste d'attributs
	//	existe déjà portant sur le même élément, elle seront fusionnées.
	//	La liste et ses éléments seront détruite par la DTD.
	// Contrat :
	//	Aucun.

	bool isValid(const xml::Node& root, const std::string & validRootName);
	// Mode d'emploi :
	//	Valide un document XML selon la DTD, en s'assurant que la racine ait
	//	bien le nom imposé.
	// Contrat :
	//	Aucun.


	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	DTD();

	virtual ~DTD();

protected:
	typedef std::pair<std::string, std::string> _ElementId;
	typedef std::map<_ElementId, Content*> _Elements;
	typedef std::map<_ElementId, AttributesList> _AttributesLists;

	_Elements _elements;
	_AttributesLists _attributesLists;

	bool _validatingRoot;
	std::string _validRootName;
	bool _lastNodeIsValid;

	virtual void visit(const xml::TextNode & node);
	virtual void visit(const xml::MarkupNode & node);
	virtual void visit(const xml::CompositeMarkupNode & node);

	bool checkAttributes(const xml::MarkupNode & node);

	Content * getElement(std::string ns, std::string name) const;
	// Mode d'emploi :
	//	Récupère l'élement associé à l'espace de nom "ns" et au nom "name".
	//	S'il n'existe pas, renvoie un pointeur nul.
	// Contrat :
	//	L'élément renvoyé ne doit pas être détruit, et ne doit être modifié
	//	que dans le cadre d'une validation.

	const AttributesList
		* getAttributesList(std::string ns, std::string name) const;
	// Mode d'emploi :
	//	Récupère la liste d'attributs associée à l'espace de nom "ns" et au
	//	nom "name".
	//	Si elle n'existe pas, renvoie un pointeur nul.
	// Contrat :
	//	Aucun.

	bool _isValid(const xml::Node& node);
	// Mode d'emploi :
	//	Valide un noeud selon la DTD, ainsi que ses enfants récursivement.
	// Contrat :
	//	Aucun.
};

} // namespace dtd

#endif // DTD_HH_
