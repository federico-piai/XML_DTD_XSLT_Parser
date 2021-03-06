/*************************************************************************
 * QuantifiableContent  -  «Description»
 * -------------------
 * Début      : 6 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <QuantifiableContent> (fichier QuantifiableContent.hh) ------
#if ! defined ( QUANTIFIABLECONTENT_HH_ )
#define QUANTIFIABLECONTENT_HH_

//--------------------------------------------------- Interfaces utilisées
#include "BrowsableContent.hh"

namespace dtd
{

class QuantifiableContent: public BrowsableContent
{
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//	
	// Contrat :
	//	


	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	QuantifiableContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~QuantifiableContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:
	struct _State
	{
		xml::CompositeMarkupNode::ChildrenIterator firstToken;
		xml::CompositeMarkupNode::ChildrenIterator endToken;
		BrowsableContent* nextStep;

		_State(xml::CompositeMarkupNode::ChildrenIterator aFirstToken,
				xml::CompositeMarkupNode::ChildrenIterator anEndToken,
				BrowsableContent* aNextStep) :
			firstToken(aFirstToken), endToken(anEndToken), nextStep(aNextStep)
		{

		}
	};
};

} // namespace dtd

#endif // QUANTIFIABLECONTENT_HH_
