all: Matrix_mult.o naive_method.o transpose.o loop_permutation.o
	# When using macOS w/o C++11
	# g++ Matrix_mult.o naive_method.o transpose.o loop_permutation.o -o test
	clang++ -std=c++11 -stdlib=libc++ Matrix_mult.o naive_method.o transpose.o loop_permutation.o -o test
	
Matrix_mult.o: Matrix_mult.cpp
	clang++ -std=c++11 -stdlib=libc++ -c Matrix_mult.cpp 
	# g++ -c Matrix_mult.cpp 

naive_method.o: naive_method.cpp
	clang++ -std=c++11 -stdlib=libc++ -c naive_method.cpp 
	# g++ -c naive_method.cpp 

loop_permutation.o: loop_permutation.cpp
	clang++ -std=c++11 -stdlib=libc++ -c loop_permutation.cpp 
	# g++ -c loop_permutation.cpp 

transpose.o: transpose.cpp
	clang++ -std=c++11 -stdlib=libc++ -c transpose.cpp 
	# g++ -c transpose.cpp 

clean:
	rm -rf *o test