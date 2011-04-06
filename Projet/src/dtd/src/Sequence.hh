/*************************************************************************
 * Sequence  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <Sequence> (fichier Sequence.hh) ------
#if ! defined ( SEQUENCE_HH_ )
#define SEQUENCE_HH_

//--------------------------------------------------- Interfaces utilisées
#include <list>
#include <stack>
#include "ElementContent.hh"

namespace dtd
{

class Sequence: public ElementContent
{
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types
	typedef std::list<ElementContent*> SequenceElements;

	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//	
	// Contrat :
	//	

	virtual void accept(InterfaceDTDVisitor & visitor) const;

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	Sequence(const SequenceElements & elements);
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~Sequence();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:
	typedef std::list<ElementContent*> _SequenceElements;
	_SequenceElements _elements;

	struct _State: public Content::_State
	{
		// TODO
	};
	typedef std::stack<_State> _StatesStack;
	_StatesStack _stack;

	virtual void _pushState(Content* nextStep);
	virtual void _popState();
	virtual bool _continueValidation(
			xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken) const;
};

} // namespace dtd

#endif // SEQUENCE_HH_
