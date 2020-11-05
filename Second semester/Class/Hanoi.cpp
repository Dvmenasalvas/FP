#include <iostream>
#include <string>
#include <vector>
using namespace std;


int Hanoi(int N, char origen, char destino, char aux){
	int i = 0;
	if (N > 0) {
		i += Hanoi(N - 2, origen, aux, destino);
		cout << "Mover torre negra " << N - 1 << " desde " << origen << " hasta " << aux << '\n';
		cout << "Mover torre blanca " << N << " desde " << origen << " hasta " << destino << '\n';
		cout << "Mover torre negra " << N - 1 << " desde " << aux << " hasta " << destino << '\n';
		i += Hanoi(N - 2, aux, destino, origen);
		i += 3;
	}
	return i;
}

int main(){
	int N;
	cout << "Inserte el numero de piezas(se multiplica por dos): ";
	cin >> N;
	N *= 2;
	cout << "Numero de movimientos: " << Hanoi(N , 'A', 'B', 'C') << '\n';
	system("pause");
	return 0;
}