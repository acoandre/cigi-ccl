mkdir _linux
cd _linux
cmake -S ../
cmake ./ -DCCL_EXAMPLES_ENABLE=ON
cmake --build ./
cmake --install ./