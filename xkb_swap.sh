#!/bin/bash


if [ "$(setxkbmap -query | awk '/layout/{print $2}')" = "us" ]; then
   setxkbmap -layout clmk-dh
else
   setxkbmap -layout us
fi
