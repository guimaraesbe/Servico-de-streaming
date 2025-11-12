#include "Midia.hpp"

Midia::Midia(const std::string titulo, int duracao_s) : _titulo(titulo), _duracao_s(duracao_s){}

std::string Midia::tipo() const {
    return "Midia";
}

void Midia::print_info() const {
    std::cout << "Titulo: " <<  this->_titulo << std::endl;
    std::cout << "Duracao: " << this->_duracao_s << "s" << std::endl;
}

std::string Midia::get_titulo() const { 
    return _titulo; 
}

std::ostream& operator<<(std::ostream& os, const Midia& m) {
    m.print_info(); 
    return os;      
}