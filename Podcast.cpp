#include "Podcast.hpp"

 Podcast::Podcast(std::string titulo, int duracao_s, std::string host, int episodio) 
 : Midia(titulo, duracao_s), _host(host), _episodio(episodio) {} 

 void Podcast::print_info() const {
    std::cout << "Info: Midia" << std::endl;
    std::cout << "Titulo: " << _titulo << std::endl;
    std::cout << "Duracao (s): " << _duracao_s << std::endl;
    std::cout << "Tipo: Podcast" << std::endl;
    std::cout << "Host: " << _host << std::endl;
    std::cout << "Episodio: " << _episodio << std::endl;
}

void Podcast::play() const {
    for (int i = 1; i <= _duracao_s; ++i) {
        std::cout << "Playing " << _titulo << " [" << i << "/" << _duracao_s << "]" << std::endl;
    }
}

std::string Podcast::tipo() const{
    return "Podcast";
}