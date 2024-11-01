#include <iostream>
#include <string>
using namespace std;

class Cliente {
private:
    string nome;
    string cpf;

public:
    Cliente() { setNome(""); setCpf(""); }
    Cliente(string nome, string cpf) { setNome(nome); setCpf(cpf); }
    
    void setNome(string n) { nome = n; }
    string getNome() { return nome; }

    void setCpf(string c) { cpf = c; }
    string getCpf() { return cpf; }
};

class ContaBancaria {
private:
    int numero;
    double saldo;
    Cliente titular;

public:
    ContaBancaria() { setNumero(0); setSaldo(0); setTitular(Cliente("", "")); }
    ContaBancaria(int num, Cliente titu) { setNumero(num); setSaldo(0); setTitular(titu); }
    ContaBancaria(int num, Cliente titu, double sal) { setNumero(num); setSaldo(sal); setTitular(titu); }

    void setNumero(int num) { numero = num; }
    int getNumero() { return numero; }

    void setSaldo(double sal) { saldo = sal; }
    double getSaldo() { return saldo; }

    void setTitular(Cliente titu) { titular = titu; }
    Cliente getTitular() { return titular; }

    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            cout << "Deposito de R$ " << valor << " realizado na conta " << numero << endl;
        } else {
            cout << "Valor de deposito invalido!" << endl;
        }
    }

    void sacar(double valor) {
        if (valor > saldo) {
            cout << "Saldo insuficiente na conta " << numero << endl;
        } else if (valor > 0) {
            saldo -= valor;
            cout << "Saque de R$ " << valor << " realizado na conta " << numero << endl;
        } else {
            cout << "Valor de saque invalido!" << endl;
        }
    }

    void transferir(double valor, ContaBancaria &destino) {
        if (valor > saldo) {
            cout << "Saldo insuficiente para transferir R$ " << valor << " da conta " << numero << endl;
        } else if (valor > 0) {
            saldo -= valor;
            destino.depositar(valor);
            cout << "Transferido: R$ " << valor << " da conta " << numero << " para a conta " << destino.getNumero() << endl;
        } else {
            cout << "Valor de transferencia invalido!" << endl;
        }
    }

    void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
        double metadeValor = valor / 2;
        if (valor > saldo) {
            cout << "Saldo insuficiente para transferir R$ " << valor << " da conta " << numero << endl;
        } else if (valor > 0) {
            saldo -= valor;
            destino1.depositar(metadeValor);
            destino2.depositar(metadeValor);
            cout << "Transferido: R$ " << metadeValor << " para cada conta (" << destino1.getNumero() << " e " << destino2.getNumero() << ") da conta " << numero << endl;
        } else {
            cout << "Valor de transferencia invalido!" << endl;
        }
    }

    void exibirSaldo() {
        cout << "Saldo atual da conta: " << numero << " R$" << saldo << "\n" << endl;
    }

    void exibirInformacoes() {
        cout << "Titular: " << titular.getNome() << " CPF: " << titular.getCpf() 
             << "\nNumero da conta: " << numero << " Saldo: R$" << saldo << endl;
    }
};
