// CLC_Commande.h
// Couche "composant" de la gestion des commandes

#pragma once
#include "CLC_Sql.h"

using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Xml;
using namespace System;

namespace NS_Composants
{
	ref class CLC_Commande
	{
	private:
		int ID_Commande;
		String^ Date_livraison_prevue;
		String^ Date_emission_facture;
		String^ Moyen_Paiement;
		String^ Date_Paiement;
		String^ Date_Reglement;
		double Solde_Reglement;
		int Nombre_Total_Articles;
		double Montant_Remises;
		double Montant_TVA_Total;
		double Prix_Commande_HT;
		double Prix_Commande_TTC;
		int ID_Client;
		int ID_Facture;

	public:
		CLC_Commande(void);
		String^ SELECT(void);
		String^ INSERT(void);
		String^ UPDATE(void);
		String^ DELETE(void);
		String^ QueryPM(void);

		void setID_Commande(int);

		void setDate_livraison_prevue(String^);
		void setDate_emission_facture(String^);
		void setMoyen_Paiement(String^);
		void setDate_Paiement(String^);
		void setDate_Reglement(String^);
		void setSolde_Reglement(double);
		void setNombre_Total_Articles(int);
		void setMontant_Remises(double);
		void setMontant_TVA_Total(double);
		void setPrix_Commande_HT(double);
		void setPrix_Commande_TTC(double);
		void setID_Client(int);
		void setID_Facture(int);

		int getID_Commande(void);

		String^ getDate_livraison_prevue(void);
		String^ getDate_emission_facture(void);
		String^ getMoyen_Paiement(void);
		String^ getDate_Paiement(void);
		String^ getDate_Reglement(void);
		double getSolde_Reglement(void);
		int getNombre_Total_Articles(void);
		double getMontant_Remises(void);
		double getMontant_TVA_Total(void);
		double getPrix_Commande_HT(void);
		double getPrix_Commande_TTC(void);
		int getID_Client(void);
		int getID_Facture(void);
	};
}
