// CLC_Perso.h
// Couche "composant" de la gestion du personnel

#pragma once
#include "CLC_Sql.h"

using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Xml;
using namespace System;

namespace NS_Composants
{
	ref class CLC_Perso
	{
	private:
		int ID_Personnel;
		String^ Nom;
		String^ Prenom;
		String^ DateE;
		String^ Adresse;

	public:
		CLC_Perso(void);

		String^ SELECT(void);
		String^ INSERT(void);
		String^ UPDATE(void);
		String^ DELETE(void);

		void setID(int);
		void setPrenom(String^);
		void setNom(String^);
		void setDateE(String^);
		void setAdresse(String^);

		int getId(void);
		String^ getNom(void);
		String^ getPrenom(void);
		String^ getDateE(void);
		String^ getAdresse(void);
	};
}
