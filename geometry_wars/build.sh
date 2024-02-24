#! /bin/bash
cd build && cmake .. && make 
case $1 in 
    'build')            
            ;;
    'run') 
            ./geometry_wars
            ;;
    *)
        ;;
esac


