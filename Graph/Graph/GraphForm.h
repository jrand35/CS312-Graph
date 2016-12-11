#pragma once
#include "Graph.h"

const int ARROW_OFFSET = 30;

namespace GraphProject {

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
				delete g;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  Debugging;
	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::Panel^  panel1;
	protected:

	private:
		//Vertices
		Label^ newLabel(System::String ^text, int x, int y){
			Label^ l = gcnew Label();
			//l->AutoSize = true;
			l->BackColor = System::Drawing::Color::LightBlue;
			l->Location = System::Drawing::Point(x, y);
			l->Name = L"label1asdf";
			l->Size = System::Drawing::Size(32, 32);
			l->TabIndex = 0;
			l->Text = text;
			l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->panel1->Controls->Add(l);
			return l;
		}

		//Edges
		Label^ newLabel2(System::String^ text, int x, int y){
			Label^ l = gcnew Label();
			//l->AutoSize = true;
			l->BackColor = System::Drawing::Color::Transparent;
			l->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			l->Location = System::Drawing::Point(x, y);
			l->Name = L"label1asdf";
			l->Size = System::Drawing::Size(16, 16);
			l->TabIndex = 0;
			l->Text = text;
			l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->panel1->Controls->Add(l);
			return l;
		}
		void MarkLabel(Label ^label){
			label->BackColor = System::Drawing::Color::Blue;
			label->ForeColor = System::Drawing::Color::White;
		}
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		Graphics ^g;
		Pen ^edgePen;
		Pen ^edgePen2;


		Graph *graph;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Debugging = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
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
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(858, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(116, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Make a Spanning Tree";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(861, 73);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(107, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Prim\'s Algorithm";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(861, 102);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(107, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Kruskal\'s Algorithm";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(882, 164);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Make a Path";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(861, 180);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(107, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Dijkstra\'s Algorithm";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(818, 73);
			this->textBox1->MaxLength = 2;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(37, 20);
			this->textBox1->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(776, 57);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Starting Vertex";
			// 
			// Debugging
			// 
			this->Debugging->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Debugging->Location = System::Drawing::Point(778, 341);
			this->Debugging->Name = L"Debugging";
			this->Debugging->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Debugging->Size = System::Drawing::Size(216, 180);
			this->Debugging->TabIndex = 8;
			this->Debugging->Text = L"Debugging";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(778, 317);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(59, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Debugging";
			// 
			// GraphForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1006, 762);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->Debugging);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Name = L"GraphForm";
			this->Text = L"Graph";
			this->Load += gcnew System::EventHandler(this, &GraphForm::GraphForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GraphForm_Load(System::Object^  sender, System::EventArgs^  e) {
		edgePen = gcnew Pen(Color::LightBlue, 6);
		//edgePen->StartCap = Drawing2D::LineCap::RoundAnchor;
		edgePen->EndCap = Drawing2D::LineCap::ArrowAnchor;
		edgePen2 = gcnew Pen(Color::Blue, 6);
		edgePen2->EndCap = Drawing2D::LineCap::ArrowAnchor;
		graph = new Graph();
		graph->LoadVertices("Small Graph Vertices.txt");
		graph->LoadEdges("Small Graph Edges.txt");
		Debugging->Text = gcnew String(graph->GetEdgeWeights().c_str());

		g = panel1->CreateGraphics();

		for (int i = 0; i < graph->VertexCount(); i++){
			newLabel(i.ToString(), graph->GetVertex(i)->GetX(), graph->GetVertex(i)->GetY());
		}

	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		for (int i = 0; i < graph->VertexCount(); i++){
			for (int j = 0; j < graph->GetVertex(i)->EdgeCount(); j++){
				Vertex *v1 = graph->GetVertex(i);
				int v2Index = v1->GetEdge(j)->DestVertexIndex;
				Vertex *v2 = graph->GetVertex(v2Index);
				int x1_ = v1->GetX();
				int y1_ = v1->GetY();
				int x2_ = v2->GetX();
				int y2_ = v2->GetY();

				float direction = Math::Atan2(y2_ - y1_, x2_ - x1_);

				int x1 = x1_ + (ARROW_OFFSET * Math::Cos(direction));
				int y1 = y1_ + (ARROW_OFFSET * Math::Sin(direction));
				int x2 = x2_ - (ARROW_OFFSET * Math::Cos(direction));
				int y2 = y2_ - (ARROW_OFFSET * Math::Sin(direction));

				g->DrawLine(edgePen, x1 + 16, y1 + 16, x2 + 16, y2 + 16);
			}
		}
	}
	};
}
