// CLS_Commande.cpp
// Couche "service" de la gestion des commandes

#include "CLS_Commande.h"

namespace NS_Svc
{
	CLS_Commande::CLS_Commande(void)
	{
		this->cad = gcnew NS_Composants::CLC_Sql();
		this->commande = gcnew NS_Composants::CLC_Commande();
		this->ds = gcnew Data::DataSet();
	}
	DataSet^ CLS_Commande::listeCommande(String^ dataTableName)
	{
		this->ds->Clear();
		this->ds = this->cad->getRows(this->commande->SELECT(), dataTableName);
		return this->ds;
	}
	int CLS_Commande::ajouter(String^ Date_livraison_prevue, String^ Date_emission_facture, String^ Moyen_Paiement, String^ Date_Paiement, String^ Date_Reglement, double Solde_Reglement, int Nombres_Total_Articles, double Montant_Remises, double Montant_TVA_Total, double Prix_Commande_HT, double Prix_Commande_TTC, int ID_Client, int ID_Facture)
	{
		int ID_Commande;
		this->commande->setDate_livraison_prevue(Date_livraison_prevue);
		this->commande->setDate_emission_facture(Date_emission_facture);
		this->commande->setMoyen_Paiement(Moyen_Paiement);
		this->commande->setDate_Paiement(Date_Paiement);
		this->commande->setDate_Reglement(Date_Reglement);
		this->commande->setSolde_Reglement(Solde_Reglement);
		this->commande->setNombre_Total_Articles(Nombres_Total_Articles);
		this->commande->setMontant_Remises(Montant_Remises);
		this->commande->setMontant_TVA_Total(Montant_TVA_Total);
		this->commande->setPrix_Commande_HT(Prix_Commande_HT);
		this->commande->setPrix_Commande_TTC(Prix_Commande_TTC);
		this->commande->setID_Client(ID_Client);
		this->commande->setID_Facture(ID_Facture);

		ID_Commande = this->cad->actionRowsID(this->commande->INSERT());
		return ID_Commande;
	}
	void CLS_Commande::modifier(int ID_Commande, String^ Date_livraison_prevue, String^ Date_emission_facture, String^ Moyen_Paiement, String^ Date_Paiement, String^ Date_Reglement, double Solde_Reglement, int Nombres_Total_Articles, double Montant_Remises, double Montant_TVA_Total, double Prix_Commande_HT, double Prix_Commande_TTC, int ID_Client, int ID_Facture)
	{
		this->commande->setDate_livraison_prevue(Date_livraison_prevue);
		this->commande->setDate_emission_facture(Date_emission_facture);
		this->commande->setMoyen_Paiement(Moyen_Paiement);
		this->commande->setDate_Paiement(Date_Paiement);
		this->commande->setDate_Reglement(Date_Reglement);
		this->commande->setSolde_Reglement(Solde_Reglement);
		this->commande->setNombre_Total_Articles(Nombres_Total_Articles);
		this->commande->setMontant_Remises(Montant_Remises);
		this->commande->setMontant_TVA_Total(Montant_TVA_Total);
		this->commande->setPrix_Commande_HT(Prix_Commande_HT);
		this->commande->setPrix_Commande_TTC(Prix_Commande_TTC);
		this->commande->setID_Client(ID_Client);
		this->commande->setID_Facture(ID_Facture);
		this->cad->actionRows(this->commande->UPDATE());
	}
	void CLS_Commande::supprimer(int ID_Commande)
	{
		this->commande->setID_Commande(ID_Commande);
		this->cad->actionRows(this->commande->DELETE());
	}
}