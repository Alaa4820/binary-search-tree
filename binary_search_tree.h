#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <algorithm>
#include <iostream>
#include <ostream>
#include <cassert>
#include <iterator> // std::forward_iterator_tag
#include <cstddef>  // std::ptrdiff_t
#include "existing_node_exception.h"
#include "empty_tree_exception.h"
/**
 * @brief Classe binary_search_tree
 * 
 * La classe implementa un generico albero binario di ricerca in cui ogni elemento
 * compare una e una sola volta
 * 
 * @tparam T Tipo degli elementi contenuti della'albero 
 * @tparam Eql funtore di eguaglianza
 * @tparam Comp funtore di comparazione
 */
template<typename T, typename Eql, typename Comp> class binary_search_tree{
    /**
     * @brief Struttura nodo
     */
    struct node{
        T value;///< valore memorizzato
        node* parent;///< puntatore al nodo padre
        node* left;///< puntatore al nodo sinistro
        node* right;///< puntatore al nodo destro

        /**
         * @brief Costruttore di default
         * 
         * @post parent == nullptr
         * @post left == nullptr
         * @post right == nullptr
         * 
         */
        node(): parent(nullptr), left(nullptr), right(nullptr){}

        /**
         * @brief Costruttore secondario
         * 
         * @param val valore da memorizzare
         */
        explicit node(const T &val): value(val), parent(nullptr), left(nullptr), right(nullptr){}
        
        /**
         * @brief Costruttore secondario
         * 
         * @param v valore da memorizzare
         * @param p puntatore al nodo padre
         * @param l puntatore al nodo sinistro
         * @param r puntatore al nodo destro
         */
        node(const T &v, node *p, node *l = nullptr, node *r = nullptr): value(v), parent(p), left(l), right(r) {}

        /**
         * Copy constructor
         * @brief Costruisce un nodo a partire da un altro nodo copiando i dati membro a membro
         * 
         * @param other oggetto nodo da copiare
         */
        node(const node &other){
            if (this != &other){
                value = other.value;
                parent = other.parent;
                left = other.left;
                right = other.left;
            }
        }

        /**
         * Operatore assegnamento
         * @brief Assegna ad un oggetto nodo un altro nodo copiando i dati membro a membro
         * 
         * @param other nodo da copiare
         * @return reference del nodo this
         */
        node& operator=(const node &other){
            value = other.value;
            parent = other.parent;
            left = other.left;
            right = other.left;
            return *this;
        }

        /**
         * Distruttore
         * 
         * @post parent == nullptr
         * @post left == nullptr
         * @post right == nullptr
         */
        ~node(){
            parent = nullptr;
            left = nullptr;
            right = nullptr;
        } 

        /**
         * Funzione che implementa l'operatore di stream
         * 
         * @param os stream di output
         * @param n nodo da spedire sullo stream
         * @return reference dello stream di output
         */
        friend std::ostream& operator<<(std::ostream &os, const node &n){
            return os<<n.value;
        }
    
    };
   
    node* _root;///< puntatore al radice dell'albero
    unsigned int _size;///< numero di elementi salvati
    Eql _equals;///< funtore di uguaglianza tra due valori di tipo T
    Comp _compare;///< funtore di comparazione tra due valori di tipo T

    
    /**
     * @brief Funzione che copia un albero a partire da un nodo passato in input
     * 
     * @param root radice dell'albero 
     * @param parent nodo padre del nodo root
     * @return node* puntatore al nuovo albero copiato
     */
    node* copy(const node* const root, node *const parent = nullptr) const{
        if(root == nullptr)
            return nullptr;
        
        node* clone = new node(root->value);
        clone->parent = parent;
        clone->left = copy(root->left, clone);
        clone->right = copy(root->right, clone);
        return clone;
    }

    /**
     * @brief Funzione che calcola il numero dei nodi di un albero binario di ricerca
     * a partire dal nodo radice
     * 
     * @param root radice dell'albero binario di ricerca
     * @return unsigned int numero dei nodi
     */
    unsigned int count_node(const node* const root) const{
        if(root == nullptr)
            return 0;
        return count_node(root->left) + count_node(root->right) + 1;
    }

    /**
     * @brief Funzione che rimuove i nodi di un albero binario di ricerca a partire
     * dalla radice
     * 
     * @param node nodo radice
     */
    void erase(const node* node){ 
        if(node == nullptr)
            return;

        erase(node->left);
        erase(node->right);
        delete node;
        _size--;
        node = nullptr;
    }

    /**
     * @brief Funzione che verifica se un valore è contenuto nell'abero binario di ricerca
     * passanto come paramentro
     * 
     * @param root radice dell'albero binario di ricerca
     * @param value valore da cercare
     * @return true se il valore è presente
     * @return false se il valore non è presente
     */
    bool contains_value(const node* const root, const T &value) const{
        if(root == nullptr)
            return false;

        if(_equals(root->value, value))
            return true;
        else{
            if(_compare(value, root->value))
                return contains_value(root->left, value);
            else
                return contains_value(root->right, value);
        }
    }

    /**
     * @brief Funzione che, a partire dall'albero binario di ricerca passato,
     * ritorna il puntatore al nodo in cui è memorizzato il valore 
     * 
     * @param root radice dell'albero binario di ricerca
     * @param value valore da cerca
     * @return const node* const puntatore al nodo in cui value è memorizzato
     */
    const node* const get_node(const node* const root, const T &value) const{
        if(root == nullptr)
            return root;
        if(_equals(value, root->value))
            return root;
        else{
            if(_compare(value, root->value))
                return get_node(root->left, value);
            else
                return get_node(root->right, value);
        }
        
    }

    /**
     * @brief Funzione che ritorna il puntatore al nodo che contiene il valore
     * più piccolo presente nell'albero binario di ricerca passato come paramento
     * 
     * @param root radice dell'albero binario di ricerca
     * @return const node* const puntatore al nodo in cui è presente il valore più piccolo
     */
    const node* const min_value_node(const node* const root) const{
        if(root == nullptr)
            return root;
        if(root->left == nullptr)
            return root;
        return min_value_node(root->left);   
    }

    
    /**
     * @brief Funzione che inserisce nell'albero binario di ricerca
     * il valore passato come parametro e ritorna un nuovo albero binario
     * di ricerca con il nuovo nodo agginto
     * 
     * @param root radice dell'albero binario di ricerca
     * @param value valore da inserire
     * @param parent puntatore al nodo padre del nuovo nodo
     * @return node* puntatore alla radice del nuovo albero binario di ricerca
     */
    node* const insert(node* root, const T &value, node* const parent = nullptr){
        node* tree_node = nullptr;
        if(root == nullptr){
            root = new node(value, parent);
            _size++;
            return root;
        }

        if(_compare(value, root->value))
            root->left = insert(root->left, value, root);
        else
            root->right = insert(root->right, value, root);

        return root;
    }

  
    public:

        /**
         * @brief Costruttore di dafault
         * 
         * @post _root == nullptr
         * @post _size == 0
         * 
         */
        binary_search_tree(): _root(nullptr), _size(0){}

        /**
         * @brief Copy constructor
         * 
         * @param other albero binario di ricerca da copiare
         * 
         * @post _root->value == other._root->value
         * @post _size == other._size 
         * 
         * @throw std::bad_alloc eccezione durante l'allocazione di un nodo
         */
        binary_search_tree(const binary_search_tree &other): _root(nullptr), _size(0){   
            try{
                _root = copy(other._root);
                _size = other._size;
            }catch(...){
                clear();
                throw;
            }
        }

        /**
         * @brief Operatore assegnamento
         * 
         * @param other albero binario di ricerca da copiare
         * @return binary_search_tree& riferimento all'albero this
         * 
         * @post _root == other._root
         * @post _size == other._size
         */
        binary_search_tree& operator=(const binary_search_tree &other){
            if (this != &other){
                binary_search_tree tmp(other);
                std::swap(_root, tmp._root);
                std::swap(_size, tmp._size);
            }
            return *this;
        }

        /**
         * @brief Distruttore
         * 
         */
        ~binary_search_tree(){
            clear();
        }

        /**
         * @brief Funzione che elimina tutti i valori presenti nell'albero binario di
         * ricerca
         * 
         */
        void clear(){
            erase(_root);
            _root = nullptr;
        }

        /**
         * @brief Funzione che ritorna il valore contenuto nella radice
         * dell'albero binario di ricerca
         * 
         * @return const T& valore memorizzato nella radice
         * 
         * @throw empty_tree_exception eccezione lanciata quando si chiama la funzione su un albero vuoto
         */
        const T& root() const{
            if(_root == nullptr)
                throw empty_tree_exception("Cannot get the root value of an empty binary search tree");
            
            return _root->value; 
        }

        /**
         * @brief Funzione che ritorna il numero dei valori memorizzati nell'albero
         * binario di ricerca
         * 
         * @return unsigned int numero degli elementi memorizzati
         */
        unsigned int size() const{
            return _size;
        }

        /**
         * @brief Funzione che verifica se l'albero binario di ricerca è vuoto
         * 
         * @return true se l'albero è vuoto
         * @return false se l'albero non è vuoto
         */
        bool empty() const{
            return _root == nullptr;
        }

        /**
         * @brief Funzione che aggiunge un nuovo valore nell'albero
         * 
         * @param value valore da aggiungere
         * 
         * @throw existing_node_exception eccezione lanciata se il valore da aggiungere già esiste
         * @throw std::bad_alloc eccezione durante l'allocazione di un nodo
         */
        void add(const T &value){
            if(contains(value))
                throw existing_node_exception("Cannot insert an existing node in the binary tree");
            
            _root = insert(_root, value); //esegue una new -> non serve try catch 
        }

        /**
         * @brief Funzione che verifica se un valore è presente nell'albero binario 
         * di ricerca
         * 
         * @param value valore da cercare 
         * @return true se il valore è presente nell'albero
         * @return false se il valore non è presente nell'albero
         * 
         * @throw empty_tree_exception eccezione lanciata in caso di albero vuoto
         */
        bool contains(const T &value) const{
            return contains_value(_root, value);
        }

    
        /**
         * @brief Funzione che ritorna il sotto-albero con radice il nodo contenente il valore
         * passato in input
         * 
         * @param d valore che sarà contenuto nella radice del nuovo albero binario di ricerca
         * @return binary_search_tree nuovo albero binario di ricerca
         * 
         * @throw std::bad_alloc eccezione lanciata durante l'allocazione di un nodo
         */
        binary_search_tree subtree(const T &d) const{
            binary_search_tree subtree;
            if(_root == nullptr)
                return subtree;

            try{
                subtree._root = copy(get_node(_root, d));
                subtree._size = count_node(subtree._root);
            }catch(...){
                subtree.clear();
                throw;
            }
            return subtree;
        }


        /**
         * @brief Operatore di stream
         * 
         * @param os stream di output
         * @param bst albero binario di ricerca da spedire sullo stream
         * @return std::ostream& reference dello stream di output
         */
        friend std::ostream& operator<<(std::ostream &os, const binary_search_tree &bst){
            binary_search_tree::const_iterator b, e;
            b = bst.begin();
            e = bst.end();
            while(b != e){
                os << *b <<" ";
                ++b;
            }
            return os;
        }

	
        /**
         * Classe const_iterator
         * Gli iteratori iterano sui dati contenuti nel albero binario di ricerca
         * @brief Classe const_iterator
         */
        class const_iterator {

            public:
                typedef std::forward_iterator_tag iterator_category;
                typedef T                         value_type;
                typedef ptrdiff_t                 difference_type;
                typedef const T*                  pointer;
                typedef const T&                  reference;

                /**
                 * @brief Costruttore di default
                 * 
                 */
                const_iterator() : _ptr(nullptr) {}
                
                /**
                 * @brief Copy constructor
                 * 
                 * @param other iteratore da cui copiare i dati
                 */
                const_iterator(const const_iterator &other) : _ptr(other._ptr){}

                /**
                 * @brief Operatore assegnamento
                 * 
                 * @param other iteratore da cui copiare i dati
                 * @return reference all'iteratore this 
                 */
                const_iterator& operator=(const const_iterator &other) {
                    _ptr=other._ptr;
                    return *this;
                }

                /**
                 * @brief Distruttore
                 * 
                 */
                ~const_iterator() {}

                /**
                * @brief Operatore*
                * 
                * @return reference al dato riferito dall'iteratore (dereferenziamento) 
                */
                reference operator*() const {
                    return _ptr->value;
                }

            /**
                 * @brief Operatore-> 
                 * 
                 * @return puntatore al dato riferito dall'iteratore 
                 */
                pointer operator->() const {
                    return &(_ptr->value);
                }
                
                /**
                * @brief Operatore++ di post-incremento
                * @return copia dell'iteratore che punta al valore precedente
                */
                const_iterator operator++(int) {
                    const_iterator tmp(*this);
                    _ptr = next(_ptr);
                    return tmp;
                }

                /**
                * @brief Operatore++ pre-incremento
                * @return reference all'teratore this
                */
                const_iterator& operator++() {
                    _ptr = next(_ptr);
                    return *this;
                }

                /**
                 * @brief Operatore==
                 * 
                 * @param other iteratore con cui fare il confronto
                 * @return true se l'iteratore this e other puntano allo stesso dato
                 * @return false se l'iteratore this e other non puntano allo stesso dato
                 */
                bool operator==(const const_iterator &other) const {
                    return _ptr==other._ptr;
                }
                
                /**
                 * @brief Operatore!=
                 * 
                 * @param other iteratore con cui fare il confronto
                 * @return true se l'iteratore this e other non puntano allo stesso dato
                 * @return false se l'iteratore this e other puntano allo stesso dato
                 */
                bool operator!=(const const_iterator &other) const {
                    return !(*this == other); 
                }

        

            private:
                friend class binary_search_tree;///< friend della classe binary_search_tree
                const binary_search_tree* _tree;///puntatore all'albero binario di ricerca corrente (this)
                const node* _ptr;///< nodo a cui l'iteratore fa riferimento

                /**
                 * @brief Costruttore privato
                 * 
                 * @param n puntatore al nodo con cui inizializzare il dato membro
                 * @param t puntatore all'albero binario di ricerca corrente
                 * 
                 * @post _ptr == n
                 * @post _tree == t
                 */
                const_iterator(const node *n, const binary_search_tree* t): _ptr(n), _tree(t) {}

                /**
                 * @brief Funzione che sposta il puntatore passato in input al nodo
                 * successivo
                 * 
                 * @param ptr puntatore al nodo
                 * @return const node* const puntatore nodo successivo
                 */
                const node* const next(const node* ptr){
                    if(ptr == nullptr)
                        return ptr;
                    if(ptr->right != nullptr){
                        return _tree->min_value_node(ptr->right); // successore di ptr è il minimo del sotto albero destro
                    }else{
                        while (ptr->parent != nullptr && ptr == ptr->parent->right){//risale l'albero
                                ptr = ptr->parent;
                        }
                        return ptr->parent;
                    }
                } 
            
            
        }; // classe const_iterator
        
        /**
         * @brief Iteratore di inzio
         * 
         * @return const_iterator
         */
        const_iterator begin() const {
            return const_iterator(min_value_node(_root), this);
        }
        
        /**
         * @brief Iteratore fine
         * 
         * @return const_iterator
         */
        const_iterator end() const {
            return const_iterator(nullptr, this);
        }
	
};

/**
 * @brief Funzione che stampa i valori presenti in un albero binario di ricerca
 * che rispettano il predicato in input
 * 
 * @tparam T tipo dei valori nell'albero
 * @tparam Eql funtore di uguaglianza
 * @tparam Comp funtore di comparazione
 * @tparam P tipo del predicato
 * @param bst oggetto albero binario di ricerca
 * @param pred funtore predicato
 */
template<typename T, typename Eql, typename Comp, typename P>
void printIF(const binary_search_tree<T, Eql, Comp> &bst, P pred){
    typename binary_search_tree<T, Eql, Comp>::const_iterator b,e;
    b = bst.begin();
    e = bst.end();
    while(b != e){
        if(pred(*b))
            std::cout<< *b <<" ";
        ++b;
    }
    std::cout<<std::endl;
}

#endif