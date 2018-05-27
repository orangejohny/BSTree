mkdir -p debug
cd debug
rm tree1.txt -f
g++ -coverage -I../include -I../tests ../tests/test1.cpp ../tests/main.cpp -o test
./test -r compact --out testResult.txt
lcov -t "test" -o test.info -c -d .
genhtml -o report test.info
cd ..
echo "To watch the report open debug/report/index.html"