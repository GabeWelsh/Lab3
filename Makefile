all: program

debug: main prompt response
	g++ main.cpp prompt.cpp response.cpp -o exe -g

program: main prompt response
	g++ main.cpp prompt.cpp response.cpp -o exe

main: main.cpp prompt.h response.h
	@g++ -c main.cpp

prompt: prompt.cpp prompt.h response.h
	@g++ -c prompt.cpp

response: response.cpp response.h
	@g++ -c response.cpp

clean:
	rm -rf *.o exe

run: program
	./exe