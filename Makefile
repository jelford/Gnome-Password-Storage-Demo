all: 
	gcc -o insert_test_password main.c -I/usr/include/gnome-keyring-1 -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include  -lgnome-keyring -lglib-2.0   -Wall
