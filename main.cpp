#include "rang.hpp"
#include "GameMaster.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>


int main() {
    GameMaster GM;
    //char input;
    //int vsComputer;
    //bool wykonanoRuch = false;

    sf::RenderWindow window(sf::VideoMode(1600, 900), "Kolko i Krzyzyk");
    
    sf::Sprite przyciskStart;
    sf::Texture teksturaStart;
    teksturaStart.loadFromFile("sprites\\start.png");
    przyciskStart.setTexture(teksturaStart);
    przyciskStart.setPosition(450,300);
    
    /*
    sf::RectangleShape przyciskStart;
    przyciskStart.setOutlineColor(sf::Color(255,255,255));
    przyciskStart.setOutlineThickness(5);
    przyciskStart.setSize(sf::Vector2f(700,300));
    przyciskStart.setPosition(450,300);
    */

    while(window.isOpen()) {
        sf::Event event;
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if(przyciskStart.getGlobalBounds().contains(mousePos.x,mousePos.y)) {
                    std::cout << "klik";
                }
            }
        }

        window.clear();
        window.draw(przyciskStart);
        window.display();
    }
    
 
    std::cout << rang::style::reset << rang::fg::reset << rang::bg::reset;
    //system("pause");
    return 0;
}

/*
// - - - - - TODO - - - - - //

[x] 1. Mozliwosc zmiany wielkosci planszy

[x] 2. Sprawdzanie wygranej dla roznych warunkow wygranej

[x] 3. Latwiejsze wybieranie pola do postawienia znaku:
        [x] a. jako cyfra 1-9 (jednak litery a-z)
        [x] b. odpowiednie wyswietlenie planszy

[ ] 4. Interfejs:
    [x] a. input uzytkownika
    [ ] b. czyszczenie konsoli
    [x] c. kolory
    [x] d. menu

[x] 5. Algorytm komputera:
    -> zbyt dlugie obliczenia dla 5x5

[ ] 6. Grafika:
    [ ] a. konfiguracja SFML
        -> coby sie kompilowalo

    NAPRAWIC:
        [x] a. algorytm wybiera pola po kolei (nie dziala)
        [x] b. czasem zle wyswietla gracza ktory wygral
        [x] c. dlugi czas obliczen dla 4x4:
            -> dodac mape ktora przechowuje stan planszy (np string)
            -> na poczatku minimax zapisuje do mapy stan planszy
            -> porownuje czy juz taki tam jest
            -> jesli tak to bierze wynik z niego
            -> na koncu minimax zapisuje do mapy stan planszy i wynik
*/