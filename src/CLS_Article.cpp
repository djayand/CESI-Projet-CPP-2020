// CLS_Article.cpp
// Couche "service" de la gestion des articles

#include "CLS_Article.h"

namespace NS_Svc
{
	CLS_Article::CLS_Article(void)
	{
		this->cad = gcnew NS_Composants::CLC_Sql();
		this->article = gcnew NS_Composants::CLC_Article();
		this->ds = gcnew Data::DataSet();
	}
	DataSet^ CLS_Article::listeArticles(String^ dataTableName)
	{
		this->ds->Clear();
		this->ds = this->cad->getRows(this->article->SELECT(), dataTableName);
		return this->ds;
	}
	int CLS_Article::ajouter(String^ nom, String^ couleur, String^ nature, double prixHT, double prixTTC, double prixAchat, double TVA, int qteStock, int seuil)
	{

		int ID_Article;
		this->article->setNom(nom);
		this->article->setCouleur(couleur);
		this->article->setNature(nature);
		this->article->setPrixHT(prixHT);
		this->article->setPrixTTC(prixTTC);
		this->article->setPrixAchat(prixAchat);
		this->article->setTVA(TVA);
		this->article->setQteStock(qteStock);
		this->article->setSeuil(seuil);
		ID_Article = this->cad->actionRowsID(this->article->INSERT());
		return ID_Article;
	}
	void CLS_Article::modifier(int ID_Article, String^ nom, String^ couleur, String^ nature, double prixHT, double prixTTC, double prixAchat, double TVA, int qteStock, int seuil)
	{
		this->article->setNom(nom);
		this->article->setCouleur(couleur);
		this->article->setNature(nature);
		this->article->setPrixHT(prixHT);
		this->article->setPrixTTC(prixTTC);
		this->article->setPrixAchat(prixAchat);
		this->article->setTVA(TVA);
		this->article->setQteStock(qteStock);
		this->article->setSeuil(seuil);
		this->cad->actionRows(this->article->UPDATE());
	}
	void CLS_Article::supprimer(int ID_Article)
	{
		this->article->setID(ID_Article);
		this->cad->actionRows(this->article->DELETE());
	}
}
