#! /bin/bash
cd ~/tutorial-and-projects/cpp-tutorials/game_programming_course/assignments/assignment_1


case $1 in 
    'build')            
            ;;
    'run') 
            ;;
    *) echo 'please provide a valid argument: run | build'
esac

executable_path='bin/sfmlgame'

if [ -e "$executable_path" ]; then
    rm $executable_path
fi
g++ src/*.cpp -std=c++17 -o bin/sfmlgame -Isrc -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

if [ "$1" = 'run' ]; then
    chmod u+x $executable_path
    echo 'running game'
    cd bin && ./sfmlgame
else
    echo 'build successful'
fi

exit 0
