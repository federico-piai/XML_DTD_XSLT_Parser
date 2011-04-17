/*************************************************************************
 * MapCreator  -  �Description�
 * -------------------
 * D�but      : 15 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- R�alisation de la classe <MapCreator> (fichier MapCreator.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me


//------------------------------------------------------ Include personnel
#include "MapCreator.hh"

using namespace xml;
using namespace std;

namespace xsl
{
//------------------------------------------------------------- Constantes

static const string TEMPLATE = "template";

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type MapCreator::M�thode ( liste des param�tres )
// Algorithme :
//	
//{
//}
void MapCreator::populateMap(const Node& xslTree)
{
	xslTree.accept(*this);
}

//------------------------------------------------- Surcharge d'op�rateurs


//-------------------------------------------- Constructeurs - destructeur
MapCreator::MapCreator(map<string, const Node *> * theMap) :
	mapTemp(theMap)
{
}

MapCreator::~MapCreator()
{
	// on ne fait rien car on ne veut pas d�truire la map qui est utilis�e apr�s.
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

void MapCreator::visit(const TextNode& node)
{
	// Dans le type de fichier xsl que nous g�rons il n'est pas n�cessaire
	// de g�rer ce type de Noeud
}

void MapCreator::visit(const MarkupNode& node)
{
	// Dans le type de fichier xsl que nous g�rons il n'est pas n�cessaire
	// de g�rer ce type de Noeud
}

void MapCreator::visit(const CompositeMarkupNode& node)
{

	if (node.name() == TEMPLATE)
	{
		checkTemplate(node);
	}

	for (CompositeMarkupNode::ChildrenIterator itNoeud = node.begin(); itNoeud
			!= node.end(); ++itNoeud)
	{
		(*itNoeud)->accept(*this);
	}

}

void MapCreator::checkTemplate(const CompositeMarkupNode& node)
{
	for (MarkupNode::AttributesIterator itAttribut = node.MarkupNode::begin(); itAttribut
			!= node.MarkupNode::end(); ++itAttribut)
	{
		if (itAttribut->first == "match")
		{
			(*mapTemp)[itAttribut->second] = &node;
		}
	}
}

} // namespace xsl
