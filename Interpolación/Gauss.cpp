#include<iostream>
#include<math.h>
#include<iomanip>
#include"Gauss.h"
using namespace std;
void Gauss::ImpMatriz(int ta,long double Coeficientes[][15]){
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
//Metodo donde se desarrolla todo el proceso de Gauss-Jordan
long double* Gauss::MetGauss(int ta,long double Coeficientes[][15]){
	static long double Soluciones[100];
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
			for(int c=r;c<=ta;++c){
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
	cout<<"Solución del sistema de ecuaciones."<<endl;
	
	ImpMatriz(ta,Coeficientes);
	/*cout<<"El polinomio de aproximación es: ";
	for(int i=ta-1;i>=0;--i){
		if(i>1){
			if(Coeficientes[i][ta]>=0&&i!=ta-1)
				cout<<"+"<<Coeficientes[i][ta]<<"x^"<<i;
			else
				cout<<Coeficientes[i][ta]<<"x^"<<i;
		}
		else if(i==1){
			if(Coeficientes[i][ta]>=0)
				cout<<"+"<<Coeficientes[i][ta]<<"x";
			else
				cout<<Coeficientes[i][ta]<<"x";
		}
		else{
			if(Coeficientes[i][ta]>=0)
				cout<<"+"<<Coeficientes[i][ta];
			else
				cout<<Coeficientes[i][ta];
		}
	}
	cout<<endl;*/
	for(int i=0;i<ta;++i)
		Soluciones[i]=Coeficientes[i][ta];
	return Soluciones;
}
	
