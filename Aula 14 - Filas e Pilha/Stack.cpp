

        void insercao(int dado) 
        {
            Node* novoNo = new Node;
            novoNo->dado = dado;
            novoNo->proximo = NULL;
            if(tras != NULL) {
                tras->proximo = novoNo;
            }
            tras = novoNo;
            if(frente == NULL) {
                frente = tras;
            }
            tamanho++;
        }

        void remocao()
         {
            if(frente != NULL) 
            {
                Node* temp = frente;
                frente = frente->proximo;
                delete temp;
                tamanho--;
                if (frente == NULL) 
                {
                    tras = NULL;
                }
            } else 
            {
                cout << "FILA vazia" << endl;
            }
        }

        int frenteFila() 
        {
            if(frente != NULL) 
            {
                return frente->dado;
            } else 
            {
                cout << "Fila vazia" << endl;
                return -1;
            }
        }

        int trasFila() 
        {
            if(tras != NULL) 
            {
                return tras->dado;
            } else 
            {
                cout << "Fila vazia" << endl;
                return -1;
            }
        }

        int tamanhoFila()
         {
            return tamanho;
        }
