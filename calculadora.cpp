#include <iostream>



using namespace std;


int incremento (int x) {
	return x+1;
}

int decremento (int x) {
	return x-1;
}

int add (int x, int y, int z = 0, int q = 0) {
	for (int i = 1; i <= (y + z + q); ++i)
		x = incremento(x);
	return x;
}

int sub (int x, int y) {
	for (int i = 1; i <= y; ++i)
		x = decremento(x);

	return x < 0 ? 0 : x;
}

int prod (int x, int y) {
	int k = 0;
	for (int i = 0; i < y; ++i) {
		k += add(x, 0);
	}
	return x == 0 ? y : y == 0 ? x : k;
}

int div (int divisor, int dividendo) {
	for (int i = 0; i < dividendo; ++i) {
		divisor = sub(divisor, dividendo);		
	}
	return divisor;
}

int mod (int divisor, int dividendo) {
	if (divisor >= dividendo)
		divisor = mod (sub(divisor, dividendo), dividendo);

	return divisor;
}

int main() {
	int op;
	bool sair = false;
	
	while (!sair) {
		cout << "Escolha:" << endl;
		cout << "(1) incrementar: " << endl;
		cout << "(2) decrementar: " << endl;
		cout << "(3) somar: " << endl;
		cout << "(4) subtrair: " << endl;
		cout << "(5) multiplicar: " << endl;
		cout << "(6) dividir: " << endl;
		cout << "(7) resto: " << endl;
		cout << "(0) sair: " << endl;
		cin >> op;
		int v[4];
		int x;
		switch(op) {
			case 1:
				cout << "valor: ";
				cin >> x;
				cout << incremento(x) << endl;
				break;
			case 2:
				cout << "valor: ";
				cin >> x;
				cout << decremento(x) << endl;
				break;
			case 3:
				for (int i = 0; i < 4; ++i){
					cout << "valor " << (i + 1) << ": ";
					cin >> v[i];
				}
				cout << add(v[0], v[1], v[2], v[3]) << endl;
				break;
			case 4:
				for (int i = 0; i < 2; ++i){
					cout << "valor " << (i + 1) << ": ";
					cin >> v[i];
				}
				cout << sub(v[0], v[1]) << endl;
				break;
			case 5:
				for (int i = 0; i < 2; ++i){
					cout << "valor " << (i + 1) << ": ";
					cin >> v[i];
				}
				cout << prod(v[0], v[1]) << endl;
				break;
			case 6:
				for (int i = 0; i < 2; ++i){
					cout << "valor " << (i + 1) << ": ";
					cin >> v[i];
				}
				cout << div(v[0], v[1]) << endl;
				break;
			case 7:
				for (int i = 0; i < 2; ++i){
					cout << "valor " << (i + 1) << ": ";
					cin >> v[i];
				}
				cout << mod(v[0], v[1]) << endl;
				break;
			case 0:
				sair = true;
				break;
			default:
				cout << op << " opcao nao eh valida!" << endl;
				break;
		}
	}

	return 0;
}
