#!/bin/bash

clear


echo "Welcome to So_long_Valgrind_Tester, by nsauret."
echo
echo
echo "--------------------------------------------------------------"
echo

echo
echo "[without arg]"
ARG='./so_long'
echo command: $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
echo "[with too much args]"
ARG='./so_long pata pon don chaka'
echo command: $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
echo "[with wrong map]"
ARG='./so_long do_not_exist.ber'
echo command: $ARG; eval $ARGv
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
echo "[with wrong map extension]"
ARG='./so_long do_not_exist.bear'
echo command: $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

chmod 000 Tester/Maps/subject.ber
echo
echo "[with wrong permissions]"
ARG='./so_long Tester/Maps/subject.ber'
echo command: $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo
chmod 777 Tester/Maps/subject.ber

echo "~"

echo
echo "[with empty file]"
ARG='./so_long Tester/Maps/empty.ber'
echo command: $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
echo "[with not rectangular map]"
ARG='./so_long Tester/Maps/not_rectangular.ber'
echo command: $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
echo "[without player]"
ARG='./so_long Tester/Maps/no_player.ber'
echo command: $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
echo "[with two players]"
ARG='./so_long Tester/Maps/two_players.ber'
echo command: $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
echo "[without exit]"
ARG='./so_long Tester/Maps/no_exit.ber'
echo command: $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
echo "[with two exits]"
ARG='./so_long Tester/Maps/two_exits.ber'
echo command: $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
echo "[without coins]"
ARG='./so_long Tester/Maps/no_coins.ber'
echo command: $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
echo "[with a wrong character]"
ARG='./so_long Tester/Maps/wrong_character.ber'
echo command: $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
echo "[without walls]"
ARG='./so_long Tester/Maps/no_walls.ber'
echo command: $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
echo "[exit not reachable]"
ARG='./so_long Tester/Maps/exit_not_reachable.ber'
echo command: $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
echo "[with a not reachable coin]"
ARG='./so_long Tester/Maps/coin_not_reachable.ber'
echo command: $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

rm tmp