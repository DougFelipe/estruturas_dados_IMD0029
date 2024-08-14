/* Implementação de uma lista simplesmente encadeada e seus métodos */
/* Douglas Felipe de Lima Silva (20220054131)*/

//Cabeçalho (INCLUIR AS BIBLIOTECAS)
#include <iostream> //incluir já por padrão

//Iniciando struct, classe e métodos necessários para a lista

//Implementação do do Struct
struct Node 
{
    int nod;
    Node* proximo;
};

//Implementação da classe da lista simplesmente encadeada
class LinkedList 
{
private:
    Node* head;
    int size;

public:
    LinkedList()
    {
        head = nullptr;
        size = 0;
    }

//Implementação dos métodos da classe
//método push_front

    void push_front(int valor) 
    {
        Node* newNode = new Node;
        newNode->nod = valor;
        newNode->proximo = head;
        head = newNode;
        size++;
    }

//método push_back
    void push_back(int valor) 
    {
        Node* newNode = new Node;
        newNode->nod = valor;
        newNode->proximo = nullptr;
//condição para verificar se a lista está vazia
        if (head == nullptr) 
        {
            head = newNode;
        } 
        else 
        {
            Node* atual = head;
            while (atual->proximo != nullptr) 
            {
                atual = atual->proximo;
            }
            atual->proximo = newNode;
        }

        size++;
    }

//método pop_front
    void pop_front() 
    {
        //veririicar se a lista está vazia
        if (head == nullptr) 
        {
            std::cout << "lista vazia" << std::endl;
            return;
        }

        Node* temp = head;
        head = head->proximo;
        delete temp;
        size--;
    }

//método pop_back
    void pop_back() 
    {
        if (head == nullptr) 
        {
            std::cout << "lista vazia" << std::endl;
            return;
        }
        //verificar se a lista tem apenas um elemento
        if (head->proximo == nullptr)
        {
            delete head;
            head = nullptr;
        } 
        //continuação do método para listas com mais de um elemento
        else 
        {
            Node* atual = head;
            while (atual->proximo->proximo != nullptr) 
            {
                atual = atual->proximo;
            }
            delete atual->proximo;
            atual->proximo = nullptr;
        }
        //diminuir o tamanho da lista em 1 após a remoção
        size--;
    }

//método print
    void print() 
    {
        if (head == nullptr) 
        {
            std::cout << "lista vazia" << std::endl;
            return;
        }

        Node* atual = head;
        //loop para percorrer a lista e imprimir os elementos
        while (atual != nullptr) 
        {
            std::cout << atual->nod << " ";
            atual = atual->proximo;
        }
        std::cout << std::endl;
    }

//método remove
    void remove(int elemento)
     {
        if (head == nullptr) 
        {
            std::cout << "lista vazia" << std::endl;
            return;
        }
        //verifica se o elemento a ser removido é o primeiro da lista
        if (head->nod == elemento) 
        {
            Node* temp = head;
            head = head->proximo;
            delete temp;
            size--;
            return;
        }

        Node* atual = head;
        //loop para percorrer a lista e encontrar o elemento a ser removido
        while (atual->proximo != nullptr && atual->proximo->nod != elemento) 
        {
            atual = atual->proximo;
        }

        if (atual->proximo != nullptr) 
        {
            Node* temp = atual->proximo;
            atual->proximo = atual->proximo->proximo;
            delete temp;
            size--;
        } 
        //condição caso o elemento não seja encontrado na lista
        else 
        {
            std::cout << "Elemento não encontrado" << std::endl;
        }
    }


//método sizeOf
    int sizeOf() {
        return size;
    }

//método find
    bool find(int valor) 
    {
        Node* atual = head;
        //loop para percorrer a lista e encontrar o elemento
        while (atual != nullptr) 
        {
            if (atual->nod == valor) 
            {
                return true;
            }
            atual = atual->proximo;
        }
        return false;
    }

//Utilizando "delete" deu algum erro de sintaxe
    void deletar() 
    {
        Node* atual = head;
        while (atual != nullptr) 
        {
            Node* temp = atual;
            atual = atual->proximo;
            delete temp;
        }
        head = nullptr;
        size = 0;
    }
};


//implementação do main com alguns testes
int main() 
{
    //criação da lista
    LinkedList lista;


//aplicação e teste dos métodos
    lista.push_front(7);
    lista.push_front(6);
    lista.push_front(4);
    lista.push_back(14);
    lista.push_back(8);
    lista.push_back(10);
    lista.push_back(0);
    lista.push_front(3);

    lista.print();  

    lista.pop_front();
    lista.pop_back();

    lista.print();  // 

    lista.remove(3);
    lista.remove(8);  

    lista.print();  

    std::cout << "Tamanho da lista: " << lista.sizeOf() << std::endl;  

    std::cout << "A lista possui 4 ? " << (lista.find(4) ? "Sim" : "Não") << std::endl;  
    std::cout << "A lista possui 25 ? " << (lista.find(25) ? "Sim" : "Não") << std::endl;  

    lista.deletar();

    lista.print();  

    return 0;
}
