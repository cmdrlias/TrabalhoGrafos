#ifndef GRAFO_H
#define GRAFO_H

class Grafo
{
public:
    Grafo();
    ~Grafo();

   int GetVertices();
   void SetVertices(int  m_vertices);
   char GetDirecionado();
   void SetDirecionado(char  m_direcionado);
   char GetPesoVert();
   void SetPesoVert(char  m_pesovert);
   void Menu();
   void Grafinhos(int **matriz, int escolha);
   void Regular(int escolha, int cont[]);
   void Completo(int escolha, int cont[]);
   void Grau(int **matriz, int escolha, int *conta);

private:
    int Vertices;
    char Direcionado;
    char PesoVert;
};

#endif // GRAFO_H
