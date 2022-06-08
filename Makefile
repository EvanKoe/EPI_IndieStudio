all:
	cd build && make
	cp build/bomberman ./bomberman

cm:
	mkdir -p build
	cd build && cmake ..

clean:
	rm -rf build/

fclean: clean

re: fclean cm all
