// CLC_Client.cpp
// Couche "composant" de la gestion des clients

#include "CLC_Client.h"

namespace NS_Composants
{
	CLC_Client::CLC_Client(void)
	{
		this->ID_Client = -1;
		this->Nom = "RIEN";
		this->Prenom = "RIEN";
		this->DateN = "RIEN";
		this->DateC = "RIEN";
		this->ID_Remise = -1;
	}
	String^ CLC_Client::SELECT(void)
	{
		return "SELECT *" + "FROM client;";
	}
	String^ CLC_Client::INSERT(void)
	{
		return "INSERT INTO client " +
			"(Nom_Client, Prenom_Client, Date_Naissance_Client, Date_1e_Commande, ID_Remise) " +
			"VALUES('" + this->getNom() + "', '" + this->getPrenom() + "', '" + this->getDateN() + "','" + this->getDateC() + "','" + this->getID_Remise() + "');SELECT @@IDENTITY;";
	}
	String^ CLC_Client::UPDATE(void)
	{
		return "UPDATE client " +
			"SET Nom_Client = '" + this->getNom() + "', Prenom_Client = '" + this->getPrenom() + "', Date_Naissance_Client ='" + this->getDateN() + "', Date_1e_Commande = '" + this->getDateC() + "', ID_Remise = '" + this->getID_Remise() + "' " +
			"WHERE(ID_Client = " + this->getID() + ");";
	}
	String^ CLC_Client::DELETE(void)
	{
		return "DELETE FROM client " +
			"WHERE ID_Client = " + this->getID() + ";";
	}
	void CLC_Client::setID(int ID_Client)
	{
		if (ID_Client > 0)
		{
			this->ID_Client = ID_Client;
		}
	}
	void CLC_Client::setPrenom(String^ Prenom)
	{
		if (Prenom != "")
		{
			this->Prenom = Prenom;
		}
	}
	void CLC_Client::setNom(String^ Nom)
	{
		if (Nom != "")
		{
			this->Nom = Nom;

		}
	}
	void CLC_Client::setDateN(String^ DateN)
	{
		if (DateN != "")
		{
			this->DateN = DateN;

		}
	}
	void CLC_Client::setDateC(String^ DateC)
	{
		if (DateC != "")
		{
			this->DateC = DateC;

		}
	}
	void CLC_Client::setID_Remise(int ID_Remise)
	{
		if (ID_Remise != 0)
		{
			this->ID_Remise = ID_Remise;

		}
	}
	int CLC_Client::getID(void)
	{
		return this->ID_Client;
	}
	String^ CLC_Client::getNom(void)
	{
		return this->Nom;
	}
	String^ CLC_Client::getPrenom(void)
	{
		return this->Prenom;
	}
	String^ CLC_Client::getDateN(void)
	{
		return this->DateN;
	}
	String^ CLC_Client::getDateC(void)
	{
		return this->DateC;
	}
	int CLC_Client::getID_Remise(void)
	{
		return this->ID_Remise;
	}
}