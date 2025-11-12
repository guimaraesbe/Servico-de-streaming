#include <iostream>
#include "Playlist.hpp"

Playlist::Playlist(std::string nome) : _nome(nome) {}

void Playlist::add(std::shared_ptr<Midia> faixa) {
    _faixas.push_back(faixa);
}

void Playlist::list() const {
    if(_faixas.empty()) {
        std::cout << "Info: (vazio) " << std::endl;
        return;
    }
    for(size_t i = 0; i < _faixas.size(); i++) {
        std::cout << "Info: Faixa " << (i +1) << std::endl;
        std::cout << *(_faixas[i]) << std::endl;
    }
}