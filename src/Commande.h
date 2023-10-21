// Commande.h
// Ce fichier code la gestion des commandes

#pragma once
#include "CLS_Commande.h"

namespace PooProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Description résumée de Perso
	/// </summary>
	public ref class Commande : public System::Windows::Forms::Form
	{
	public:
		Commande(void)
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
		~Commande()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ txt_ID;
	private: System::Windows::Forms::TextBox^ txt_dateLivraison;
	private: System::Windows::Forms::TextBox^ txt_dateFacture;
	private: System::Windows::Forms::TextBox^ txt_moyen;
	private: System::Windows::Forms::TextBox^ txt_datePaiement;
	private: System::Windows::Forms::TextBox^ txt_dateReglement;
	private: System::Windows::Forms::TextBox^ txt_remise;
	private: System::Windows::Forms::TextBox^ txt_solde;
	private: System::Windows::Forms::TextBox^ txt_nbArticles;
	private: System::Windows::Forms::TextBox^ txt_TVAt;
	private: System::Windows::Forms::TextBox^ txt_prixHTc;
	private: System::Windows::Forms::TextBox^ txt_prixTTCc;
	private: System::Windows::Forms::TextBox^ txt_ID_Client;
	private: System::Windows::Forms::TextBox^ txt_ID_Facture;
	private: System::Windows::Forms::TextBox^ txt_message;
	private: System::Windows::Forms::Button^ btn_Insert;
	private: System::Windows::Forms::Button^ btn_Update;
	private: System::Windows::Forms::Button^ btn_Delete;
	private: System::Windows::Forms::Button^ button_Save;
	private: System::Windows::Forms::Button^ btn_first;
	private: System::Windows::Forms::Button^ btn_next;
	private: System::Windows::Forms::Button^ btn_previous;
	private: System::Windows::Forms::Button^ btn_end;
	private: System::Windows::Forms::BindingSource^ bindingSource1;
	private: System::ComponentModel::IContainer^ components;
	private: NS_Svc::CLS_Commande^ processCommande;
	private: Data::DataSet^ ds;
	private: int index;
	private: String^ mode;

		   /// <summary>
		   /// Variable nécessaire au concepteur.
		   /// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->label8 = (gcnew System::Windows::Forms::Label());
			   this->label9 = (gcnew System::Windows::Forms::Label());
			   this->label10 = (gcnew System::Windows::Forms::Label());
			   this->label11 = (gcnew System::Windows::Forms::Label());
			   this->label12 = (gcnew System::Windows::Forms::Label());
			   this->label13 = (gcnew System::Windows::Forms::Label());
			   this->label14 = (gcnew System::Windows::Forms::Label());
			   this->txt_ID = (gcnew System::Windows::Forms::TextBox());
			   this->txt_dateLivraison = (gcnew System::Windows::Forms::TextBox());
			   this->txt_dateFacture = (gcnew System::Windows::Forms::TextBox());
			   this->txt_moyen = (gcnew System::Windows::Forms::TextBox());
			   this->txt_datePaiement = (gcnew System::Windows::Forms::TextBox());
			   this->txt_dateReglement = (gcnew System::Windows::Forms::TextBox());
			   this->txt_remise = (gcnew System::Windows::Forms::TextBox());
			   this->txt_solde = (gcnew System::Windows::Forms::TextBox());
			   this->txt_nbArticles = (gcnew System::Windows::Forms::TextBox());
			   this->txt_TVAt = (gcnew System::Windows::Forms::TextBox());
			   this->txt_prixHTc = (gcnew System::Windows::Forms::TextBox());
			   this->txt_prixTTCc = (gcnew System::Windows::Forms::TextBox());
			   this->txt_ID_Client = (gcnew System::Windows::Forms::TextBox());
			   this->txt_ID_Facture = (gcnew System::Windows::Forms::TextBox());
			   this->txt_message = (gcnew System::Windows::Forms::TextBox());
			   this->btn_Insert = (gcnew System::Windows::Forms::Button());
			   this->btn_Update = (gcnew System::Windows::Forms::Button());
			   this->btn_Delete = (gcnew System::Windows::Forms::Button());
			   this->button_Save = (gcnew System::Windows::Forms::Button());
			   this->btn_first = (gcnew System::Windows::Forms::Button());
			   this->btn_next = (gcnew System::Windows::Forms::Button());
			   this->btn_previous = (gcnew System::Windows::Forms::Button());
			   this->btn_end = (gcnew System::Windows::Forms::Button());
			   this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(30, 20);
			   this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(192, 29);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"ID Commande :";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->Location = System::Drawing::Point(30, 60);
			   this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(186, 29);
			   this->label2->TabIndex = 1;
			   this->label2->Text = L"Date livraison :";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label3->Location = System::Drawing::Point(30, 100);
			   this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(167, 29);
			   this->label3->TabIndex = 2;
			   this->label3->Text = L"Date facture :";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label4->Location = System::Drawing::Point(30, 140);
			   this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(219, 29);
			   this->label4->TabIndex = 3;
			   this->label4->Text = L"Moyen paiement :";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label5->Location = System::Drawing::Point(30, 180);
			   this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(196, 29);
			   this->label5->TabIndex = 4;
			   this->label5->Text = L"Date paiement :";
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label6->Location = System::Drawing::Point(30, 220);
			   this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(206, 29);
			   this->label6->TabIndex = 23;
			   this->label6->Text = L"Date règlement :";
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label7->Location = System::Drawing::Point(30, 260);
			   this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(221, 29);
			   this->label7->TabIndex = 20;
			   this->label7->Text = L"Solde règlement :";
			   // 
			   // label8
			   // 
			   this->label8->AutoSize = true;
			   this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label8->Location = System::Drawing::Point(30, 300);
			   this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label8->Name = L"label8";
			   this->label8->Size = System::Drawing::Size(233, 29);
			   this->label8->TabIndex = 21;
			   this->label8->Text = L"Nombre d\'articles :";
			   // 
			   // label9
			   // 
			   this->label9->AutoSize = true;
			   this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label9->Location = System::Drawing::Point(30, 340);
			   this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label9->Name = L"label9";
			   this->label9->Size = System::Drawing::Size(206, 29);
			   this->label9->TabIndex = 22;
			   this->label9->Text = L"Montant remise :";
			   // 
			   // label10
			   // 
			   this->label10->AutoSize = true;
			   this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label10->Location = System::Drawing::Point(30, 380);
			   this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label10->Name = L"label10";
			   this->label10->Size = System::Drawing::Size(232, 29);
			   this->label10->TabIndex = 33;
			   this->label10->Text = L"Montant TVA total :";
			   // 
			   // label11
			   // 
			   this->label11->AutoSize = true;
			   this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label11->Location = System::Drawing::Point(30, 420);
			   this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label11->Name = L"label11";
			   this->label11->Size = System::Drawing::Size(249, 29);
			   this->label11->TabIndex = 34;
			   this->label11->Text = L"Prix commande HT :";
			   // 
			   // label12
			   // 
			   this->label12->AutoSize = true;
			   this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label12->Location = System::Drawing::Point(30, 460);
			   this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label12->Name = L"label12";
			   this->label12->Size = System::Drawing::Size(266, 29);
			   this->label12->TabIndex = 35;
			   this->label12->Text = L"Prix commande TTC :";
			   // 
			   // label13
			   // 
			   this->label13->AutoSize = true;
			   this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label13->Location = System::Drawing::Point(30, 500);
			   this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label13->Name = L"label13";
			   this->label13->Size = System::Drawing::Size(127, 29);
			   this->label13->TabIndex = 36;
			   this->label13->Text = L"ID Client :";
			   // 
			   // label14
			   // 
			   this->label14->AutoSize = true;
			   this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label14->Location = System::Drawing::Point(30, 540);
			   this->label14->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label14->Name = L"label14";
			   this->label14->Size = System::Drawing::Size(147, 29);
			   this->label14->TabIndex = 37;
			   this->label14->Text = L"ID Facture :";
			   // 
			   // txt_ID
			   // 
			   this->txt_ID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txt_ID->Location = System::Drawing::Point(300, 20);
			   this->txt_ID->Margin = System::Windows::Forms::Padding(4);
			   this->txt_ID->Name = L"txt_ID";
			   this->txt_ID->ReadOnly = true;
			   this->txt_ID->Size = System::Drawing::Size(332, 34);
			   this->txt_ID->TabIndex = 5;
			   // 
			   // txt_dateLivraison
			   // 
			   this->txt_dateLivraison->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->txt_dateLivraison->Location = System::Drawing::Point(300, 60);
			   this->txt_dateLivraison->Margin = System::Windows::Forms::Padding(4);
			   this->txt_dateLivraison->Name = L"txt_dateLivraison";
			   this->txt_dateLivraison->Size = System::Drawing::Size(332, 34);
			   this->txt_dateLivraison->TabIndex = 6;
			   // 
			   // txt_dateFacture
			   // 
			   this->txt_dateFacture->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->txt_dateFacture->Location = System::Drawing::Point(300, 100);
			   this->txt_dateFacture->Margin = System::Windows::Forms::Padding(4);
			   this->txt_dateFacture->Name = L"txt_dateFacture";
			   this->txt_dateFacture->Size = System::Drawing::Size(332, 34);
			   this->txt_dateFacture->TabIndex = 7;
			   // 
			   // txt_moyen
			   // 
			   this->txt_moyen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txt_moyen->Location = System::Drawing::Point(300, 140);
			   this->txt_moyen->Margin = System::Windows::Forms::Padding(4);
			   this->txt_moyen->Name = L"txt_moyen";
			   this->txt_moyen->Size = System::Drawing::Size(332, 34);
			   this->txt_moyen->TabIndex = 8;
			   // 
			   // txt_datePaiement
			   // 
			   this->txt_datePaiement->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->txt_datePaiement->Location = System::Drawing::Point(300, 180);
			   this->txt_datePaiement->Margin = System::Windows::Forms::Padding(4);
			   this->txt_datePaiement->Name = L"txt_datePaiement";
			   this->txt_datePaiement->Size = System::Drawing::Size(332, 34);
			   this->txt_datePaiement->TabIndex = 9;
			   // 
			   // txt_dateReglement
			   // 
			   this->txt_dateReglement->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->txt_dateReglement->Location = System::Drawing::Point(300, 220);
			   this->txt_dateReglement->Margin = System::Windows::Forms::Padding(4);
			   this->txt_dateReglement->Name = L"txt_dateReglement";
			   this->txt_dateReglement->Size = System::Drawing::Size(332, 34);
			   this->txt_dateReglement->TabIndex = 24;
			   // 
			   // txt_remise
			   // 
			   this->txt_remise->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txt_remise->Location = System::Drawing::Point(300, 340);
			   this->txt_remise->Margin = System::Windows::Forms::Padding(4);
			   this->txt_remise->Name = L"txt_remise";
			   this->txt_remise->Size = System::Drawing::Size(332, 34);
			   this->txt_remise->TabIndex = 25;
			   // 
			   // txt_solde
			   // 
			   this->txt_solde->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txt_solde->Location = System::Drawing::Point(300, 260);
			   this->txt_solde->Margin = System::Windows::Forms::Padding(4);
			   this->txt_solde->Name = L"txt_solde";
			   this->txt_solde->Size = System::Drawing::Size(332, 34);
			   this->txt_solde->TabIndex = 26;
			   // 
			   // txt_nbArticles
			   // 
			   this->txt_nbArticles->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txt_nbArticles->Location = System::Drawing::Point(300, 300);
			   this->txt_nbArticles->Margin = System::Windows::Forms::Padding(4);
			   this->txt_nbArticles->Name = L"txt_nbArticles";
			   this->txt_nbArticles->Size = System::Drawing::Size(332, 34);
			   this->txt_nbArticles->TabIndex = 27;
			   // 
			   // txt_TVAt
			   // 
			   this->txt_TVAt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txt_TVAt->Location = System::Drawing::Point(300, 380);
			   this->txt_TVAt->Margin = System::Windows::Forms::Padding(4);
			   this->txt_TVAt->Name = L"txt_TVAt";
			   this->txt_TVAt->Size = System::Drawing::Size(332, 34);
			   this->txt_TVAt->TabIndex = 28;
			   // 
			   // txt_prixHTc
			   // 
			   this->txt_prixHTc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txt_prixHTc->Location = System::Drawing::Point(300, 420);
			   this->txt_prixHTc->Margin = System::Windows::Forms::Padding(4);
			   this->txt_prixHTc->Name = L"txt_prixHTc";
			   this->txt_prixHTc->Size = System::Drawing::Size(332, 34);
			   this->txt_prixHTc->TabIndex = 29;
			   // 
			   // txt_prixTTCc
			   // 
			   this->txt_prixTTCc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txt_prixTTCc->Location = System::Drawing::Point(300, 460);
			   this->txt_prixTTCc->Margin = System::Windows::Forms::Padding(4);
			   this->txt_prixTTCc->Name = L"txt_prixTTCc";
			   this->txt_prixTTCc->Size = System::Drawing::Size(332, 34);
			   this->txt_prixTTCc->TabIndex = 30;
			   // 
			   // txt_ID_Client
			   // 
			   this->txt_ID_Client->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txt_ID_Client->Location = System::Drawing::Point(300, 500);
			   this->txt_ID_Client->Margin = System::Windows::Forms::Padding(4);
			   this->txt_ID_Client->Name = L"txt_ID_Client";
			   this->txt_ID_Client->Size = System::Drawing::Size(332, 34);
			   this->txt_ID_Client->TabIndex = 31;
			   // 
			   // txt_ID_Facture
			   // 
			   this->txt_ID_Facture->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txt_ID_Facture->Location = System::Drawing::Point(300, 540);
			   this->txt_ID_Facture->Margin = System::Windows::Forms::Padding(4);
			   this->txt_ID_Facture->Name = L"txt_ID_Facture";
			   this->txt_ID_Facture->Size = System::Drawing::Size(332, 34);
			   this->txt_ID_Facture->TabIndex = 32;
			   // 
			   // txt_message
			   // 
			   this->txt_message->Location = System::Drawing::Point(660, 20);
			   this->txt_message->Margin = System::Windows::Forms::Padding(4);
			   this->txt_message->Multiline = true;
			   this->txt_message->Name = L"txt_message";
			   this->txt_message->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			   this->txt_message->Size = System::Drawing::Size(350, 564);
			   this->txt_message->TabIndex = 7;
			   // 
			   // btn_Insert
			   // 
			   this->btn_Insert->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btn_Insert->Location = System::Drawing::Point(35, 598);
			   this->btn_Insert->Margin = System::Windows::Forms::Padding(4);
			   this->btn_Insert->Name = L"btn_Insert";
			   this->btn_Insert->Size = System::Drawing::Size(189, 44);
			   this->btn_Insert->TabIndex = 12;
			   this->btn_Insert->Text = L"Insérer";
			   this->btn_Insert->UseVisualStyleBackColor = true;
			   this->btn_Insert->Click += gcnew System::EventHandler(this, &Commande::InsertCommande);
			   // 
			   // btn_Update
			   // 
			   this->btn_Update->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btn_Update->Location = System::Drawing::Point(239, 598);
			   this->btn_Update->Margin = System::Windows::Forms::Padding(4);
			   this->btn_Update->Name = L"btn_Update";
			   this->btn_Update->Size = System::Drawing::Size(189, 44);
			   this->btn_Update->TabIndex = 13;
			   this->btn_Update->Text = L"Modifier";
			   this->btn_Update->UseVisualStyleBackColor = true;
			   this->btn_Update->Click += gcnew System::EventHandler(this, &Commande::UpdateCommande);
			   // 
			   // btn_Delete
			   // 
			   this->btn_Delete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btn_Delete->Location = System::Drawing::Point(443, 598);
			   this->btn_Delete->Margin = System::Windows::Forms::Padding(4);
			   this->btn_Delete->Name = L"btn_Delete";
			   this->btn_Delete->Size = System::Drawing::Size(189, 44);
			   this->btn_Delete->TabIndex = 14;
			   this->btn_Delete->Text = L"Supprimer";
			   this->btn_Delete->UseVisualStyleBackColor = true;
			   this->btn_Delete->Click += gcnew System::EventHandler(this, &Commande::DeleteCommande);
			   // 
			   // button_Save
			   // 
			   this->button_Save->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button_Save->Location = System::Drawing::Point(39, 650);
			   this->button_Save->Margin = System::Windows::Forms::Padding(4);
			   this->button_Save->Name = L"button_Save";
			   this->button_Save->Size = System::Drawing::Size(593, 44);
			   this->button_Save->TabIndex = 15;
			   this->button_Save->Text = L"Sauvegarder";
			   this->button_Save->UseVisualStyleBackColor = true;
			   this->button_Save->Click += gcnew System::EventHandler(this, &Commande::EnrengistrerCommande);
			   // 
			   // btn_first
			   // 
			   this->btn_first->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btn_first->Location = System::Drawing::Point(660, 592);
			   this->btn_first->Margin = System::Windows::Forms::Padding(4);
			   this->btn_first->Name = L"btn_first";
			   this->btn_first->Size = System::Drawing::Size(60, 40);
			   this->btn_first->TabIndex = 16;
			   this->btn_first->Text = L"<<";
			   this->btn_first->UseVisualStyleBackColor = true;
			   this->btn_first->Click += gcnew System::EventHandler(this, &Commande::FirstClick);
			   // 
			   // btn_next
			   // 
			   this->btn_next->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btn_next->Location = System::Drawing::Point(840, 592);
			   this->btn_next->Margin = System::Windows::Forms::Padding(4);
			   this->btn_next->Name = L"btn_next";
			   this->btn_next->Size = System::Drawing::Size(40, 40);
			   this->btn_next->TabIndex = 17;
			   this->btn_next->Text = L">";
			   this->btn_next->UseVisualStyleBackColor = true;
			   this->btn_next->Click += gcnew System::EventHandler(this, &Commande::Next);
			   // 
			   // btn_previous
			   // 
			   this->btn_previous->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btn_previous->Location = System::Drawing::Point(792, 592);
			   this->btn_previous->Margin = System::Windows::Forms::Padding(4);
			   this->btn_previous->Name = L"btn_previous";
			   this->btn_previous->Size = System::Drawing::Size(40, 40);
			   this->btn_previous->TabIndex = 18;
			   this->btn_previous->Text = L"<";
			   this->btn_previous->UseVisualStyleBackColor = true;
			   this->btn_previous->Click += gcnew System::EventHandler(this, &Commande::Previous);
			   // 
			   // btn_end
			   // 
			   this->btn_end->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btn_end->Location = System::Drawing::Point(950, 592);
			   this->btn_end->Margin = System::Windows::Forms::Padding(4);
			   this->btn_end->Name = L"btn_end";
			   this->btn_end->Size = System::Drawing::Size(60, 40);
			   this->btn_end->TabIndex = 19;
			   this->btn_end->Text = L">>";
			   this->btn_end->UseVisualStyleBackColor = true;
			   this->btn_end->Click += gcnew System::EventHandler(this, &Commande::EndClick);
			   // 
			   // Commande
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1023, 696);
			   this->Controls->Add(this->label14);
			   this->Controls->Add(this->label13);
			   this->Controls->Add(this->label12);
			   this->Controls->Add(this->label11);
			   this->Controls->Add(this->label10);
			   this->Controls->Add(this->txt_ID_Facture);
			   this->Controls->Add(this->txt_ID_Client);
			   this->Controls->Add(this->txt_prixTTCc);
			   this->Controls->Add(this->txt_prixHTc);
			   this->Controls->Add(this->txt_TVAt);
			   this->Controls->Add(this->txt_nbArticles);
			   this->Controls->Add(this->txt_solde);
			   this->Controls->Add(this->txt_remise);
			   this->Controls->Add(this->txt_dateReglement);
			   this->Controls->Add(this->label6);
			   this->Controls->Add(this->label9);
			   this->Controls->Add(this->label8);
			   this->Controls->Add(this->label7);
			   this->Controls->Add(this->btn_end);
			   this->Controls->Add(this->btn_previous);
			   this->Controls->Add(this->btn_next);
			   this->Controls->Add(this->btn_first);
			   this->Controls->Add(this->txt_message);
			   this->Controls->Add(this->button_Save);
			   this->Controls->Add(this->btn_Delete);
			   this->Controls->Add(this->btn_Update);
			   this->Controls->Add(this->btn_Insert);
			   this->Controls->Add(this->txt_datePaiement);
			   this->Controls->Add(this->txt_moyen);
			   this->Controls->Add(this->txt_dateFacture);
			   this->Controls->Add(this->txt_dateLivraison);
			   this->Controls->Add(this->txt_ID);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Location = System::Drawing::Point(16, 241);
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"Commande";
			   this->Text = L"Outil de gestion des commandes";
			   this->Load += gcnew System::EventHandler(this, &Commande::CommandeLoad);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

		   // Lier l'application et la BDD
	private: System::Void CommandeLoad(System::Object^ sender, System::EventArgs^ e) {
		this->index = 0;
		this->mode = "RIEN";
		this->ds = gcnew Data::DataSet();
		this->processCommande = gcnew NS_Svc::CLS_Commande();
		this->loadData(this->index);
		this->txt_message->Text = "Data chargées";
	}
		   // Charger des données  
	private: void loadData(int index)
	{
		this->ds->Clear();
		this->ds = this->processCommande->listeCommande("liste");
		this->txt_ID->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[0]);
		this->txt_dateLivraison->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[1]);
		this->txt_dateFacture->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[2]);
		this->txt_moyen->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[3]);
		this->txt_datePaiement->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[4]);
		this->txt_dateReglement->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[5]);
		this->txt_remise->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[6]);
		this->txt_solde->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[7]);
		this->txt_nbArticles->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[8]);
		this->txt_TVAt->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[9]);
		this->txt_prixHTc->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[10]);
		this->txt_prixTTCc->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[11]);
		this->txt_ID_Client->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[12]);
		this->txt_ID_Facture->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[13]);
	}

		   // Aller au 1er ID
	private: System::Void FirstClick(System::Object^ sender, System::EventArgs^ e)
	{
		this->index = 0;
		this->loadData(this->index);
		this->txt_message->Text = "Enregistrement n° : " + (this->index + 1);
	}

		   // Aller a l'ID précédent
	private: System::Void Previous(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->index > 0)
		{
			this->index--;
			this->loadData(this->index);
			this->txt_message->Text = "Enregistrement n° : " + (this->index + 1);
		}
	}

		   // Aller a l'ID suivant
	private: System::Void Next(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->index < this->ds->Tables["liste"]->Rows->Count - 1)
		{
			this->index++;
			this->loadData(this->index);
			this->txt_message->Text = "Enregistrement n° : " + (this->index + 1);
		}
	}

		   // Aller au dernier ID
	private: System::Void EndClick(System::Object^ sender, System::EventArgs^ e)
	{
		this->index = this->ds->Tables["liste"]->Rows->Count - 1;
		this->loadData(this->index);
		this->txt_message->Text = "Enregistrement n° : " + (this->index + 1);
	}

		   // Insérer une Commande
	private: System::Void InsertCommande(System::Object^ sender, System::EventArgs^ e)
	{
		this->txt_ID->Clear();
		this->txt_dateLivraison->Clear();
		this->txt_dateFacture->Clear();
		this->txt_moyen->Clear();
		this->txt_datePaiement->Clear();
		this->txt_dateReglement->Clear();
		this->txt_remise->Clear();
		this->txt_solde->Clear();
		this->txt_nbArticles->Clear();
		this->txt_TVAt->Clear();
		this->txt_prixHTc->Clear();
		this->txt_prixTTCc->Clear();
		this->txt_ID_Client->Clear();
		this->txt_ID_Facture->Clear();
		this->mode = "insert";
		this->txt_message->Text = "Saississez les informations";
	}

		   // Modifier une Commande
	private: System::Void UpdateCommande(System::Object^ sender, System::EventArgs^ e)
	{
		this->mode = "update";
		this->txt_message->Text = "Veuillez modifier les information de la nouvelle courante et enregistrer.";
	}

		   // Supprimer une Commande
	private: System::Void DeleteCommande(System::Object^ sender, System::EventArgs^ e)
	{
		this->mode = "delete";
		this->txt_message->Text = "Veuillez confirmer la suppression de la personne en cours en enregistrant.";
	}

		   // Enrengistrer une Commande
	private: System::Void EnrengistrerCommande(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->mode == "insert")
		{
			int ID_Commande;
			ID_Commande = this->processCommande->ajouter(this->txt_dateLivraison->Text, this->txt_dateFacture->Text, this->txt_moyen->Text, this->txt_datePaiement->Text, this->txt_dateReglement->Text, Convert::ToDouble(this->txt_remise->Text), Convert::ToDouble(this->txt_solde->Text), Convert::ToInt32(this->txt_nbArticles->Text), Convert::ToDouble(this->txt_TVAt->Text), Convert::ToDouble(this->txt_prixHTc->Text), Convert::ToDouble(this->txt_prixTTCc->Text), Convert::ToInt32(this->txt_ID_Client->Text), Convert::ToInt32(this->txt_ID_Facture->Text));
			this->txt_message->Text = "L'ID généré est le : " + ID_Commande + ". ";
		}
		else if (this->mode == "update")
		{
			this->processCommande->modifier(Convert::ToInt32(this->txt_ID->Text), this->txt_dateLivraison->Text, this->txt_dateFacture->Text, this->txt_moyen->Text, this->txt_datePaiement->Text, this->txt_dateReglement->Text, Convert::ToDouble(this->txt_remise->Text), Convert::ToDouble(this->txt_solde->Text), Convert::ToInt32(this->txt_nbArticles->Text), Convert::ToDouble(this->txt_TVAt->Text), Convert::ToDouble(this->txt_prixHTc->Text), Convert::ToDouble(this->txt_prixTTCc->Text), Convert::ToInt32(this->txt_ID_Client->Text), Convert::ToInt32(this->txt_ID_Facture->Text));
		}
		else if (this->mode == "delete")
		{
			this->processCommande->supprimer(Convert::ToInt32(this->txt_ID->Text));
		}
		this->index = 0;
		this->loadData(this->index);
		this->txt_message->Text += "Traitement terminé.";
	}
};
}