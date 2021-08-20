#! /bin/bash

trap "exit" INT TERM ERR
trap "kill 0" EXIT

PORT=6789

if [ $# -eq 0 ]
  then
    echo "No arguments supplied"
    echo "First argument should be ip of Spark 4: ota-flash.sh 192.168.1.100"
    exit 1
fi

# get local ip, filter out localhost and docker addresses
LOCALIP=$(ifconfig | grep -Eo 'inet (addr:)?([0-9]*\.){3}[0-9]*' \
  | grep -Eo '([0-9]*\.){3}[0-9]*' \
  | grep -v '127.0.0.1' \
  | grep -vE '172\.([0-9]*\.){2}[0-9]')

POST_URL="http://$1/firmware_update"
SERVE_URL="http://$LOCALIP:$PORT/brewblox_esp.bin"

echo "Serving build directory from from http://$1:6789"
echo "Sending POST to $POST_URL with firmware URL $SERVE_URL"

python3 -m http.server $PORT --directory build & 

curl -X POST "$POST_URL" -d "$SERVE_URL"
wait
exit $?