all:
	mkdir build && cd build && cmake .. && make
	cp build/bomberman ./bomberman

clean:
	rm -rf build/

fclean: clean

re: fclean all