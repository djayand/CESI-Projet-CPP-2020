// Commande.h
// Ce fichier code la gestion des commandes

#pragma once
#include "CLS_Article.h"

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
	public ref class Article : public System::Windows::Forms::Form
	{
	public:
		Article(void)
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
		~Article()
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
	private: System::Windows::Forms::TextBox^ txt_ID;
	private: System::Windows::Forms::TextBox^ txt_nom;
	private: System::Windows::Forms::TextBox^ txt_couleur;
	private: System::Windows::Forms::TextBox^ txt_nature;
	private: System::Windows::Forms::TextBox^ txt_prixHT;
	private: System::Windows::Forms::TextBox^ txt_prixTTC;
	private: System::Windows::Forms::TextBox^ txt_prixAchat;
	private: System::Windows::Forms::TextBox^ txt_TVA;
	private: System::Windows::Forms::TextBox^ txt_qte;
	private: System::Windows::Forms::TextBox^ txt_rea;
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
	private: NS_Svc::CLS_Article^ processArticle;
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
			   this->txt_ID = (gcnew System::Windows::Forms::TextBox());
			   this->txt_couleur = (gcnew System::Windows::Forms::TextBox());
			   this->txt_nom = (gcnew System::Windows::Forms::TextBox());
			   this->txt_nature = (gcnew System::Windows::Forms::TextBox());
			   this->txt_prixHT = (gcnew System::Windows::Forms::TextBox());
			   this->txt_prixTTC = (gcnew System::Windows::Forms::TextBox());
			   this->txt_prixAchat = (gcnew System::Windows::Forms::TextBox());
			   this->txt_TVA = (gcnew System::Windows::Forms::TextBox());
			   this->txt_qte = (gcnew System::Windows::Forms::TextBox());
			   this->txt_rea = (gcnew System::Windows::Forms::TextBox());
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
			   this->label1->Size = System::Drawing::Size(133, 29);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"ID Article :";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->Location = System::Drawing::Point(30, 60);
			   this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(82, 29);
			   this->label2->TabIndex = 26;
			   this->label2->Text = L"Nom :";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label3->Location = System::Drawing::Point(30, 100);
			   this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(119, 29);
			   this->label3->TabIndex = 1;
			   this->label3->Text = L"Couleur :";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label4->Location = System::Drawing::Point(30, 140);
			   this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(105, 29);
			   this->label4->TabIndex = 27;
			   this->label4->Text = L"Nature :";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label5->Location = System::Drawing::Point(30, 180);
			   this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(208, 29);
			   this->label5->TabIndex = 2;
			   this->label5->Text = L"Prix unitaire HT :";
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label6->Location = System::Drawing::Point(30, 220);
			   this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(225, 29);
			   this->label6->TabIndex = 3;
			   this->label6->Text = L"Prix unitaire TTC :";
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label7->Location = System::Drawing::Point(30, 260);
			   this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(198, 29);
			   this->label7->TabIndex = 31;
			   this->label7->Text = L"Prix entreprise :";
			   // 
			   // label8
			   // 
			   this->label8->AutoSize = true;
			   this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label8->Location = System::Drawing::Point(30, 300);
			   this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label8->Name = L"label8";
			   this->label8->Size = System::Drawing::Size(175, 29);
			   this->label8->TabIndex = 4;
			   this->label8->Text = L"Montant TVA :";
			   // 
			   // label9
			   // 
			   this->label9->AutoSize = true;
			   this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label9->Location = System::Drawing::Point(30, 340);
			   this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label9->Name = L"label9";
			   this->label9->Size = System::Drawing::Size(173, 29);
			   this->label9->TabIndex = 23;
			   this->label9->Text = L"Qté en stock :";
			   // 
			   // label10
			   // 
			   this->label10->AutoSize = true;
			   this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label10->Location = System::Drawing::Point(30, 380);
			   this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label10->Name = L"label10";
			   this->label10->Size = System::Drawing::Size(132, 29);
			   this->label10->TabIndex = 25;
			   this->label10->Text = L"Seuil réa :";
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
			   // txt_couleur
			   // 
			   this->txt_couleur->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txt_couleur->Location = System::Drawing::Point(300, 100);
			   this->txt_couleur->Margin = System::Windows::Forms::Padding(4);
			   this->txt_couleur->Name = L"txt_couleur";
			   this->txt_couleur->Size = System::Drawing::Size(332, 34);
			   this->txt_couleur->TabIndex = 6;
			   // 
			   // txt_nom
			   // 
			   this->txt_nom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txt_nom->Location = System::Drawing::Point(300, 60);
			   this->txt_nom->Margin = System::Windows::Forms::Padding(4);
			   this->txt_nom->Name = L"txt_nom";
			   this->txt_nom->Size = System::Drawing::Size(332, 34);
			   this->txt_nom->TabIndex = 29;
			   // 
			   // txt_nature
			   // 
			   this->txt_nature->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txt_nature->Location = System::Drawing::Point(300, 140);
			   this->txt_nature->Margin = System::Windows::Forms::Padding(4);
			   this->txt_nature->Name = L"txt_nature";
			   this->txt_nature->Size = System::Drawing::Size(332, 34);
			   this->txt_nature->TabIndex = 7;
			   // 
			   // txt_prixHT
			   // 
			   this->txt_prixHT->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txt_prixHT->Location = System::Drawing::Point(300, 180);
			   this->txt_prixHT->Margin = System::Windows::Forms::Padding(4);
			   this->txt_prixHT->Name = L"txt_prixHT";
			   this->txt_prixHT->Size = System::Drawing::Size(332, 34);
			   this->txt_prixHT->TabIndex = 8;
			   // 
			   // txt_prixTTC
			   // 
			   this->txt_prixTTC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txt_prixTTC->Location = System::Drawing::Point(300, 220);
			   this->txt_prixTTC->Margin = System::Windows::Forms::Padding(4);
			   this->txt_prixTTC->Name = L"txt_prixTTC";
			   this->txt_prixTTC->Size = System::Drawing::Size(332, 34);
			   this->txt_prixTTC->TabIndex = 9;
			   // 
			   // txt_prixAchat
			   // 
			   this->txt_prixAchat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txt_prixAchat->Location = System::Drawing::Point(300, 260);
			   this->txt_prixAchat->Margin = System::Windows::Forms::Padding(4);
			   this->txt_prixAchat->Name = L"txt_prixAchat";
			   this->txt_prixAchat->Size = System::Drawing::Size(332, 34);
			   this->txt_prixAchat->TabIndex = 24;
			   // 
			   // txt_TVA
			   // 
			   this->txt_TVA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txt_TVA->Location = System::Drawing::Point(300, 300);
			   this->txt_TVA->Margin = System::Windows::Forms::Padding(4);
			   this->txt_TVA->Name = L"txt_TVA";
			   this->txt_TVA->Size = System::Drawing::Size(332, 34);
			   this->txt_TVA->TabIndex = 28;
			   // 
			   // txt_qte
			   // 
			   this->txt_qte->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txt_qte->Location = System::Drawing::Point(300, 340);
			   this->txt_qte->Margin = System::Windows::Forms::Padding(4);
			   this->txt_qte->Name = L"txt_qte";
			   this->txt_qte->Size = System::Drawing::Size(332, 34);
			   this->txt_qte->TabIndex = 30;
			   // 
			   // txt_rea
			   // 
			   this->txt_rea->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txt_rea->Location = System::Drawing::Point(300, 380);
			   this->txt_rea->Margin = System::Windows::Forms::Padding(4);
			   this->txt_rea->Name = L"txt_rea";
			   this->txt_rea->Size = System::Drawing::Size(332, 34);
			   this->txt_rea->TabIndex = 32;
			   // 
			   // txt_message
			   // 
			   this->txt_message->Location = System::Drawing::Point(655, 20);
			   this->txt_message->Margin = System::Windows::Forms::Padding(4);
			   this->txt_message->Multiline = true;
			   this->txt_message->Name = L"txt_message";
			   this->txt_message->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			   this->txt_message->Size = System::Drawing::Size(350, 394);
			   this->txt_message->TabIndex = 7;
			   // 
			   // btn_Insert
			   // 
			   this->btn_Insert->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btn_Insert->Location = System::Drawing::Point(35, 438);
			   this->btn_Insert->Margin = System::Windows::Forms::Padding(4);
			   this->btn_Insert->Name = L"btn_Insert";
			   this->btn_Insert->Size = System::Drawing::Size(189, 44);
			   this->btn_Insert->TabIndex = 12;
			   this->btn_Insert->Text = L"Insérer";
			   this->btn_Insert->UseVisualStyleBackColor = true;
			   this->btn_Insert->Click += gcnew System::EventHandler(this, &Article::InsertArticle);
			   // 
			   // btn_Update
			   // 
			   this->btn_Update->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btn_Update->Location = System::Drawing::Point(239, 438);
			   this->btn_Update->Margin = System::Windows::Forms::Padding(4);
			   this->btn_Update->Name = L"btn_Update";
			   this->btn_Update->Size = System::Drawing::Size(189, 44);
			   this->btn_Update->TabIndex = 13;
			   this->btn_Update->Text = L"Modifier";
			   this->btn_Update->UseVisualStyleBackColor = true;
			   this->btn_Update->Click += gcnew System::EventHandler(this, &Article::UpdateArticle);
			   // 
			   // btn_Delete
			   // 
			   this->btn_Delete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btn_Delete->Location = System::Drawing::Point(443, 438);
			   this->btn_Delete->Margin = System::Windows::Forms::Padding(4);
			   this->btn_Delete->Name = L"btn_Delete";
			   this->btn_Delete->Size = System::Drawing::Size(189, 44);
			   this->btn_Delete->TabIndex = 14;
			   this->btn_Delete->Text = L"Supprimer";
			   this->btn_Delete->UseVisualStyleBackColor = true;
			   this->btn_Delete->Click += gcnew System::EventHandler(this, &Article::DeleteArticle);
			   // 
			   // button_Save
			   // 
			   this->button_Save->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button_Save->Location = System::Drawing::Point(35, 490);
			   this->button_Save->Margin = System::Windows::Forms::Padding(4);
			   this->button_Save->Name = L"button_Save";
			   this->button_Save->Size = System::Drawing::Size(597, 44);
			   this->button_Save->TabIndex = 15;
			   this->button_Save->Text = L"Sauvegarder";
			   this->button_Save->UseVisualStyleBackColor = true;
			   this->button_Save->Click += gcnew System::EventHandler(this, &Article::EnrengistrerArticle);
			   // 
			   // btn_first
			   // 
			   this->btn_first->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btn_first->Location = System::Drawing::Point(656, 422);
			   this->btn_first->Margin = System::Windows::Forms::Padding(4);
			   this->btn_first->Name = L"btn_first";
			   this->btn_first->Size = System::Drawing::Size(60, 40);
			   this->btn_first->TabIndex = 16;
			   this->btn_first->Text = L"<<";
			   this->btn_first->UseVisualStyleBackColor = true;
			   this->btn_first->Click += gcnew System::EventHandler(this, &Article::FirstClick);
			   // 
			   // btn_next
			   // 
			   this->btn_next->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btn_next->Location = System::Drawing::Point(836, 422);
			   this->btn_next->Margin = System::Windows::Forms::Padding(4);
			   this->btn_next->Name = L"btn_next";
			   this->btn_next->Size = System::Drawing::Size(40, 40);
			   this->btn_next->TabIndex = 17;
			   this->btn_next->Text = L">";
			   this->btn_next->UseVisualStyleBackColor = true;
			   this->btn_next->Click += gcnew System::EventHandler(this, &Article::Next);
			   // 
			   // btn_previous
			   // 
			   this->btn_previous->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btn_previous->Location = System::Drawing::Point(788, 422);
			   this->btn_previous->Margin = System::Windows::Forms::Padding(4);
			   this->btn_previous->Name = L"btn_previous";
			   this->btn_previous->Size = System::Drawing::Size(40, 40);
			   this->btn_previous->TabIndex = 18;
			   this->btn_previous->Text = L"<";
			   this->btn_previous->UseVisualStyleBackColor = true;
			   this->btn_previous->Click += gcnew System::EventHandler(this, &Article::Previous);
			   // 
			   // btn_end
			   // 
			   this->btn_end->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btn_end->Location = System::Drawing::Point(946, 422);
			   this->btn_end->Margin = System::Windows::Forms::Padding(4);
			   this->btn_end->Name = L"btn_end";
			   this->btn_end->Size = System::Drawing::Size(60, 40);
			   this->btn_end->TabIndex = 19;
			   this->btn_end->Text = L">>";
			   this->btn_end->UseVisualStyleBackColor = true;
			   this->btn_end->Click += gcnew System::EventHandler(this, &Article::EndClick);
			   // 
			   // Article
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1019, 547);
			   this->Controls->Add(this->txt_rea);
			   this->Controls->Add(this->label7);
			   this->Controls->Add(this->txt_qte);
			   this->Controls->Add(this->txt_nom);
			   this->Controls->Add(this->txt_TVA);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label10);
			   this->Controls->Add(this->txt_prixAchat);
			   this->Controls->Add(this->label9);
			   this->Controls->Add(this->btn_end);
			   this->Controls->Add(this->btn_previous);
			   this->Controls->Add(this->btn_next);
			   this->Controls->Add(this->btn_first);
			   this->Controls->Add(this->txt_message);
			   this->Controls->Add(this->button_Save);
			   this->Controls->Add(this->btn_Delete);
			   this->Controls->Add(this->btn_Update);
			   this->Controls->Add(this->btn_Insert);
			   this->Controls->Add(this->txt_prixTTC);
			   this->Controls->Add(this->txt_prixHT);
			   this->Controls->Add(this->txt_nature);
			   this->Controls->Add(this->txt_couleur);
			   this->Controls->Add(this->txt_ID);
			   this->Controls->Add(this->label8);
			   this->Controls->Add(this->label6);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label1);
			   this->Location = System::Drawing::Point(16, 241);
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"Article";
			   this->Text = L"Outil de gestion des articles";
			   this->Load += gcnew System::EventHandler(this, &Article::ArticleLoad);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

		   // Lier l'application et la BDD
	private: System::Void ArticleLoad(System::Object^ sender, System::EventArgs^ e)
	{
		this->index = 0;
		this->mode = "RIEN";
		this->ds = gcnew Data::DataSet();
		this->processArticle = gcnew NS_Svc::CLS_Article();
		this->loadData(this->index);
		this->txt_message->Text = "Data chargées";
	}

		   // Charger des données  
	private: void loadData(int index)
	{
		this->ds->Clear();
		this->ds = this->processArticle->listeArticles("liste");
		this->txt_ID->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[0]);
		this->txt_nom->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[1]);
		this->txt_couleur->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[2]);
		this->txt_nature->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[3]);
		this->txt_prixHT->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[4]);
		this->txt_prixTTC->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[5]);
		this->txt_prixAchat->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[6]);
		this->txt_TVA->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[7]);
		this->txt_qte->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[8]);
		this->txt_rea->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[9]);
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

		   // Insérer un Article
	private: System::Void InsertArticle(System::Object^ sender, System::EventArgs^ e)
	{
		this->txt_ID->Clear();
		this->txt_nom->Clear();
		this->txt_couleur->Clear();
		this->txt_nature->Clear();
		this->txt_prixHT->Clear();
		this->txt_prixTTC->Clear();
		this->txt_prixAchat->Clear();
		this->txt_TVA->Clear();
		this->txt_qte->Clear();
		this->txt_rea->Clear();
		this->mode = "insert";
		this->txt_message->Text = "Saississez les informations";
	}

		   // Modifier un Article
	private: System::Void UpdateArticle(System::Object^ sender, System::EventArgs^ e)
	{
		this->mode = "update";
		this->txt_message->Text = "Veuillez modifier les information de la nouvelle courante et enregistrer.";
	}

		   // Supprimer un Article
	private: System::Void DeleteArticle(System::Object^ sender, System::EventArgs^ e)
	{
		this->mode = "delete";
		this->txt_message->Text = "Veuillez confirmer la suppression de la personne en cours en enregistrant.";
	}

		   // Enrengistrer
	private: System::Void EnrengistrerArticle(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->mode == "insert")
		{
			int ID_Article;
			ID_Article = this->processArticle->ajouter(this->txt_nom->Text, this->txt_couleur->Text, this->txt_nature->Text, Convert::ToDouble(this->txt_prixHT->Text), Convert::ToDouble(this->txt_prixTTC->Text), Convert::ToDouble(this->txt_prixAchat->Text), Convert::ToDouble(this->txt_TVA->Text), Convert::ToInt32(this->txt_qte->Text), Convert::ToInt32(this->txt_rea->Text));
			this->txt_message->Text = "L'ID généré est le : " + ID_Article + ". ";
		}
		else if (this->mode == "update")
		{
			this->processArticle->modifier(Convert::ToInt32(this->txt_ID->Text), this->txt_nom->Text, this->txt_couleur->Text, this->txt_nature->Text, Convert::ToDouble(this->txt_prixHT->Text), Convert::ToDouble(this->txt_prixTTC->Text), Convert::ToDouble(this->txt_prixAchat->Text), Convert::ToDouble(this->txt_TVA->Text), Convert::ToInt32(this->txt_qte->Text), Convert::ToInt32(this->txt_rea->Text));
		}
		else if (this->mode == "delete")
		{
			this->processArticle->supprimer(Convert::ToInt32(this->txt_ID->Text));
		}
		this->index = 0;
		this->loadData(this->index);
		this->txt_message->Text += "Traitement terminé.";
	}
};
}