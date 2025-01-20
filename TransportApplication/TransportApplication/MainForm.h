#pragma once
#include "World.h"

namespace TransportApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	World TransportWorld(6);
	const Transport* SelectedCar = nullptr;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();

			this->ComboBox_TransportType->Items->Clear();
			this->ComboBox_TransportType->Items->Add("Легковий автомобіль");
			this->ComboBox_TransportType->Items->Add("Вантажний автомобіль");
			this->ComboBox_TransportType->Items->Add("Мотоцикл");
			this->ComboBox_TransportType->Items->Add("Автобус");
			this->ComboBox_TransportType->SelectedIndex = 0;
			this->timer1->Enabled = true;
			UpdateTransportList();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ mapPictureBox;
	protected:













	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ legendStartLabel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;


	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label17;


	private: System::Windows::Forms::ComboBox^ ComboBox_TransportType;
	private: System::Windows::Forms::ListBox^ ListBox_Transports;



	private: System::Windows::Forms::Button^ Button_AddTransport;
	private: System::Windows::Forms::Button^ Button_RemoveTransport;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Button^ Button_World;







	private: System::ComponentModel::IContainer^ components;
	protected:

	private:


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->mapPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->legendStartLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->ComboBox_TransportType = (gcnew System::Windows::Forms::ComboBox());
			this->ListBox_Transports = (gcnew System::Windows::Forms::ListBox());
			this->Button_AddTransport = (gcnew System::Windows::Forms::Button());
			this->Button_RemoveTransport = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->Button_World = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mapPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// mapPictureBox
			// 
			this->mapPictureBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mapPictureBox->Location = System::Drawing::Point(603, 22);
			this->mapPictureBox->Name = L"mapPictureBox";
			this->mapPictureBox->Size = System::Drawing::Size(400, 300);
			this->mapPictureBox->TabIndex = 0;
			this->mapPictureBox->TabStop = false;
			this->mapPictureBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::mapPictureBox_Paint);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label11->ForeColor = System::Drawing::Color::White;
			this->label11->Location = System::Drawing::Point(727, 326);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(86, 24);
			this->label11->TabIndex = 22;
			this->label11->Text = L"Легенда";
			// 
			// timer1
			// 
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(24, 33);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(359, 24);
			this->label3->TabIndex = 24;
			this->label3->Text = L"Оберіть тип транпорту для додавання";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label12->ForeColor = System::Drawing::Color::White;
			this->label12->Location = System::Drawing::Point(24, 126);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(322, 24);
			this->label12->TabIndex = 25;
			this->label12->Text = L"Оберіть транспорт для видалення";
			// 
			// legendStartLabel
			// 
			this->legendStartLabel->AutoSize = true;
			this->legendStartLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->legendStartLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->legendStartLabel->Location = System::Drawing::Point(534, 366);
			this->legendStartLabel->Name = L"legendStartLabel";
			this->legendStartLabel->Size = System::Drawing::Size(39, 29);
			this->legendStartLabel->TabIndex = 26;
			this->legendStartLabel->Text = L"⚫";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(573, 364);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(211, 24);
			this->label1->TabIndex = 27;
			this->label1->Text = L"- легковий автомобіль";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(573, 403);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(227, 24);
			this->label2->TabIndex = 29;
			this->label2->Text = L"- вантажний автомобіль";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(75)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->label5->Location = System::Drawing::Point(534, 405);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(39, 29);
			this->label5->TabIndex = 28;
			this->label5->Text = L"⚫";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(573, 444);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(107, 24);
			this->label7->TabIndex = 31;
			this->label7->Text = L"- мотоцикл";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(125)));
			this->label8->Location = System::Drawing::Point(534, 446);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(39, 29);
			this->label8->TabIndex = 30;
			this->label8->Text = L"⚫";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label13->ForeColor = System::Drawing::Color::White;
			this->label13->Location = System::Drawing::Point(576, 486);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(230, 24);
			this->label13->TabIndex = 35;
			this->label13->Text = L"- дорога без обмеження";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Bold));
			this->label14->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(150)));
			this->label14->Location = System::Drawing::Point(532, 470);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(46, 42);
			this->label14->TabIndex = 34;
			this->label14->Text = L"▅";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label15->ForeColor = System::Drawing::Color::White;
			this->label15->Location = System::Drawing::Point(575, 526);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(323, 24);
			this->label15->TabIndex = 37;
			this->label15->Text = L"- дорога з обмеженням (до 10 тон)";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Bold));
			this->label17->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(150)));
			this->label17->Location = System::Drawing::Point(532, 510);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(46, 42);
			this->label17->TabIndex = 38;
			this->label17->Text = L"▅";
			// 
			// ComboBox_TransportType
			// 
			this->ComboBox_TransportType->FormattingEnabled = true;
			this->ComboBox_TransportType->Location = System::Drawing::Point(28, 70);
			this->ComboBox_TransportType->Name = L"ComboBox_TransportType";
			this->ComboBox_TransportType->Size = System::Drawing::Size(355, 33);
			this->ComboBox_TransportType->TabIndex = 48;
			// 
			// ListBox_Transports
			// 
			this->ListBox_Transports->FormattingEnabled = true;
			this->ListBox_Transports->ItemHeight = 25;
			this->ListBox_Transports->Location = System::Drawing::Point(28, 174);
			this->ListBox_Transports->Name = L"ListBox_Transports";
			this->ListBox_Transports->Size = System::Drawing::Size(355, 404);
			this->ListBox_Transports->TabIndex = 49;
			this->ListBox_Transports->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::ListBox_Transports_SelectedIndexChanged);
			// 
			// Button_AddTransport
			// 
			this->Button_AddTransport->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
			this->Button_AddTransport->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Button_AddTransport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->Button_AddTransport->ForeColor = System::Drawing::Color::White;
			this->Button_AddTransport->Location = System::Drawing::Point(402, 34);
			this->Button_AddTransport->Name = L"Button_AddTransport";
			this->Button_AddTransport->Size = System::Drawing::Size(176, 69);
			this->Button_AddTransport->TabIndex = 50;
			this->Button_AddTransport->Text = L"Додати транспорт";
			this->Button_AddTransport->UseVisualStyleBackColor = false;
			this->Button_AddTransport->Click += gcnew System::EventHandler(this, &MainForm::Button_AddTransport_Click);
			// 
			// Button_RemoveTransport
			// 
			this->Button_RemoveTransport->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(77)));
			this->Button_RemoveTransport->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Button_RemoveTransport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->Button_RemoveTransport->ForeColor = System::Drawing::Color::White;
			this->Button_RemoveTransport->Location = System::Drawing::Point(402, 174);
			this->Button_RemoveTransport->Name = L"Button_RemoveTransport";
			this->Button_RemoveTransport->Size = System::Drawing::Size(176, 69);
			this->Button_RemoveTransport->TabIndex = 51;
			this->Button_RemoveTransport->Text = L"Видалити транспорт";
			this->Button_RemoveTransport->UseVisualStyleBackColor = false;
			this->Button_RemoveTransport->Click += gcnew System::EventHandler(this, &MainForm::Button_RemoveTransport_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(37)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(576, 566);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(261, 24);
			this->label4->TabIndex = 53;
			this->label4->Text = L"- шлях обраного автомобіля";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Bold));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(200)));
			this->label6->Location = System::Drawing::Point(532, 550);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 42);
			this->label6->TabIndex = 52;
			this->label6->Text = L"▅";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(859, 405);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(190, 24);
			this->label9->TabIndex = 55;
			this->label9->Text = L"- автобусна зупинка";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Bold));
			this->label10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(106)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label10->Location = System::Drawing::Point(815, 389);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(46, 42);
			this->label10->TabIndex = 54;
			this->label10->Text = L"▅";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->ForeColor = System::Drawing::Color::White;
			this->label16->Location = System::Drawing::Point(820, 366);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(39, 29);
			this->label16->TabIndex = 56;
			this->label16->Text = L"⚫";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label18->ForeColor = System::Drawing::Color::White;
			this->label18->Location = System::Drawing::Point(859, 364);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(93, 24);
			this->label18->TabIndex = 57;
			this->label18->Text = L"- автобус";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label19->ForeColor = System::Drawing::Color::White;
			this->label19->Location = System::Drawing::Point(859, 451);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(103, 24);
			this->label19->TabIndex = 59;
			this->label19->Text = L"- заправка";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Bold));
			this->label20->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->label20->Location = System::Drawing::Point(815, 435);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(46, 42);
			this->label20->TabIndex = 58;
			this->label20->Text = L"▅";
			// 
			// Button_World
			// 
			this->Button_World->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(77)));
			this->Button_World->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Button_World->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->Button_World->ForeColor = System::Drawing::Color::White;
			this->Button_World->Location = System::Drawing::Point(402, 253);
			this->Button_World->Name = L"Button_World";
			this->Button_World->Size = System::Drawing::Size(176, 97);
			this->Button_World->TabIndex = 60;
			this->Button_World->Text = L"Зберегти поточний стан у файл";
			this->Button_World->UseVisualStyleBackColor = false;
			this->Button_World->Click += gcnew System::EventHandler(this, &MainForm::Button_World_Click);
			// 
			// MainForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(37)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->ClientSize = System::Drawing::Size(1060, 613);
			this->Controls->Add(this->Button_World);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->Button_RemoveTransport);
			this->Controls->Add(this->Button_AddTransport);
			this->Controls->Add(this->ListBox_Transports);
			this->Controls->Add(this->ComboBox_TransportType);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->legendStartLabel);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->mapPictureBox);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->Name = L"MainForm";
			this->Text = L"Транспорт";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mapPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
	}

	private: System::Void mapPictureBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		Color backgroundColor = Color::FromArgb(42, 52, 77);
		Color roadColor = Color::FromArgb(55, 100, 150);
		Color limitedRoadColor = Color::FromArgb(250, 225, 150);

		Color lightTransportColor = Color::FromArgb(50, 225, 255);
		Color heavyTransportColor = Color::FromArgb(240, 75, 90);
		Color motorcycleTransportColor = Color::FromArgb(0, 255, 125);
		Color busTransportColor = Color::FromArgb(255, 255, 255);

		Color busStationColor = Color::FromArgb(106, 82, 255);

		Color gasStationColor = Color::FromArgb(200, 50, 100);

		Color currentTransportPathColor = Color::FromArgb(200, 200, 200);

		//Зафарбовуємо фон
		e->Graphics->Clear(backgroundColor);
		//Малюємо дороги
		auto routes = Navigator::Instance().GetRoads();
		for (int i = 0; i < routes.size(); i++)
		{
			System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(routes[i].maxWeightKg <= 10000 ? limitedRoadColor : roadColor, 7);
			pen->StartCap = Drawing2D::LineCap::Round;
			pen->EndCap = Drawing2D::LineCap::Round;
			e->Graphics->DrawLine(pen, (int)routes[i].start.x, (int)routes[i].start.y, (int)routes[i].end.x, (int)routes[i].end.y);
		}
		// Шлях обраного транспорту
		if (SelectedCar != nullptr)
		{
			System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(currentTransportPathColor, 7);

			auto currentPath = SelectedCar->GetCurrentPath();
			for (int i = 0; i < currentPath.size() - 1; i++)
			{
				e->Graphics->DrawLine(pen, (int)currentPath[i].x, (int)currentPath[i].y, (int)currentPath[i+1].x, (int)currentPath[i+1].y);
			}
		}

		// Малюємо заправну станцію
		{
			auto gasStation = Navigator::Instance().GasStation;
			System::Drawing::Brush^ brush = gcnew System::Drawing::SolidBrush(gasStationColor);
			e->Graphics->FillRectangle(brush, (int)gasStation.x - 15, (int)gasStation.y - 15, 30, 30);
		}
		// автобусні зупинки
		{
			auto allSchedules = Navigator::Instance().GetBusSchedules();
			for (auto& schedule : allSchedules)
			{
				for (auto& position : schedule)
				{
					System::Drawing::Brush^ brush = gcnew System::Drawing::SolidBrush(busStationColor);
					e->Graphics->FillRectangle(brush, (int)position.x - 10, (int)position.y - 10, 20, 20);
				}
			}
		}
		

		//Малюємо транспорт
		auto transports = TransportWorld.GetTransports();
		for (auto transport : transports)
		{
			System::Drawing::Brush^ brush = gcnew System::Drawing::SolidBrush(lightTransportColor);
			switch (transport->GetCarType())
			{
			case Transport::Type::Light:
				brush = gcnew System::Drawing::SolidBrush(lightTransportColor);
				e->Graphics->FillEllipse(brush, (int)transport->GetPosition().x - 8, (int)transport->GetPosition().y - 8, 16, 16);
				break;
			case Transport::Type::Heavy:
				brush = gcnew System::Drawing::SolidBrush(heavyTransportColor);
				e->Graphics->FillEllipse(brush, (int)transport->GetPosition().x - 10, (int)transport->GetPosition().y - 10, 20, 20);
				break;
			case Transport::Type::Motorcycle:
				brush = gcnew System::Drawing::SolidBrush(motorcycleTransportColor);
				e->Graphics->FillEllipse(brush, (int)transport->GetPosition().x - 6, (int)transport->GetPosition().y - 6, 12, 12);
				break;
			case Transport::Type::Bus:
				brush = gcnew System::Drawing::SolidBrush(busTransportColor);
				e->Graphics->FillEllipse(brush, (int)transport->GetPosition().x - 9, (int)transport->GetPosition().y - 9, 18, 18);
				break;
			default:
				break;
			}
		}
	}

	private: System::Void UpdateTransportList()
	{
		auto transports = TransportWorld.GetTransports();
		this->ListBox_Transports->Items->Clear();
		for (auto transport : transports)
		{
			switch (transport->GetCarType())
			{
			case Transport::Type::Light:
				this->ListBox_Transports->Items->Add("Легковий автомобіль");
				break;
			case Transport::Type::Heavy:
				this->ListBox_Transports->Items->Add("Вантажний автомобіль");
				break;
			case Transport::Type::Motorcycle:
				this->ListBox_Transports->Items->Add("Мотоцикл");
				break;
			case Transport::Type::Bus:
				this->ListBox_Transports->Items->Add("Автобус");
				break;
			default:
				break;
			}
		}
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		TransportWorld.Tick();
		this->mapPictureBox->Refresh();
	}

	private: System::Void Button_AddTransport_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		switch (this->ComboBox_TransportType->SelectedIndex)
		{
		case 0:
			TransportWorld.AddLightCar();
			break;
		case 1:
			TransportWorld.AddHeavyCar();
			break;
		case 2:
			TransportWorld.AddMotorcycle();
			break;
		case 3:
			TransportWorld.AddBus();
			break;
		default:
			break;
		}
		UpdateTransportList();
	}

	private: System::Void Button_RemoveTransport_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (SelectedCar != nullptr)
		{
			TransportWorld.RemoveTransport(SelectedCar);
			SelectedCar = nullptr;
		}

		UpdateTransportList();
	}

	private: System::Void ListBox_Transports_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		auto transports = TransportWorld.GetTransports();
		if (ListBox_Transports->SelectedIndex >= 0 && ListBox_Transports->SelectedIndex < transports.size())
		{
			auto it = transports.begin();
			std::advance(it, ListBox_Transports->SelectedIndex);
			SelectedCar = *it;
		}
		else
			SelectedCar = nullptr;
	}
	private: System::Void Button_World_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		TransportWorld.SaveToFile("world.txt");
		MessageBox::Show("Поточний стан програми збережено у файл world.txt");
	}
};
}
