// CLS_Client.h
// Couche "service" de la gestion des clients

#pragma once

#include "CLC_Sql.h"
#include "CLC_Client.h"

using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Xml;
using namespace System;

namespace NS_Svc
{
	ref class CLS_Client
	{
	private:
		NS_Composants::CLC_Sql^ cad;
		NS_Composants::CLC_Client^ client;
		DataSet^ ds;
	public:
		CLS_Client(void);
		DataSet^ listeClient(String^);
		int ajouter(String^, String^, String^, String^, int);
		void modifier(int, String^, String^, String^, String^, int);
		void supprimer(int);
	};
}