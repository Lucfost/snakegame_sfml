#pragma once
#include<iostream>
#include<functional>
#include<vector>
#include<SFML/Window/Event.hpp>
 
/// 
/// Here you can customize it by adding any mouse or keyboard template.
/// 

typedef std::function<void(sf::Keyboard::Key)> KeyboardFunction;
typedef std::vector<KeyboardFunction> KeyboardFunctionList;

typedef std::function<void(sf::Event::MouseMoveEvent)> MouseMoveFunction;
typedef std::vector<MouseMoveFunction> MouseMoveFunctionList;

typedef std::function<void(sf::Event::MouseButtonEvent)> MouseClickFunction;
typedef std::vector<MouseClickFunction> MouseClickFunctionList;