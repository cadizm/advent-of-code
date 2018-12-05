```bash
$ make run
docker-compose run --rm --workdir=/src dev-env
b3a1f792fb63:/src$ ls
2017/  2018/  docker-compose.yml  Makefile  README.md
b3a1f792fb63:/src$ cd 2018
b3a1f792fb63:/src/2018$ ls
CPPLINT.cfg  data/  day01.cc  Makefile  README.md
b3a1f792fb63:/src/2018$ make
g++ -g -Wall -Wextra -pthread -pipe -O2 -std=c++11 -I/googletest/googletest/include -L/googletest/build/lib  day01.cc  -lgtest -lgtest_main -lpthread -lm -o day01
b3a1f792fb63:/src/2018$ ./day01
516
71892
```
