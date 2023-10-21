// CLS_Article.h
// Couche "service" de la gestion du stock

#pragma once

#include "CLC_Sql.h"
#include "CLC_Article.h"

using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Xml;
using namespace System;

namespace NS_Svc
{
	ref class CLS_Article
	{
	private:
		NS_Composants::CLC_Sql^ cad;
		NS_Composants::CLC_Article^ article;
		DataSet^ ds;
	public:
		CLS_Article(void);
		DataSet^ listeArticles(String^);
		int ajouter(String^, String^, String^, double, double, double, double, int, int);
		void modifier(int, String^, String^, String^, double, double, double, double, int, int);
		void supprimer(int);
	};
}