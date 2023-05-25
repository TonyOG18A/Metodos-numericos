#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<fstream>
#include<math.h>

using namespace std;

class Lagrange{
	public:
		long double Funcion(long long int n,long double Parametros[],long double x){
			long double Fx=0;
			for(int i=0;i<=n;++i)
				Fx+=Parametros[i]*pow(x,n-i);
			return Fx;
		}
		void Grafica(long long int n,long double Parametros[],long double x){
			ofstream file_plot;
			file_plot.open("Grafica.dat");
			
			for(double i=x-100;i<=x+100;i+=0.001){
				fx=Funcion(n,Parametros,i);
				file_plot<<i<<" "<<fx<<endl;
			}
			file_plot.close();

			FILE*vent=popen("gnuplot -persist","w");
			fprintf(vent, "load \"Grafica.txt\" \n");
		}
		long double* Li(int Grado,long double x[]){
			static long double Lix[100];
			long double PolAux[Grado+1];
			long double Pol3[4]={0};
			Pol3[0]=1;
			Lix[0]=1;
			Pol3[3]=1;
			if(Grado>=1&&Grado<=2){
				Lix[1]=0;
				Lix[2]=1;
				for(int r=0;r<Grado;++r){
					Lix[1]-=x[r];
					if(Grado==2)
						Lix[2]*=(-1*x[r]);
				}
			}
			if(Grado>2){
				for(int r=0;r<3;++r){
					Pol3[1]-=x[r];
					Pol3[3]*=(-1*x[r]);
				}
				for(int r=2 ;r>=0;--r){
					Aux=0;
					for(int c=0;c<r;++c)
						Aux-=x[c];
					Pol3[2]+=(-1*x[r])*Aux;
				}
				for(int r=0;r<=3;++r){
					PolAux[r]=Pol3[r];
					Lix[r]=Pol3[r];
				}
				for(int i=0;i<=Grado-4;++i){
					for(int r=0;r<=Grado-1;++r){
						if(r<Grado-1)
							Lix[r+1]=(PolAux[r]*(-1*x[3+i]))+PolAux[r+1];	
						else
							Lix[r+1]=PolAux[r]*(-1*x[3+i]);
					}
				for(int r=0;r<=Grado;++r)
					PolAux[r]=Lix[r];	
				}
			}
		return Lix;
		}
		void ImprimirPolinomio(long long int Grado,long double Px[]){
			cout<<"El polinomio de aproximación es: f(x)= ";
			for(int i=0;i<=Grado;++i){
				if(Px[i]>0&&i!=0&&i!=Grado){
					if(i!=Grado-1)
						cout<<"+"<<Px[i]<<"x^"<<Grado-i;
					else
						cout<<"+"<<Px[i]<<"x";
				}
				else if(i==Grado){
					if(Px[i]>0)
						cout<<"+"<<Px[i];
					else
						cout<<Px[i];

				}

				else{
					if(i!=Grado-1)
						cout<<Px[i]<<"x^"<<Grado-i;
					else
						cout<<Px[i]<<"x";
				}
			}
		}
		void MetLagrange(){
			system("CLS");
			cout<<"Ingrese el nombre del archivo."<<endl;
			cin>>archivo;
			ifstream Datos(archivo,ios::in);
			if(!Datos){
				cerr<<"No se pudo abrir el archivo"<<endl;
				exit(EXIT_FAILURE);
			}
			long double Valores[100][2];
			while(Datos>>Punto>>datoX>>datoY){
				cout<<Punto<<"\t"<<datoX<<"\t"<<datoY<<endl;
				for(int c=0;c<2;++c){
					if(c==0)
						Valores[Punto][c]=datoX;
					else
						Valores[Punto][c]=datoY;
				}
			}
			cout<<"Ingrese el grado con el que desea que se genere el polinomio de aproximación(Grado maximo="<<Punto<<"):";
			cin>>Grado;
			long double Px[Grado+1]={0};
			long double* L;
			long double xi[Punto];		
			for(int i=0;i<=Grado;++i){
				Comp=1;
				for(int r=0,k=0;r<=Grado;++r){
					if(r!=i){
						xi[k]=Valores[r][0];
						Comp*=(Valores[i][0]-xi[k]);
						++k;
					}
				}
				L=Li(Grado,xi);
				Comp=Valores[i][1]/Comp;
				for(int k=0;k<=Grado;++k)
					Px[k]+=Comp*L[k];
			}
			ImprimirPolinomio(Grado,Px);
			cout<<"\nIngrese un punto para evaluarlo:";
			cin>>num;
			fx=Funcion(Grado,Px,num);
			
			cout<<"F("<<num<<")="<<fx<<endl;
			Grafica(Grado,Px,num);
		}
	private:
		string archivo;
		int Punto=0;
		int Grado=0;
		double n=1;
		double d=1;
		long double datoX=0;
		long double datoY=0;
		long double Aux=0;
		long double Comp=1;
		long double num=0;
		long double fx=0;
		long double num2=1;
		string Fraccion;
};
int main(){
	Lagrange Polinomio;
	Polinomio.MetLagrange();
	return 0;
}
