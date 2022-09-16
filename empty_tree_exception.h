#ifndef EMPTY_TREE_EXCEPTION_H
#define EMPTY_TREE_EXCEPTION_H
#include <stdexcept>
/**
 * @brief Classe Eccezione
 * 
 * La classe implementa un'eccezione a run time in
 * caso di operazioni su un albero vuoto
 * 
 */
class empty_tree_exception : public std::runtime_error {
	
	public:
		/**
		 * @brief Costruttore 
		 * 
		 * @param message stringa contenente il messaggio
		 */
		empty_tree_exception(const std::string &message);

};

#endif