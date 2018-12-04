CXX = g++
EXE = allstars
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
IDIR = include
SRC = src
FLAGS = -std=c++11 -I$(IDIR)/
OBJS = obj/animation.o obj/boss.o obj/collision_checker.o obj/enemy.o obj/enemy_waves.o obj/enemy_waves_details.o obj/game_manager.o obj/garbage_remover.o obj/level.o obj/main.o obj/main_menu.o obj/movable.o obj/overlay.o obj/paused_state.o obj/players.o obj/playing_state.o obj/projectile.o obj/resources.o obj/ship_details.o obj/ships.o obj/ship_selection.o obj/spaceship.o obj/util.o 

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(LIBS) $^ -o $@

obj/animation.o: $(SRC)/animation.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/boss.o: $(SRC)/boss.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/collision_checker.o: $(SRC)/collision_checker.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/enemy.o: $(SRC)/enemy.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/enemy_waves.o: $(SRC)/enemy_waves.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/enemy_waves_details.o: $(SRC)/enemy_waves_details.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/game_manager.o: $(SRC)/game_manager.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/garbage_remover.o: $(SRC)/garbage_remover.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/level.o: $(SRC)/level.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/main.o: $(SRC)/main.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/main_menu.o: $(SRC)/main_menu.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/movable.o: $(SRC)/movable.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/overlay.o: $(SRC)/overlay.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/paused_state.o: $(SRC)/paused_state.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/players.o: $(SRC)/players.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/playing_state.o: $(SRC)/playing_state.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/projectile.o: $(SRC)/projectile.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/resources.o: $(SRC)/resources.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/ship_details.o: $(SRC)/ship_details.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/ships.o: $(SRC)/ships.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/ship_selection.o: $(SRC)/ship_selection.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/spaceship.o: $(SRC)/spaceship.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

obj/util.o: $(SRC)/util.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

main.o: $(SRC)/main.cpp

clean:
	rm obj/*.o *.gch $(IDIR)/*.gch
