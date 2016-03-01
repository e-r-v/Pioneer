DIR=obj/

#main dependency
main: $(DIR)main.o $(DIR)graph.o $(DIR)kb.o $(DIR)stars.o $(DIR)mytimer.o main.h
	gcc -Wall -o main $(DIR)main.o $(DIR)graph.o $(DIR)kb.o $(DIR)stars.o $(DIR)mytimer.o /usr/local/lib/liballegro.so /usr/local/lib/liballegro_acodec.so /usr/local/lib/liballegro_audio.so /usr/local/lib/liballegro_color.so /usr/local/lib/liballegro_font.so /usr/local/lib/liballegro_image.so /usr/local/lib/liballegro_main.so /usr/local/lib/liballegro_memfile.so /usr/local/lib/liballegro_physfs.so /usr/local/lib/liballegro_primitives.so /usr/local/lib/liballegro_ttf.so

$(DIR)main.o: main.c
	gcc -c main.c -o $(DIR)main.o

$(DIR)graph.o: graph.c graph.h
	gcc -c graph.c -o $(DIR)graph.o

$(DIR)kb.o: kb.c kb.h
	gcc -c kb.c -o $(DIR)kb.o
	
$(DIR)stars.o: stars.c stars.h
	gcc -c stars.c -o $(DIR)stars.o
	
$(DIR)mytimer.o: mytimer.c mytimer.h
	gcc -c mytimer.c -o $(DIR)mytimer.o
