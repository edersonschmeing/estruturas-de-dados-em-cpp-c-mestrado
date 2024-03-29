#include<iostream>
#include "../include/Vertice.hpp"

Vertice::Vertice() {
    id = 0;
    this->cor = BRANCA;
    this->distancia = -1;
    this->nome = "";
    this->antecessor = NULL;
    this->arestas = new Lista<Aresta*>();   
}

Vertice::~Vertice() {
  delete this->arestas;
}

int Vertice::getId() {
   return this->id;
}

void Vertice::setId(int cor) {
   this->id = cor;
};

int Vertice::getCor() {
   return this->cor;
}

void Vertice::setCor(int cor) {
   this->cor = cor;
}

int Vertice::getDistancia() {
   return this->distancia;
}

void Vertice::setDistancia(int distancia) {
   this->distancia = distancia;
}

string Vertice::getNome() {
   return this->nome;
}

void Vertice::setNome(string nome) {
   this->nome = nome;
}

void Vertice::setAntecessor(Vertice *antecessor) {
    this->antecessor = antecessor;
}

Vertice* Vertice::getAntecessor() {
    return this->antecessor;
}


Lista<Aresta*>* Vertice::getArestas() {
   return this->arestas;
}

bool Vertice::adicionarAresta(Aresta* aresta) {
    return this->arestas->adicionarNaCauda(aresta);    
}

//verificar se precisa
void Vertice::imprimirArestas() {
   for (int i = 0; i < this->arestas->getTamanho(); i++) {
        Aresta *aresta = this->arestas->getElemento(i); 
        cout << " O "  << this->getNome()  << " -> ";
        cout << " D " << aresta->getVertice()->getNome()  << " -> ";
   }
   cout << endl;
}

/*void Vertice::imprimirArestas() {
   cout << " ARESTAS -> ";
   No<Vertice*>* tmp = this->arestas->getCabeca();
   while(tmp != NULL) {
        Aresta* v  = (Aresta*)tmp->elemento; 
        cout << v->nome  << " -> ";
        tmp = tmp->proximo;
   }  
   cout << endl;  
}*/