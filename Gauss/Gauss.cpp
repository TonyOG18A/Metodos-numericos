#include<iostream>
#include<math.h>
#include<iomanip>
#include<string>
using namespace std;


class Gauss{
	public:
		//Metodo para recibir los datos de la matriz
		void RecDatos(){
			cout<<"Ingrese el tamaño de su sistema de ecuaciones: ";
			cin>>tam;
			long double Coeficientes[10][15]={0};
			
			cout<<"Ingrese los coeficiente de su sistema de ecuaciones."<<endl;
			for(int i=0;i<=tam;++i){
				if(i<tam)
					cout<<"x"<<i<<"\t";
				else	
					cout<<"v";
			}
			cout<<endl;
			for(int r=0;r<tam;++r)
				for(int c=0;c<=tam;++c)
					cin>>Coeficientes[r][c];
			MetGauss(tam,Coeficientes);
		}
		//Metodo para imprimir la matriz
		void ImpMatriz(int ta,long double Coeficientes[][15]){
			for(int i=0;i<=ta;++i){
				if(i<ta)
					cout<<"x"<<ta-i-1<<"\t";
				else	
					cout<<"v";
			}
			cout<<endl;
			for(int r=0;r<ta;++r){
				cout<<"|";
				for(int c=0;c<=ta;++c){
					cout<<Coeficientes[r][c];
					if(c==ta-1||c==ta)
						cout<<"|\t";
					else 
						cout<<"\t";
				}
				cout<<endl;
			}

		}
		string DecimalAFraccion(long double numero){
			if(numero-int(numero)!=0){
				num2=1;
				n=1;
				d=1;	
				Fraccion={0};	
				while(!(num2==numero)){
					num2=n/d;
					if(num2<numero)
						++n;
					if(num2>numero){
						--n;
						++d;
					}
				}
				Fraccion+=(to_string(int(n))+"/"+to_string(int(d)));	
				return Fraccion;
			}
			else
				return to_string(int(numero));
		}
		//Metodo para imprimir los resultados en fraccion.
		void ImpResultados(int ta,long double Coeficientes[][15],bool Valid,int f){
			if(Valid==false){
				for(int i=0;i<ta;++i){
					num=double(Coeficientes[i][ta]);
					if(num<0)
						num*=-1;
					if(Coeficientes[i][ta]<0)
						cout<<"x"<<i<<"= -"<<DecimalAFraccion(num)<<endl;
					else
						cout<<"x"<<i<<"= "<<DecimalAFraccion(num)<<endl;
				}
			}
			else{
				cout<<"x"<<f<<"= t"<<endl;
				for(int i=0;i<ta&&i!=f;++i){
					PartReal=0;
					PartParametrica=0;
					long double PartParametricaAnterior[ta-2];
					long double PartRealAnterior[ta-2];
					for(int c=0;c<=i;++c){
						if(i>=2){
							if(c!=i)
								PartReal+=((-1*Coeficientes[ta-2-i][ta-1-i+c])*PartRealAnterior[i-1-c]);
						}
						else
							PartReal+=((-1*Coeficientes[ta-2-i][ta-1-i+c])*Coeficientes[ta-1-i+c][ta]);
						if(c==i)
							PartParametrica+=((-1*Coeficientes[ta-2-i][ta-1-i+c]));
						else{
							if(i>=2)
								PartParametrica+=((-1*Coeficientes[ta-2-i][ta-1-i+c])*PartParametricaAnterior[i-1-c]);
							else
								PartParametrica+=((Coeficientes[ta-2-i][ta-1-i+c])*Coeficientes[ta-1-i+c][ta-i+c]);
							
						}
					}	
					PartParametricaAnterior[i]=PartParametrica;
					PartReal+=Coeficientes[ta-2-i][ta];
					PartRealAnterior[i]=PartReal;
					//Fraccion=DecimalAFraccion(double(PartReal));
					if(PartReal<0){
						PartReal*=-1;
						cout<<"x"<<ta-2-i<<"= -"<<DecimalAFraccion(double(PartReal));
					}
					else
						cout<<"x"<<ta-2-i<<"= "<<DecimalAFraccion(double(PartReal));
					if(PartParametrica<0){
						PartParametrica*=-1;
						cout<<"-"<<DecimalAFraccion(double(PartParametrica))<<"t"<<endl;
					}
					else
						cout<<"+"<<DecimalAFraccion(double(PartParametrica))<<"t"<<endl;
				}
			}
			

		}//Metodo donde se desarrolla todo el proceso de Gauss-Jordan
		void MetGauss(int ta,long double Coeficientes[][15]){
			for(int i=0,r=0,r2=1,r3=1;i<=(ta*2)-1;++i){
				if(i%2==0&&i<(ta*2)-1){
					D=Coeficientes[r][r];
					if(Coeficientes[r][r]==0){
						Valid1=true;
						if(Coeficientes[r][ta]==0){
							Valid2=true;
							fila=r;
						}
						break;
					}	
					for(int c=r;c<=tam;++c){
						Coeficientes[r][c]/=D;
					}
				++r;
				}
				if(i%2!=0&&i<(ta*2)-1){
					for(int k=r2;k<ta;++k){
						D=Coeficientes[k][r2-1];
						for(int c=r2-1;c<=ta;++c)
							Coeficientes[k][c]-=(D*Coeficientes[r2-1][c]);
						
					}
					++r2;
				}
				if(i>=(ta*2)-1){
					for(int k=ta-2;k>=0;--k){
						if(k==ta-2){
							D=Coeficientes[k][k+1];
							for(int c=k+1;c<=ta;++c)
								Coeficientes[k][c]-=(D*Coeficientes[k+1][c]);
						}
						else
								for(int f=0;f<ta-(k+1);++f){					
									D=Coeficientes[k][f+k+1];
									Coeficientes[k][f+k+1]-=(D*Coeficientes[f+k+1][f+k+1]);
									Coeficientes[k][ta]-=(D*Coeficientes[f+k+1][ta]);
								}
					}
				}
			}
			ImpMatriz(tam,Coeficientes);
			if(Valid1==true)
				if(Valid2==true){
					cout<<"Sistema consistente indeterminado.Numero infinito de soluciones."<<endl;
					ImpResultados(tam,Coeficientes,Valid2,fila);
				}
				else
					cout<<"Sistema consistente indeterminado.No existe solucion."<<endl;
			else{
				cout<<"Sistema consistente determinado.Solucion unica."<<endl;
				ImpResultados(tam,Coeficientes,false,fila);
			}
		}
	private:
		int tam=0;
		int fila=0;
		double n=1;
		double d=1;
		long double num=0;
		long double num2=1;
		long double D=0;
		long double PartReal=0;
		long double PartParametrica=0;
		//long double PartParametricaAnterior=0;
		bool Valid1=false;
		bool Valid2=false;
		string Fraccion;
};

int main(){
	Gauss Gauss1;
	Gauss1.RecDatos();
return 0;
}
