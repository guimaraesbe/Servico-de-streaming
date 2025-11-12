#include "Catalogo.hpp"
#include "Musica.hpp"
#include "Podcast.hpp"
#include <iostream>

bool Catalogo::add_musica(std::string titulo, int duracao_s, std::string artista, std::string genero) {
    if(get(titulo) != nullptr) {
        std::cout << "Erro: titulo " << titulo << " repetido" << std::endl;
        return false;
    }
    _itens.push_back(std::make_shared<Musica>(titulo, duracao_s, artista, genero));
    std::cout << "OK: musica " << titulo << " adicionada" << std::endl;
    return true;
}

bool Catalogo::add_podcast(std::string titulo, int duracao_s, std::string host, int episodios) {
    if(get(titulo) != nullptr) {
        std::cout << "Erro: titulo " << titulo << " repetido" << std::endl;
        return false;
    }
    _itens.push_back(std::make_shared<Podcast>(titulo, duracao_s, host, episodios));
    std::cout << "OK: podcast " << titulo << " adicionado" << std::endl;
    return true;
}

std::shared_ptr<Midia> Catalogo::get(std::string titulo) const {
    for (auto& m : _itens) {
        if (m->get_titulo() == titulo) {
            return m;
        }
    }
    return nullptr;
}

void Catalogo::list_all() const {
    if (_itens.empty()) {
        std::cout << "Info: (vazio)" << std::endl;
        return;
    }
    for (auto& m : _itens) {
        std::cout << *m << std::endl; // usa operator<<
    }
}