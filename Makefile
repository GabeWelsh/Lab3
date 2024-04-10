all: program

debug:
	g++ main.cpp prompt.cpp response.cpp -I . -o exe -g

program:
	g++ main.cpp prompt.cpp response.cpp -I . -o exe

clean:
	rm -rf *.o exe

run: program
	./exe