default:
	make build
	make run

build:
	g++-10 -std=c++17 -Wshadow -Wall -Wno-unused-result -fsanitize=address -fsanitize=undefined -fmax-errors=1 -g -D_GLIBCXX_DEBUG -o price_generator price_generator.cpp 
	g++-10 -std=c++17 -Wshadow -Wall -Wno-unused-result -fsanitize=address -fsanitize=undefined -fmax-errors=1 -g -D_GLIBCXX_DEBUG -o trade_logic trade_logic.cpp 

run:
	./price_generator 10000 1 > price_val.log
	./trade_logic 100000 10 10 < price_val.log 2> trade.log