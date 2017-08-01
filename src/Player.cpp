#include "Player.hpp"

Player::Player(const char* name):
    m_name(name) {
}

Player::~Player() {
}

const char* Player::getName() {
    return m_name;
}

