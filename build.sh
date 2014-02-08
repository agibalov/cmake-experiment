rm -rf build
mkdir build
cd build
cmake ..
make

echo "*** Running tests"
./hello-test
echo "*** Done"

echo "*** Running app"
./hello
echo "*** Done"

cd ..
