#!/bin/bash

clear


echo "Welcome to So_long_Tester, by nsauret."
echo
echo
echo "--------------------------------------------------------------"
echo

echo
echo "[without arg]"
ARG='./so_long'
echo command: $ARG; eval $ARG
echo

echo "~"

echo
echo "[with too much args]"
ARG='./so_long pata pon don chaka'
echo command: $ARG; eval $ARG
echo

echo "~"

echo
echo "[with wrong map]"
ARG='./so_long do_not_exist.ber'
echo command: $ARG; eval $ARG
echo

echo "~"

echo
echo "[with wrong map extension]"
ARG='./so_long do_not_exist.bear'
echo command: $ARG; eval $ARG
echo

echo "~"

chmod 000 Maps/Tester/empty.ber
echo
echo "[with wrong permissions]"
ARG='./so_long Maps/Tester/empty.ber'
echo command: $ARG; eval $ARG
echo
chmod 777 Maps/Tester/empty.ber

echo "~"

echo
echo "[with empty file]"
ARG='./so_long Maps/Tester/empty.ber'
echo command: $ARG; eval $ARG
echo

echo "~"

echo
echo "[with not rectangular map]"
ARG='./so_long Maps/Tester/not_rectangular.ber'
echo command: $ARG; eval $ARG
echo

echo "~"

echo
echo "[without player]"
ARG='./so_long Maps/Tester/no_player.ber'
echo command: $ARG; eval $ARG
echo

echo "~"

echo
echo "[with two players]"
ARG='./so_long Maps/Tester/two_players.ber'
echo command: $ARG; eval $ARG
echo

echo "~"

echo
echo "[without exit]"
ARG='./so_long Maps/Tester/no_exit.ber'
echo command: $ARG; eval $ARG
echo

echo "~"

echo
echo "[with two exits]"
ARG='./so_long Maps/Tester/two_exits.ber'
echo command: $ARG; eval $ARG
echo

echo "~"

echo
echo "[without coins]"
ARG='./so_long Maps/Tester/no_coins.ber'
echo command: $ARG; eval $ARG
echo

echo "~"

echo
echo "[with a wrong character]"
ARG='./so_long Maps/Tester/wrong_character.ber'
echo command: $ARG; eval $ARG
echo

echo "~"

echo
echo "[without walls]"
ARG='./so_long Maps/Tester/no_walls.ber'
echo command: $ARG; eval $ARG
echo

echo "~"

echo
echo "[exit not reachable]"
ARG='./so_long Maps/Tester/exit_not_reachable.ber'
echo command: $ARG; eval $ARG
echo

echo "~"

echo
echo "[with a not reachable coin]"
ARG='./so_long Maps/Tester/coin_not_reachable.ber'
echo command: $ARG; eval $ARG
echo