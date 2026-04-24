.PHONY: writer reader pipe

pipe:
	mkfifo MyPipe

writer:
	gcc writer.c -o writer

reader:
	gcc reader.c -o reader
