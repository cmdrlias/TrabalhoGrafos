#ifndef GRAFO_H
#define GRAFO_H

class Grafo {
    private:
        int Vertices;
        int Direcionado;
        char PesoVert;
        int **Matriz;
        int *cont;
    public:
        Grafo();
        ~Grafo();
       void Menu();
       void Grafinhos();
       void Regular();
       void Completo();
       void Grau();
       /* ------------ GETTERS E SETTERS -------------- */
       int GetVertices();
       void SetVertices(int vertices);
       int GetDirecionado();
       void SetDirecionado(int direcionado);
       char GetPesoVert();
       void SetPesoVert(char pesovert);
       int **GetMatriz();
       void SetMatriz(int **matriz);
       int *GetCont();
       void SetCont(int *Cont);
};

#endif // GRAFO_H
