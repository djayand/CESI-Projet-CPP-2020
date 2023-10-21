// CLC_Article.h
// Couche "composant" de la gestion du stock

#pragma once
#include "CLC_Sql.h"
#include "CLC_Perso.h"

using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Xml;
using namespace System;

namespace NS_Composants
{
	ref class CLC_Article  // Définition de notre classe
	{
	private:
		int ID_Article;
		String^ nom;
		String^ couleur;
		String^ nature;
		double prixHT; // Prix UNITAIRE
		double prixTTC; // Prix UNITAIRE
		double prixAchat; // Coût de fabrication pour l'entreprise
		double TVA;
		int qteStock;
		int seuil;

	public:
		CLC_Article(void);

		String^ SELECT(void); 
		String^ INSERT(void);
		String^ UPDATE(void);
		String^ DELETE(void);

		void setID(int);  // Accesseurs
		void setNom(String^); // (setters)
		void setCouleur(String^);
		void setNature(String^);
		void setPrixHT(double);
		void setPrixTTC(double);
		void setPrixAchat(double);
		void setTVA(double);
		void setQteStock(int);
		void setSeuil(int);
		
		int getID(void);  // Mutateurs
		String^ getNom(void); // (getters)
		String^ getCouleur(void);
		String^ getNature(void);
		double getPrixHT(void);
		double getPrixTTC(void);
		double getTVA(void);
		double getPrixAchat(void);
		int getQteStock(void);
		int getSeuil(void);
	};
}
