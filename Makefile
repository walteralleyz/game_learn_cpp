exec: build link run

build:
	g++ -c *.cpp && cd objects && g++ -c *.cpp && cd ..

link:
	g++ -o game -I ./game *.o objects/*.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

run:
	clear && echo "Starting game..." && ./game