// Menu.h
// Ce fichier code le menu général de l'application

#pragma once

#include "Perso.h"
#include "Client.h"
#include "Article.h"
#include "Commande.h"
#include "Stats.h"

namespace PooProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de menu
	/// </summary>
	public ref class menu : public System::Windows::Forms::Form
	{
	public:
		menu(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~menu()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ buttonClient;
	private: System::Windows::Forms::Button^ buttonPerso;
	private: System::Windows::Forms::Button^ buttonCommandes;
	private: System::Windows::Forms::Button^ buttonStock;
	private: System::Windows::Forms::Button^ buttonStats;

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(menu::typeid));
			this->buttonClient = (gcnew System::Windows::Forms::Button());
			this->buttonPerso = (gcnew System::Windows::Forms::Button());
			this->buttonCommandes = (gcnew System::Windows::Forms::Button());
			this->buttonStock = (gcnew System::Windows::Forms::Button());
			this->buttonStats = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonClient
			// 
			this->buttonClient->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonClient->Location = System::Drawing::Point(170, 50);
			this->buttonClient->Name = L"buttonClient";
			this->buttonClient->Size = System::Drawing::Size(380, 50);
			this->buttonClient->TabIndex = 0;
			this->buttonClient->Text = L"Gestion des clients";
			this->buttonClient->UseVisualStyleBackColor = true;
			this->buttonClient->Click += gcnew System::EventHandler(this, &menu::ClientClick);
			// 
			// buttonPerso
			// 
			this->buttonPerso->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonPerso->Location = System::Drawing::Point(170, 140);
			this->buttonPerso->Name = L"buttonPerso";
			this->buttonPerso->Size = System::Drawing::Size(380, 50);
			this->buttonPerso->TabIndex = 1;
			this->buttonPerso->Text = L"Gestion du personnel";
			this->buttonPerso->UseVisualStyleBackColor = true;
			this->buttonPerso->Click += gcnew System::EventHandler(this, &menu::PersoClick);
			// 
			// buttonCommandes
			// 
			this->buttonCommandes->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonCommandes->Location = System::Drawing::Point(170, 230);
			this->buttonCommandes->Name = L"buttonCommandes";
			this->buttonCommandes->Size = System::Drawing::Size(380, 50);
			this->buttonCommandes->TabIndex = 7;
			this->buttonCommandes->Text = L"Gestion des commandes";
			this->buttonCommandes->UseVisualStyleBackColor = true;
			this->buttonCommandes->Click += gcnew System::EventHandler(this, &menu::CommandeClick);
			// 
			// buttonStock
			// 
			this->buttonStock->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonStock->Location = System::Drawing::Point(170, 320);
			this->buttonStock->Name = L"buttonStock";
			this->buttonStock->Size = System::Drawing::Size(380, 50);
			this->buttonStock->TabIndex = 8;
			this->buttonStock->Text = L"Gestion du stock";
			this->buttonStock->UseVisualStyleBackColor = true;
			this->buttonStock->Click += gcnew System::EventHandler(this, &menu::StockClick);
			// 
			// buttonStats
			// 
			this->buttonStats->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonStats->Location = System::Drawing::Point(170, 410);
			this->buttonStats->Name = L"buttonStats";
			this->buttonStats->Size = System::Drawing::Size(380, 50);
			this->buttonStats->TabIndex = 9;
			this->buttonStats->Text = L"Accès au statistiques";
			this->buttonStats->UseVisualStyleBackColor = true;
			this->buttonStats->Click += gcnew System::EventHandler(this, &menu::StatsClick);
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;;
			this->ClientSize = System::Drawing::Size(702, 533);
			this->Controls->Add(this->buttonStats);
			this->Controls->Add(this->buttonStock);
			this->Controls->Add(this->buttonCommandes);
			this->Controls->Add(this->buttonPerso);
			this->Controls->Add(this->buttonClient);
			this->ForeColor = System::Drawing::SystemColors::InfoText;
			this->Name = L"menu";
			this->Text = L"Menu principal";
			this->ResumeLayout(false);

		}
#pragma endregion

		// Gérer les clients
	private: System::Void ClientClick(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		PooProject::Client ClientF;
		ClientF.ShowDialog();
		this->Show();
	}

		   // Gérer le personnel
	private: System::Void PersoClick(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		PooProject::Perso PersoF;
		PersoF.ShowDialog();
		this->Show();
	}

		   // Gérer les commandes
	private: System::Void CommandeClick(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		PooProject::Commande CommandeF;
		CommandeF.ShowDialog();
		this->Show();
	}

		   // Gérer le stock
	private: System::Void StockClick(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		PooProject::Article StockF;
		StockF.ShowDialog();
		this->Show();
	}

		   // Consulter les statistiques
	private: System::Void StatsClick(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		PooProject::Stats StatsF;
		StatsF.ShowDialog();
		this->Show();
	}
};
}