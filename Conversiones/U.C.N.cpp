#include<iostream>
#include<math.h>
#include<cstdlib>
#include<iomanip>
#include<string>
using namespace std;
class conver{
	public:
		void dectobin(long double num,int sig){
			p=0;
			string binario;
			cout<<"Binario: ";
			if(num<0){
				num*=-1;
				cout<<"-";
			}
			long long entero=(long long)(num);
			decimal=num-entero;
			coc=num;
		while(entero>1){
        			entero=coc;
              		if(entero%2==1)
              			binario="1"+binario;
              		else
                     		binario="0"+binario;
              		coc=entero/2;
		}
       		cout<<binario;
              	if(sig!=0){
       		cout<<".";
       			for(int r=0;r<sig;++r){
					prod=decimal*2;
					cout<<int(prod);
					decimal=prod - int(prod);
					if(decimal==0)
						r=sig;
				}
			}
		}
		long double bintodec(string binario){
			decimal=0;
			pot=-1;
			for(int r=0;r<binario.size();++r){
				if(binario[r]!='.'&&binario[r]!='-'){
					++pot;	
				}
				if(binario[r]=='.')
					r=binario.size();
				//(binario[r]=='.')?r=0:0;
				//(r==0&&binario[c]!='.')?pot=0:0;
				
			}
			for(long long int d=0;d<binario.size();++d){
                		if(binario[d]!='.'&&binario[d]!='-'){
					decimal+=(binario[d]-'0')*pow(2,pot);
				--pot;
				}
			}
			(binario[0]=='-')?decimal*=-1:0;
			return decimal;
		}
		void dectooct(long double num,int sig){
			o=0;
			if(num<0){
				num*=-1;
				cout<<"-";
			}
			long long entero=(long long)(num);
			decimal=num-entero;
			while(entero>0){
				octal[o]=entero%8;
				coc=entero/8;
				entero=coc;
				++o;
			}
			cout<<"Octal: ";
			for(int j=o-1;j>=0;--j)
				cout<<octal[j];
			if(sig!=0){
				cout<<".";
       			for(int r=0;r<sig;++r){
       				prod=decimal*8;
       				cout<<int(prod);
       				decimal=prod-int(prod);
       				if(decimal==0)
						r=sig;
				}
			}

		}
		long double octtodec(string octal){
			decimal=0;
			pot=0;
			for(int r=octal.size()-1,c=r;r>=0;--r,--c){
				(octal[r]=='.')?r=0:0;
				(r==0&&octal[c]!='.')?pot=0:0;
				--pot;
			}
			++pot;
			for(int h=octal.size()-1;h>=0;--h,++pot){
				if(octal[h]!='.'&&octal[h]!='-')
					decimal+=(octal[h]-'0')*pow(8,pot);
				else
					--pot;	
			}
			(octal[0]=='-')?decimal*=-1:0;
			return decimal;
		}
		void bintooct(string binario,int sig){
			dectooct(bintodec(binario),sig);
		}
		void octtobin(string oct,int sig){
			dectobin(octtodec(oct),sig);
		}
	private:
		long long int coc=0;
		long long int i=0;
		long long int numero=0;
		long long int entero=0;
		long long int pot=0;
		long long int o=0;
		long long int p=0;
		long long int sig=0;
		long double prod=0;
		long double decimal=0;
		int octal[100];
};
int main(){
		long long int opc,sig,res=1,entero;
	long double frac,num;
	string binario,oct;
	conver conver;
	cout<<"Bienvenido al U.N.C (Universal Number Converter) JAJAJA .\n";
	while(res==1){
		cout<<"Seleccione el tipo de conversion que desea realizar ingresando el numero que se encuentra a lado de la opcion.\n1.-Decimal-Binario.                        2.-Binario-Decimal.\n3.-Decimal-Octal.                          4.-Octal-Decimal.\n5.-Binario-Octal.                          6.-Octal-Binario.\n"<<"                                ";
			cin>>opc;
		switch(opc){
			case 1:
			cout<<"Ingrese el numero decimal que desea convertir a numero binario: ";
			cin>>num;
			if(num-(long long)(num)==0)
			conver.dectobin(num,0);
			else{
				cout<<"Ingrese la cantidad de cifras significativas que desea despues del punto decimal: ";
				cin>>sig;
				conver.dectobin(num,sig);
			}
			break;
			case 2:
			cout<<"Ingrese el numero binario que desea convertir a numero decimal: ";
			cin>>binario;
			cout<<"Ingrese la cantidad de cifras significativas que desea: ";
			cin>>sig;
			cout<<conver.bintodec(binario);
			break;
			case 3:
			cout<<"Ingrese el numero decimal que desea convertir a numero octal: ";
			cin>>num;
			if(num-(long long)(num)==0)
				conver.dectooct(num,0);
			else{
				cout<<"Ingrese la cantidad de cifras significativas que desea despues del punto decimal: ";
				cin>>sig;
				conver.dectooct(num,sig);
			}
			break;
			case 4:
			cout<<"Ingrese el numero octal que desea convertir a numero decimal: ";
			cin>>oct;
			cout<<"Ingrese la cantidad de cifras significativas que desea: ";
			cin>>sig;
			cout<<setprecision(sig)<<conver.octtodec(oct);
			break;
			case 5:
			cout<<"Ingrese el numero binario que desea convertir a numero octal: ";
			cin>>binario;
			if(atof(binario.c_str())-atoi(binario.c_str())==0)
				conver.bintooct(binario,0);
			else{
				cout<<"Ingrese la cantidad de cifras significativas que desea despues del punto decimal:";
				cin>>sig;
				conver.bintooct(binario,sig);
			}
			break;
			case 6:
			cout<<"Ingrese el numero octal que desea convertir a numero binario: ";
			cin>>oct;
			long num=(long)(atof(oct.c_str()));
			long long entero=(long long)(atoi(oct.c_str()));
			cout<<num<<endl<<entero<<endl;
			cout<<num-entero;
			if(num-entero==0)
				conver.octtobin(oct,0);
			else{
				cout<<"Ingrese la cantidad de cifras significativas que desea despues del punto decimal: ";
				cin>>sig;
				conver.octtobin(oct,sig);
			}
			break;
		}
	cout<<"\nContinuar? Si(1)    No(0):";
	cin>>res;
	}
return 0;
}
