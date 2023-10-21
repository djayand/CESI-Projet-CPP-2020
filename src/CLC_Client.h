// CLC_Client.h
// Couche "composant" de la gestion des clients

#pragma once
#include "CLC_Sql.h"

using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Xml;
using namespace System;

namespace NS_Composants
{
	ref class CLC_Client
	{
	private:
		int ID_Client;
		String^ Nom;
		String^ Prenom;
		String^ DateN;
		String^ DateC;
		int ID_Remise;

	public:
		CLC_Client(void);

		String^ SELECT(void);
		String^ INSERT(void);
		String^ UPDATE(void);
		String^ DELETE(void);

		void setID(int);
		void setNom(String^);
		void setPrenom(String^);
		void setDateN(String^);
		void setDateC(String^);
		void setID_Remise(int);

		int getID(void);
		String^ getNom(void);
		String^ getPrenom(void);
		String^ getDateN(void);
		String^ getDateC(void);
		int getID_Remise(void);
	};
}