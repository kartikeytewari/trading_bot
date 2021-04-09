# build files
g++-10 -std=c++17 -Wshadow -Wall -Wno-unused-result -fsanitize=address -fsanitize=undefined -fmax-errors=1 -g -D_GLIBCXX_DEBUG -o price_generator price_generator.cpp 
g++-10 -std=c++17 -Wshadow -Wall -Wno-unused-result -fsanitize=address -fsanitize=undefined -fmax-errors=1 -g -D_GLIBCXX_DEBUG -o trade_logic trade_logic.cpp 

# run test cases
for ((i = 0 ; i <= 10 ; i++)) do
    ./price_generator 30 $i > price_val.log
    ./trade_logic 100000 10 10 < price_val.log > trade.log
done
