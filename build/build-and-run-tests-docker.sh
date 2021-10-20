bash clean-all.sh
../docker/start-compiler.sh
docker exec firmware-compiler bash ../build/build-tests.sh
docker exec firmware-compiler  ../app/brewblox-particle/test/build/brewblox_test_runner
docker exec firmware-compiler  ../controlbox/build/cbox_test_runner
docker exec firmware-compiler  ../lib/test/build/lib_test_runner