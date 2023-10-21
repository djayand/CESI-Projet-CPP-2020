// CLC_Commande.cpp
// Couche "composant" de la gestion des commandes

#include "CLC_Commande.h"

namespace NS_Composants
{
	CLC_Commande::CLC_Commande(void)
	{
		this->ID_Commande = -1;
		this->Date_livraison_prevue = "RIEN";
		this->Date_emission_facture = "RIEN";
		this->Moyen_Paiement = "RIEN";
		this->Date_Paiement = "RIEN";
		this->Date_Reglement = "RIEN";
		this->Solde_Reglement = -1;
		this->Nombre_Total_Articles = -1;
		this->Montant_Remises = -1;
		this->Montant_TVA_Total = -1;
		this->Prix_Commande_HT = -1;
		this->Prix_Commande_TTC = -1;
		this->ID_Client = -1;
		this->ID_Facture = -1;
	}

	String^ CLC_Commande::SELECT(void)
	{
		return "SELECT *" + "FROM commande;";
	}
	String^ CLC_Commande::INSERT(void)
	{
		return "INSERT INTO commande " +
			"(Date_livraison_prevue, Date_emission_facture, Moyen_Paiement, Date_Paiement, Date_Reglement, Solde_Reglement, Nombre_Total_Articles, Montant_Remise, Montant_TVA_Total, Prix_Commande_HT, Prix_Commande_TTC, ID_Client, ID_Facture) " +
			"VALUES('" + this->getDate_livraison_prevue() + "', '" + this->getDate_emission_facture() + "', '" + this->getMoyen_Paiement() + "','" + this->getDate_Paiement() + "','" + this->getSolde_Reglement() + "','" + this->getNombre_Total_Articles() + "','" + this->getMontant_Remises() + "','" + this->getMontant_TVA_Total() + "','" + this->getPrix_Commande_HT() + "','" + this->getPrix_Commande_TTC() + "','" + this->getID_Client() + "','" + this->getID_Facture() + "');SELECT @@IDENTITY;";
	}
	String^ CLC_Commande::UPDATE(void)
	{
		return "UPDATE commande " +
			"SET Date_livraison_prevue = '" + this->getDate_livraison_prevue() + "', Date_emission_facture = '" + this->getDate_emission_facture() + "', Moyen_Paiement ='" + this->getMoyen_Paiement() + "', Date_Paiement = '" + this->getDate_Paiement() + "', Solde_Reglement = '" + this->getSolde_Reglement() + "', Nombre_Total_Articles = '" + this->getNombre_Total_Articles() + "', Montant_Remise = '" + this->getMontant_Remises() + "', Montant_TVA_Total = '" + this->getMontant_TVA_Total() + "', Prix_Commande_HT = '" + this->getPrix_Commande_HT() + "', Prix_Commande_TTC = '" + this->getPrix_Commande_TTC() + "', ID_Client = '" + this->getID_Client() + "', ID_Facture = '" + this->getID_Facture() + "' " +
			"WHERE(ID_Commande = " + this->getID_Commande() + ");";
	}
	String^ CLC_Commande::DELETE(void)
	{
		return "DELETE FROM commande " +
			"WHERE ID_Commande = " + this->getID_Commande() + ";";
	}
	String^ CLC_Commande::QueryPM(void)
	{
		return "SELECT AVG('" + this->getPrix_Commande_TTC() + "')" +
			"AS Panier_Moyen FROM commande";
	}

	void CLC_Commande::setID_Commande(int ID_Commande)
	{
		if (ID_Commande > 0)
		{
			this->ID_Commande = ID_Commande;
		}
	}
	void CLC_Commande::setDate_livraison_prevue(String^ Date_livraison_prevue)
	{
		if (Date_livraison_prevue != "")
		{
			this->Date_livraison_prevue = Date_livraison_prevue;
		}
	}
	void CLC_Commande::setDate_emission_facture(String^ Date_emmission_facture)
	{
		if (Date_emmission_facture != "")
		{
			this->Date_emission_facture = Date_emmission_facture;

		}
	}
	void CLC_Commande::setMoyen_Paiement(String^ Moyen_Paiement)
	{
		if (Moyen_Paiement != "")
		{
			this->Moyen_Paiement = Moyen_Paiement;

		}
	}
	void CLC_Commande::setDate_Paiement(String^ Date_Paiement)
	{
		if (Date_Paiement != "")
		{
			this->Date_Paiement = Date_Paiement;

		}
	}
	void CLC_Commande::setDate_Reglement(String^ Date_Reglement)
	{
		if (Date_Reglement != "")
		{
			this->Date_Reglement = Date_Reglement;

		}
	}
	void CLC_Commande::setSolde_Reglement(double Solde_Reglement)
	{
		if (Solde_Reglement > 0)
		{
		this->Solde_Reglement = Solde_Reglement;
		}
	}

	void CLC_Commande::setNombre_Total_Articles(int Nombre_Total_Articles)
	{
		if (Nombre_Total_Articles > 0)
		{
		this->Nombre_Total_Articles = Nombre_Total_Articles;

		}
	}
	void CLC_Commande::setMontant_Remises(double Montant_Remises)
	{
		if (Montant_Remises > 0)
		{
		this->Montant_Remises = Montant_Remises;

		}
	}
	void CLC_Commande::setMontant_TVA_Total(double Montant_TVA_Total)
	{
		if (Montant_TVA_Total > 0)
		{
		this->Montant_TVA_Total = Montant_TVA_Total;

		}
	}
	void CLC_Commande::setPrix_Commande_HT(double Prix_Commande_HT)
	{
		if (Prix_Commande_HT > 0)
		{
		this->Prix_Commande_HT = Prix_Commande_HT;

		}
	}
	void CLC_Commande::setPrix_Commande_TTC(double Prix_Commande_TTC)
	{
		if (Prix_Commande_TTC > 0)
		{
		this->Prix_Commande_TTC = Prix_Commande_TTC;

		}
	}
	void CLC_Commande::setID_Client(int ID_Client)
	{
		if (ID_Client > 0)
		{
		this->ID_Client = ID_Client;

		}
	}
	void CLC_Commande::setID_Facture(int ID_Facture)
	{
		if (ID_Facture > 0)
		{
		this->ID_Facture = ID_Facture;

		}
	}


	int CLC_Commande::getID_Commande(void)
	{
		return this->ID_Commande;
	}
	String^ CLC_Commande::getDate_livraison_prevue(void)
	{
		return this->Date_livraison_prevue;
	}
	String^ CLC_Commande::getDate_emission_facture(void)
	{
		return this->Date_emission_facture;
	}
	String^ CLC_Commande::getMoyen_Paiement(void)
	{
		return this->Moyen_Paiement;
	}
	String^ CLC_Commande::getDate_Paiement(void)
	{
		return this->Date_Paiement;
	}
	String^ CLC_Commande::getDate_Reglement(void)
	{
		return this->Date_Reglement;
	}
	double CLC_Commande::getSolde_Reglement(void)
	{
		return this->Solde_Reglement;
	}
	int CLC_Commande::getNombre_Total_Articles(void)
	{
		return this->Nombre_Total_Articles;
	}
	double CLC_Commande::getMontant_Remises(void)
	{
		return this->Montant_Remises;
	}
	double CLC_Commande::getMontant_TVA_Total(void)
	{
		return this->Montant_TVA_Total;
	}
	double CLC_Commande::getPrix_Commande_HT(void)
	{
		return this->Prix_Commande_HT;
	}
	double CLC_Commande::getPrix_Commande_TTC(void)
	{
		return this->Prix_Commande_TTC;
	}
	int CLC_Commande::getID_Client(void)
	{
		return this->ID_Client;
	}
	int CLC_Commande::getID_Facture(void)
	{
		return this->ID_Facture;
	}
}