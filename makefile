all: main.cpp GameMaster.cpp Plansza.cpp Pole.cpp Gracz.cpp
	g++ -Wall -pedantic main.cpp GameMaster.cpp Plansza.cpp Pole.cpp Gracz.cpp -IC:\\Users\\r0ck\\Desktop\\SFML-2.4.0\\include -LC:\\Users\\r0ck\\Desktop\\SFML-2.4.0\\lib -lsfml-graphics -lsfml-window -lsfml-system
#g++ -Wall -pedantic main.cpp GameMaster.cpp Plansza.cpp Pole.cpp Gracz.cpp -IC:\\Users\\user\\Desktop\\SFML-2.5.1\\include -LC:\\Users\\user\\Desktop\\SFML-2.5.1\\lib -lsfml-graphics -lsfml-window -lsfml-system
