


## install few packages
```
sudo apt install g++ libcln6 libcln6-dev python-matplotlib python-numpy python2.7-dev
```


## extract ginac
## extract matplotlib

## install ginac
```
cd ginac-1.7.6
./configure
make
sudo make install
```

## compile ur program
```
g++ -o main main.cpp -lginac -std=c++11 -I/usr/include/python2.7 -lpython2.7
```

## run
./main

