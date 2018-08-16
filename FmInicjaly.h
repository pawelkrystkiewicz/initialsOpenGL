#pragma once
#include"stdafx.h"
namespace Inicjaly
{
	double z=0;// = Convert::ToDouble(inputOffset->Value);//DNO LITERKI
	double z1=10;// = Convert::ToDouble(inputLettersHeight->Value);//WYSOKOŒÆ
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	/// <summary>
	/// Summary for FmInicjaly
	/// </summary>


	public ref class FmInicjaly : public System::Windows::Forms::Form
	{
	public:
		FmInicjaly(void)
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
		~FmInicjaly()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnZamknij;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tpOpenGL;


	private: System::Windows::Forms::Panel^  pOpenGL;
	private: System::Windows::Forms::TabPage^  tpInfo;
	private: System::Windows::Forms::TextBox^  tbInfo;
	private: System::ComponentModel::IContainer^  components;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		HDC panelDC;
		HGLRC panelRC;

		GLfloat zoom, rotX, rotY, tX, tY, lastX, lastY;
		//GLfloat amb[3], diff[3], pos[3];
		//listy wyœwietlania
		GLuint dlCS, dlTR, dlCUBE, dlCO, dlP, dlK;

		//timer
		GLfloat time;

		//textures
		GLuint tekstura;

	private: System::Windows::Forms::GroupBox^  Figures;


	private: System::Windows::Forms::CheckBox^  cbTR;


	private: System::Windows::Forms::CheckBox^  cbCS;
	private: System::Windows::Forms::CheckBox^  cbCUBE;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  cbCubeAnim;
	private: System::Windows::Forms::CheckBox^  cbCO;
	private: System::Windows::Forms::Timer^  tAnimator;
	private: System::Windows::Forms::CheckBox^  cbScene;
	private: System::Windows::Forms::CheckBox^  cbK;
	private: System::Windows::Forms::CheckBox^  cbP;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  lblLetter1;

	private:
	public: System::Windows::Forms::NumericUpDown^  inputLettersHeight;
	public: System::Windows::Forms::NumericUpDown^  inputOffset;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckBox^  cbTexturing;



	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::CheckBox^  cbLighting;
	private: System::Windows::Forms::TrackBar^  tbAmbRed;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::TrackBar^  tbAmbBlue;
	private: System::Windows::Forms::TrackBar^  tbAmbGreen;
	private: System::Windows::Forms::GroupBox^  tbPosRed;
	private: System::Windows::Forms::TrackBar^  tbPosZ;

	private: System::Windows::Forms::TrackBar^  tbPosY;



	private: System::Windows::Forms::TrackBar^  tbPosX;


	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::TrackBar^  tbDiffBlue;

	private: System::Windows::Forms::TrackBar^  tbDiffGreen;

	private: System::Windows::Forms::TrackBar^  tbDiffRed;
	private: System::Windows::Forms::CheckBox^  cbAnimLetters;







	public:

























	private: System::Windows::Forms::TabPage^  tpOpcje;


		int SetDCPixelFormat(HDC hDC)
		{
			PIXELFORMATDESCRIPTOR pfd =
			{
			sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER | PFD_TYPE_RGBA,
			32, //color resolution
			0, 0, 0, 0, 0, 0,
			0,
			0,
			0,
			0, 0, 0, 0,
			32, //bits for depth buffer
			0,
			0,
			PFD_MAIN_PLANE, //drawing on one and only layer
			0,
			0, 0, 0

			};

			GLint iPixelFormat;

			if ((iPixelFormat = ChoosePixelFormat(hDC, &pfd)) == 0)
			{
				MessageBox::Show("Funkcja SETPIXELFORMAT nie dzia³a poprawnie");

				return 0;
			}

			if (SetPixelFormat(hDC, iPixelFormat, &pfd) == 0)

			{
				MessageBox::Show("Funkcja SetPixelFormat nie dzia³a poprawnie");
				return 0;
			}
			return 1;
		}
		


		void formResize()
		{
			GLsizei cw = pOpenGL->Width;
			GLsizei ch = pOpenGL->Height;

			if (ch == 0)
			{
				ch = 1;
			}
			GLdouble asp = (GLdouble)cw / (GLdouble)ch; //aspect ratio
			glViewport(0, 0, cw, ch); //drawing on full aval area
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(35.0, asp, 1.0, 10000.0);

			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			Invalidate();
		}

		void createCS(GLuint lista)
		{
			glNewList(lista, GL_COMPILE);
			//rysowanie ukl. wsp.
			glBegin(GL_LINES);	
			//start drawing line
			//drawing coordinate lines//
			//axis
			glColor3f(1.0, 0.0, 0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(100.0, 0.0, 0.0);
			//arrow arm1
			glVertex3f(95.0, -2.0, 3.0);
			glVertex3f(100.0, 0.0, 0.0);
			//arrow arm2
			glVertex3f(95.0, 3.0, -2.0);
			glVertex3f(100.0, 0.0, 0.0);

			//axis
			glColor3f(0.0, 1.0, 0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 100.0, 0.0);
			//arrow arm1
			glVertex3f(-2.0, 95.0, 3.0);
			glVertex3f(0.0, 100.0, 0.0);
			//arrow arm2
			glVertex3f(3.0, 95.0, -2.0);
			glVertex3f(0.0, 100.0, 0.0);

			//axis
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 0.0, 100.0);
			//arrow arm1
			glVertex3f(-2.0, 3.0, 95);
			glVertex3f(0.0, 0.0, 100.0);
			//arrow arm2
			glVertex3f(3.0, -2.0, 95);
			glVertex3f(0.0, 0.0, 100.0);
			glEnd();					//end drawing line

			glEndList();
		}
		
		void createTR(GLuint lista)
		{
			glNewList(lista, GL_COMPILE);

			//drawing traingle//
			glBegin(GL_TRIANGLES);

			glColor3f(1.0, 0.0, 0.0);
			glVertex3f(30.0, 0.0, 0.0);

			glColor3f(0.0, 1.0, 0.0);
			glVertex3f(0.0, 30.0, 0.0);

			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(0.0, 0.0, 30.0);

			glEnd();
			//end drawing line
			glEndList();
		}
		void createCUBE(GLuint lista)
		{
			//glNewList(lista, GL_COMPILE);
			GLfloat cubePoints[8][3]
			{	//plaszczyzna z=0
				{ 0.0, 0.0, 0.0 }, //P0
				{ 100.0, 0.0, 0.0 },//P1
				{ 0.0, 100.0, 0.0 },//P2
				{ 100.0, 100.0, 0.0 },//P3
									  //plaszczyzna z=100
				{ 0.0, 0.0, 100.0 },//P4
				{ 100.0, 0.0, 100.0 },//P5
				{ 0.0, 100.0, 100.0 },//P6
				{ 100.0, 100.0, 100.0 },//P7

			};
			GLfloat cubeColors[8][3]
			{
				{ 0.0, 0.0, 0.0 },//P0
				{ 1.0, 0.0, 0.0 },//P1
				{ 0.0, 1.0, 0.0 },//P2
				{ 1.0, 1.0, 0.0 },//P3

				{ 0.0, 0.0, 1.0 },//P4
				{ 1.0, 0.0, 1.0 },//P5
				{ 0.0, 1.0, 1.0 },//P6
				{ 1.0, 1.0, 1.0 },//P7

			};

			glNewList(lista, GL_COMPILE);
			glBegin(GL_TRIANGLES);
			//P0 P1 P2 P3
			glTexCoord2i(1, 0); glColor3fv(cubeColors[0]);		glVertex3fv(cubePoints[0]);
			glTexCoord2i(1, 1); glColor3fv(cubeColors[2]);		glVertex3fv(cubePoints[2]);
			glTexCoord2i(0, 0); glColor3fv(cubeColors[1]);		glVertex3fv(cubePoints[1]);
			
		
			glColor3fv(cubeColors[1]);
			glVertex3fv(cubePoints[1]);
			glColor3fv(cubeColors[2]);
			glVertex3fv(cubePoints[2]);
			glColor3fv(cubeColors[3]);
			glVertex3fv(cubePoints[3]);
			
			//górna œciana
			glColor3fv(cubeColors[4]);
			glVertex3fv(cubePoints[4]);
			glColor3fv(cubeColors[5]);
			glVertex3fv(cubePoints[5]);
			glColor3fv(cubeColors[6]);
			glVertex3fv(cubePoints[6]);

			glColor3fv(cubeColors[6]);
			glVertex3fv(cubePoints[6]);
			glColor3fv(cubeColors[5]);
			glVertex3fv(cubePoints[5]);
			glColor3fv(cubeColors[7]);
			glVertex3fv(cubePoints[7]);
			
			glColor3fv(cubeColors[0]);
			glVertex3fv(cubePoints[0]);
			glColor3fv(cubeColors[1]);
			glVertex3fv(cubePoints[1]);
			glColor3fv(cubeColors[5]);
			glVertex3fv(cubePoints[5]);
			
			glColor3fv(cubeColors[0]);
			glVertex3fv(cubePoints[0]);
			glColor3fv(cubeColors[5]);
			glVertex3fv(cubePoints[5]);
			glColor3fv(cubeColors[4]);
			glVertex3fv(cubePoints[4]);

			glColor3fv(cubeColors[1]);
			glVertex3fv(cubePoints[1]);
			glColor3fv(cubeColors[3]);
			glVertex3fv(cubePoints[3]);
			glColor3fv(cubeColors[7]);
			glVertex3fv(cubePoints[7]);

			glColor3fv(cubeColors[7]);
			glVertex3fv(cubePoints[7]);
			glColor3fv(cubeColors[5]);
			glVertex3fv(cubePoints[5]);
			glColor3fv(cubeColors[1]);
			glVertex3fv(cubePoints[1]);
	
			glColor3fv(cubeColors[7]);
			glVertex3fv(cubePoints[7]);
			glColor3fv(cubeColors[3]);
			glVertex3fv(cubePoints[3]);
			glColor3fv(cubeColors[2]);
			glVertex3fv(cubePoints[2]);

			glColor3fv(cubeColors[7]);
			glVertex3fv(cubePoints[7]);
			glColor3fv(cubeColors[2]);
			glVertex3fv(cubePoints[2]);
			glColor3fv(cubeColors[6]);
			glVertex3fv(cubePoints[6]);

			glColor3fv(cubeColors[0]);
			glVertex3fv(cubePoints[0]);
			glColor3fv(cubeColors[4]);
			glVertex3fv(cubePoints[4]);
			glColor3fv(cubeColors[2]);
			glVertex3fv(cubePoints[2]);

			glColor3fv(cubeColors[4]);
			glVertex3fv(cubePoints[4]);
			glColor3fv(cubeColors[6]);
			glVertex3fv(cubePoints[6]);
			glColor3fv(cubeColors[2]);
			glVertex3fv(cubePoints[2]);

			//jak zadziala to narysowaæ krawedzie GLlines jako osobna funkcja
			glEnd();
			glEndList();
					
		}
		void createCubeOutline(GLuint lista)
		{
			//glNewList(lista, GL_COMPILE);
			GLfloat linePoints[8][3]
			{	//plaszczyzna z=0
				{ 0.0, 0.0, 0.0 }, //P0
				{ 100.0, 0.0, 0.0 },//P1
				{ 0.0, 100.0, 0.0 },//P2
				{ 100.0, 100.0, 0.0 },//P3
									  //plaszczyzna z=100
				{ 0.0, 0.0, 100.0 },//P4
				{ 100.0, 0.0, 100.0 },//P5
				{ 0.0, 100.0, 100.0 },//P6
				{ 100.0, 100.0, 100.0 },//P7

			};

			glNewList(lista, GL_COMPILE);
			glBegin(GL_LINE_LOOP);
			glLineWidth(3);
			glColor3b(0.0, 0.0, 0.0);
			//P0 P1 P2 P3

			glVertex3fv(linePoints[0]);
			glVertex3fv(linePoints[1]);
			glVertex3fv(linePoints[3]);
			glVertex3fv(linePoints[2]);

			glEnd();

			glBegin(GL_LINE_LOOP);
			glLineWidth(3);
			glColor3b(0.0, 0.0, 0.0);

			glVertex3fv(linePoints[1]);
			glVertex3fv(linePoints[5]);
			glVertex3fv(linePoints[7]);
			glVertex3fv(linePoints[3]);

			glEnd();

			glBegin(GL_LINE_LOOP);
			glLineWidth(3);
			glColor3b(0.0, 0.0, 0.0);

			glVertex3fv(linePoints[5]);
			glVertex3fv(linePoints[4]);
			glVertex3fv(linePoints[6]);
			glVertex3fv(linePoints[7]);

			glEnd();

			glBegin(GL_LINE_LOOP);
			glLineWidth(3);
			glColor3b(0.0, 0.0, 0.0);

			glVertex3fv(linePoints[4]);
			glVertex3fv(linePoints[0]);
			glVertex3fv(linePoints[2]);
			glVertex3fv(linePoints[6]);
			//jak zadziala to narysowaæ krawedzie GLlines jako osobna funkcja
			glEnd();
			glEndList();
		}
		void createLetterP(GLuint lista)
		{
			//double z = 0.0;//DNO LITERKI
			//double z1 = 10.0;//WYSOKOŒÆ
			double x1 = 10.0;//odl. na X
			double xinc = 20.0; //inkrementacja odleg³oœci
			double y1 = 10.0; //wys.pocz¹tkowa
			double h = 20.0; //wys. trójk¹ta
			glNewList(lista, GL_COMPILE);
			GLfloat S1[6][3] //section I
			{	//nó¿ka I strona lewa
				{ x1, y1, z}, 
				{ x1, y1 + h, z},
				{ x1, y1 + 2 * h, z},
				{ x1, y1 + 3 * h, z },
				{ x1, y1 + 4 * h, z },
				{ x1, y1 + 5 * h, z },
			};
			GLfloat S2[6][3] //section II
			{	//nó¿ka I strona prawa
				{ x1 + xinc, y1, z },
				{ x1 + xinc, y1 + h, z },
				{ x1 + xinc, y1 + 2 * h, z },
				{ x1 + xinc, y1 + 3 * h, z },
				{ x1 + xinc, y1 + 4 * h, z },
				{ x1 + xinc, y1 + 5 * h, z },
			};
			GLfloat S3[6][3] //section III
			{	//nó¿ka I strona prawa
				{ x1 + 2 * xinc, y1, z },
				{ x1 + 2 * xinc, y1 + h, z },
				{ x1 + 2 * xinc, y1 + 2 * h, z },
				{ x1 + 2 * xinc, y1 + 3 * h, z },
				{ x1 + 2 * xinc, y1 + 4 * h, z },
				{ x1 + 2 * xinc, y1 + 5 * h, z },
			};

			GLfloat S4[6][3] //section IV
			{	//nó¿ka I strona prawa
				{ x1 + 3 * xinc, y1, z },
				{ x1 + 3 * xinc, y1 + h, z },
				{ x1 + 3 * xinc, y1 + 2 * h, z },
				{ x1 + 3 * xinc, y1 + 3 * h, z },
				{ x1 + 3 * xinc, y1 + 4 * h, z },
				{ x1 + 3 * xinc, y1 + 5 * h, z },
			};
		
			GLfloat S1Z[6][3] //section I
			{	//nó¿ka I strona lewa
				{ x1, y1, z1 },
				{ x1, y1 + h, z1 },
				{ x1, y1 + 2 * h, z1 },
				{ x1, y1 + 3 * h, z1 },
				{ x1, y1 + 4 * h, z1 },
				{ x1, y1 + 5 * h, z1 },
			};
			GLfloat S2Z[6][3] //section II
			{	//nó¿ka I strona prawa
				{ x1 + xinc, y1, z1 },
				{ x1 + xinc, y1 + h, z1 },
				{ x1 + xinc, y1 + 2 * h, z1 },
				{ x1 + xinc, y1 + 3 * h, z1 },
				{ x1 + xinc, y1 + 4 * h, z1 },
				{ x1 + xinc, y1 + 5 * h, z1 },
			};
			GLfloat S3Z[6][3] //section III
			{	//nó¿ka I strona prawa
				{ x1 + 2 * xinc, y1, z1 },
				{ x1 + 2 * xinc, y1 + h, z1 },
				{ x1 + 2 * xinc, y1 + 2 * h, z1 },
				{ x1 + 2 * xinc, y1 + 3 * h, z1 },
				{ x1 + 2 * xinc, y1 + 4 * h, z1 },
				{ x1 + 2 * xinc, y1 + 5 * h, z1 },
			};

			GLfloat S4Z[6][3] //section IV
			{	//nó¿ka I strona prawa
				{ x1 + 3 * xinc, y1, z1 },
				{ x1 + 3 * xinc, y1 + h, z1 },
				{ x1 + 3 * xinc, y1 + 2 * h, z1 },
				{ x1 + 3 * xinc, y1 + 3 * h, z1 },
				{ x1 + 3 * xinc, y1 + 4 * h, z1 },
				{ x1 + 3 * xinc, y1 + 5 * h, z1 },
			};

			//drawing triangle//
			glBegin(GL_TRIANGLES);
			glColor3f(0.0, 0.0, 0.50);
			glVertex3fv(S2[0]);	//glColor3fv(cubeColors[2]);
			glVertex3fv(S1[0]); //glColor3fv(cubeColors[1]);
			glVertex3fv(S2[1]);	//glColor3fv(cubeColors[3]);
			
			glEnd();

			glBegin(GL_TRIANGLES);
			//glColor3fv(cubeColors[1]);
			glVertex3fv(S1[0]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S1[1]);
			glVertex3fv(S2[1]);
			//glColor3fv(cubeColors[3]);
			
			glEnd();


			glBegin(GL_TRIANGLES);
			//glColor3fv(cubeColors[1]);
			glVertex3fv(S2[1]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S1[1]);
			glVertex3fv(S2[2]);
			//glColor3fv(cubeColors[3]);
			
			glEnd();

			glBegin(GL_TRIANGLES);
			//glColor3fv(cubeColors[1]);
			glVertex3fv(S1[1]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S1[2]);
			glVertex3fv(S2[2]);
			//glColor3fv(cubeColors[3]);
		
			glEnd();

			glBegin(GL_TRIANGLES);
			//glColor3fv(cubeColors[1]);
			glVertex3fv(S2[2]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S1[2]);
			glVertex3fv(S2[3]);
			//glColor3fv(cubeColors[3]);
			
			glEnd();

			glBegin(GL_TRIANGLES);
			//glColor3fv(cubeColors[1]);
			glVertex3fv(S2[3]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S1[2]);
			glVertex3fv(S1[3]);
			//glColor3fv(cubeColors[3]);
			
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S1[3]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S1[4]);
			glVertex3fv(S2[4]);
			//glColor3fv(cubeColors[3]);
			
			glEnd();
		
			glBegin(GL_TRIANGLES);
			glVertex3fv(S1[3]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S2[4]);
			glVertex3fv(S2[3]);
			//glColor3fv(cubeColors[3]);
			
			glEnd();

			glBegin(GL_TRIANGLES);
			//glColor3fv(cubeColors[1]);
			glVertex3fv(S1[4]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S2[5]);
			glVertex3fv(S2[4]);
			//glColor3fv(cubeColors[3]);
		
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S1[4]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S1[5]);
			glVertex3fv(S2[5]);
			//glColor3fv(cubeColors[3]);
			
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S2[4]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S1[5]);
			glVertex3fv(S2[5]);
			//glColor3fv(cubeColors[3]);
			
			glEnd();
			
			//-------phase z-------

			glBegin(GL_TRIANGLES);
			//glColor3fv(cubeColors[1]);
			glVertex3fv(S2Z[0]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S2Z[1]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S1Z[0]);
			glEnd();

			glBegin(GL_TRIANGLES);
			//glColor3fv(cubeColors[1]);
			glVertex3fv(S1Z[0]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S2Z[1]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S1Z[1]);
			glEnd();


			glBegin(GL_TRIANGLES);
			//glColor3fv(cubeColors[1]);
			glVertex3fv(S2Z[1]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S2Z[2]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S1Z[1]);
			glEnd();

			glBegin(GL_TRIANGLES);
			//glColor3fv(cubeColors[1]);
			glVertex3fv(S1Z[1]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S2Z[2]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S1Z[2]);
			glEnd();

			glBegin(GL_TRIANGLES);
			//glColor3fv(cubeColors[1]);
			glVertex3fv(S2Z[2]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S2Z[3]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S1Z[2]);
			glEnd();

			glBegin(GL_TRIANGLES);
			//glColor3fv(cubeColors[1]);
			glVertex3fv(S2Z[3]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S1Z[3]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S1Z[2]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S1Z[3]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S2Z[4]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S1Z[4]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S1Z[3]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S2Z[3]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S2Z[4]);
			glEnd();

			glBegin(GL_TRIANGLES);
			//glColor3fv(cubeColors[1]);
			glVertex3fv(S1Z[4]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S2Z[4]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S2Z[5]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S1Z[4]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S2Z[5]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S1Z[5]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S2Z[4]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S2Z[5]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S1Z[5]);
			glEnd();

			//------bridge---------
			glBegin(GL_TRIANGLES);
			glVertex3fv(S2[2]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S3[3]);
			glVertex3fv(S3[2]);
			//glColor3fv(cubeColors[3]);
			
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S2[2]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S2[3]);
			glVertex3fv(S3[3]);
			
			//glColor3fv(cubeColors[3]);
			
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S2[4]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S3[5]);
			glVertex3fv(S3[4]);
			//glColor3fv(cubeColors[3]);
			
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S2[4]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S2[5]);
			glVertex3fv(S3[5]);
			//glColor3fv(cubeColors[3]);
			
			glEnd();
			
			//------ending---------
			glBegin(GL_TRIANGLES);
			glVertex3fv(S3[2]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S3[3]);
			glVertex3fv(S4[3]);
			//glColor3fv(cubeColors[3]);
			
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S3[3]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S4[4]);
			glVertex3fv(S4[3]);
			//glColor3fv(cubeColors[3]);
			
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S3[3]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S3[4]);
			glVertex3fv(S4[4]);
			//glColor3fv(cubeColors[3]);
			
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S3[4]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S3[5]);
			glVertex3fv(S4[4]);
			//glColor3fv(cubeColors[3]);
			
			glEnd();
			//------bridge---------Z
			glBegin(GL_TRIANGLES);
			glVertex3fv(S2Z[2]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S3Z[2]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S3Z[3]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S2Z[2]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S3Z[3]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S2Z[3]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S2Z[4]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S3Z[4]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S3Z[5]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S2Z[4]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S3Z[5]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S2Z[5]);
			glEnd();

			//------ending---------z
			glBegin(GL_TRIANGLES);
			glVertex3fv(S3Z[2]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S4Z[3]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S3Z[3]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S3Z[3]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S4Z[3]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S4Z[4]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S3Z[3]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S4Z[4]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S3Z[4]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S3Z[4]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S4Z[4]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S3Z[5]);
			glEnd();
			glColor3f(1.0, 1.0, 1.0);
			//---SIDES---
			glBegin(GL_TRIANGLES);
			glVertex3fv(S1[0]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S1Z[0]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S1Z[5]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S1[0]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S1Z[5]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S1[5]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S4[3]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S4Z[4]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S4Z[3]);
			
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S4[3]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S4[4]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S4Z[4]);
			
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S2[0]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S2Z[5]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S2Z[0]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S2[0]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S2[5]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S2Z[5]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S3[3]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S3Z[3]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S3Z[4]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S3[3]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S3Z[4]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S3[4]);
			glEnd();

			//UPPER COVER
			glBegin(GL_TRIANGLES);
			glVertex3fv(S1Z[5]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S3Z[5]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S3[5]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S1Z[5]);//glColor3fv(cubeColors[2]);
			glVertex3fv(S3[5]);//glColor3fv(cubeColors[3]);
			glVertex3fv(S1[5]);
			glEnd();
			//INSIDE UPPER COVER
			glBegin(GL_TRIANGLES);
			glVertex3fv(S2Z[3]);
			//glColor3fv(cubeColors[2]);
			glVertex3fv(S3Z[3]);
			//glColor3fv(cubeColors[3]);
			glVertex3fv(S3[3]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S2Z[3]);//glColor3fv(cubeColors[2]);
			glVertex3fv(S3[3]);//glColor3fv(cubeColors[3]);
			glVertex3fv(S2[3]);
			glEnd();

			//LOWER COVER /END
			glBegin(GL_TRIANGLES);
			glVertex3fv(S2Z[2]);//glColor3fv(cubeColors[3]);
			glVertex3fv(S3[2]);//glColor3fv(cubeColors[2]);
			glVertex3fv(S3Z[2]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S2Z[2]);//glColor3fv(cubeColors[3]);
			glVertex3fv(S2[2]);//glColor3fv(cubeColors[2]);
			glVertex3fv(S3[2]);
			glEnd();

			//INSIDE UPPER COVER /END
			glBegin(GL_TRIANGLES);
			glVertex3fv(S2Z[4]);//glColor3fv(cubeColors[3]);
			glVertex3fv(S3[4]);//glColor3fv(cubeColors[2]);
			glVertex3fv(S3Z[4]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S2Z[4]);//glColor3fv(cubeColors[3]);
			glVertex3fv(S2[4]);//glColor3fv(cubeColors[2]);
			glVertex3fv(S3[4]);
			glEnd();
			
			//SLIDE UPPER COVER
			glBegin(GL_TRIANGLES);
			glVertex3fv(S3Z[5]);//glColor3fv(cubeColors[3]);
			glVertex3fv(S4Z[4]);//glColor3fv(cubeColors[2]);
			glVertex3fv(S4[4]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S3Z[5]);//glColor3fv(cubeColors[3]);
			glVertex3fv(S4[4]);//glColor3fv(cubeColors[2]);
			glVertex3fv(S3[5]);
			glEnd();
			//SLIDE LOWER COVER
			glBegin(GL_TRIANGLES);
			glVertex3fv(S3Z[2]);//glColor3fv(cubeColors[3]);
			glVertex3fv(S4[3]);
			glVertex3fv(S4Z[3]);//glColor3fv(cubeColors[2]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S3Z[2]);//glColor3fv(cubeColors[3]);
			glVertex3fv(S3[2]);
			glVertex3fv(S4[3]);//glColor3fv(cubeColors[2]);
			glEnd();

			//MOST LOWER CLOSING
			glBegin(GL_TRIANGLES);
			glVertex3fv(S1Z[0]);//glColor3fv(cubeColors[3]);
			glVertex3fv(S2[0]);
			glVertex3fv(S2Z[0]);//glColor3fv(cubeColors[2]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3fv(S1Z[0]);//glColor3fv(cubeColors[3]);
			glVertex3fv(S1[0]);
			glVertex3fv(S2[0]);//glColor3fv(cubeColors[2]);
			glEnd();


			glEndList();
		}
				void createLetterK(GLuint lista)
				{
					glNewList(lista, GL_COMPILE);
					//double z = 0.0;//g³êbokoœæ 3D
					//double z1 = 10.0;//g³êbokoœæ 3D
					double x1 = 10.0;//odl. na X
					double x = 20.0;
					double xinc = 20.0; //inkrementacja odleg³oœci
					double y1 = 10.0; //wys.pocz¹tkowa
					double h = 20.0; //wys. trójk¹ta
					glNewList(lista, GL_COMPILE);
					
					GLfloat S5[6][3] //section V
					{	//nó¿ka I strona prawa
						{ x1 + 4 * x, y1, z },
						{ x1 + 4 * x, y1 + h, z },
						{ x1 + 4 * x, y1 + 2 * h, z },
						{ x1 + 4 * x, y1 + 3 * h, z },
						{ x1 + 4 * x, y1 + 4 * h, z },
						{ x1 + 4 * x, y1 + 5 * h, z },
					};
					GLfloat S6[6][3] //section VI
					{	//nó¿ka I strona prawa
						{ x1 + 5 * x, y1, z },
						{ x1 + 5 * x, y1 + h, z },
						{ x1 + 5 * x, y1 + 2 * h, z },
						{ x1 + 5 * x, y1 + 3 * h, z },
						{ x1 + 5 * x, y1 + 4 * h, z },
						{ x1 + 5 * x, y1 + 5 * h, z },
					};
					GLfloat S7[6][3] //section VII
					{	//nó¿ka I strona prawa
						{ x1 + 6 * x, y1, z },
						{ x1 + 6 * x, y1 + h, z },
						{ x1 + 6 * x, y1 + 2 * h, z },
						{ x1 + 6 * x, y1 + 3 * h, z },
						{ x1 + 6 * x, y1 + 4 * h, z },
						{ x1 + 6 * x, y1 + 5 * h, z },
					};
					GLfloat S8[6][3] //section VIII
					{	//nó¿ka I strona prawa
						{ x1 + 7 * xinc, y1, z },
						{ x1 + 7 * xinc, y1 + h, z },
						{ x1 + 7 * xinc, y1 + 2 * h, z },
						{ x1 + 7 * xinc, y1 + 3 * h, z },
						{ x1 + 7 * xinc, y1 + 4 * h, z },
						{ x1 + 7 * xinc, y1 + 5 * h, z },
					};
					GLfloat S9[6][3] //section XI
					{	//nó¿ka I strona prawa
						{ x1 + 8 * xinc, y1, z },
						{ x1 + 8 * xinc, y1 + h, z },
						{ x1 + 8 * xinc, y1 + 2 * h, z },
						{ x1 + 8 * xinc, y1 + 3 * h, z },
						{ x1 + 8 * xinc, y1 + 4 * h, z },
						{ x1 + 8 * xinc, y1 + 5 * h, z },
					};

					GLfloat S5Z[6][3] //section V
					{	
						{ x1 + 4 * x, y1, z1 },
						{ x1 + 4 * x, y1 + h, z1 },
						{ x1 + 4 * x, y1 + 2 * h, z1 },
						{ x1 + 4 * x, y1 + 3 * h, z1 },
						{ x1 + 4 * x, y1 + 4 * h, z1 },
						{ x1 + 4 * x, y1 + 5 * h, z1 },
					};
					GLfloat S6Z[6][3] //section VI
					{	
						{ x1 + 5 * x, y1, z1 },
						{ x1 + 5 * x, y1 + h, z1 },
						{ x1 + 5 * x, y1 + 2 * h, z1 },
						{ x1 + 5 * x, y1 + 3 * h, z1 },
						{ x1 + 5 * x, y1 + 4 * h, z1 },
						{ x1 + 5 * x, y1 + 5 * h, z1 },
					};
					GLfloat S7Z[6][3] //section VII
					{	
						{ x1 + 6 * x, y1, z1 },
						{ x1 + 6 * x, y1 + h, z1 },
						{ x1 + 6 * x, y1 + 2 * h, z1 },
						{ x1 + 6 * x, y1 + 3 * h, z1 },
						{ x1 + 6 * x, y1 + 4 * h, z1 },
						{ x1 + 6 * x, y1 + 5 * h, z1 },
					};
					GLfloat S8Z[6][3] //section VIII
					{	
						{ x1 + 7 * xinc, y1, z1},
						{ x1 + 7 * xinc, y1 + h, z1 },
						{ x1 + 7 * xinc, y1 + 2 * h, z1 },
						{ x1 + 7 * xinc, y1 + 3 * h, z1 },
						{ x1 + 7 * xinc, y1 + 4 * h, z1 },
						{ x1 + 7 * xinc, y1 + 5 * h, z1 },
					};
					GLfloat S9Z[6][3] //section XI
					{	
						{ x1 + 8 * xinc, y1, z1 },
						{ x1 + 8 * xinc, y1 + h, z1 },
						{ x1 + 8 * xinc, y1 + 2 * h, z1 },
						{ x1 + 8 * xinc, y1 + 3 * h, z1 },
						{ x1 + 8 * xinc, y1 + 4 * h, z1 },
						{ x1 + 8 * xinc, y1 + 5 * h, z1 },
					};
					//drawing traingle//pocz¹tek ty³u
					glBegin(GL_TRIANGLES);
					glColor3f(0.0, 0.5, 0.5);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S6[0]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S5[0]);
					glVertex3fv(S6[1]);
					//glColor3fv(cubeColors[3]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S5[0]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S5[1]);
					glVertex3fv(S6[1]);
					//glColor3fv(cubeColors[3]);
					
					glEnd();


					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S6[1]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S5[1]);
					glVertex3fv(S6[2]);
					//glColor3fv(cubeColors[3]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S5[1]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S5[2]);
					glVertex3fv(S6[2]);
					//glColor3fv(cubeColors[3]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S6[2]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S5[2]);
					glVertex3fv(S6[3]);
					//glColor3fv(cubeColors[3]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S6[3]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S5[2]);
					glVertex3fv(S5[3]);
					//glColor3fv(cubeColors[3]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S5[3]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S5[4]);
					glVertex3fv(S6[4]);
					//glColor3fv(cubeColors[3]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S5[3]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6[4]);
					glVertex3fv(S6[3]);
					//glColor3fv(cubeColors[3]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S5[4]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S6[5]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6[4]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S5[4]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5[5]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6[5]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6[4]);	//glColor3fv(cubeColors[3]);
					glVertex3fv(S5[5]);	//glColor3fv(cubeColors[2]);
					glVertex3fv(S6[5]); //glColor3fv(cubeColors[2]);
					
					glEnd();
					
					//------UPPER LEG-----

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6[3]);	//glColor3fv(cubeColors[2]);
					glVertex3fv(S7[2]);
					glVertex3fv(S6[2]); //glColor3fv(cubeColors[3]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6[2]);	//glColor3fv(cubeColors[2]);
					glVertex3fv(S7[2]);
					glVertex3fv(S7[1]); //glColor3fv(cubeColors[3]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S7[2]);	//glColor3fv(cubeColors[2]);
					glVertex3fv(S8[1]);
					glVertex3fv(S7[1]);//glColor3fv(cubeColors[3]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S7[1]);	//glColor3fv(cubeColors[2]);
					glVertex3fv(S8[1]);
					glVertex3fv(S8[0]); //glColor3fv(cubeColors[3]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S8[1]);//glColor3fv(cubeColors[2]);
					glVertex3fv(S9[0]); 
					glVertex3fv(S8[0]);//glColor3fv(cubeColors[3]);
					
					glEnd();

					//------LOWER LEG-----
					glBegin(GL_TRIANGLES);
					glVertex3fv(S6[2]);	//glColor3fv(cubeColors[2]);
					glVertex3fv(S6[3]);
					glVertex3fv(S7[3]);	//glColor3fv(cubeColors[3]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6[3]);	//glColor3fv(cubeColors[2]);
					glVertex3fv(S7[4]);
					glVertex3fv(S7[3]);	//glColor3fv(cubeColors[3]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S7[3]);	//glColor3fv(cubeColors[2]);
					glVertex3fv(S7[4]);
					glVertex3fv(S8[4]);	//glColor3fv(cubeColors[3]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S7[4]);	//glColor3fv(cubeColors[2]);
					glVertex3fv(S8[5]);
					glVertex3fv(S8[4]);	//glColor3fv(cubeColors[3]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S8[4]);	//glColor3fv(cubeColors[2]);
					glVertex3fv(S8[5]);
					glVertex3fv(S9[5]);	//glColor3fv(cubeColors[3]);
					
					glEnd();
					//end drawing line//koniec ty³u
					
					//drawing traingle//
					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S6[0]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6[1]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5[0]);
					glEnd();

					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S5[0]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6[1]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5[1]);
					glEnd();


					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S6[1]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6[2]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5[1]);
					glEnd();

					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S5[1]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6[2]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5[2]);
					glEnd();

					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S6[2]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6[3]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5[2]);
					glEnd();

					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S6[3]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S5[3]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5[2]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S5[3]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6[4]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5[4]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S5[3]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6[3]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S6[4]);
					glEnd();

					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S5[4]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6[4]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S6[5]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S5[4]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6[5]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5[5]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6[4]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6[5]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5[5]);
					glEnd();
					
					//------UPPER LEG-----

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6[3]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6[2]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S7[2]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6[2]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S7[1]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S7[2]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S7[2]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S7[1]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S8[1]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S7[1]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S8[0]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S8[1]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S8[1]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S8[0]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S9[0]);
					glEnd();

					//------LOWER LEG-----
					glBegin(GL_TRIANGLES);
					glVertex3fv(S6[2]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S7[3]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S6[3]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6[3]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S7[3]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S7[4]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S7[3]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S8[4]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S7[4]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S7[4]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S8[4]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S8[5]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S8[4]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S9[5]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S8[5]);
					glEnd();
					
					//-----Z PHASE------

					//drawing traingle//
					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S6Z[0]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6Z[1]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5Z[0]);
					glEnd();

					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S5Z[0]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6Z[1]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5Z[1]);
					glEnd();


					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S6Z[1]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6Z[2]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5Z[1]);
					glEnd();

					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S5Z[1]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6Z[2]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5Z[2]);
					glEnd();

					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S6Z[2]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6Z[3]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5Z[2]);
					glEnd();

					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S6Z[3]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S5Z[3]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5Z[2]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S5Z[3]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6Z[4]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5Z[4]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S5Z[3]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6Z[3]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S6Z[4]);
					glEnd();

					glBegin(GL_TRIANGLES);
					//glColor3fv(cubeColors[1]);
					glVertex3fv(S5Z[4]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6Z[4]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S6Z[5]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S5Z[4]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6Z[5]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5Z[5]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6Z[4]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6Z[5]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5Z[5]);
					glEnd();

					//------UPPER LEG-----

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6Z[3]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6Z[2]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S7Z[2]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6Z[2]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S7Z[1]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S7Z[2]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S7Z[2]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S7Z[1]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S8Z[1]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S7Z[1]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S8Z[0]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S8Z[1]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S8Z[1]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S8Z[0]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S9Z[0]);
					glEnd();

					//------LOWER LEG-----
					glBegin(GL_TRIANGLES);
					glVertex3fv(S6Z[2]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S7Z[3]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S6Z[3]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6Z[3]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S7Z[3]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S7Z[4]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S7Z[3]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S8Z[4]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S7Z[4]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S7Z[4]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S8Z[4]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S8Z[5]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S8Z[4]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S9Z[5]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S8Z[5]);
					glEnd();
					glColor3f(1.0, 1.0, 1.0);
					//-----sidewall-----

					glBegin(GL_TRIANGLES);
					glVertex3fv(S5[0]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S5Z[0]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5[5]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S5Z[0]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S5Z[5]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5[5]);
					glEnd();


					glBegin(GL_TRIANGLES);
					glVertex3fv(S6Z[0]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6[0]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S6[5]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6Z[0]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6[5]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S6Z[5]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6[3]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6Z[3]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S8[5]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6Z[3]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S8Z[5]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S8[5]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6[2]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S8[0]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S6Z[2]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6Z[2]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S8[0]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S8Z[0]);
					glEnd();
					
					//WEWNETRZNE POKRYWY BOCZNE

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6[3]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6Z[3]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S9[0]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6Z[3]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S9Z[0]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S9[0]);
					glEnd();

					//GÓRA ^ DÓ£_

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6[2]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S9[5]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S6Z[2]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S6Z[2]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S9[5]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S9Z[5]);
					glEnd();

					//KONIEC WEWN.POKRYW B.

					glBegin(GL_TRIANGLES);
					glVertex3fv(S5Z[5]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6Z[5]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S6[5]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S5Z[5]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S6[5]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S5[5]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S8Z[5]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S9Z[5]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S9[5]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S8Z[5]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S9[5]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S8[5]);
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S5Z[0]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S6[0]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6Z[0]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S5Z[0]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S5[0]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S6[0]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S8Z[0]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S9[0]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S9Z[0]);
					
					glEnd();

					glBegin(GL_TRIANGLES);
					glVertex3fv(S8Z[0]);
					//glColor3fv(cubeColors[2]);
					glVertex3fv(S8[0]);
					//glColor3fv(cubeColors[3]);
					glVertex3fv(S9[0]);
					
					glEnd();





					glEndList();
				}
#pragma region Windows Form Designer generated code
				/// <summary>
				/// Required method for Designer support - do not modify
				/// the contents of this method with the code editor.
				/// </summary>
				void InitializeComponent(void)
				{
					this->components = (gcnew System::ComponentModel::Container());
					this->btnZamknij = (gcnew System::Windows::Forms::Button());
					this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
					this->tpOpenGL = (gcnew System::Windows::Forms::TabPage());
					this->pOpenGL = (gcnew System::Windows::Forms::Panel());
					this->tpInfo = (gcnew System::Windows::Forms::TabPage());
					this->tbInfo = (gcnew System::Windows::Forms::TextBox());
					this->tpOpcje = (gcnew System::Windows::Forms::TabPage());
					this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
					this->tbPosRed = (gcnew System::Windows::Forms::GroupBox());
					this->tbPosZ = (gcnew System::Windows::Forms::TrackBar());
					this->tbPosY = (gcnew System::Windows::Forms::TrackBar());
					this->tbPosX = (gcnew System::Windows::Forms::TrackBar());
					this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
					this->tbDiffBlue = (gcnew System::Windows::Forms::TrackBar());
					this->tbDiffGreen = (gcnew System::Windows::Forms::TrackBar());
					this->tbDiffRed = (gcnew System::Windows::Forms::TrackBar());
					this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
					this->tbAmbBlue = (gcnew System::Windows::Forms::TrackBar());
					this->tbAmbGreen = (gcnew System::Windows::Forms::TrackBar());
					this->tbAmbRed = (gcnew System::Windows::Forms::TrackBar());
					this->cbLighting = (gcnew System::Windows::Forms::CheckBox());
					this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
					this->cbTexturing = (gcnew System::Windows::Forms::CheckBox());
					this->inputOffset = (gcnew System::Windows::Forms::NumericUpDown());
					this->label1 = (gcnew System::Windows::Forms::Label());
					this->lblLetter1 = (gcnew System::Windows::Forms::Label());
					this->cbK = (gcnew System::Windows::Forms::CheckBox());
					this->inputLettersHeight = (gcnew System::Windows::Forms::NumericUpDown());
					this->cbP = (gcnew System::Windows::Forms::CheckBox());
					this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
					this->cbAnimLetters = (gcnew System::Windows::Forms::CheckBox());
					this->cbScene = (gcnew System::Windows::Forms::CheckBox());
					this->cbCubeAnim = (gcnew System::Windows::Forms::CheckBox());
					this->Figures = (gcnew System::Windows::Forms::GroupBox());
					this->cbCO = (gcnew System::Windows::Forms::CheckBox());
					this->cbCUBE = (gcnew System::Windows::Forms::CheckBox());
					this->cbTR = (gcnew System::Windows::Forms::CheckBox());
					this->cbCS = (gcnew System::Windows::Forms::CheckBox());
					this->tAnimator = (gcnew System::Windows::Forms::Timer(this->components));
					this->tabControl1->SuspendLayout();
					this->tpOpenGL->SuspendLayout();
					this->tpInfo->SuspendLayout();
					this->tpOpcje->SuspendLayout();
					this->groupBox3->SuspendLayout();
					this->tbPosRed->SuspendLayout();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbPosZ))->BeginInit();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbPosY))->BeginInit();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbPosX))->BeginInit();
					this->groupBox5->SuspendLayout();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbDiffBlue))->BeginInit();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbDiffGreen))->BeginInit();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbDiffRed))->BeginInit();
					this->groupBox4->SuspendLayout();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbAmbBlue))->BeginInit();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbAmbGreen))->BeginInit();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbAmbRed))->BeginInit();
					this->groupBox2->SuspendLayout();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inputOffset))->BeginInit();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inputLettersHeight))->BeginInit();
					this->groupBox1->SuspendLayout();
					this->Figures->SuspendLayout();
					this->SuspendLayout();
					// 
					// btnZamknij
					// 
					this->btnZamknij->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
					this->btnZamknij->BackColor = System::Drawing::SystemColors::ControlLight;
					this->btnZamknij->Location = System::Drawing::Point(1209, 518);
					this->btnZamknij->Margin = System::Windows::Forms::Padding(4);
					this->btnZamknij->Name = L"btnZamknij";
					this->btnZamknij->Size = System::Drawing::Size(100, 28);
					this->btnZamknij->TabIndex = 0;
					this->btnZamknij->Text = L"Zamknij";
					this->btnZamknij->UseVisualStyleBackColor = false;
					this->btnZamknij->Click += gcnew System::EventHandler(this, &FmInicjaly::btnZamknij_Click);
					// 
					// tabControl1
					// 
					this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
						| System::Windows::Forms::AnchorStyles::Left)
						| System::Windows::Forms::AnchorStyles::Right));
					this->tabControl1->Controls->Add(this->tpOpenGL);
					this->tabControl1->Controls->Add(this->tpInfo);
					this->tabControl1->Controls->Add(this->tpOpcje);
					this->tabControl1->Location = System::Drawing::Point(0, 0);
					this->tabControl1->Margin = System::Windows::Forms::Padding(4);
					this->tabControl1->Name = L"tabControl1";
					this->tabControl1->SelectedIndex = 0;
					this->tabControl1->Size = System::Drawing::Size(1285, 511);
					this->tabControl1->TabIndex = 1;
					// 
					// tpOpenGL
					// 
					this->tpOpenGL->Controls->Add(this->pOpenGL);
					this->tpOpenGL->Location = System::Drawing::Point(4, 25);
					this->tpOpenGL->Margin = System::Windows::Forms::Padding(4);
					this->tpOpenGL->Name = L"tpOpenGL";
					this->tpOpenGL->Padding = System::Windows::Forms::Padding(4);
					this->tpOpenGL->Size = System::Drawing::Size(1277, 482);
					this->tpOpenGL->TabIndex = 0;
					this->tpOpenGL->Text = L"OpenGL";
					this->tpOpenGL->UseVisualStyleBackColor = true;
					// 
					// pOpenGL
					// 
					this->pOpenGL->Dock = System::Windows::Forms::DockStyle::Fill;
					this->pOpenGL->Location = System::Drawing::Point(4, 4);
					this->pOpenGL->Margin = System::Windows::Forms::Padding(4);
					this->pOpenGL->Name = L"pOpenGL";
					this->pOpenGL->Size = System::Drawing::Size(1269, 474);
					this->pOpenGL->TabIndex = 0;
					this->pOpenGL->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &FmInicjaly::pOpenGL_MouseMove);
					this->pOpenGL->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &FmInicjaly::pOpenGL_MouseUp);
					// 
					// tpInfo
					// 
					this->tpInfo->Controls->Add(this->tbInfo);
					this->tpInfo->Location = System::Drawing::Point(4, 25);
					this->tpInfo->Margin = System::Windows::Forms::Padding(4);
					this->tpInfo->Name = L"tpInfo";
					this->tpInfo->Size = System::Drawing::Size(1037, 482);
					this->tpInfo->TabIndex = 1;
					this->tpInfo->Text = L"Info";
					this->tpInfo->UseVisualStyleBackColor = true;
					// 
					// tbInfo
					// 
					this->tbInfo->Dock = System::Windows::Forms::DockStyle::Fill;
					this->tbInfo->Location = System::Drawing::Point(0, 0);
					this->tbInfo->Margin = System::Windows::Forms::Padding(4);
					this->tbInfo->Multiline = true;
					this->tbInfo->Name = L"tbInfo";
					this->tbInfo->ScrollBars = System::Windows::Forms::ScrollBars::Both;
					this->tbInfo->Size = System::Drawing::Size(1037, 482);
					this->tbInfo->TabIndex = 0;
					this->tbInfo->WordWrap = false;
					// 
					// tpOpcje
					// 
					this->tpOpcje->Controls->Add(this->groupBox3);
					this->tpOpcje->Controls->Add(this->groupBox2);
					this->tpOpcje->Controls->Add(this->groupBox1);
					this->tpOpcje->Controls->Add(this->Figures);
					this->tpOpcje->Location = System::Drawing::Point(4, 25);
					this->tpOpcje->Name = L"tpOpcje";
					this->tpOpcje->Padding = System::Windows::Forms::Padding(3);
					this->tpOpcje->Size = System::Drawing::Size(1037, 482);
					this->tpOpcje->TabIndex = 2;
					this->tpOpcje->Text = L"Opcje";
					this->tpOpcje->UseVisualStyleBackColor = true;
					this->tpOpcje->Click += gcnew System::EventHandler(this, &FmInicjaly::tabPage1_Click);
					// 
					// groupBox3
					// 
					this->groupBox3->Controls->Add(this->tbPosRed);
					this->groupBox3->Controls->Add(this->groupBox5);
					this->groupBox3->Controls->Add(this->groupBox4);
					this->groupBox3->Controls->Add(this->cbLighting);
					this->groupBox3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->groupBox3->Location = System::Drawing::Point(280, 179);
					this->groupBox3->Name = L"groupBox3";
					this->groupBox3->Size = System::Drawing::Size(716, 300);
					this->groupBox3->TabIndex = 4;
					this->groupBox3->TabStop = false;
					this->groupBox3->Text = L"Lights";
					// 
					// tbPosRed
					// 
					this->tbPosRed->Controls->Add(this->tbPosZ);
					this->tbPosRed->Controls->Add(this->tbPosY);
					this->tbPosRed->Controls->Add(this->tbPosX);
					this->tbPosRed->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->tbPosRed->Location = System::Drawing::Point(452, 70);
					this->tbPosRed->Name = L"tbPosRed";
					this->tbPosRed->Size = System::Drawing::Size(217, 224);
					this->tbPosRed->TabIndex = 14;
					this->tbPosRed->TabStop = false;
					this->tbPosRed->Text = L"Position";
					// 
					// tbPosZ
					// 
					this->tbPosZ->Location = System::Drawing::Point(6, 161);
					this->tbPosZ->Maximum = 255;
					this->tbPosZ->Minimum = -255;
					this->tbPosZ->MinimumSize = System::Drawing::Size(0, 10);
					this->tbPosZ->Name = L"tbPosZ";
					this->tbPosZ->Size = System::Drawing::Size(205, 56);
					this->tbPosZ->TabIndex = 12;
					// 
					// tbPosY
					// 
					this->tbPosY->Location = System::Drawing::Point(6, 99);
					this->tbPosY->Maximum = 255;
					this->tbPosY->Minimum = -255;
					this->tbPosY->MinimumSize = System::Drawing::Size(0, 10);
					this->tbPosY->Name = L"tbPosY";
					this->tbPosY->Size = System::Drawing::Size(205, 56);
					this->tbPosY->TabIndex = 11;
					// 
					// tbPosX
					// 
					this->tbPosX->Location = System::Drawing::Point(6, 37);
					this->tbPosX->Maximum = 255;
					this->tbPosX->Minimum = -255;
					this->tbPosX->MinimumSize = System::Drawing::Size(0, 10);
					this->tbPosX->Name = L"tbPosX";
					this->tbPosX->Size = System::Drawing::Size(205, 56);
					this->tbPosX->TabIndex = 10;
					// 
					// groupBox5
					// 
					this->groupBox5->Controls->Add(this->tbDiffBlue);
					this->groupBox5->Controls->Add(this->tbDiffGreen);
					this->groupBox5->Controls->Add(this->tbDiffRed);
					this->groupBox5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->groupBox5->Location = System::Drawing::Point(229, 70);
					this->groupBox5->Name = L"groupBox5";
					this->groupBox5->Size = System::Drawing::Size(217, 224);
					this->groupBox5->TabIndex = 13;
					this->groupBox5->TabStop = false;
					this->groupBox5->Text = L"Diffuse";
					// 
					// tbDiffBlue
					// 
					this->tbDiffBlue->Location = System::Drawing::Point(6, 161);
					this->tbDiffBlue->Maximum = 255;
					this->tbDiffBlue->MinimumSize = System::Drawing::Size(0, 10);
					this->tbDiffBlue->Name = L"tbDiffBlue";
					this->tbDiffBlue->Size = System::Drawing::Size(205, 56);
					this->tbDiffBlue->TabIndex = 12;
					// 
					// tbDiffGreen
					// 
					this->tbDiffGreen->Location = System::Drawing::Point(6, 99);
					this->tbDiffGreen->Maximum = 255;
					this->tbDiffGreen->MinimumSize = System::Drawing::Size(0, 10);
					this->tbDiffGreen->Name = L"tbDiffGreen";
					this->tbDiffGreen->Size = System::Drawing::Size(205, 56);
					this->tbDiffGreen->TabIndex = 11;
					// 
					// tbDiffRed
					// 
					this->tbDiffRed->Location = System::Drawing::Point(6, 37);
					this->tbDiffRed->Maximum = 255;
					this->tbDiffRed->MinimumSize = System::Drawing::Size(0, 10);
					this->tbDiffRed->Name = L"tbDiffRed";
					this->tbDiffRed->Size = System::Drawing::Size(205, 56);
					this->tbDiffRed->TabIndex = 10;
					// 
					// groupBox4
					// 
					this->groupBox4->Controls->Add(this->tbAmbBlue);
					this->groupBox4->Controls->Add(this->tbAmbGreen);
					this->groupBox4->Controls->Add(this->tbAmbRed);
					this->groupBox4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->groupBox4->Location = System::Drawing::Point(6, 70);
					this->groupBox4->Name = L"groupBox4";
					this->groupBox4->Size = System::Drawing::Size(217, 224);
					this->groupBox4->TabIndex = 12;
					this->groupBox4->TabStop = false;
					this->groupBox4->Text = L"Ambient";
					// 
					// tbAmbBlue
					// 
					this->tbAmbBlue->Location = System::Drawing::Point(6, 161);
					this->tbAmbBlue->Maximum = 255;
					this->tbAmbBlue->MinimumSize = System::Drawing::Size(0, 10);
					this->tbAmbBlue->Name = L"tbAmbBlue";
					this->tbAmbBlue->Size = System::Drawing::Size(205, 56);
					this->tbAmbBlue->TabIndex = 12;
					// 
					// tbAmbGreen
					// 
					this->tbAmbGreen->Location = System::Drawing::Point(6, 99);
					this->tbAmbGreen->Maximum = 255;
					this->tbAmbGreen->MinimumSize = System::Drawing::Size(0, 10);
					this->tbAmbGreen->Name = L"tbAmbGreen";
					this->tbAmbGreen->Size = System::Drawing::Size(205, 56);
					this->tbAmbGreen->TabIndex = 11;
					// 
					// tbAmbRed
					// 
					this->tbAmbRed->Location = System::Drawing::Point(6, 37);
					this->tbAmbRed->Maximum = 255;
					this->tbAmbRed->MinimumSize = System::Drawing::Size(0, 10);
					this->tbAmbRed->Name = L"tbAmbRed";
					this->tbAmbRed->Size = System::Drawing::Size(205, 56);
					this->tbAmbRed->TabIndex = 10;
					// 
					// cbLighting
					// 
					this->cbLighting->AutoSize = true;
					this->cbLighting->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->cbLighting->Location = System::Drawing::Point(6, 37);
					this->cbLighting->Name = L"cbLighting";
					this->cbLighting->Size = System::Drawing::Size(76, 29);
					this->cbLighting->TabIndex = 2;
					this->cbLighting->Text = L"Light";
					this->cbLighting->UseVisualStyleBackColor = true;
					// 
					// groupBox2
					// 
					this->groupBox2->Controls->Add(this->cbTexturing);
					this->groupBox2->Controls->Add(this->inputOffset);
					this->groupBox2->Controls->Add(this->label1);
					this->groupBox2->Controls->Add(this->lblLetter1);
					this->groupBox2->Controls->Add(this->cbK);
					this->groupBox2->Controls->Add(this->inputLettersHeight);
					this->groupBox2->Controls->Add(this->cbP);
					this->groupBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->groupBox2->Location = System::Drawing::Point(8, 179);
					this->groupBox2->Name = L"groupBox2";
					this->groupBox2->Size = System::Drawing::Size(234, 260);
					this->groupBox2->TabIndex = 8;
					this->groupBox2->TabStop = false;
					this->groupBox2->Text = L"Letters";
					this->groupBox2->Enter += gcnew System::EventHandler(this, &FmInicjaly::groupBox2_Enter);
					// 
					// cbTexturing
					// 
					this->cbTexturing->AutoSize = true;
					this->cbTexturing->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->cbTexturing->Location = System::Drawing::Point(6, 169);
					this->cbTexturing->Name = L"cbTexturing";
					this->cbTexturing->Size = System::Drawing::Size(112, 29);
					this->cbTexturing->TabIndex = 12;
					this->cbTexturing->Text = L"Texturing";
					this->cbTexturing->UseVisualStyleBackColor = true;
					this->cbTexturing->CheckedChanged += gcnew System::EventHandler(this, &FmInicjaly::cbTexturing_CheckedChanged);
					// 
					// inputOffset
					// 
					this->inputOffset->Cursor = System::Windows::Forms::Cursors::Hand;
					this->inputOffset->DecimalPlaces = 1;
					this->inputOffset->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->inputOffset->Location = System::Drawing::Point(134, 80);
					this->inputOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 0, 0, 0, 0 });
					this->inputOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
					this->inputOffset->Name = L"inputOffset";
					this->inputOffset->Size = System::Drawing::Size(94, 31);
					this->inputOffset->TabIndex = 11;
					this->inputOffset->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
					this->inputOffset->ValueChanged += gcnew System::EventHandler(this, &FmInicjaly::inputOffset_ValueChanged);
					// 
					// label1
					// 
					this->label1->AutoSize = true;
					this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->label1->Location = System::Drawing::Point(6, 81);
					this->label1->Name = L"label1";
					this->label1->Size = System::Drawing::Size(56, 30);
					this->label1->TabIndex = 10;
					this->label1->Text = L"Offset";
					this->label1->UseCompatibleTextRendering = true;
					// 
					// lblLetter1
					// 
					this->lblLetter1->AutoSize = true;
					this->lblLetter1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->lblLetter1->Location = System::Drawing::Point(7, 43);
					this->lblLetter1->Name = L"lblLetter1";
					this->lblLetter1->Size = System::Drawing::Size(119, 30);
					this->lblLetter1->TabIndex = 9;
					this->lblLetter1->Text = L"Letters height";
					this->lblLetter1->UseCompatibleTextRendering = true;
					this->lblLetter1->Click += gcnew System::EventHandler(this, &FmInicjaly::label1_Click);
					// 
					// cbK
					// 
					this->cbK->AutoSize = true;
					this->cbK->Checked = true;
					this->cbK->CheckState = System::Windows::Forms::CheckState::Checked;
					this->cbK->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->cbK->Location = System::Drawing::Point(6, 140);
					this->cbK->Name = L"cbK";
					this->cbK->Size = System::Drawing::Size(112, 29);
					this->cbK->TabIndex = 4;
					this->cbK->Text = L"Letter \"K\"";
					this->cbK->UseVisualStyleBackColor = true;
					// 
					// inputLettersHeight
					// 
					this->inputLettersHeight->Cursor = System::Windows::Forms::Cursors::Hand;
					this->inputLettersHeight->DecimalPlaces = 1;
					this->inputLettersHeight->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->inputLettersHeight->Location = System::Drawing::Point(134, 43);
					this->inputLettersHeight->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
					this->inputLettersHeight->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
					this->inputLettersHeight->Name = L"inputLettersHeight";
					this->inputLettersHeight->Size = System::Drawing::Size(94, 31);
					this->inputLettersHeight->TabIndex = 0;
					this->inputLettersHeight->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
					this->inputLettersHeight->ValueChanged += gcnew System::EventHandler(this, &FmInicjaly::inputLettersHeight_ValueChanged);
					// 
					// cbP
					// 
					this->cbP->AutoSize = true;
					this->cbP->Checked = true;
					this->cbP->CheckState = System::Windows::Forms::CheckState::Checked;
					this->cbP->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->cbP->Location = System::Drawing::Point(6, 114);
					this->cbP->Name = L"cbP";
					this->cbP->Size = System::Drawing::Size(112, 29);
					this->cbP->TabIndex = 5;
					this->cbP->Text = L"Letter \"P\"";
					this->cbP->UseVisualStyleBackColor = true;
					// 
					// groupBox1
					// 
					this->groupBox1->Controls->Add(this->cbAnimLetters);
					this->groupBox1->Controls->Add(this->cbScene);
					this->groupBox1->Controls->Add(this->cbCubeAnim);
					this->groupBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->groupBox1->Location = System::Drawing::Point(280, 15);
					this->groupBox1->Name = L"groupBox1";
					this->groupBox1->Size = System::Drawing::Size(229, 130);
					this->groupBox1->TabIndex = 2;
					this->groupBox1->TabStop = false;
					this->groupBox1->Text = L"Animations";
					// 
					// cbAnimLetters
					// 
					this->cbAnimLetters->AutoSize = true;
					this->cbAnimLetters->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->cbAnimLetters->Location = System::Drawing::Point(4, 95);
					this->cbAnimLetters->Name = L"cbAnimLetters";
					this->cbAnimLetters->Size = System::Drawing::Size(90, 29);
					this->cbAnimLetters->TabIndex = 3;
					this->cbAnimLetters->Text = L"Letters";
					this->cbAnimLetters->UseVisualStyleBackColor = true;
					this->cbAnimLetters->CheckedChanged += gcnew System::EventHandler(this, &FmInicjaly::cbAnimLetters_CheckedChanged);
					// 
					// cbScene
					// 
					this->cbScene->AutoSize = true;
					this->cbScene->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->cbScene->Location = System::Drawing::Point(6, 37);
					this->cbScene->Name = L"cbScene";
					this->cbScene->Size = System::Drawing::Size(80, 29);
					this->cbScene->TabIndex = 2;
					this->cbScene->Text = L"Stage";
					this->cbScene->UseVisualStyleBackColor = true;
					this->cbScene->CheckedChanged += gcnew System::EventHandler(this, &FmInicjaly::cbScene_CheckedChanged);
					// 
					// cbCubeAnim
					// 
					this->cbCubeAnim->AutoSize = true;
					this->cbCubeAnim->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->cbCubeAnim->Location = System::Drawing::Point(6, 65);
					this->cbCubeAnim->Name = L"cbCubeAnim";
					this->cbCubeAnim->Size = System::Drawing::Size(78, 29);
					this->cbCubeAnim->TabIndex = 1;
					this->cbCubeAnim->Text = L"Cube";
					this->cbCubeAnim->UseVisualStyleBackColor = true;
					this->cbCubeAnim->CheckedChanged += gcnew System::EventHandler(this, &FmInicjaly::cbCubeAnim_CheckedChanged);
					// 
					// Figures
					// 
					this->Figures->Controls->Add(this->cbCO);
					this->Figures->Controls->Add(this->cbCUBE);
					this->Figures->Controls->Add(this->cbTR);
					this->Figures->Controls->Add(this->cbCS);
					this->Figures->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->Figures->Location = System::Drawing::Point(15, 15);
					this->Figures->Name = L"Figures";
					this->Figures->Size = System::Drawing::Size(227, 158);
					this->Figures->TabIndex = 0;
					this->Figures->TabStop = false;
					this->Figures->Text = L"Figures";
					this->Figures->Enter += gcnew System::EventHandler(this, &FmInicjaly::Elementy_Enter);
					// 
					// cbCO
					// 
					this->cbCO->AutoSize = true;
					this->cbCO->Checked = true;
					this->cbCO->CheckState = System::Windows::Forms::CheckState::Checked;
					this->cbCO->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->cbCO->Location = System::Drawing::Point(6, 113);
					this->cbCO->Name = L"cbCO";
					this->cbCO->Size = System::Drawing::Size(145, 29);
					this->cbCO->TabIndex = 3;
					this->cbCO->Text = L"Cube\'s edges";
					this->cbCO->UseVisualStyleBackColor = true;
					// 
					// cbCUBE
					// 
					this->cbCUBE->AutoSize = true;
					this->cbCUBE->Checked = true;
					this->cbCUBE->CheckState = System::Windows::Forms::CheckState::Checked;
					this->cbCUBE->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->cbCUBE->Location = System::Drawing::Point(6, 88);
					this->cbCUBE->Name = L"cbCUBE";
					this->cbCUBE->Size = System::Drawing::Size(78, 29);
					this->cbCUBE->TabIndex = 2;
					this->cbCUBE->Text = L"Cube";
					this->cbCUBE->UseVisualStyleBackColor = true;
					this->cbCUBE->CheckedChanged += gcnew System::EventHandler(this, &FmInicjaly::checkBox1_CheckedChanged);
					// 
					// cbTR
					// 
					this->cbTR->AutoSize = true;
					this->cbTR->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->cbTR->Location = System::Drawing::Point(6, 64);
					this->cbTR->Name = L"cbTR";
					this->cbTR->Size = System::Drawing::Size(101, 29);
					this->cbTR->TabIndex = 1;
					this->cbTR->Text = L"Triangle";
					this->cbTR->UseVisualStyleBackColor = true;
					// 
					// cbCS
					// 
					this->cbCS->AutoSize = true;
					this->cbCS->Checked = true;
					this->cbCS->CheckState = System::Windows::Forms::CheckState::Checked;
					this->cbCS->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					this->cbCS->Location = System::Drawing::Point(6, 37);
					this->cbCS->Name = L"cbCS";
					this->cbCS->Size = System::Drawing::Size(190, 29);
					this->cbCS->TabIndex = 0;
					this->cbCS->Text = L"Coordinate system";
					this->cbCS->UseVisualStyleBackColor = true;
					// 
					// tAnimator
					// 
					this->tAnimator->Tick += gcnew System::EventHandler(this, &FmInicjaly::tAnimator_Tick);
					// 
					// FmInicjaly
					// 
					this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
					this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
					this->ClientSize = System::Drawing::Size(1325, 561);
					this->Controls->Add(this->tabControl1);
					this->Controls->Add(this->btnZamknij);
					this->Margin = System::Windows::Forms::Padding(4);
					this->Name = L"FmInicjaly";
					this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
					this->Text = L"Inicja³y PK 2018";
					this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FmInicjaly::FmInicjaly_FormClosing);
					this->Load += gcnew System::EventHandler(this, &FmInicjaly::FmInicjaly_Load);
					this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FmInicjaly::FmInicjaly_Paint);
					this->tabControl1->ResumeLayout(false);
					this->tpOpenGL->ResumeLayout(false);
					this->tpInfo->ResumeLayout(false);
					this->tpInfo->PerformLayout();
					this->tpOpcje->ResumeLayout(false);
					this->groupBox3->ResumeLayout(false);
					this->groupBox3->PerformLayout();
					this->tbPosRed->ResumeLayout(false);
					this->tbPosRed->PerformLayout();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbPosZ))->EndInit();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbPosY))->EndInit();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbPosX))->EndInit();
					this->groupBox5->ResumeLayout(false);
					this->groupBox5->PerformLayout();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbDiffBlue))->EndInit();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbDiffGreen))->EndInit();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbDiffRed))->EndInit();
					this->groupBox4->ResumeLayout(false);
					this->groupBox4->PerformLayout();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbAmbBlue))->EndInit();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbAmbGreen))->EndInit();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbAmbRed))->EndInit();
					this->groupBox2->ResumeLayout(false);
					this->groupBox2->PerformLayout();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inputOffset))->EndInit();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inputLettersHeight))->EndInit();
					this->groupBox1->ResumeLayout(false);
					this->groupBox1->PerformLayout();
					this->Figures->ResumeLayout(false);
					this->Figures->PerformLayout();
					this->ResumeLayout(false);

				}
#pragma endregion
			private: System::Void btnZamknij_Click(System::Object^  sender, System::EventArgs^  e)
			{
				Close();
			}
			private: System::Void FmInicjaly_Load(System::Object^  sender, System::EventArgs^  e)
			{
				tbInfo->AppendText("Uruchomienie aplikacji.\r\n");
				tbInfo->AppendText("\n");
				tbInfo->AppendText("\n");
				tbInfo->AppendText("\n");
				tbInfo->AppendText("Program do wyœwietlania inicja³ów.\n");
				tbInfo->AppendText("Autor: Krystkiewicz Pawe³\n");
				tbInfo->AppendText("Politechnika Poznañska 2018\n");
				tbInfo->AppendText("Utworzenie kontekstu do renderowania OpenGL.");

				panelDC = GetDC((HWND)pOpenGL->Handle.ToPointer());
				SetDCPixelFormat(panelDC);
				panelRC = wglCreateContext(panelDC);
				wglMakeCurrent(panelDC, panelRC);

			glEnable(GL_DEPTH_TEST);
			/*
				wchar_t *filename = L"C:\\texture.png";
				tekstura = uploadTexture(filename);
				*/
				if (cbCubeAnim->Checked)
				{
				}
				else
				{
					glEnable(GL_CULL_FACE);
				}

				formResize();

				dlCS = 1;
				dlTR = 2;
				dlCUBE = 3;
				dlCO = 4;
				dlP = 5;
				dlK = 6;

				createCS(dlCS);
				createTR(dlTR);
				createCUBE(dlCUBE);
				createCubeOutline(dlCO);
				createLetterP(dlP);
				createLetterK(dlK);

				time = 0.0;
				zoom = 400.0;
				rotX = 11.0;
				rotY = -115.0;
				tX = 0.0;
				tY = 0.0;
				lastX = 0.0;
				lastY = 0.0;
			}
			private: System::Void FmInicjaly_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
			{
				wglDeleteContext(panelRC);//deleting exisiting rendering context, add another if more contexts will be added/used
			}


			private: System::Void FmInicjaly_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
			{
				glClearColor(0.0, 0.5, 1.0, 0.0);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

				glMatrixMode(GL_MODELVIEW);

				if (cbTexturing->Checked)
				{
					glEnable(GL_TEXTURE_2D);
				}
				else
				{
					glDisable(GL_TEXTURE_2D);
				}
				
				if (cbLighting->Checked)
				{
					glEnable(GL_LIGHTING);
					glEnable(GL_LIGHT0);
					glEnable(GL_COLOR_MATERIAL);

					glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

					GLfloat amb[3], diff[3], pos[3];
					amb[0] = (GLfloat)tbAmbRed->Value / 255.0;
					amb[1] = (GLfloat)tbAmbGreen->Value / 255.0;
					amb[2] = (GLfloat)tbAmbBlue->Value / 255.0;

					diff[0] = (GLfloat)tbDiffRed->Value / 255.0;
					diff[1] = (GLfloat)tbDiffGreen->Value / 255.0;
					diff[2] = (GLfloat)tbDiffBlue->Value / 255.0;

					pos[0] = (GLfloat)tbPosX->Value;
					pos[1] = (GLfloat)tbPosY->Value;
					pos[2] = (GLfloat)tbPosZ->Value;

					glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
					glLightfv(GL_LIGHT0, GL_AMBIENT, diff);
					glLightfv(GL_LIGHT0, GL_AMBIENT, pos);
					
					glPointSize(10);
					
					glBegin(GL_POINTS);
					glColor3b(0.0, 0.0, 0.0);
					glVertex3fv(pos);
					glEnd;
				}
				else
				{
					glDisable(GL_LIGHTING);
					glDisable(GL_LIGHT0);
					glDisable(GL_COLOR_MATERIAL);

					

				}


				glLoadIdentity();
				glTranslatef(0.0, 0.0, -zoom);
				glTranslatef(tX, tY, 0.0);

				glRotatef(rotX, 1.0, 0.0, 0.0);
				glRotatef(rotY, 0.0, 1.0, 0.0);

				/*if (cbCS->Checked)
				{
					glCallList(dlCS);
				}

				if (cbP->Checked)
				{
					glCallList(dlP);
				}

				if (cbK->Checked)
				{
					glCallList(dlK);
				}*/

				if (cbTR->Checked)
				{
					glCallList(dlTR);
				}

				//Cube Animation
				if (cbCubeAnim->Checked)
				{
					glPushMatrix();
					glScalef(sin(time), sin(time + Math::PI * 2 / 3), sin(time - Math::PI * 2 / 3));
					glRotatef(time * 180 * Math::PI, 1.0, 1.0, 1.0);
					if (cbCUBE->Checked) glCallList(dlCUBE);
					glPopMatrix();
				}
				else
				{
					if (cbCUBE->Checked) glCallList(dlCUBE);
				}
				//CS Animation
				if (cbScene->Checked)
				{
					glPushMatrix();
					glScalef(sin(time), sin(time + Math::PI * 2 / 3), sin(time - Math::PI * 2 / 3));
					glRotatef(time * 180 * Math::PI, 1.0, 1.0, 1.0);
					if (cbCS->Checked) glCallList(dlCS);
					glPopMatrix();
				}
				else
				{
					if (cbCS->Checked) glCallList(dlCS);
				}
				//Letters Animation
				if (cbAnimLetters->Checked)
				{
					glPushMatrix();
					glScalef(sin(time), sin(time + Math::PI * 2 / 3), sin(time - Math::PI * 2 / 3));
					glRotatef(time * 180 * Math::PI, 1.0, 1.0, 1.0);
					if (cbP->Checked) glCallList(dlP);
					if (cbK->Checked) glCallList(dlK);
					glPopMatrix();
				}
				else
				{
					if (cbP->Checked) glCallList(dlP);
					if (cbK->Checked) glCallList(dlK);
				}
			

				if (cbCO->Checked)
				{
					glCallList(dlCO);
				}

				SwapBuffers(panelDC);


			}

			private: System::Void pOpenGL_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
			{
				Cursor = Cursors::Default;
			}
			private: System::Void pOpenGL_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
			{
				GLfloat dx = e->Location.X - lastX;
				GLfloat dy = e->Location.Y - lastY;
				lastX = e->Location.X;
				lastY = e->Location.Y;

				switch (e->Button)
				{
				case System::Windows::Forms::MouseButtons::Left:
				{
					Cursor = Cursors::SizeAll;
					rotX += 0.5*dy;
					if (rotX == 360)
						rotX -= 360;


					rotY += 0.5*dx;//+resetowanie przed przeci¹¿eniem //if(rotX=360){rotx-=360;}
					if (rotY == 360)
						rotY -= 360;
					Invalidate();

					break;
				}
				case System::Windows::Forms::MouseButtons::Right:
				{
					if (dy != 0)
					{
						Cursor = Cursors::SizeNS;
						zoom -= 0.5*dy;	//+resetowanie przed przeci¹¿eniem //if(rotX=)
						Invalidate();
					}
					break;
				}
				case System::Windows::Forms::MouseButtons::Middle:
				{


					Cursor = Cursors::SizeAll;
					tX += 0.5*dx;	//+resetowanie przed przeci¹¿eniem //if(rotX=)
					tY -= 0.5*dy;
					Invalidate();

					break;
				}

				}
			};

					 ;

			private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e)
			{
			}
			private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
			{
			}

			private: System::Void tAnimator_Tick(System::Object^  sender, System::EventArgs^  e)
			{
				Invalidate();
				if (time < Math::PI)
				{
					time = time + 0.05;
				}
				else
				{
					time = time - Math::PI;
				}
			}
			private: System::Void cbCubeAnim_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
			{
				tAnimator->Enabled = cbCubeAnim->Checked;
			}
					 
			private: System::Void groupBox2_Enter(System::Object^  sender, System::EventArgs^  e) {
			}
private: System::Void tbLettersBase_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	
			//z = tBLettersBase;
}
private: System::Void tBLettersHeight_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	
	//z1 = (double)tBLettersHeight;
}
private: System::Void tBLettersBase_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	{
		
	}
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
public: System::Void inputLettersHeight_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	z1 = Convert::ToDouble(inputLettersHeight->Value);
	createLetterP(dlP);
	createLetterK(dlK);
	//Invalidate();
}
private: System::Void trackBarH_Scroll(System::Object^  sender, System::EventArgs^  e) {
	//z1 = Convert::ToDouble(trackBarH ->Value);
}
private: System::Void inputLettersOffset_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	z = Convert::ToDouble(inputOffset->Value);
	createLetterP(dlP);
	createLetterK(dlK);
}
private: System::Void Elementy_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void inputOffset_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	z = Convert::ToDouble(inputOffset->Value);
	createLetterP(dlP);
	createLetterK(dlK);
}

private: System::Void cbAnimLetters_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	tAnimator->Enabled = cbAnimLetters->Checked;
}
private: System::Void cbScene_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	tAnimator->Enabled = cbScene->Checked;
}
private: System::Void checkBox1_CheckedChanged_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void cbTexturing_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

}
};
		}
	