// CLS_Commande.h
// Couche "service" de la gestion des commandes

#pragma once

#include "CLC_Sql.h"
#include "CLC_Commande.h"

using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Xml;
using namespace System;

namespace NS_Svc
{
	ref class CLS_Commande
	{
	private:
		NS_Composants::CLC_Sql^ cad;
		NS_Composants::CLC_Commande^ commande;
		DataSet^ ds;
	public:
		CLS_Commande(void);
		DataSet^ listeCommande(String^);
		int ajouter(String^, String^, String^, String^, String^, double, int, double, double, double, double, int, int);
		void modifier(int, String^, String^, String^, String^, String^, double, int, double, double, double, double, int, int);
		void supprimer(int);
	};
}