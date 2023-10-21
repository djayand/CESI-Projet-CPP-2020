// CLC_Article.cpp
// Couche "composant" de la gestion du stock

#include "CLC_Article.h"

namespace NS_Composants
{
	CLC_Article::CLC_Article(void) // Initialisation (constructeur par défault)
	{
		this->ID_Article = -1;
		this->nom = "RIEN";
		this->couleur = "RIEN";
		this->nature = "RIEN";
		this->prixHT = -1; // Prix UNITAIRE
		this->prixTTC = -1; // Prix UNITAIRE
		this->prixAchat = -1; //Coût FABRICATION
		this->TVA = -1;
		this->qteStock = -1;
		this->seuil = -1;
	}

	String^ CLC_Article::SELECT(void) // Def méthodes (requêtes SQL)
	{
		return "SELECT * " + "FROM article;";
	}
	String^ CLC_Article::INSERT(void)
	{
		return "INSERT INTO article " +
			"(Nom_Article, Couleur_Article, Nature_Article, Prix_Unitaire_HT, Prix_Unitaire_TTC, Prix_Unitaire_Achat, Montant_TVA_Unitaire, Qte_Stock, Seuil ) " +
			"VALUES('" + this->getNom() + "' , '" + this->getCouleur() + "' , '" + this->getNature() + "' , '" + this->getPrixHT() + "' , '" + this->getPrixTTC() + "' , '" + this->getPrixAchat() + "' , '" + this->getTVA() + "' , '" + this->getQteStock() + "' , '" + this->getSeuil() + "');SELECT @@IDENTITY;";
	}
	String^ CLC_Article::UPDATE(void)
	{
		return "UPDATE article " +
			"SET Nom_Article = '" + this->getNom() + "' , Couleur_Article = '" + this->getCouleur() + "', Nature_Article = '" + this->getNature() + "', Prix_Unitaire_HT = '" + this->getPrixHT() + "' , Prix_Unitaire_TTC = '" + this->getPrixTTC() + "' , Prix_Unitaire_Achat = '" + this->getPrixAchat() + "' , Montant_TVA_Unitaire = '" + this->getTVA() + "', Qte_Stock = '" + this->getQteStock() + "', Seuil = '" + this->getSeuil() + "' " +
			"WHERE(ID_Article = '" + this->getID() + "');";
	}
	String^ CLC_Article::DELETE(void)
	{
		return "DELETE FROM article " +
			"WHERE(ID_Article = " + this->getID() + ");";
	}

	void CLC_Article::setID(int ID_Article)
	{
		if (ID_Article > 0)
		{
			this->ID_Article = ID_Article;
		}
	}
	void CLC_Article::setNom(String^ nom)
	{
		if (nom != "")
		{
			this->nom = nom;
		}
	}
	void CLC_Article::setCouleur(String^ couleur)
	{
		if (couleur != "")
		{
			this->couleur = couleur;
		}
	}
	void CLC_Article::setNature(String^ nature)
	{
		if (nature != "")
		{
			this->nature = nature;
		}
	}
	void CLC_Article::setPrixHT(double prixHT)
	{
		if (prixHT > 0)
		{
			this->prixHT = prixHT;
		}
	}
	void CLC_Article::setPrixTTC(double prixTTC)
	{
		if (prixTTC > 0)
		{
			this->prixTTC = prixTTC;
		}
	}
	void CLC_Article::setPrixAchat(double prixAchat)
	{
		if (prixAchat > 0)
		{
			this->prixAchat = prixAchat;
		}
	}
	void CLC_Article::setTVA(double TVA)
	{
		if (TVA > 0)
		{
			this->TVA = TVA;
		}
	}
	void CLC_Article::setQteStock(int qteStock)
	{
		if (qteStock > 0)
		{
			this->qteStock = qteStock;
		}
	}
	void CLC_Article::setSeuil(int seuil)
	{
		if (seuil > 0)
		{
			this->seuil = seuil;
		}
	}

	int CLC_Article::getID(void)
	{
		return this->ID_Article;
	}
	String^ CLC_Article::getNom(void)
	{
		return this->nom;
	}
	String^ CLC_Article::getCouleur(void)
	{
		return this->couleur;
	}
	String^ CLC_Article::getNature(void)
	{
		return this->nature;
	}
	double CLC_Article::getPrixHT(void)
	{
		return this->prixHT;
	}
	double CLC_Article::getPrixTTC(void)
	{
		return this->prixTTC;
	}
	double CLC_Article::getPrixAchat(void)
	{
		return this->prixAchat;
	}
	double CLC_Article::getTVA(void)
	{
		return this->TVA;
	}
	int CLC_Article::getQteStock(void)
	{
		return this->qteStock;
	}
	int CLC_Article::getSeuil(void)
	{
		return this->seuil;
	}
}