//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Power_Polynomial.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define Max 100
int result1 = 1;
int result2 = 1;
int result3;
int para[Max];

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void Power(int x, int n)
{   int i;
	for (i = 1; i <= n; i++)
	   result1 *= x;
}

void poly(int para[], int k, int m)
{	result3 = para[k];
	int func[100];
	for(int i = 1; i <= m; i++)
	{	for(int j = k - 1; j >= 0; j--)
		{	result3 = result3 * i + para[j];
		}
		func[i] = result3;
        result3 = para[k];
	}
	for(int i = 1; i <= m; i++)
		Form1->Memo2->Lines->Add("f("+IntToStr(i)+") = "+IntToStr(func[i]));

}


void __fastcall TForm1::Button1Click(TObject *Sender)
{	int x = StrToInt(Edit1->Text);
	int n = StrToInt(Edit2->Text);
	if(CheckBox1->Checked)
	{	Power(x, n);
		Form1->Memo1->Lines->Add("x^n = "+IntToStr(result1));
	}
	if(CheckBox2->Checked)
	{	result2 = pow(x, n);
		Form1->Memo1->Lines->Add("pow(x, n) = "+IntToStr(result2));
	}
	result1 = 1;
	result2 = 1;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{	int k = StrToInt(Edit3->Text);
	int m = StrToInt(Edit4->Text);
	TStringList* sl = new TStringList();
	sl->Delimiter=','; // ¤À¹j¦r¤¸
	sl->DelimitedText = Edit5->Text; // ¦r¦ê¨Ó·½
	for(int i = 0; i < sl->Count; ++i)
		para[i] = StrToInt(sl->Strings[i]);
	delete sl;
	poly(para, k, m);
}
//---------------------------------------------------------------------------

