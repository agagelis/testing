project : Engine.o Gnome.o HiScore.o  main.o Moving.o Potter.o Traal.o Jewel.o GameMap.o Monster.o HiScoreManager.o
			g++ Engine.o Gnome.o HiScore.o  main.o Moving.o Potter.o Traal.o Jewel.o GameMap.o Monster.o HiScoreManager.o -o project -lncurses
Engine.o : Engine.cpp
			g++ -c Engine.cpp
Gnome.o : Gnome.cpp
			g++ -c Gnome.cpp
HiScore.o : HiScore.cpp
			g++ -c HiScore.cpp

main.o : main.cpp
			g++ -c main.cpp
Moving.o : Moving.cpp
			g++ -c Moving.cpp
Potter.o : Potter.cpp
			g++ -c Potter.cpp
Traal.o : Traal.cpp
			g++ -c Traal.cpp
Jewel.o : Jewel.cpp
			g++ -c Jewel.cpp
GameMap.o : GameMap.cpp
			g++ -c GameMap.cpp	
Monster.o : Monster.cpp
			g++ -c Monster.cpp	
HiScoreManager.o : HiScoreManager.cpp
			g++ -c HiScoreManager.cpp							
clean: 
		rm *.o project