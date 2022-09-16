#ifndef EXISTING_NODE_EXCEPTION_H
#define EXISTING_NODE_EXCEPTION_H
#include <stdexcept>
/**
 * @brief Classe Eccezione
 * 
 * La classe implementa un'eccezione a run time in
 * caso di aggiunta di un nodo esistente
 * 
 */
class existing_node_exception : public std::runtime_error {
	
	public:
		/**
		 * @brief Costruttore 
		 * 
		 * @param message stringa contenente il messaggio
		 */
		existing_node_exception(const std::string &message);

};

#endif