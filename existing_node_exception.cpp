#include "existing_node_exception.h"

existing_node_exception::existing_node_exception(const std::string &message) 
    : std::runtime_error(message) {}




