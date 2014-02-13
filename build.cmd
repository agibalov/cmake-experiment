rd build /s /q
mkdir build
cd build
cmake .. -G"Visual Studio 12 Win64"
msbuild hello.sln
Debug\hello-test
Debug\hello
cd ..
