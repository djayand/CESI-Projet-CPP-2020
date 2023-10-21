// CLC_Perso.cpp
// Couche "composant" de la gestion du personnel

#include "CLC_Perso.h"

namespace NS_Composants
{
	CLC_Perso::CLC_Perso(void)
	{
		this->ID_Personnel = -1;
		this->Nom = "RIEN";
		this->Prenom = "RIEN";
		this->DateE = "RIEN";
		this->Adresse = "RIEN";
	}
	String^ CLC_Perso::SELECT(void)
	{
		return "SELECT *" + "FROM personnel;";
	}
	String^ CLC_Perso::INSERT(void)
	{
		return "INSERT INTO personnel " +
			"(Nom_Personnel, Prenom_Personnel, Date_Embauche, Adresse_Personnel) " +
			"VALUES('" + this->getNom() + "', '" + this->getPrenom() + "', '" + this->getDateE() + "','" + this->getAdresse() + "');SELECT @@IDENTITY;";
	}
	String^ CLC_Perso::UPDATE(void)
	{
		return "UPDATE personnel " +
			"SET Nom_Personnel = '" + this->getNom() + "', Prenom_Personnel = '" + this->getPrenom() + "', Date_Embauche = '" + this->getDateE() + "',Adresse_Personnel ='" + this->getAdresse() + "' " +
			"WHERE(ID_Personnel = " + this->getId() + ");";
	}
	String^ CLC_Perso::DELETE(void)
	{
		return "DELETE FROM personnel " +
			"WHERE(ID_Personnel = " + this->getId() + ");";
	}
	void CLC_Perso::setID(int ID_Personnel)
	{
		if (ID_Personnel > 0)
		{
			this->ID_Personnel = ID_Personnel;
		}
	}
	void CLC_Perso::setPrenom(String^ Prenom)
	{
		if (Prenom != "")
		{
			this->Prenom = Prenom;
		}
	}
	void CLC_Perso::setNom(String^ Nom)
	{
		if (Nom != "")
		{
			this->Nom = Nom;

		}
	}
	void CLC_Perso::setDateE(String^ DateE)
	{
		if (DateE != "")
		{
			this->DateE = DateE;

		}
	}
	void CLC_Perso::setAdresse(String^ Adresse)
	{
		if (Adresse != "")
		{
			this->Adresse = Adresse;

		}
	}
	int CLC_Perso::getId(void)
	{
		return this->ID_Personnel;
	}
	String^ CLC_Perso::getNom(void)
	{
		return this->Nom;
	}
	String^ CLC_Perso::getPrenom(void)
	{
		return this->Prenom;
	}
	String^ CLC_Perso::getDateE(void)
	{
		return this->DateE;
	}
	String^ CLC_Perso::getAdresse(void)
	{
		return this->Adresse;
	}
}