#include "binary_search_tree.h"
#include <iostream>
#include <string>
#include <cassert>
#include <math.h>
/**
 * @brief Struttura che implementa un punto 
 * 
 */
struct point{
    int x;///< coordinata x
    int y;///< coordinta y

public:
    /**
     * @brief costruttore di default
     * 
     */
    point() : x(), y() {}
    /**
     * @brief Costruttore secondario
     * 
     * @param i coordinata x
     * @param j coordinata y
     */
    point(int i, int j) : x(i), y(j) {}
    
    /**
     * @brief Copy constructor
     * 
     * @param other oggetto point da cui copiare i dati
     */
    point(const point &other) : x(other.x), y(other.y) {}
    
    /**
     * @brief Distruttore
     * 
     */
    ~point() {}

    /**
     * @brief Operatore assegnamento
     * 
     * @param other oggetto point da cui copiare i dati
     * @return reference all'oggetto this
     */
    point &operator=(const point &other) {
        x = other.x;
        y = other.y;
        return *this;
    }
    /**
     * @brief Operatore==
     * 
     * @param other oggetto point 
     * @return true se i gue oggetti hanno le stesse coordinate
     * @return false se i gue oggetti non hanno le stesse coordinate
     */
    bool operator==(const point &other) const{
        return (x == other.x) && (y == other.y);
    }
    /**
     * @brief Operatore di strea,
     * 
     * @param os oggetto stream
     * @param p oggetto point
     * @return reference all'oggetto os
     */
    friend std::ostream& operator<<(std::ostream &os, const point &p){
        return os<<"("<<p.x<<", "<<p.y<<")";
    }
    /**
     * @brief getter della coordinata x
     * 
     * @return int x
     */
    int getX()const{
        return x;
    }
    /**
     * @brief getter della coordinata y
     * 
     * @return int y
     */
    int getY() const{
        return y;
    }

    /**
     * @brief Calcola la distanza tra il punto this e il punto
     * passato come parametro
     * 
     * @param p punto da cui calcolare la distanza
     * @return double valore della distanza tra i due punti
     */
    double distance_from(const point &p) const{
        return sqrt(pow(x-p.x, 2) + pow(y-p.y, 2));
    }
    

};




/**
 * @brief Funtore predicato di uguaglianza tra due point
 * 
 */
struct equals_point{
    bool operator()(const point &p1, const point &p2) const{
        return p1==p2;
    }
};
/**
 * @brief Funtore predicato di uguaglianza tra due interi
 * 
 */
struct equals_int{
    bool operator()(int a, int b) const{
        return a==b;
    }
};
/**
 * @brief Funtore predicato di uguaglianza tra due stringhe
 * 
 */
struct equals_string{
    bool operator()(const std::string &a, const std::string &b) const{
        return a == b;;
    }
};
/**
 * @brief Funtore predicato di uguaglianza tra due point
 * 
 */
struct compare_point{
    bool operator()(const point &p1, const point &p2) const{
        return p1.getX() < p2.getX() && p1.getY() < p2.getY();
    }
};
/**
 * @brief Funtore predicato di uguaglianza tra due interi
 * 
 */
struct compare_int{
    bool operator()(int a, int b) const{
        return a < b;
    }
};
/**
 * @brief Funtore predicato di uguaglianza tra due stringhe
 * 
 */
struct compare_string{
    bool operator()(const std::string &a, const std::string &b) const{
        return a < b;;
    }
};

/**
 * @brief Funtore predicato, valuta se un intero è pari 
 * 
 */
bool is_even(int x){
    return x%2 == 0;
}
/**
 * @brief Funtore predicato, valuta se un intero è dispari
 * 
 */
bool is_odd(int x){
    return !is_even(x);
}
/**
 * @brief Funtore predicato, valuta se una stringa ha una lunghezza pari a 4
 * 
 */
bool lenght_equal_4(const std::string &s){
    return s.size()==4;
}
/**
 * @brief Funtore predicato, valuta se un punto si trova nel quarto quadrante
 * 
 */
bool is_located_in_quadrant_4(const point &p){
    return p.x<0 && p.y<0;
}
bool string_starts_with_c(const std::string &s){
    return s.at(0) == 99;
}

/**
 * @brief Creazione di un albero binario di ricerca di interi
 * 
 * @return binary_search_tree<int, equals_int, compare_int> tree
 */
binary_search_tree<int, equals_int, compare_int> create_tree_int(){
    binary_search_tree<int, equals_int, compare_int> tree;
    tree.add(6);
    tree.add(4);
    tree.add(8);
    tree.add(2);
    tree.add(5);
    tree.add(1);
    tree.add(3);
    tree.add(7);
    tree.add(9);
    return tree;
}
/**
 * @brief Creazione di un albero binario di ricerca di point
 * 
 * @return binary_search_tree<point, equals_point, compare_point> tree
 */
binary_search_tree<point, equals_point, compare_point> create_tree_point(){
    binary_search_tree<point, equals_point, compare_point> tree_point;
    tree_point.add(point(1,1));
    tree_point.add(point(6,6));
    tree_point.add(point(2,2));
    tree_point.add(point(-3,-3));
    tree_point.add(point(-5,-5));
    tree_point.add(point(9,9));
    tree_point.add(point(10,11));
    tree_point.add(point(-4,-1));
    tree_point.add(point(0,0));
    return tree_point;
}
/**
 * @brief Creazione di un albero binario di ricerca di string
 * 
 * @return binary_search_tree<std::string, equals_string, compare_string> tree
 */
binary_search_tree<std::string, equals_string, compare_string> create_tree_string(){
    binary_search_tree<std::string, equals_string, compare_string> tree;
    tree.add("c++");
    tree.add("java");
    tree.add("php");
    tree.add("prolog");
    tree.add("c#");
    tree.add("go lang");
    tree.add("c");
    tree.add("lisp");
    tree.add("spring boot");
    tree.add("hibernate");
    tree.add("django");
    tree.add("scala");
    tree.add("spark sql");
    tree.add("sql");
    return tree;
}

/**
 * @brief Test binary search tree int printIF
 */
void test_printIF(){
    std::cout<<"***** TEST BINARY SEARCH TREE PRINTIF *****"<<std::endl;
    binary_search_tree<int, equals_int, compare_int> tree(create_tree_int());
    std::cout<<"Even values: ";
    printIF(tree, is_even);
    std::cout<<"Odd values: ";
    printIF(tree, is_odd);

    binary_search_tree<point, equals_point, compare_point> tree_point;
    tree_point = create_tree_point();
    std::cout<<"Points in the 4th quadrant: ";
    printIF(tree_point, is_located_in_quadrant_4);

    binary_search_tree<std::string, equals_string, compare_string> tree_s(create_tree_string());
    std::cout<<"Values that starts with 'c': ";
    printIF(tree_s, string_starts_with_c);

   
}
/**
 * @brief Test const binary search tree int
 * 
 */
void test_const_bst_int(const binary_search_tree<int, equals_int, compare_int> &tree){
    std::cout<<"***** TEST CONST INT BINARY SEARCH TREE *****"<<std::endl;
    
    std::cout<<"Const BST: ";
    std::cout<< tree <<std::endl;
    std::cout<<"Even values: ";
    printIF(tree, is_even);

    binary_search_tree<int, equals_int, compare_int> subtree = tree.subtree(4);
    binary_search_tree<int, equals_int, compare_int>::const_iterator b,e;
    b = subtree.begin();
    e = subtree.end();
    std::cout<<"Subtree [root = 4]: "<<std::endl;
    while(b != e){
        std::cout<< *b <<" ";
        b++;
    }
    std::cout<<std::endl;
    assert(tree.contains(4));
    assert(tree.contains(1));
    assert(tree.contains(6));
    assert(tree.contains(3));
    assert(!tree.empty());
    assert(tree.size() == 9);
    assert(tree.root() == 6);
    assert(!tree.contains(-1111111));
    
    
}
/**
 * @brief Test const binary search tree point
 * 
 * @param tree 
 */
void test_const_bst_point(const binary_search_tree<point, equals_point, compare_point> &tree){
    std::cout<<"***** TEST CONST POINT BINARY SEARCH TREE *****"<<std::endl;
    std::cout<<"Const BST: ";
    std::cout<< tree <<std::endl;
    std::cout<<"Even values: ";
    printIF(tree, is_located_in_quadrant_4);

    binary_search_tree<point, equals_point, compare_point> subtree = tree.subtree(point(6,6));
    binary_search_tree<point, equals_point, compare_point>::const_iterator b,e;
    b = subtree.begin();
    e = subtree.end();
    std::cout<<"Subtree [root = point(6,6)]: "<<std::endl;
    while(b != e){
        std::cout<< *b <<" ";
        b++;
    }
    std::cout<<std::endl;
    (tree.contains(point(-5,-5)));
    assert(!tree.empty());
    assert(tree.size() == 9); 
    assert(!tree.contains(point(100000,10000)));
 
}
/**
 * @brief Test dei 4 metodo fondamentali
 * 
 */
void test_metodi_fondamentali(){
    std::cout<<"***** TEST METODI FONDAMENTALI *****"<<std::endl;
    binary_search_tree<int, equals_int, compare_int> tree;
    assert(tree.size()==0);
    assert(tree.empty());
    try{
        int root=tree.root();
    }catch(const empty_tree_exception &e){
        std::cout<< e.what() <<std::endl;
    }
    tree = create_tree_int();
    binary_search_tree<int, equals_int, compare_int> tree2(tree);
    binary_search_tree<int, equals_int, compare_int> tree3, tree4;
    tree4 = tree3 = tree2;
    assert(tree.root() == tree2.root());
    assert(tree.size() == tree2.size());
    assert(tree3.size() == tree2.size() && tree4.size() == tree2.size());
    assert(tree3.root() == tree2.root() && tree.root() == tree2.root());
    assert(tree4.root() == 6);

    binary_search_tree<point, equals_point, compare_point> p;
    assert(p.empty());
    assert(p.size() == 0);
    try{
        tree.root();
    }catch(const empty_tree_exception &e){
        std::cout<< e.what() << std::endl;
    }
    p = create_tree_point();
    binary_search_tree<point, equals_point, compare_point> pt(p);
    assert(!p.empty());
    assert(pt.root() == p.root());


}
/**
 * @brief Test su binary search tree di int
 * 
 */
void test_binary_serch_tree_int(){
    std::cout<<"***** TEST BINARY SEARCH TREE INT *****"<<std::endl;
    binary_search_tree<int, equals_int, compare_int> t;
    binary_search_tree<int, equals_int, compare_int> sub_tree(t);
    binary_search_tree<int, equals_int, compare_int> leaf;
    assert(t.empty() && t.size()==0);
    for(unsigned int i=0; i < 100; ++i)
        t.add(i);
    assert(!t.empty() && t.size()==100);
    try{
        t.add(4);
    }catch(const existing_node_exception &e){
        std::cout<< e.what() << std::endl;
    }
    assert(t.root() == 0);
    for(unsigned int i=20; i < 60; ++i)
        t.contains(i);
    
    sub_tree = t.subtree(50);
    leaf = sub_tree.subtree(99);

    assert(sub_tree.size() == 50);
    assert(sub_tree.root() == 50);
    assert(!sub_tree.empty());
    assert(leaf.size() == 1);
    assert(leaf.root() == 99);
    leaf = leaf.subtree(1000);
    sub_tree.clear();
    t.clear();
    assert(leaf.size() == 0);
    assert(t.empty() && t.size()==0);
    assert(sub_tree.empty() &&  sub_tree.size()==0);
    try{
        leaf.root();
    }catch(const empty_tree_exception &e){
        std::cout<< e.what() <<std::endl;
    }
}
/**
 * @brief Test su binary search tree di string
 * 
 */
void test_binary_serch_tree_string(){
    std::cout<<"***** TEST BINARY SEARCH TREE STRING *****"<<std::endl;
    binary_search_tree<std::string, equals_string, compare_string> t;
    binary_search_tree<std::string, equals_string, compare_string> sub_tree(t);
    binary_search_tree<std::string, equals_string, compare_string> leaf;
    assert(t.empty() && t.size()==0);
    t = create_tree_string();
    assert(!t.empty() && t.size() == 14);
    std::cout<<"Tree root: "<<t.root() <<std::endl;
    std::cout<< t <<std::endl;
    try{
        t.add("c++");
    }catch(const existing_node_exception &e){
        std::cout<< e.what() << std::endl;
    }

    assert(t.root() == "c++");
    assert(t.contains("java"));
    assert(!t.contains("spring"));
    assert(t.contains("spring boot"));
    
    sub_tree = t.subtree("go lang");
    leaf = sub_tree.subtree("hibernate");  
    std::cout << "Subtree: "<< sub_tree<< std::endl;
    std::cout << "Leaf: "<< leaf<< std::endl;

    assert(sub_tree.size() == 3);
    assert(sub_tree.root() == "go lang");
    assert(!sub_tree.empty());
    assert(leaf.size() == 1);
    assert(leaf.root() == "hibernate");
    leaf = leaf.subtree("sql"); 
    sub_tree.clear();
    t.clear();
    assert(leaf.size() == 0);
    assert(t.empty() && t.size()==0);
    assert(sub_tree.empty() &&  sub_tree.size()==0);
    try{
        leaf.root();
    }catch(const empty_tree_exception &e){
        std::cout<< e.what() <<std::endl;
    }
}
/**
 * @brief Test su binary search tree di point
 * 
 */
void test_binary_serch_tree_point(){
    std::cout<<"***** TEST BINARY SEARCH TREE POINT *****"<<std::endl;
    binary_search_tree<point, equals_point, compare_point> t;
    binary_search_tree<point, equals_point, compare_point> sub_tree(t);
    binary_search_tree<point, equals_point, compare_point> leaf;
    assert(t.empty() && t.size()==0);
    for(unsigned int i=0; i < 100; ++i)
        t.add(point(i, i));
    assert(!t.empty() && t.size()==100);
    try{
        t.add(point(10,10));
    }catch(const existing_node_exception &e){
        std::cout<< e.what() << std::endl;
    }
    assert(t.root() == point(0,0));
    sub_tree = t.subtree(point(50,50));
    leaf = sub_tree.subtree(point(99,99));
    std::cout<<"Leaf: " <<leaf <<std::endl;
    assert(sub_tree.size() == 50);
    assert(sub_tree.root() == point(50,50));
    assert(!sub_tree.empty());
    assert(leaf.size() == 1);
    assert(leaf.root() == point(99,99));

    leaf = leaf.subtree(point(500,500));
    sub_tree.clear();
    t.clear();
    assert(leaf.size() == 0);
    assert(t.empty() && t.size()==0);
    assert(sub_tree.empty() &&  sub_tree.size()==0);
    try{
        leaf.root();
    }catch(const empty_tree_exception &e){
        std::cout<< e.what() <<std::endl;
    }
}
/**
 * @brief Test sugli iteratori
 * 
 */
void test_const_iterator(){
    std::cout<<"***** TEST BINARY SEARCH TREE CONST ITERATOR *****"<<std::endl;
    binary_search_tree<int, equals_int, compare_int> tree;
    binary_search_tree<int, equals_int, compare_int>::const_iterator a,b;
    tree = create_tree_int();
    assert(a == b);
    for(a = tree.begin(), b = tree.end(); a != b; ++a)
        std::cout<< *a <<" ";

    std::cout<<std::endl;
    a = tree.begin();
    binary_search_tree<int, equals_int, compare_int>::const_iterator c(a);
    assert(a == c);
    assert(*a == *c);
    a++;
    c++;
    assert(a == c);
    assert(*a == *c);
    ++a;
    c++;
    assert(a == c);
    assert(*a == *c);
    (++a)++;
    assert(*a == 5);
    assert(*c == 3);
    assert(a != c);
    assert(*a != *c);
    const int* const p = &(*a);
    assert(*p == 5);
    b = a;
    assert(b == a);
    assert(*b == *a);
    assert(*b == 5);
    ((++b)++);
    assert(*b == 7);
    
    binary_search_tree<point, equals_point, compare_point> t = create_tree_point();
    binary_search_tree<point, equals_point, compare_point>::const_iterator begin,e;
    begin = t.begin();
    e = t.end();
    for(;begin != e; ++begin)
        std::cout<< *begin <<" ";
    std::cout<<std::endl;

    begin = e = t.begin();
    assert(*begin == point(-5, -5));
    assert(begin == e);
    begin++;
    assert(*begin == point(-3, -3));
    assert(begin != e);
    (++e)++;
    ++begin;
    assert(*begin == *e);
    assert(begin == e);
    std::cout<< *begin << " " << *e <<std::endl;
    assert(begin->getX() == -4 && begin->getY() == -1);
    e++;
    assert(((int)begin->distance_from(*(e++)))== 4);
}




int main(){
    binary_search_tree<int, equals_int, compare_int> tree;
    binary_search_tree<point, equals_point, compare_point> tree_point;
    tree = create_tree_int();
    tree_point = create_tree_point();
    
    test_metodi_fondamentali();
    test_binary_serch_tree_int();
    test_binary_serch_tree_string();
    test_binary_serch_tree_point();
    test_const_bst_int(tree);
    test_const_bst_point(tree_point);
    test_printIF();
    test_const_iterator();

    return 0;
}