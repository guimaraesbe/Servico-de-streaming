#include "Musica.hpp"

Musica::Musica(std::string titulo, int duracao_s, std::string artista, std::string genero) 
: Midia(titulo, duracao_s), _artista(artista), _genero(genero) {}

void Musica::print_info() const {
    std::cout << "Info: Midia" << std::endl;
    std::cout << "Titulo: " << _titulo << std::endl;
    std::cout << "Duracao (s): " << _duracao_s << std::endl;
    std::cout << "Tipo: Musica" << std::endl;
    std::cout << "Artista: " << _artista << std::endl;
    std::cout << "Genero: " << _genero << std::endl;
}

void Musica::play() const {
    for (int i = 1; i <= _duracao_s; ++i) {
        std::cout << "Playing " << _titulo << " [" << i << "/" << _duracao_s << "]" << std::endl;
    }
}

std::string Musica::tipo() const{
    return "Musica";
}

