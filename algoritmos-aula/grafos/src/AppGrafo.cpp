
 #include "../include/AppGrafo.hpp"

 #include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

AppGrafo::AppGrafo() {
    this->grafo = new Grafo();
}

AppGrafo::~AppGrafo() {
    delete this->grafo;
}
   
void AppGrafo::carregarGrafoDoArquivo(string diretorioArquivo) { 

    string origem, destino; 
	 int peso;

    ifstream arquivo;
    //tratar exception de abertura de arquivo 
    arquivo.open(diretorioArquivo);
        
    if(arquivo.is_open()){
         while (!arquivo.eof()) {         
           arquivo >> origem >> peso >> destino;
           cout << origem << " - " << peso << " - " << destino << endl;
        
           this->grafo->adicionarVertice(origem);
           this->grafo->adicionarVertice(destino);
           
           Vertice *verticeOrigem = this->grafo->getVertice(origem);
           Vertice *verticeDestino = this->grafo->getVertice(destino);
           Aresta *aresta = new Aresta();
           aresta->SetPeso(peso);
           aresta->setVertice(verticeDestino);
           verticeOrigem->adicionarAresta(aresta);

         }  
        arquivo.close();
    }
    else{
        cout << "Não foi possível acessar o arquivo do grafo." << endl;
        exit(0);
    }
}

void AppGrafo::mostrarMenu() { 
   
   int operacao = 1;
   while (operacao < 10 && operacao > 0) {
      cout << "                                       " << endl;
      cout << "---------------------------------------" << endl;   
      cout << "          TEORIA DOS GRAFOS                       " << endl;       
      cout << "---------------------------------------" << endl;
      cout << "01 - Carregar Grafo de Arquivo" << endl;
      cout << "02 - Adicionar Vertice" << endl;
      cout << "03 - Excluir Vertice" << endl;
      cout << "04 - Imprimir Vertice" << endl;
      cout << "05 - Adicionar Aresta " << endl;
      cout << "06 - Excluir Aresta" << endl;
      cout << "07 - Imprimir Aresta" << endl;
      cout << "08 - Dijkstra" << endl;
      cout << "10 - Sair" << endl;
  
      cout << "Escolha uma opção: ";
      cin >> operacao;  
    
      string nome;
      
     Vertice *verticeOrigem = NULL;
     Vertice *verticeDestino = NULL;

     switch (operacao) { 
     case 1:
            cout << "01 - Carregar Grafo de Arquivo" << endl;
            cout << "Nome do arquivo: ";
            cin >> nome;
            this->carregarGrafoDoArquivo(nome);
         break;
      case 2:
            cout << "02 - Nome do Vertice: " << endl;
            cout << "Nome do Vertice: ";
            cin >> nome;
            this->grafo->adicionarVertice(nome);
         break;
      case 3:
         cout << "03 - Nome do Vertice: " << endl;
         cout << "Nome do Vertice: ";
         cin >> nome;
         grafo->excluirVertice(nome);
         break;
      case 4:
         cout << "04 - Imprimir Vertice" << endl;
         grafo->imprimirVertices();
         break;
      case 5:
         cout << "05 - Adicionar Aresta" << endl;
         cout << "Não implementado" << endl;
         break;
      case 6:
         cout << "06 - Excluir Aresta" << endl;
         cout << "Não implementado" << endl;
         break;
      case 7: 
         cout << "07 - Imprimir Arestas" << endl;
         cout << "Não implementado" << endl;
         break; 
      case 8:
         cout << "Dijkstra - Escolha um vertice origem: ";
         cin >> nome;
         verticeOrigem = grafo->getVertice(nome);
         cout << "Dijkstra - Escolha um vertice destino: ";
         cin >> nome;
         verticeDestino = grafo->getVertice(nome);
         grafo->dijkstra(verticeOrigem, verticeDestino);
         break;
      case 10:
         cout << "10 - Exit" << endl;
         break;
            
      }  
   }       
} 