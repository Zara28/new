#include <iostream>
#include <stdio.h>
       int a1,a11;
        long int a2,a22;
        short int a3,a33;
        float a4,a44;
        double a5,a55;
        char a6,a66;
        char a7[10],a77[10];
//---------------------------------------------------------------------------
void Vvod()
{
        cout<<"Vvedite <int> : ";
        cin>>a1;
        ñout<<"Vvedite <long> : ";
        cin>>a2;
        cout<<"Vvedite <short> : ";
        cin>>a3;
        cout<<"Vvedite <float>";
        cin>>a4;
        cout<<"Vvedite <double>";
        cin>>a5;
        cout<<"Vvedite <char>";
        cin>>a6;
        cout<<"Vvedite <char[10]>";
        cin>>a7;
}
//---------------------------------------------------------------------------
void ZapFail(FILE *f2)
{
  fprintf(f2,"%d \n",a1);
  fprintf(f2,"%ld \n",a2);
  fprintf(f2,"%hd \n",a3);
  fprintf(f2,"%.3f \n",a4);
  fprintf(f2,"%.3lf \n",a5);
  fprintf(f2,"%c \n",a6);
  fprintf(f2,"%s \n", &a7);
}
//---------------------------------------------------------------------------
void ChitFail(FILE *f2)
{
  fscanf(f2,"%i",&a11);
  cout<<"\n"<<a11;
  fscanf(f2,"%i",&a22);
  ñout<<"\n"<<a22;
  fscanf(f2,"%i",&a33);
  cout<<"\n"<<a33;
  fscanf(f2,"%f",&a44);
  cout<<"\n"<<a44;
  fscanf(f2,"%lf",&a55);
  cout<<"\n"<<a55;
  fscanf(f2,"%s",&a66);
  cout<<"\n"<<a66;
  fscanf(f2,"%s",a77);
  cout<<"\n"<<a77;
}
//---------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
    Vvod();
    FILE *f2;

    f2=fopen("str2.txt","w");
    ZapFail(f2);
    fclose(f2);

    f2=fopen("str2.txt","r");
    ChitFail(f2);
    fclose(f2);
}
