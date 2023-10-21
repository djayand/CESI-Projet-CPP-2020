// CLS_Perso.h
// Couche "service" de la gestion du personnel

#pragma once

#include "CLC_Sql.h"
#include "CLC_Perso.h"

using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Xml;
using namespace System;

namespace NS_Svc
{
	ref class CLS_Perso
	{
	private:
		NS_Composants::CLC_Sql^ cad;
		NS_Composants::CLC_Perso^ personnel;
		DataSet^ ds;
	public:
		CLS_Perso(void);
		DataSet^ listePersonnes(String^);
		int ajouter(String^, String^, String^, String^);
		void modifier(int, String^, String^, String^, String^);
		void supprimer(int);
	};
}