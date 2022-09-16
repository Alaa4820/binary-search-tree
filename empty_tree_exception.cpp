#include "empty_tree_exception.h"

empty_tree_exception::empty_tree_exception(const std::string &message) 
    : std::runtime_error(message) {}




