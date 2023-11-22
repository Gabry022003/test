class Nodo:
    def __init__(self, dato):
        self.dato = dato
        self.successivo = None

class ListaConcatenata:
    def __init__(self):
        self.testa = None

    def aggiungi_elemento(self, dato):
        nuovo_nodo = Nodo(dato)
        nuovo_nodo.successivo = self.testa
        self.testa = nuovo_nodo

    def stampa_lista(self):
        corrente = self.testa
        while corrente:
            print(corrente.dato, end=' ')
            corrente = corrente.successivo
        print()

# Esempio di utilizzo della lista concatenata
lista = ListaConcatenata()
lista.aggiungi_elemento(1)
lista.aggiungi_elemento(2)
lista.aggiungi_elemento(3)

print("Lista concatenata:")
lista.stampa_lista()
