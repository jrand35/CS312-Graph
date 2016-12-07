#pragma once

namespace Graph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GraphForm
	/// </summary>
	public ref class GraphForm : public System::Windows::Forms::Form
	{
	public:
		GraphForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GraphForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		Graphics ^g;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(13, 13);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(759, 737);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GraphForm::panel1_Paint);
			// 
			// GraphForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 762);
			this->Controls->Add(this->panel1);
			this->Name = L"GraphForm";
			this->Text = L"Graph";
			this->Load += gcnew System::EventHandler(this, &GraphForm::GraphForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void GraphForm_Load(System::Object^  sender, System::EventArgs^  e) {
		g = panel1->CreateGraphics();
	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

	}
	};
}
