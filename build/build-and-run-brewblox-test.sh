#!/bin/bash
MY_DIR=$(dirname $(readlink -f $0))

function status()
{
if [[ "$1" -eq 0 ]]; then
  echo "✓ SUCCESS"
else
  echo "✗ FAILED"
  exit "$1";
fi
}

pushd "$MY_DIR/../app/brewblox-particle/test" > /dev/null
echo "Building BrewBlox app unit tests"
make -j $MAKE_ARGS -s runner
(( result = $? ))
status $result
(( exit_status = exit_status || result ))

build/brewblox_test_runner
(( result = $? ))
status $result
(( exit_status = exit_status || result ))
popd > /dev/null

exit $exit_status

