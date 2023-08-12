//
// Created by anup on 8/11/23.
//
#include<sstream>
#include "Intro_State.hpp"
#include "MainMenuState.hpp"
namespace ttt {
    IntroState::IntroState(ttt::GameDataRef data) : _data(data) {}

    void IntroState::init() {
        _data->assets.loadTexture("IntroPage", "/home/anup/CLionProjects/sfml-test/rec/IntroPage.jpg");

        _sprite.setTexture(_data->assets.getTexture("IntroPage"));
    }

    void IntroState::handleInput() {
        sf::Event evt;
        while (_data->window.pollEvent(evt)) {
            if (sf::Event::Closed == evt.type) {
                _data->window.close();


             }
         }
    }



     void IntroState::update(float dt) {
         if (_clock.getElapsedTime().asSeconds() > 3)
         {
             // Switch To Main Menu
             _data->machine.addState(StateRef(new MainMenuState(_data)), true);
         }


     }
     void IntroState::render(float dt) {

         _data->window.clear(sf::Color::Red);
         _data->window.draw(_sprite);
//         _data->window.draw(_text);

         _data->window.display();
     }
}