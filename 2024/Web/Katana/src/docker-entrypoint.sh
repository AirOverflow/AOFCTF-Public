#!/bin/ash
# *~ Author: @TheFlash2k

wget "http://172.17.0.1:9512/flag?chal_id=$CHALLENGE_ID&team_id=$TEAM_ID&user_id=$USER_ID" -O /home/bot/flag.txt

rm -- "$0"

node /home/bot/index.js
